#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct process_t {
  int k;
  int n;
  int begin;
  int end;
} process_t;

void *thread(void *args) {
  process_t *data = (process_t *) args;
  
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  int count;
  int first;
  int i;
  int index;
  char *marked;
  int n;
  int N;
  int prime;

  if (argc != 2) {
    printf("Command line: %s <m>\n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);
  N = n+1;

  marked = (char *) malloc(N);

  if (marked == NULL) {
    printf("Cannot allocate enough memory\n");
    exit(1);
  }

  for (i = 0; i < N; i++) {
    marked[i] = 1;
  }

  marked[0] = 0;
  marked[1] = 0; // not primes
  index = 2;
  prime = 2;
  do {
    first = 2 * prime;

    printf("from %d to %d, prime: %d\n", first, N, prime);
    for (i = first; i < N; i += prime) {
      marked[i] = 0;
    }
    while (!marked[++index]);
    prime = index;
  } while (prime * prime <= n);

  count = 0;
  for (i = 0; i < N; i++) {
    count += marked[i];
  }

  printf("\nThere are %d primes less than or equal to %d\n\n", count, n);

  return 0;
}
