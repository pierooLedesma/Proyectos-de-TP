

/* 
 * Archivo:   Alumno.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 2 de julio del 2025, 10:45 AM
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

struct Alumno {
    int codAlumno;
    char *nombre;
    struct Escala escAlumno;
    struct Curso *cursos;
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};

#endif /* ALUMNO_HPP */

