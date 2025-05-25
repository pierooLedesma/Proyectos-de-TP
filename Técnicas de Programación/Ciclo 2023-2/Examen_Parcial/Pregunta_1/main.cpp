

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un reporte de los detalles realizados por ciclo.
 *              El usuario ingresa un semestre (año y ciclo) para elaborar el reporte.
 *              Se empieza con el procesamiento del archivo "Alumnos.txt" en el que se
 *              realiza una lectura e impresión de los datos de cada alumno.
 *              Por cada alumno, se busca el valor de crédito de la escala que está
 *              el alumno en dicho semestre en el archivo "Escalas.txt". Luego, se 
 *              busca en "Matricula.txt" la lista de cursos que el alumno cursó en dicho
 *              semestre. Finalmente, por cada curso, se busca y se imprime la
 *              información de cada curso.
 * Creado el 18 de mayo de 2025, 08:16 PM
 */

#include "Funciones.h"


int main(int argc, char** argv) {
    int anio_usuario,ciclo_usuario;
    solicitar_semestre_al_usuario(ciclo_usuario,anio_usuario);
    elaborar_reporte("Alumnos.txt","Matricula.txt",
                     "Escalas.txt","Cursos.txt",
                     "ReportePorCiclo.txt",
                     ciclo_usuario,anio_usuario);
    return 0;
}

