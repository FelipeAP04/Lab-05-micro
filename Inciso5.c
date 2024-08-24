#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072

long count_key(long Nlen, long *a, long key) {
    long count = 0;
    for (int i = 0; i < Nlen; i++)
        if (a[i] == key) count++;
    return count;
}

void count_key_task(long Nlen, long *a, long key, long *result) {
    if (Nlen <= 1024) { // Tamaño mínimo para la descomposición
        *result = count_key(Nlen, a, key);
    } else {
        long mid = Nlen / 2;
        long result1, result2;

        #pragma omp task
        count_key_task(mid, a, key, &result1);

        #pragma omp task
        count_key_task(Nlen - mid, a + mid, key, &result2);

        #pragma omp taskwait
        *result = result1 + result2;
    }
}

int main() {
    long a[N], key = 42, nkey = 0;
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    #pragma omp parallel
    {
        #pragma omp single
        count_key_task(N, a, key, &nkey);
    }

    printf("Numero de veces que 'key' aparece en paralelo: %ld\n", nkey);

    return 0;
}