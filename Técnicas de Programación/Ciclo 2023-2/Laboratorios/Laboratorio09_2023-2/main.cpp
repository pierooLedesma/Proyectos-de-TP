

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza un reporte realizado por un ciclo que ingresa el usuario en el que
 *              se verifica por cada curso los alumnos que se han matriculado en ese ciclo ingresado
 *              y los totales pagados en ese curso de cada alumno como el monto total del curso.
 * Creado el 17 de junio del 2025, 01:26 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int semestre_ingresado = solicitar_semestre();
    
    struct Escala arrEscalas[MAX_CANT_ESCALAS];
    int cantEscalas;
    leer_escalas("Escalas.csv", arrEscalas, cantEscalas);
    
    struct Curso *arrCursos;
    int cantCursos;
    arrCursos = new struct Curso[MAX_CANT_CURSOS];
    leer_cursos("Cursos.csv", arrCursos, cantCursos);

    leer_matricula("Matricula.csv", arrCursos, cantCursos, semestre_ingresado);
    completar_el_pago_por_credito_de_cada_alumno("Alumnos.csv", arrCursos, cantCursos, arrEscalas,
                                                 cantEscalas, semestre_ingresado);
    completar_el_ingreso_total_por_curso(arrCursos, cantCursos);
    ordenar_arreglo_de_cursos_y_listas_de_alumnos(arrCursos, cantCursos);
    emitir_reporte("ReporteDePagoPorCurso.txt", arrCursos, cantCursos, semestre_ingresado);
    
    return 0;
}



