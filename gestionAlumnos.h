#ifndef TPLISTA_GESTIONALUMNOS_H
#define TPLISTA_GESTIONALUMNOS_H

typedef struct{
    int id;
    char * nombre;
    int calificacion;
}Materia;

typedef struct{
    int id;
    char * nombre;
    int edad;
    struct ListadoMaterias * materiasEnCurso;
    struct ListadoMaterias * materiasAprobadas;
}Alumno;

typedef struct ListadoMaterias {
    int cantidadElementos;
    Materia * materias;
}ListadoMaterias;

typedef struct ListadoAlumnos {
    int cantidadElementos;
    Alumno * alumnos;
}ListadoAlumnos;

#endif //TPLISTA_GESTIONALUMNOS_H
