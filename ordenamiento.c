#include <stdio.h>
#include <stdlib.h>

void burbuja(int lista1[], int n) {
    int i, j;
 for (i=1; i<n; i++){
          for (j=0 ; j<n - 1; j++){
               if (lista1[j] > lista1[j+1]){
                   int temp = lista1[j];
                   lista1[j] = lista1[j+1];
                    lista1[j+1] = temp;
            }
        }
    }
}

void insercion(int lista1[], int n) {
    int i, k, j;
    for (i = 1; i < n; i++) {
        k = lista1[i];
        j = i - 1;
        while (j >= 0 && lista1[j] > k) {
            lista1[j + 1] = lista1[j];
            j = j - 1;
        }
        lista1[j + 1] = k;
    }
}

void seleccion(int lista1[], int n) {
    int i, j, pos_menor;
    for (i = 0; i < n - 1; i++) {
        pos_menor = i;
        for (j = i + 1; j < n; j++) {
            if (lista1[j] < lista1[pos_menor]) {
                pos_menor = j;
            }
        }
        int temp = lista1[i];
        lista1[i] = lista1[pos_menor];
        lista1[pos_menor] = temp;
    }
}

void printArray(int lista1[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", lista1[i]);
    }
    printf("\n");
}

int main() {
    int lista1[] = { 20,50,10,5,17,35,26 };
    int n = sizeof(lista1) / sizeof(lista1[0]);
    int opcion;

    do {
        printf("\n");
        printf("Menu\n");
        printf("1. Burbuja\n");
        printf("2. Insercion\n");
        printf("3. Seleccion\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                burbuja(lista1, n);
                printf("Arreglo ordenado usando Burbuja: ");
                printArray(lista1, n);
                break;
            case 2:
                insercion(lista1, n);
                printf("Arreglo ordenado usando Insercion: ");
                printArray(lista1, n);
                break;
            case 3:
                seleccion(lista1, n);
                printf("Arreglo ordenado usando Seleccion: ");
                printArray(lista1, n);
                break;
            case 4:
                printf("Cerrando programa\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}