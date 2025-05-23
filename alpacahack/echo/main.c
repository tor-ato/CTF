#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 0x100

/* Call this function! */
void win() {
  char *args[] = {"/bin/cat", "/flag.txt", NULL};
  execve(args[0], args, NULL);
  exit(1);
}

int get_size() {
  // Input size
  int size = 0;
  scanf("%d%*c", &size);

  // Validate size
  if ((size = abs(size)) > BUF_SIZE) {
    puts("[-] Invalid size");
    exit(1);
  }

  return size;
}

void get_data(char *buf, unsigned size) {
  unsigned i;
  char c;

  // Input data until newline
  for (i = 0; i < size; i++) {
    if (fread(&c, 1, 1, stdin) != 1) break;
    if (c == '\n') break;
    buf[i] = c;
  }
  buf[i] = '\0';
}

void echo() {
  int size;
  char buf[BUF_SIZE];

  // Input size
  printf("Size: ");
  size = get_size();

  // Input data
  printf("Data: ");
  get_data(buf, size);

  // Show data
  printf("Received: %s\n", buf);
}

int main() {
	int size1 = abs(-2147483647);
	printf("abs(-2147483647): %d\n", size1);
	int size2 = abs(-2147483648);
	printf("abs(-2147483648): %d\n", size2);
	int size3 = abs(-2147483649);
	printf("abs(-2147483649): %d\n", size3);
	int size4 = abs(-2147483650);
	printf("abs(-2147483650): %d\n", size4);
  // setbuf(stdin, NULL);
  // setbuf(stdout, NULL);
  // echo();
  return 0;
}
