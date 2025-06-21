

/* 
 * Archivo:   Curso.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de junio del 2025, 01:42 PM
 */

#ifndef CURSO_H
#define CURSO_H

struct Curso {
    int codigo;
    char *nombre;
    double numeroDeCreditos;
    struct Alumno *listaDeAlumnosMatriculados;
    int cantAlumnosMatriculados;
    double totalDeIngresos;
};

#endif /* CURSO_H */


