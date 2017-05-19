#include <stdlib.h>
#include <stdio.h>

/*
 * Based on "Parallel programming in C with MPI and OpenMP"
 * by Quinn
 */

int main(int argc, char *argv[]) {
  unsigned int count, first, i, index, n, prime;
  char *marked;

  if (argc < 2) {
    printf("Command line: %s N [print]\n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);

  marked = (char *) malloc(n+1);

  if (marked == NULL) {
    printf("Cannot allocate enough memory\n");
    exit(1);
  }

  for (i = 0; i < n+1; i++) {
    marked[i] = 1;
  }

  marked[0] = 0;
  marked[1] = 1;
  index = 2;
  prime = 2;
  
  do {
    first = 2 * prime;

    for (i = first; i <= n; i += prime) {
      marked[i] = 0;
    }
    
    while (!marked[++index]);

    prime = index;
  } while (prime * prime <= n);

  if (argc > 2) {
    count = 0;
    for (i = 0; i <= n; i++) {
      count += marked[i];
    }

    printf("\nThere are %d primes less than or equal to %d\n\n", count, n);
  }

  return 0;
}
