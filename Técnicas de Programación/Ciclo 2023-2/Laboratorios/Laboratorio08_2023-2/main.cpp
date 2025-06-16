

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un reporte en la que se verifica los pagos realizados
 *              por cada curso en un determinado semestre que ingresa el usuario.
 * Creado el 16 de junio del 2025, 10:47 AM
 */


#include "Funciones.h"



int main(int argc, char** argv) {
    int semestre_ingresado = solicitar_semestre();
    
    struct Alumno arrAlumnos[MAX_CANT_ALUMNOS];
    int cant_alumnos;
    leer_alumnos("Alumnos.csv", arrAlumnos, cant_alumnos);
    
    struct Curso arrCursos[MAX_CANT_CURSOS];
    int cant_cursos;
    leer_cursos("Cursos.csv", arrCursos, cant_cursos);
    
    struct Escala arrEscalas[MAX_CANT_ESCALAS];
    int cant_escalas;
    leer_escalas("Escalas.csv", arrEscalas, cant_escalas);
    
    leer_matricula("Matricula.csv", arrCursos, cant_cursos, arrAlumnos,
                   cant_alumnos, arrEscalas, cant_escalas, semestre_ingresado);
    ordenar_arreglo_cursos(arrCursos, cant_cursos);
    emitir_reporte("ReporteDePagoPorCurso.txt", arrCursos, cant_cursos, semestre_ingresado);
    
    return 0;
}

