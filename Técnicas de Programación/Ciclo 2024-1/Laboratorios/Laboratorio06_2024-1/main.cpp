

/*
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa solicita al usuario ingresar un código de facultad. Luego, procesa el archivo
 *              "Calificaciones.txt" para registrar en arreglos la información de los alumnos: código, número
 *              de cursos llevados, suma ponderada y total de créditos cursados. Estos datos se almacenan
 *              de forma ordenada ascendentemente según el código del alumno, utilizando búsqueda binaria
 *              para optimizar las inserciones y consultas.
 *              Para generar el reporte, se utiliza el archivo "Facultades.txt" con el fin de imprimir el nombre de
 *              la facultad correspondiente al código ingresado por el usuario, y el archivo "Alumnos.txt" para
 *              mostrar los datos de cada alumno perteneciente a dicha facultad. Además, los nombres leídos
 *              del archivo "Alumnos.txt" son modificados para cumplir con un formato de presentación
 *              adecuado: se reorganiza el orden de nombre y apellidos, y se ajusta la capitalización de manera
 *              que la primera letra de cada palabra esté en mayúscula y el resto en minúscula.
 * Creado el 29 de mayo de 2025, 01:17 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int cod_facultad_usuario, arrCodigoAlumnos[MAX_CANTIDAD_ALUMNOS],
        arrNumCursos[MAX_CANTIDAD_ALUMNOS], cant_alumnos;
    double arrSumaPonderada[MAX_CANTIDAD_ALUMNOS], arrNumCreditos[MAX_CANTIDAD_ALUMNOS];
    cod_facultad_usuario = solicitar_codigo_de_una_facultad_al_usuario();
    leer_calificaciones("Calificaciones.txt", arrCodigoAlumnos, arrNumCursos,
                        arrSumaPonderada, arrNumCreditos, cant_alumnos);
    procesar_la_elaboracion_del_reporte("Facultades.txt", "Alumnos.txt",
                "ReporteDeAlumnosDeUnaFacultadSolicitada.txt", arrCodigoAlumnos, arrNumCursos,
                arrSumaPonderada, arrNumCreditos, cant_alumnos, cod_facultad_usuario);
    return 0;
}

