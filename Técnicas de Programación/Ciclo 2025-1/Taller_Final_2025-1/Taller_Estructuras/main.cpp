

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un listado de alumnos matriculados de un
 *              determinado ciclo que es ingresado por el usuario.
 * Creado el 2 de julio del 2025, 10:24 AM
 */


#include "Funciones.hpp"


int main(int argc, char** argv) {
    struct Curso *arrCursos;
    struct Escala *arrEscalas;
    struct Alumno *arrAlumnos;
    int cantCursos, cantEscalas, cantAlumnos, anho_usuario, ciclo_usuario;
    
    arrCursos = new struct Curso[MAX_CANT_CURSOS];
    arrEscalas = new struct Escala[MAX_CANT_ESCALAS];
    arrAlumnos = new struct Alumno[MAX_CANT_ALUMNOS]{}; // Inicializar los campos con valores por defecto.
    
    procesarCursos("Cursos.csv", arrCursos, cantCursos);
    verificar_asignacion_de_cursos("ReportePruebaCursos.txt", arrCursos, cantCursos);
    procesarEscalas("Escalas.csv", arrEscalas, cantEscalas);
    verificar_asignacion_de_escalas("ReportePruebaEscalas.txt", arrEscalas, cantEscalas);
    procesar_alumnos("Alumnos.csv", arrAlumnos, cantAlumnos);
    emitir_reporte(anho_usuario, ciclo_usuario, arrAlumnos, cantAlumnos, false);
    procesar_matricula("Matricula.txt", anho_usuario, ciclo_usuario, arrCursos, cantCursos,
                       arrEscalas, cantEscalas, arrAlumnos, cantAlumnos);
    ordenar_arreglo_alumnos(arrAlumnos, cantAlumnos);
    emitir_reporte(anho_usuario, ciclo_usuario, arrAlumnos, cantAlumnos, true);
    
    return 0;
}



