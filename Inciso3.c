#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    #pragma omp sections
    {
        #pragma omp section
        {
            int factorial = 4;
            int faTotal = 1;
            printf("Funcion de numeros factoriales \n");
            for (int i = 1; i <= factorial; i++)
            {
                faTotal = faTotal * i;
            }
            printf("El factorial de %d es: %d \n", factorial, faTotal);
        }

        #pragma omp section
        {
        int fibonacci = 5;
        int n1 = 0, n2 = 1, fiTotal = 0;
        printf("Funcion de serie Fibonacci \n");
        for (int i = 0; i <= fibonacci; i++)
        {
            fiTotal = n1 + n2;
            n1 = n2;
            n2 = fiTotal;
        }
        printf("El numero %d de fibonacci es: %d \n", fibonacci, fiTotal);
        }

        #pragma omp section
        {
            int arreglo[] = {13, 22, 7, 51, 32, 22, 1};
            int size = sizeof(arreglo) / sizeof(arreglo[0]);
            int arMax = arreglo[0];
            printf("Funcion para encontrar el valor maximo de un array\n");
            for (int i = 1; i < size; i++)
            {
                if (arreglo[i] > arMax){
                    arMax = arreglo[i];
                }
            }
            
            printf("el valor maximo de este array es: %d \n", arMax);
        }

    }
}