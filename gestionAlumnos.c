#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionAlumnos.h"

// - - - Listado de materias- - -
/***
 * Crea un nuevo listado de materias inicializado y lo retorna
 */
ListadoMaterias *inicializarListadoMaterias() {

    ListadoMaterias *listado = (ListadoMaterias *) malloc(sizeof(ListadoMaterias) * 1);
    if (listado == NULL) {
        printf("no se pudo reservar el espacio en la memoria");
    } else {
        listado->cantidadElementos = 0;
        Materia *materias = (Materia *) malloc(sizeof(Materia) * 1);
        if (materias == NULL) {
            printf("no se pudo reservar el espacio en la memoria");
        } else {
            listado->materias = materias;
        }
    }

    return listado;

}
/***
 * Imprime todas las materias
 * @param listado - Listado de materias
 */
void imprimirMaterias(ListadoMaterias *listado) {

    int i;
    for (i = 0; i < listado->cantidadElementos; i++) {

        printf("ID %d @ %s  \n",listado->materias[i].id, listado->materias[i].nombre);
    }

}
/***
 * Agrega una materia ya existente a otra lista de materias. Pasa el puntero en vez de crear otra materia.
 * @param listado - Listado de materias
 * @param materia - Materia que se va a insertar
 */
void agregarMateria(ListadoMaterias *listado, Materia *materia) {

    listado->materias[listado->cantidadElementos] = *materia;
    listado->cantidadElementos++;
    Materia *materiaAux = (Materia *) realloc(listado->materias, sizeof(Materia) * (listado->cantidadElementos + 1));
    if (!materiaAux) {
        printf("No se redimensiono el espacio");
    } else {
        listado->materias = materiaAux;
    }
}
/***
 * Recibe un listado y le agrega una nueva materia.
 * @param listado - Lista de materias
 * @param nombre - Nombre de la materia
 */
void agregarNuevaMateria(ListadoMaterias *listado, char *nombre) {

    listado->materias[listado->cantidadElementos].nombre = nombre;
    listado->materias[listado->cantidadElementos].id = listado->cantidadElementos;

    listado->cantidadElementos++;

    Materia *materiasAux = realloc(listado->materias, sizeof(Materia) * ((listado->cantidadElementos) + 1));
    if (materiasAux == NULL) {
        printf("No se pudo redimensionar lista de materias");
    } else {
        listado->materias = materiasAux;
    }


}

// - - Listado de alumnos -

/***
 * Crea un listado de alumnos inicializado y lo retorna.
 */
ListadoAlumnos *inicializarListadoAlumnos() {

    ListadoAlumnos *listado = (ListadoAlumnos *) malloc(sizeof(ListadoAlumnos) * 1);
    if (listado == NULL) {
        printf("no se pudo reservar espacio en la memoria");
    }
    listado->cantidadElementos = 0;
    Alumno *alumnos = (Alumno *) malloc(sizeof(Alumno) * 1);
    if (alumnos == NULL) {
        printf("no se pudo reservar espacio en la memoria");
    } else {
        listado->alumnos = alumnos;
    }

    return listado;

}
/***
 * Agrega un nuevo alumno a la lista de alumnos pasada como parametros
 * @param listado - Listado de los alumnos
 * @param nombre - Nombre del alumno
 * @param edad - Edad del alumno
 */
void agregarNuevoAlumno(ListadoAlumnos *listado, char *nombre, int edad) {

    //Guarda  EL ALUMNO

    listado->alumnos[listado->cantidadElementos].id = listado->cantidadElementos;
    listado->alumnos[listado->cantidadElementos].nombre = nombre;
    listado->alumnos[listado->cantidadElementos].edad = edad;
    listado->alumnos[listado->cantidadElementos].materiasEnCurso = inicializarListadoMaterias();
    listado->alumnos[listado->cantidadElementos].materiasAprobadas = inicializarListadoMaterias();

    listado->cantidadElementos++;

    //Se hace un realloc para reservar mas espacio que el que se le dio inicialmente con malloc

    Alumno *alumnosAux = realloc(listado->alumnos, sizeof(Alumno) * ((listado->cantidadElementos) + 1));
    if (!alumnosAux) {
        printf("No se redimensiono el espacio");
    } else {
        listado->alumnos = alumnosAux;
    }
}
/***
 * Imprime el alumno que se le pasa como parametro.
 * @param alumno - Alumno que va a imprimirse
 */
void imprimirAlumno(Alumno alumno) {
    printf("ID: %d\n", alumno.id);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Edad: %d\n", alumno.edad);
    printf("- - Materias en curso - -\n");
    imprimirMaterias(alumno.materiasEnCurso);
    printf("- - Materias aprobadas - -\n");
    for (int j = 0; j < alumno.materiasAprobadas->cantidadElementos; j++) {
        printf("ID %d @ %s | calificacion : %d \n",alumno.materiasAprobadas->materias[j].id, alumno.materiasAprobadas->materias[j].nombre,
               alumno.materiasAprobadas->materias[j].calificacion);
    }
    printf("\n");

}
/***
 * Imprime todos los alumnos con sus respectivas materias.
 * @param listado - Listado de los alumnos
 */
void imprimirAlumnos(ListadoAlumnos *listado) {
    printf("----LISTA DE ALUMNOS COMPLETA----\n");
    int i;
    for (i = 0; i < listado->cantidadElementos; i++) {
        imprimirAlumno(listado->alumnos[i]);

    }

}
/***
 * Imprime el alumno que busca por nombre
 * @param listado - Listado de los alumnos
 * @param nombre - Nombre del alumno que va a buscar
 */
