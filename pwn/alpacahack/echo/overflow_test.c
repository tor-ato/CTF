#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Received: %d\n",  abs(-2147483648));
	printf("Received: %d\n",  abs(-2147483649));
	return 0;
}

