#include <omp.h>
#include <stdio.h>

int main() {
    int variable1 = 0; // Variable compartida
    int variable2 = 0; // Variable privada

    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < 10; i++) {
        variable1 += i; // Acceso a variable compartida
        variable2 = i * 2; // Acceso a variable privada
        printf("Hilo %d: variable1 = %d, variable2 = %d\n", omp_get_thread_num(), variable1, variable2);
    }

    printf("Valor final de variable1: %d\n", variable1);
    printf("Valor final de variable2: %d\n", variable2);

    return 0;
}