void buscarAlumnoPorNombre(ListadoAlumnos *listado, char *nombre) {
    for (int i = 0; i < listado->cantidadElementos; i++) {
        if (strcmp(listado->alumnos[i].nombre, nombre) == 0) {
            printf("Datos del alumno buscado: %s \n", nombre);
            imprimirAlumno(listado->alumnos[i]);
            printf("    -------------- \n");
            return;
        }
    }
}
/***
 * Imprime todos los alumnos que se encuentran en el rango etario indicado por parametros
 * @param listado - Listado de los alumnos
 * @param edadMin - Edad minima
 * @param edadMax - Edad maxima
 */
void buscarAlumnosPorRangoDeEdad(ListadoAlumnos *listado, int edadMin, int edadMax) {
    printf("Datos de los alumnos con edad entre los %d y %d de edad :  \n", edadMin, edadMax);
    for (int i = 0; i < listado->cantidadElementos; i++) {
        if (listado->alumnos[i].edad >= edadMin && listado->alumnos[i].edad <= edadMax) {
            imprimirAlumno(listado->alumnos[i]);
        }
    }
    printf("    -------------- \n");
}

// - - FUNCIONES PARA CURSAR Y APROBAR MATERIAS - -

/***
 * Hace el proceso para cursar una materia. La agrega a la lista de materias en curso del alumno.
 * @param listadoMaterias - Listado de las materias
 * @param listadoAlumnos - Listado de los alumnos
 * @param idAlumno - ID del alumno que va a cursar la materia
 * @param idMateria - ID de la materia que va a cursar el alumno
 */
void cursarMateria(ListadoMaterias *listadoMaterias, ListadoAlumnos *listadoAlumnos, int idAlumno, int idMateria) {

    if (idAlumno >= listadoAlumnos->cantidadElementos || idMateria >= listadoMaterias->cantidadElementos) {
        printf("No se pudo cursar materia, el id del alumno o de la materia es incorrecto \n");
        return;
    }
    Materia * materia = NULL;
    for(int i = 0; i < listadoMaterias->cantidadElementos;i++){
        if(listadoMaterias->materias[i].id == idMateria){
            materia = &listadoMaterias->materias[i];
        }
    }
    Alumno * alumno = &listadoAlumnos->alumnos[idAlumno];

    ListadoMaterias *enCurso = alumno->materiasEnCurso;
    agregarMateria(enCurso, materia);

}

/***
 * Hace el proceso para rendir una materia. Si la calificacion es mayor a 4, quita la materia de la cursada y lo pone en materias aprobadas
 * @param listadoMaterias - Listado con las materias
 * @param listadoAlumnos - Listado con los alumnos
 * @param idAlumno - ID del alumno que va a rendir
 * @param idMateria - ID de la materia que el alumno va a rendir
 * @param calificacion - Calificacion con la que rinde la materia el alumno
 */
void rendir(ListadoMaterias *listadoMaterias, ListadoAlumnos *listadoAlumnos, int idAlumno, int idMateria, int calificacion) {
    if (idAlumno >= listadoAlumnos->cantidadElementos || idMateria >= listadoMaterias->cantidadElementos) {
        printf("No se pudo cursar materia, el id del alumno o de la materia es incorrecto \n");
        return;
    }

    if (calificacion >= 4) {
        Materia * materiaRendida = NULL;
        for(int i = 0; i < listadoMaterias->cantidadElementos;i++){
            if(listadoMaterias->materias[i].id == idMateria){
                materiaRendida = &listadoMaterias->materias[i];
            }
        }
        materiaRendida->calificacion = calificacion;

        //guarda la materia en materias aprobadas
        agregarMateria(listadoAlumnos->alumnos[idAlumno].materiasAprobadas, materiaRendida);
        //agrega la materia aprobada al final del arreglo de materias en curso
        listadoAlumnos->alumnos[idAlumno].materiasEnCurso->materias[idMateria] = listadoAlumnos->alumnos[idAlumno].materiasEnCurso->materias[
                (listadoAlumnos->alumnos[idAlumno].materiasEnCurso->cantidadElementos) - 1];

        //Se hace un realloc para hacer mas chico el arreglo de materias en curso, le resto las materias aprobadas
        ListadoMaterias *materiasAux = realloc(listadoAlumnos->alumnos[idAlumno].materiasEnCurso, sizeof(ListadoMaterias) *
                                                                                           ((listadoAlumnos->alumnos[idAlumno].materiasEnCurso->cantidadElementos)));
        if (materiasAux == NULL) {
            printf("No se pudo redimensionar lista de materias");
        } else {
            listadoAlumnos->alumnos[idAlumno].materiasEnCurso = materiasAux;
            listadoAlumnos->alumnos[idAlumno].materiasEnCurso->cantidadElementos--;

        }
    }
}
/***
 * Calcula el promedio de las notas de las materias aprobadas del alumno pasado como parametro
 * @param listado - Listado de alumnos
 * @param nombre - Nombre del alumno
 * @return Retorna el promedio de las notas de las materias aprobadas
 */
double calcularPromedioDeAlumno(ListadoAlumnos * listado, char * nombre){
    int sumaNotas = 0;
    for (int i = 0; i < listado->cantidadElementos; i++) {
        if (strcmp(listado->alumnos[i].nombre, nombre) == 0) {
            Alumno * alumno = &listado->alumnos[i];

            for(int k = 0; k < alumno->materiasAprobadas->cantidadElementos; k++){
                sumaNotas = sumaNotas + alumno->materiasAprobadas->materias[k].calificacion;
            }
            return ((double) sumaNotas) / ((double) alumno->materiasAprobadas->cantidadElementos);
        }
    }
}




