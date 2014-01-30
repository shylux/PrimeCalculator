#include <stdio.h>
#include <stdlib.h>

struct Prime {
  int primeNumber;
  int multipleOfPrime;
  struct Prime *next;
};

/* Checks if number is prime.
 * head is the beginning of a list containing all primes < number
 * number is the number to check
 * return true (1) if number is prime or false (0) otherwise
 */
int checkNumber(struct Prime *head, int number) {
  struct Prime *node = head;
  while (1) {
    while (node->multipleOfPrime < number)
      node->multipleOfPrime += node->primeNumber;
    if (node->multipleOfPrime == number) return 0;
    if (node->next == NULL) break;
    node = node->next;
  }
  // append new prime to list
  struct Prime *newPrime = malloc(sizeof(struct Prime));
  newPrime->primeNumber = number;
  newPrime->multipleOfPrime = number;
  newPrime->next = NULL;
  node->next = newPrime;
  return 1;
}

void printPrimes(struct Prime *head) {
  struct Prime *node = head;
  while (1) {
    printf("%d\n", node->primeNumber);
    if (node->next == NULL) break;
    node = node->next;
  }
}

int main(int argc, const char *argv[]) {
  struct Prime *head;
  head = malloc(sizeof(struct Prime));
  (*head).primeNumber = 2;
  (*head).multipleOfPrime = 2;
  (*head).next = NULL;

  int i;
  for (i = 3;; i++)
    if (checkNumber(head, i))
      printf("Added: %d\n", i);

  return 0;
}
