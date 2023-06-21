//Gestion de pacientes de un hospital
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PACIENTES 100

typedef struct { //Define una estructura en la cual se ingresan distinto tipos de datos.
    char nombre[60]; //Tipo de dato "caracter" con un maximo de [60] a ingresar.
    char apellido[60];
    int edad; //Tipo de dato entero.
    int altura;
    float peso; //Tipo de dato decimal.
    char obraSocial[50];
    char condicion[500];
    char alergias[150];
    char alergia[500];
    char alergia[500];
    int darDeBaja;
} paciente;

void darDeBaja(paciente* listaPacientes, int tamano);// Permitirá eliminar a un paciente registrado en la lista.
void ingresarPaciente(paciente* listaPacientes, int* tamano);//Se cargará la informacion de un paciente.
void mostrarPacientes(paciente* listaPacientes, int tamano);//vizualizacion de la lista de pacientes y sus datos correspondientes.  
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

    paciente nuevoPaciente;//ingresar los datos de nuevo paciente

    printf("Ingrese nombre del paciente: ");//proporcionamos el nombre 
    scanf("%s", nuevoPaciente.nombre);

    printf("Ingrese apellido del paciente: ");//proporcionamos el apellido
    scanf("%s", nuevoPaciente.apellido);

    printf("Ingrese edad del paciente: ");//proporcionamos la edad
    scanf("%d", &nuevoPaciente.edad);

    printf("Ingrese altura del paciente: ");//proporcionamos la altura
    scanf("%d", &nuevoPaciente.altura);

    printf("Ingrese peso del paciente: ");//proporcionamos el peso
    scanf("%f", &nuevoPaciente.peso);

    printf("Ingrese obra social del paciente: ");
    scanf("%s", nuevoPaciente.obraSocial);

    printf("Ingrese condicion del paciente: ");
    scanf("%s", nuevoPaciente.condicion);

    printf("Ingrese alergias del paciente: ");

    scanf("%s", nuevoPaciente.alergias);

    scanf("%s", nuevoPaciente.alergia);
    
    scanf("%s", nuevoPaciente.alergia);
    

    nuevoPaciente.darDeBaja = 0; 

    listaPacientes[*tamano] = nuevoPaciente;
    (*tamano)++;

    printf("Paciente ingresado correctamente.\n");
}

void mostrarPacientes(paciente* listaPacientes, int tamano) {
    printf("Lista de pacientes registrados:\n");//a continuacion se muestra los datos de los pacientes registrados
    for (int i = 0; i < tamano; i++) {
        printf("Paciente %d:\n", i + 1);
        printf("Nombre: %s\n", listaPacientes[i].nombre);
        printf("Apellido: %s\n", listaPacientes[i].apellido);
        printf("Edad: %d\n", listaPacientes[i].edad);
        printf("Altura: %d\n", listaPacientes[i].altura);
        printf("Peso: %.2f\n", listaPacientes[i].peso);
        printf("Obra Social: %s\n", listaPacientes[i].obraSocial);
        printf("Condicion: %s\n", listaPacientes[i].condicion);

        printf("Alergias: %s\n", listaPacientes[i].alergias);

        printf("alergias: %s\n", listaPacientes[i].alergia);

        printf("alergias: %s\n", listaPacientes[i].alergia);

        printf("----------------------------\n");
    }
}

void menu() { 
    paciente listaPacientes[MAX_PACIENTES];
    int tamano = 0;

    int opcion; 
    do { //Cumple la funcion de menu.
        printf(" --- Registro de pacientes --- \n");
        printf("1. Ingresar un nuevo paciente\n");
        printf("2. Dar de baja a un paciente\n");
        printf("3. Mostrar pacientes registrados\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) { //Permite seleccionar las opciones y que se lleve acabo la funcion a la cual fueron asignadas.
            case 1: {
                ingresarPaciente(listaPacientes, &tamano);
                break;// finaliza la ejecución de la instrucción do, switch o while
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
                printf("Saliendo del programa...\n"); //Permite salir del programa debido a que se afectada por "while (opcion != 0)".
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
    } while (opcion != 0); //Cuando se seleccione una opcion distinta de 0 el programa finalizara.
}

int main() {
    menu();
    return 0;
}
