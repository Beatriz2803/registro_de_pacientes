#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PACIENTES 100

typedef struct {
    char nombre[60];
    char apellido[60];
    int edad;
    int altura;
    float peso;
    char obraSocial[50];
    char condicion[500];
    int darDeBaja;
} paciente;

void darDeBaja(paciente* listaPacientes, int tamano);
void ingresarPaciente(paciente* listaPacientes, int* tamano);
void mostrarPacientes(paciente* listaPacientes, int tamano);
void menu();

void darDeBaja(paciente* listaPacientes, int tamano) {
    char nombre[60];
    char apellido[60];

    printf("Ingrese nombre del paciente a dar de baja: ");
    scanf("%s", nombre);
    printf("Ingrese apellido del paciente a dar de baja: ");
    scanf("%s", apellido);

 
    int encontrado = 0;
    for (int i = 0; i < tamano; i++) {
        if (strcmp(listaPacientes[i].nombre, nombre) == 0 && strcmp(listaPacientes[i].apellido, apellido) == 0) {
 
            for (int j = i; j < tamano - 1; j++) {
                listaPacientes[j] = listaPacientes[j + 1];
            }
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("El paciente ha sido dado de baja correctamente.\n");
    } else {
        printf("El paciente no se encontro en la lista.\n");
    }
}

void ingresarPaciente(paciente* listaPacientes, int* tamano) {
    if (*tamano >= MAX_PACIENTES) {
        printf("No se pueden agregar mas pacientes. La lista esta llena.\n");
        return;
    }

    paciente nuevoPaciente;

    printf("Ingrese nombre del paciente: ");
    scanf("%s", nuevoPaciente.nombre);

    printf("Ingrese apellido del paciente: ");
    scanf("%s", nuevoPaciente.apellido);

    printf("Ingrese edad del paciente: ");
    scanf("%d", &nuevoPaciente.edad);

    printf("Ingrese altura del paciente: ");
    scanf("%d", &nuevoPaciente.altura);

    printf("Ingrese peso del paciente: ");
    scanf("%f", &nuevoPaciente.peso);

    printf("Ingrese obra social del paciente: ");
    scanf("%s", nuevoPaciente.obraSocial);

    printf("Ingrese condicion del paciente: ");
    scanf("%s", nuevoPaciente.condicion);

    nuevoPaciente.darDeBaja = 0; 

    listaPacientes[*tamano] = nuevoPaciente;
    (*tamano)++;

    printf("Paciente ingresado correctamente.\n");
}

void mostrarPacientes(paciente* listaPacientes, int tamano) {
    printf("Lista de pacientes registrados:\n");
    for (int i = 0; i < tamano; i++) {
        printf("Paciente %d:\n", i + 1);
        printf("Nombre: %s\n", listaPacientes[i].nombre);
        printf("Apellido: %s\n", listaPacientes[i].apellido);
        printf("Edad: %d\n", listaPacientes[i].edad);
        printf("Altura: %d\n", listaPacientes[i].altura);
        printf("Peso: %.2f\n", listaPacientes[i].peso);
        printf("Obra Social: %s\n", listaPacientes[i].obraSocial);
        printf("Condicion: %s\n", listaPacientes[i].condicion);
        printf("----------------------------\n");
    }
}

void menu() {
    paciente listaPacientes[MAX_PACIENTES];
    int tamano = 0;

    int opcion;
    do {
        printf(" --- Registro de pacientes --- \n");
        printf("1. Ingresar un nuevo paciente\n");
        printf("2. Dar de baja a un paciente\n");
        printf("3. Mostrar pacientes registrados\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                ingresarPaciente(listaPacientes, &tamano);
                break;
            }
            case 2: {
                darDeBaja(listaPacientes, tamano);
                break;
            }
            case 3: {
                mostrarPacientes(listaPacientes, tamano);
                break;
            }
            case 0: {
                printf("Saliendo del programa...\n");
                break;
            }
            default:
                printf("Opción invalida. Intente nuevamente.\n");
                break;
        }

        getchar();
        printf("Presione una tecla para continuar...\n");
        getchar();
        system("cls");
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}
