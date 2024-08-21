#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    int n = 3;
    int sum = 0;
    double start_time, end_time;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    
    end_time = omp_get_wtime();

    printf("La suma total es: %d\n", sum);
    printf("Se calculó en %f segundos\n", end_time - start_time);

    return 0;
}