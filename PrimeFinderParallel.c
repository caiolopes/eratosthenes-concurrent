#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

typedef struct process_t {
  int prime;
  int begin;
  int end;
} process_t;

char *marked;

pthread_mutex_t print_lock;

void *thread(void *args) {
  process_t *data = (process_t *) args;
  int i;

  pthread_mutex_lock(&print_lock);
  printf("from %d to %d, prime: %d\n", data->begin, data->end, data->prime);

  for (i = data->begin; i <= data->end; i += data->prime) {
    marked[i] = 0;
  } 

  pthread_mutex_unlock(&print_lock);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  int count;
  int first;
  int i;
  int index;
  int n;
  int N;
  int prime;
  int j;
  int block_size, first_block_size;
  int last_end;
  int num_threads;
  process_t *args;

  if (argc != 3) {
    printf("Command line: %s <m>\n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);
  num_threads = atoi(argv[2]);
  pthread_t threads[num_threads];
  N = n+1;


  pthread_mutex_init(&print_lock, NULL);
  marked = (char *) malloc(N);

  if (marked == NULL) {
    printf("Cannot allocate enough memory\n");
    exit(1);
  }

  for (i = 0; i < N; i++) {
    marked[i] = 1;
  }

  block_size = floor(N / num_threads);
  first_block_size = block_size + N % num_threads;

  marked[0] = 0;
  marked[1] = 0; // not primes
  index = 2;
  prime = 2;
  do {
    first = 2 * prime;

    printf("creating threads...\n");
    for (j = 0; j < num_threads; j++) {
      args = (process_t *) malloc(sizeof(process_t));
      if (j == 0) {
        args->begin = first;
        args->end = first_block_size;
        last_end = args->end;
      } else {
        args->begin = last_end;
        args->end = args->begin + block_size;
        last_end = args->end;
      }
      args->prime = prime;

      pthread_create(&threads[j], NULL, thread, (void *)args);
    }

    for (j = 0; j < num_threads; j++) {
      pthread_join(threads[j], NULL);
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
