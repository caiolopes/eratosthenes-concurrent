#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <pthread.h>

using namespace std;

struct process_t {
  int k;
  int n;
  int begin;
  int end;
};

typedef process_t process_t;

vector<int> primes;
pthread_mutex_t print_lock;

void *process(void *args) {
  process_t *data = (process_t *) args;

  //pthread_mutex_lock(&print_lock);
  //cout << "from " << data->begin << " to " << data->end << endl;
  //pthread_mutex_unlock(&print_lock);
  for (int i = 2; i <= sqrt(data->n); i++) {
    if (primes[i] == 1) {
      for (int j = i; i*j <= data->end; j++) {
          //pthread_mutex_lock(&print_lock);
          //cout << "k: " << data->k << ", i*j: " << i << "*" << j<< endl;
          //pthread_mutex_unlock(&print_lock);
          primes[i*j] = 0;
      }
    }
  }

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

    int last_end;
    pthread_mutex_init(&print_lock, NULL);

    for (int k = 0; k < num_threads; k++) {
      process_t *args = (process_t *) malloc(sizeof(process_t));

      args->k = k;
      args->n = n;
      if (k == 0) {
        args->begin = 2;
        args->end = first_block_size;
        last_end = args->end;
      } else {
        args->begin = last_end + 1;
        args->end = args->begin - 1 + block_size;
        last_end = args->end;
      }

      //cout << "k: " << k << ", start: " << args->begin << ", end: " << args->end << endl;

      rc = pthread_create(&threads[k], NULL, process, (void *)args);

      if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(1);
      }
    }

    for (int k = 0; k < num_threads; k++) {
      pthread_join(threads[k], NULL);
    }

    if (argc > 3) {
      int count = 0;
      for (int i = 0; i < primes.size(); i++) {
        if (primes[i]) {
		  cout << i << '\n';
          count++;
        }
      }
     cout << "\nThere are " << count << " primes less than or equal to " << n << "\n" << endl;
    }
  } else {
    cout << "usage: " << argv[0] << " n num_threads [print]" << endl;
  }

  return 0;
}
