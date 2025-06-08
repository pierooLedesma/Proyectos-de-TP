

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: Este programa genera un reporte de alumnos matriculados que pertenecen a dos
 *              facultades específicas, cuyos códigos son ingresados por el usuario.
 *                      
 *              El usuario ingresa dos códigos de facultades. Se asume que ambos 
 *              códigos son válidos y existen en el archivo "Facultades.txt".
 *                      
 *              Luego, se procesa el archivo "Calificaciones.txt", del cual se extraen y almacenan los datos
 *              en los siguientes arreglos: "arrCodigoAlumnos", "arrNumCursos", "arrSumaPonderada" y
 *              "arrNumCreditos". Si un alumno ya está registrado, sus datos se acumulan. Si no, se
 *              añade como un nuevo alumno en los arreglos.
 *                      
 *              A continuación, se lee el archivo "Alumnos.csv", donde se obtiene:
 *              - El nombre del alumno -> almacenado en "arrAlumno"
 *              - Su código de facultad -> almacenado en "arrFacultad"
 *                      
 *              Finalmente, se genera el archivo de salida "ReporteDeAlumnosMatriculados.txt". 
 *              Antes de imprimir, se ordenan los alumnos: Primero, por código de facultad en orden
 *              ascendente; luego, por promedio ponderado en orden descendente. Para mostrar el
 *              nombre de la facultad, se recurre al archivo "Facultades.txt". Solo se imprimen en el
 *              reporte aquellos alumnos que pertenecen a una de las dos facultades seleccionadas
 *              por el usuario.
 * Creado el 5 de junio del 2025, 10:39 AM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arrCodigoAlumnos[MAX_CANT_ALUMNOS], arrNumCursos[MAX_CANT_ALUMNOS]{}, cant_alumnos;
    double arrSumaPonderada[MAX_CANT_ALUMNOS]{}, arrNumCreditos[MAX_CANT_ALUMNOS]{};
    char *cod_facu_usuario_1, *cod_facu_usuario_2, *arrAlumno[MAX_CANT_ALUMNOS],
         *arrFacultad[MAX_CANT_ALUMNOS];
    solicitar_dos_codigos_de_facultad_al_usuario(cod_facu_usuario_1, cod_facu_usuario_2);
    leer_calificaciones("Calificaciones.txt", arrCodigoAlumnos, arrNumCursos,
                        arrSumaPonderada, arrNumCreditos, cant_alumnos);
    leer_alumnos_y_facultad("Alumnos.csv", arrCodigoAlumnos, arrAlumno, arrFacultad, cant_alumnos);
    emitir_reporte("Facultades.txt", "ReporteDeAlumnosMatriculados.txt", cod_facu_usuario_1,
                   cod_facu_usuario_2, arrCodigoAlumnos, arrAlumno, arrNumCursos,
                   arrSumaPonderada, arrNumCreditos, arrFacultad, cant_alumnos);
    return 0;
}

