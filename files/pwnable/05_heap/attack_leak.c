#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

unsigned long ofs_libc_mainarena = 0x1ebb80;
int main(void){
	void *ma, *mb;
	malloc_chunk *ca;

	setbuf(stdout, NULL);

	ma = malloc(0x418);
	// caはmaのヘッダーが入る
	ca = mem2chunk(ma);
	malloc(0);
	mb = malloc(0x418);
	malloc(0);

	// unsorted bin に入る
	free(ma);
	free(mb);

	puts("UAF");
	// (b -> a -> bin[0]) loop
	printf("heap base : %p\n",   (void*)ca->bk - 0x6d0);
	// main arena + 0x60 == bins[0]
	printf("libc base : %p\n\n", (void*)ca->fd - 0x60 - ofs_libc_mainarena);

	// 初期化してないから、上の情報がそのまま取れる。
	void *p = malloc(0x418);
	malloc_chunk *c = mem2chunk(p);

	puts("Uninitialized");
	printf("heap base : %p\n",   (void*)c->bk - 0x6d0);
	printf("libc base : %p\n\n", (void*)c->fd - 0x60 - ofs_libc_mainarena);
}
