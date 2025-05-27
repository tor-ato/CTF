#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

// ダブルフリ＝できるますよん
int main(void){
	void *m;

	// tcacheに入る
	m = malloc(0x18);
	// チャンクサイズの計算
	// ヘッダーを入れなくてはいけないから、
	// 0x18 + 0x10 = 0x28 
	// in usedはnext chunkのprev sizeまで使えるから、
	// 0x28 - 0x08 = 0x20が確保される
	printf("m = %p\n", m);

	// tcacheに入る
	free(m);
	((tcache_entry*)m)->key = NULL;	// vuln
	// 上記をすることによってdouble free checkを通過できる
	free(m);			// vuln

	// 二回tcache listに入ってしまっているので、mを二回取れてしまう。
	printf("1st malloc : %p\n", malloc(0x18));
	printf("2nd malloc : %p\n", malloc(0x18));
}
