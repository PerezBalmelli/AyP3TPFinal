#include <stdio.h>
#include <conio.h>
#include "gestionAlumnos.h"
#include "gestionAlumnos.c"

// - - - MAIN - - -

void menu(ListadoAlumnos * listadoAlumnos, ListadoMaterias * listadoMaterias){

    int input;
    char nombre[30];
    int numero1, numero2, numero3;
    char temp; // Variable temporal utilizada para capturar un salto de linea

    printf("                                      Bienvenido!\n                        SISTEMA DE GESTION UNIVERSITARIA BASICO\n\n========================================REGISTRO======================================\n");
    printf("\n Presione [1] para agregar nuevo alumno \n Presione [2] para agregar nueva materia \n Presione [3] para registrar una materia cursada \n Presione [4] para registrar una materia aprobada \n\n");
    printf("========================================CONSULTA======================================\n");
    printf("\n Presione [5] para calcular promedio de alumno \n Presione [6] para buscar alumno por nombre \n Presione [7] para buscar alumno por rango etario \n Presione [8] para ver todos los alumnos \n Presione [9] para ver todas las materias \n\n");
    printf("========================================SALIDA========================================\n");
    printf("\n Presione [0] para salir del programa\n");
    scanf("%d", &input);

    switch(input)
    {
        case 0:
            return; //Sale del programa
        case 1:
            printf("\n\n=====================================NUEVO ALUMNO=====================================\n\n");
            printf("Introduzca el nombre del alumno:");
            scanf("%c",&temp);
            scanf("%[^\n]", &nombre);
            printf("Introduzca la edad del alumno:");
            scanf("%d", &numero1);
            agregarNuevoAlumno(listadoAlumnos,nombre,numero1);
            printf("Se agrego el alumno %s exitosamente.\nPresione [ENTER] para continuar.\n", nombre);
            printf("\n=====================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 2:
            printf("\n\n=====================================NUEVA MATERIA=====================================\n\n");
            printf("Introduzca el nombre de la materia:");
            scanf("%c",&temp);
            scanf("%[^\n]", &nombre);
            agregarNuevaMateria(listadoMaterias,nombre);
            printf("Se agrego la materia %s exitosamente.\nPresione [ENTER] para continuar.\n", nombre);
            printf("\n========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 3:
            printf("\n\n=====================================CURSAR MATERIA====================================\n\n");
            printf("Introduzca el ID del alumno:");
            scanf("%d", &numero1);
            printf("Introduzca el ID de la materia a cursar:");
            scanf("%d", &numero2);
            cursarMateria(listadoMaterias, listadoAlumnos,numero1,numero2);
            printf("Se le agrego la materia exitosamente a la cursada del alumno.\nPresione [ENTER] para continuar.\n");
            printf("\n========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 4:
            printf("\n\n=====================================RENDIR MATERIA====================================\n\n");
            printf("Introduzca el ID del alumno:");
            scanf("%d", &numero1);
            printf("Introduzca el ID de la materia a rendir:");
            scanf("%d", &numero2);
            printf("Introduzca la calificacion:");
            scanf("%d", &numero3);
            rendir(listadoMaterias, listadoAlumnos, numero1, numero2, numero3);
            printf("Se le rindio la materia exitosamente.\nPresione [ENTER] para continuar.\n");
            printf("\n========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 5:
            printf("\n\n=====================================PROMEDIO=====================================\n\n");
            printf("Introduzca el nombre del alumno:");
            scanf("%c",&temp);
            scanf("%[^\n]", &nombre);
            printf("Promedio: %.2f\n", calcularPromedioDeAlumno(listadoAlumnos,nombre));
            printf("Presione [ENTER] para continuar.\n");
            printf("\n====================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 6:
            printf("\n\n===================================BUSCAR POR NOMBRE===================================\n\n");
            printf("Introduzca el nombre del alumno:");
            scanf("%c",&temp);
            scanf("%[^\n]", &nombre);
            buscarAlumnoPorNombre(listadoAlumnos,nombre);
            printf("Presione [ENTER] para continuar.\n");
            printf("\n=========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 7:
            printf("\n\n=====================================BUSCAR POR EDAD====================================\n\n");
            printf("Edad minima:");
            scanf("%d", &numero1);
            printf("Edad maxima:");
            scanf("%d", &numero2);
            buscarAlumnosPorRangoDeEdad(listadoAlumnos,numero1,numero2);
            printf("Presione [ENTER] para continuar.\n");
            printf("\n==========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 8:
            imprimirAlumnos(listadoAlumnos);
            printf("Presione [ENTER] para continuar.\n");
            printf("\n========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        case 9:
            imprimirMaterias(listadoMaterias);
            printf("Presione [ENTER] para continuar.\n");
            printf("\n========================================================================================\n");
            getch();
            menu(listadoAlumnos,listadoMaterias);
            break;
        default:
            printf("Introduzca un numero valido");
            break;
    }

}

int main() {

    ListadoMaterias * listadoMaterias = inicializarListadoMaterias();

    ListadoAlumnos * listadoAlumnos = inicializarListadoAlumnos();

    menu(listadoAlumnos,listadoMaterias);
}