#include <stdio.h>
#include <stdlib.h>

struct Prime {
  int primeNumber;
  int multipleOfPrime;
  struct Prime *next;
};

int main(int argc, const char *argv[]) {
  struct Prime *head;
  head = malloc(sizeof(struct Prime));
  (*head).primeNumber = 2;
  (*head).multipleOfPrime = 2;
  printf("First Prime: %d\n", (*head).primeNumber);
  return 0;
}
