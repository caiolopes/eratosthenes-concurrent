#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <pthread.h>

using namespace std;

struct process_t {
  int i;
  int begin;
  int end;
};

typedef process_t process_t;

vector<int> primes;

void *process(void *args) {
  //for (int j = begin; i*j <= end; j++) {
    //primes[i*j] = 0;
  //}
  pthread_exit(NULL);
}

int main (int argc, char **argv) {
  if (argc > 2) {
    int n = atoi(argv[1]);
    int num_threads = atoi(argv[2]);

    primes.resize(n + 1);

    for (int i = 0; i <= n; i++) {
      primes[i] = 1;
    }

    primes[0] = 0; // 0
    primes[1] = 1; // 1

    int block_size = floor(n / num_threads);
    int first_block_size = block_size + n % num_threads;
    int rc;
    pthread_t threads[num_threads];

    cout << first_block_size << endl;
    cout << block_size << endl;

    for (int i = 2; i <= sqrt(n); i++) {
      if (primes[i] == 1) {
        int last_end;
        for (int k = 0; k < num_threads; k++) {
          process_t *args = (process_t *) malloc(sizeof(process_t));

          args->i = i;
          if (k == 0) {
            args->begin = 2;
            args->end = first_block_size;
            last_end = args->end;
          } else {
            args->begin = last_end + 1;
            args->end = args->begin - 1 + block_size;
            last_end = args->end;
          }

          cout << "i: " << i << ", k: " << k << ", start: " << args->begin << ", end: " << args->end << endl;

          //rc = pthread_create(&threads[k], NULL, process, (void *)args);

          //if (rc) {
            //cout << "Error: unable to create thread, " << rc << endl;
            //exit(1);
          //} 
        }
      }
    }

    if (argc > 3) {
      for (int i = 0; i < primes.size(); i++) {
        if (primes[i]) {
          cout << i << endl;
        }
      }
    }
  } else {
    cout << "usage: " << argv[0] << " n num_threads [print]" << endl;
  }

  return 0;
}