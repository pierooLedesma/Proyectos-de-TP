

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa primero lee el archivo "Alumnos.txt" para almacenar los datos que se leen en
 *              arreglos (la del código y escala del alumno). Luego, se lee los el archivo "Cursos.txt" y se
 *              almacena los datos leídos en arreglos (código y número de créditos del curso). Posterior
 *              a lo anterior, se lee el archivo "Escalas.txt" y se guarda en arreglos los datos que se lee
 *              (año, ciclo, escala y valor de crédito). Seguidamente, se emite un reporte de prueba para
 *              verificar la correcta asignación de los datos almecenados en los arreglos de "escalas". Se
 *              lee el archivo "Matricula.txt" para actualizar los arreglos de la cantidad de alumnos, la
 *              cantidad de créditosy el total de ingresos por ciclo y escala. Después, se ordenan los
 *              arreglos de "escalas" por la cantidad de alumnos y ascendentemente por el total de
 *              ingresos. Finalmente, se emite el reporte solicitado mediante los arreglos de "escalas.txt".
 * Creado el 18 de mayo de 2025, 08:17 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arr_cod_alumno[MAX_CANT_ALUMNOS],cant_alumnos,
        arr_cod_cursos[MAX_CANT_CURSOS],cant_cursos,
        arr_anio_escala[MAX_CANT_ESCALAS],arr_ciclo_escala[MAX_CANT_ESCALAS],
        arr_cant_alumnos_escalas[MAX_CANT_ESCALAS]{},cant_escalas;
    char arr_escala_alumno[MAX_CANT_ALUMNOS],arr_escalas[MAX_CANT_ESCALAS];
    double arr_num_creditos_curso[MAX_CANT_CURSOS],arr_valor_credito_escala[MAX_CANT_ESCALAS],
           arr_cant_creditos_escala[MAX_CANT_ESCALAS]{},arr_total_ingresos_escala[MAX_CANT_ESCALAS]{};
    leer_alumnos("Alumnos.txt",arr_cod_alumno,arr_escala_alumno,cant_alumnos);
    leer_cursos("Cursos.txt",arr_cod_cursos,arr_num_creditos_curso,cant_cursos);
    leer_escalas("Escalas.txt",arr_anio_escala,arr_ciclo_escala,arr_escalas,
                 arr_valor_credito_escala,cant_escalas);
    emitir_reporte_prueba_escalas("ReportePruebaDeEscalas.txt",arr_anio_escala,arr_ciclo_escala,
                                  arr_escalas,arr_valor_credito_escala,cant_escalas);
    leer_matricula("Matricula.txt",arr_cod_alumno,arr_escala_alumno,cant_alumnos,
                   arr_cod_cursos,arr_num_creditos_curso,cant_cursos,arr_anio_escala,
                   arr_ciclo_escala,arr_escalas,arr_cant_alumnos_escalas,arr_valor_credito_escala,
                   arr_cant_creditos_escala,arr_total_ingresos_escala,cant_escalas);
    ordenar_arreglos(arr_anio_escala,arr_ciclo_escala,arr_escalas,arr_cant_alumnos_escalas,
                     arr_valor_credito_escala,arr_cant_creditos_escala,arr_total_ingresos_escala,cant_escalas);
    emitir_reporte("Reporte_Ingresos_Ciclos_Escalas.txt",arr_anio_escala,arr_ciclo_escala,arr_escalas,
                   arr_cant_alumnos_escalas,arr_valor_credito_escala,arr_cant_creditos_escala,
                   arr_total_ingresos_escala,cant_escalas);
    return 0;
}

