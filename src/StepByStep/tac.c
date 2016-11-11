/*
 * Programing Language C-- "Compiler"
 *    Tokuyama kousen Educational Computer 16bit Ver.
 *
 * Copyright (C) 2010-2016 by
 *                      Dept. of Computer Science and Electronic Engineering,
 *                      Tokuyama College of Technology, JAPAN
 *
 *   上記著作権者は，Free Software Foundation によって公開されている GNU 一般公
 * 衆利用許諾契約書バージョン２に記述されている条件を満たす場合に限り，本ソース
 * コード(本ソースコードを改変したものを含む．以下同様)を使用・複製・改変・再配
 * 布することを無償で許諾する．
 *
 *   本ソースコードは＊全くの無保証＊で提供されるものである。上記著作権者および
 * 関連機関・個人は本ソースコードに関して，その適用可能性も含めて，いかなる保証
 * も行わない．また，本ソースコードの利用により直接的または間接的に生じたいかな
 * る損害に関しても，その責任を負わない．
 *
 *
 */

/*
 * tac.c : vm2tacのドライバ
 *
 * 2016.07.10         : 初期バージョン
 *
 * $Id$
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "util.h"
#include "../util.h"
#include "../vm.h"
#include "../namtbl.h"

#define StrMAX  128

// 大域データ
static char str[StrMAX + 1];
static FILE *fp;                                  // 入力ファイル
int lxGetLn(){ return 0; }                        // vm2tacでは使われないはず
char *lxGetFname() { return "ERROR lxGetFname"; } // vm2tacでは使われないはず

static void callfunc0(int op){
       if(op==22) vmRet();
  else if(op==23) vmRetI();
  else if(op==24) vmMReg();
  else if(op==25) vmArg();
  else if(op==26) vmLdWrd();
  else if(op==27) vmLdByt();
  else if(op==28) vmStWrd();
  else if(op==29) vmStByt();
  else if(op==30) vmNeg();
  else if(op==31) vmNot();
  else if(op==32) vmBNot();
  else if(op==33) vmChar();
  else if(op==34) vmBool();
  else if(op==35) vmAdd();
  else if(op==36) vmSub();
  else if(op==37) vmShl();
  else if(op==38) vmShr();
  else if(op==39) vmBAnd();
  else if(op==40) vmBXor();
  else if(op==41) vmBOr();
  else if(op==42) vmMul();
  else if(op==43) vmDiv();
  else if(op==44) vmMod();
  else if(op==45) vmGt();
  else if(op==46) vmGe();
  else if(op==47) vmLt();
  else if(op==48) vmLe();
  else if(op==49) vmEq();
  else if(op==50) vmNe();
  else if(op==51) vmPop();
  else if(op==60) vmOrd();
}

static void callfunc1(int op, int a1){
       if(op==0)  vmName(a1);
  else if(op==1)  vmTmpLab(a1);
  else if(op==2)  vmTmpLabStr(a1);
  else if(op==3)  vmJmp(a1);
  else if(op==4)  vmJT(a1);
  else if(op==5)  vmJF(a1);
  else if(op==6)  vmLdCns(a1);
  else if(op==7)  vmLdGlb(a1);
  else if(op==8)  vmLdLoc(a1);
  else if(op==9)  vmLdPrm(a1);
  else if(op==10) vmLdStr(a1);
  else if(op==11) vmLdLab(a1);
  else if(op==12) vmStGlb(a1);
  else if(op==13) vmStLoc(a1);
  else if(op==14) vmStPrm(a1);
  else if(op==15) vmDwName(a1);
  else if(op==16) vmDwLab(a1);
  else if(op==17) vmDwLabStr(a1);
  else if(op==18) vmDwCns(a1);
  else if(op==19) vmDbCns(a1);
  else if(op==20) vmWs(a1);
  else if(op==21) vmBs(a1);
}

static void callfunc2(int op, int a1, int a2){
       if(op==52)  vmEntry(a1, a2);
  else if(op==53)  vmEntryK(a1, a2);
  else if(op==54)  vmEntryI(a1, a2);
  else if(op==55)  vmCallP(a1, a2);
  else if(op==56)  vmCallF(a1, a2);
}

int main(int argc, char *argv[]){
  int op;
  char *fn = "stdin";
  if (argc==2){
    if (!strEndsWith(argv[1], ".vm")) error("入力ファイル形式が違う");
    fp = eOpen(argv[1],"r");  // 中間ファイルをオープン
    fn = argv[1];
  }else if(argc==1){
    fp = stdin;
  }else{
    fprintf(stderr, "使用方法 : %s [<srcfile>]\n", argv[0]);
    exit(1);
  }
  ntLoadTable(fn);                   // 名前表ファイルから名前表を作成
  while(true){
    op = getDec(fp);
    if(op==EOF)
      return 0;
    if(22<=op && op<=51){                    // 引数0の関数
      callfunc0(op);
    }else if(0<=op && op<=21){   // 引数1の関数
      int a1 = getDec(fp);
      callfunc1(op, a1);
    }else if(52<=op && op<=56){              // 引数2の関数
      int a1 = getDec(fp);
      int a2 = getDec(fp);
      callfunc2(op, a1, a2);
    }else if(op==57 || op==58){              // 引数3の関数
      int a1 = getDec(fp);
      int a2 = getDec(fp);
      int a3 = getDec(fp);
      if(op==57) vmBoolOR(a1, a2, a3);
      else       vmBoolAND(a1, a2, a3);
    }else if(op==59){
      int i=0;
      char ch;
      while((ch=fgetc(fp))!='\n'){               // 改行がくるまで文字列
        if(i>StrMAX)
          error("文字列が長すぎる");
        str[i] = ch;
        i = i+1;
      }
      str[i] = '\0';
      vmStr(str);
    }else{
      error("bug");
    }
  }
  return 0;
}
