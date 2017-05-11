#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void run() {
    return;
}

int main (int argc, char **argv) {

    if (argc > 1) {
        int n = atoi(argv[1]);
        int n_threads = atoi(argv[2]);

        pthread_t* threads = calloc(sizeof(pthread_t), n_threads);

        for(int i = 0; i < n_threads; i++) {
            if (pthread_create(&threads[i], 0, (void *) run, (void *) 0) != 0) {
                printf("ERROR - pthread_created failed!\n");
                exit(0);
            }
        }

        for(int i = 0; i < n_threads; i++) {
            pthread_join(threads[i], 0);
        }
    } else {
        printf("usage: ./e_con n t [--print]\n"
               "n: maximum number\n"
               "t: number of threads\n");
    }

    return 0;
}
