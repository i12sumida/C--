/*
 * Programing Language C-- "Compiler"
 *    Tokuyama kousen Educational Computer 16bit Ver.
 *
 * Copyright (C) 2016 by
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
 * lx.c : C--コンパイラの字句解析ルーチンのドライバ
 *
 * 2016.04.30         : 初期バージョン
 *
 * $Id$
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../lexical.h"
#include "../util.h"
#include "util.h"

// 字句解析を行い、結果を出力する
static void procLex(FILE *ofp) {
  int tok = LxFILE;                            // ファイル名を出力するため
  while (tok!=EOF) {
    if(tok==LxNAME || tok==LxSTRING)
      fprintf(ofp, "%d\t%d\t%s\n", lxGetLn(), tok, lxGetStr());
    else if(tok==LxINTEGER || tok==LxLOGICAL || tok==LxCHARACTER)
      fprintf(ofp, "%d\t%d\t%d\n", lxGetLn(), tok, lxGetVal());
    else if(tok==LxFILE)
      fprintf(ofp, "%d\t%d\t%s\n", lxGetLn(), tok, lxGetFname());
    else
      fprintf(ofp, "%d\t%d\n", lxGetLn(), tok);
    tok=lxGetTok();
  }
}

// 入出力ファイルをオープンし字句解析を行う
int main(int argc, char *argv[]){
  FILE *ifp, *ofp;
  if (argc==2) {                               // ソースファイルの指定があれば
    ifp = eOpen(argv[1],"r");                  //   ソースファイルをオープン
    lxSetFname(argv[1]);                       //   error表示用にファイル名登録
  } else if (argc==1) {                        // ソースファイルの指定なしなら
    ifp = stdin;                               //   stdinからソースを読む
    lxSetFname("STDIN");                       //   error表示用にファイル名登録
  } else {
    fprintf(stderr, "使用方法 : %s [<srcfile>]\n", argv[0]);
    exit(1);
  }
  lxSetFp(ifp);                                // 字句解析に fp を知らせる

  ofp=openDstWithExt(lxGetFname(),".lx");      // 拡張子を".lx"に変更して
                                               //   書込み用にオープンする
  procLex(ofp);                                // 字句解析を行う
  return 0;
}
