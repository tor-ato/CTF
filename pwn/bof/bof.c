#include <stdio.h>
#include <stdlib.h>

void win(void) {
    system("/bin/sh");
    exit(0);
}

int main(void) {
    char buf[30];
    scanf("%s", buf);
    puts(buf);
    return 0;
}
// gcc chall.c -fno-stack-protection -fno-pie -o chall
