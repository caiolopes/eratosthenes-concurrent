#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
//#include <time.h>

// Usage: time ./e_con n t
int n;
int n_max;
unsigned char* primes;

pthread_mutex_t index_cond_lock;


void run() {
    int i = 0;
    while(1) {
        pthread_mutex_lock(&index_cond_lock);
        if(n > sqrt(n_max)) {
            pthread_mutex_unlock(&index_cond_lock);
            return;
        }
        i = n;
        n++;
        pthread_mutex_unlock(&index_cond_lock);
        if (primes[i] == 1) {
            for (int j = 2; i*j <= n_max; j++) {
                primes[i*j] = 0;
            }
        }
    }
    return;
}

int main (int argc, char **argv) {


    if (argc > 1) {
        n_max = atoi(argv[1]);
        int n_threads = atoi(argv[2]);
        primes = (unsigned char*)malloc(sizeof(unsigned char) * (n_max+1));
        for (int i = 0; i <= n_max; i++) {
          primes[i] = 1;
        }

        pthread_t* threads = calloc(sizeof(pthread_t), n_threads);

        pthread_mutex_init(&index_cond_lock, NULL);

        n = 2;
        //clock_t begin = clock();
        for(int i = 0; i < n_threads; i++) {
            if (pthread_create(&threads[i], 0, (void *) run, (void *) 0) != 0) {
                printf("ERROR - pthread_created failed!\n");
                exit(0);
            }
        }

        for(int i = 0; i < n_threads; i++) {
            pthread_join(threads[i], 0);
        }
        //clock_t end = clock();

        //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        //printf("time spent: %f s\n", time_spent);
    } else {
        printf("usage: ./e_con n t [--print]\n"
               "n: maximum number\n"
               "t: number of threads\n");
    }

    if (argc > 3) {
      for (int i = 0; i <= n_max; i++) {
        if (primes[i] == 1) {
          printf("%d\n", i);
        }
      }
    }

    return 0;
}
