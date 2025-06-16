

/* 
 * Archivo:   Curso.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 16 de junio del 2025, 11:10 AM
 */

#ifndef CURSO_H
#define CURSO_H

struct Curso {
    int codigo;
    char nombre[MAX_CARACTERES_NOMBRE_CURSO];
    double numeroDeCreditos;
    int cantidadDeAlumnosMatriculados;
    double montoPagadoDeAlumnosMatriculados;
};

#endif /* CURSO_H */

