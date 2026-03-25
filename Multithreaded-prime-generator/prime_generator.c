#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 50000000
uint64_t primes[max] = {2};
pthread_mutex_t lock;
int next_index = 1; // Start at 1 since 2 is already in primes[0]

void* prime_thread(void* arg) {
    int start = *((int*)arg);
    int end = start + max / *((int*)arg + 1); // Calculate the end index for each thread

    for (uint64_t num = start; num < end; num++) {
        bool is_prime = true;
        for (uint64_t idx = 0; idx < next_index && primes[idx] * primes[idx] <= num; idx++) {
            if (!(num % primes[idx])) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            pthread_mutex_lock(&lock);
            primes[next_index++] = num;
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_exit(NULL);
}

char check_prime(uint64_t num) {
    for (uint64_t idx = 0; idx < next_index && primes[idx] * primes[idx] <= num; idx++)
        if (!(num % primes[idx]))
            return 0;
    return 1;
}

char is_in_list(uint64_t num) {
    for (int64_t i = 0; i < next_index; i++)
        if (primes[i] == num)
            return 1;
    return 0;
}

int intcmp(const uint64_t* a, const uint64_t* b) {
    if (*a < *b)
        return -1;
    return *a > *b;
}

int main(int argc, char** argv) {
    int threads = 1;
    if (argc > 1)
        threads = atoi(argv[1]);
    pthread_t handles[threads];
    int thread_ids[threads];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < threads; i++) {
        thread_ids[i] = i * (max / threads); // Start index for each thread
        if (pthread_create(&handles[i], NULL, prime_thread, &thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1); // Exit with error code 1
        }
    }

    for (int i = 0; i < threads; i++)
        if (pthread_join(handles[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1); // Exit with error code 1
        }

    pthread_mutex_destroy(&lock);

    printf("Middle 25 primes:\n");
    for (uint64_t i = max / 2; i < max / 2 + 25; i++)
        printf("%lu\n", primes[i]);

    printf("Last 25 primes:\n");
    for (uint64_t i = max - 25; i < max; i++)
        printf("%lu\n", primes[i]);

    return 0;
}
