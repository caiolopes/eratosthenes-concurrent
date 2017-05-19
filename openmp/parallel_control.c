#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <string.h>

// Usage: time ./e_con n [--print]
int n;
int n_max;
int n_threads;
unsigned char* primes;


int main (int argc, char **argv) {
    omp_lock_t index_lock;

    if (argc > 1) {
        n_max = atoi(argv[1]);
        primes = (unsigned char*)malloc(sizeof(unsigned char) * (n_max+1));
        for (int i = 0; i <= n_max; i++) {
          primes[i] = 1;
        }

        primes[0] = 0;
        primes[1] = 1;

        omp_init_lock(&index_lock);

        n = 2;
        int nthreads = omp_get_num_threads();


#pragma omp parallel
        while(1) {
            omp_set_lock(&index_lock);
            if(n > sqrt(n_max)) {
                omp_unset_lock(&index_lock);
                break;
            }
            int i = n;
            n++;
            omp_unset_lock(&index_lock);
            if (primes[i] == 1) {
                for (int j = 2; i*j <= n_max; j++) {
                    primes[i*j] = 0;
                }
            }
            nthreads = omp_get_num_threads();
        }

        if (argc > 2) {
            if(strcmp(argv[2], "--print") || strcmp(argv[2], "--print\n")) {
                int count = 0;
                if((argc > 3) && (strcmp(argv[3], "all") || strcmp(argv[2], "all\n"))) {
                    for (int i = 0; i <= n_max; i++) {
                        if (primes[i] == 1) {
                            printf("%d\n", i);
                            count++;
                        }
                    }
                } else {
                    for (int i = 0; i <= n_max; i++) {
                        if (primes[i] == 1) {
                            count++;
                        }
                    }
                }
                printf("There are %d primes less than or equal to %d\n\n", count, n_max);
                printf("Number of threads = %d\n", nthreads);
            }
        }
    } else {
        printf("usage: ./e_con n [--print all]\n"
               "n: maximum number"
               "--print: print num of primes (optional)"
               "all: print all primes (optional)\n");
    }

    return 0;
}
