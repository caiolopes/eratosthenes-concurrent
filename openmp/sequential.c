#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Based on "Parallel programming in C with MPI and OpenMP"
 * by Quinn
 */

int main(int argc, char *argv[]) {
  unsigned int first, i, index, n, prime;
  char *marked;

  if (argc < 2) {
      printf("Usage: %s n [--print all]\n"
             "n: maximum number\n"
             "--print: print num of primes (optional)\n"
             "all: print all primes (optional)\n", argv[0]);
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
      if(!strcmp(argv[2], "--print") || !strcmp(argv[2], "--print\n")) {
          int count = 0;
          if((argc > 3) && (!strcmp(argv[3], "all") || !strcmp(argv[2], "all\n"))) {
              for (int i = 0; i <= n; i++) {
                  if (marked[i] == 1) {
                      printf("%d\n", i);
                      count++;
                  }
              }
          } else {
              for (int i = 0; i <= n; i++) {
                  if (marked[i] == 1) {
                      count++;
                  }
              }
          }
          printf("There are %d primes less than or equal to %d\n", count, n);
      }
  }


  return 0;
}
