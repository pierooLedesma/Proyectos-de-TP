

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un reporte de lo que pagaría un alumno en un semestre
 *              determinado de acuerdo a la cantidad de créditos que lleva. Primero, se le
 *              solicita al usuario que ingrese un semestre (de esta forma: año-ciclo). Posterior
 *              a ello, se inicia la elaboración del reporte. Se leen los archivos "Alumnos.txt",
 *              "Cursos.txt" y "Escalas.txt" y se almacena en arreglos los datos que se leen
 *              excepto las cadenas de caracteres. Mediante el archivo "Matricula.txt", se actualiza 
 *              la cantidad de curso, la cantidad de créditos y el monto pagado en arreglos por
 *              cada alumno. Finalmente, se elabora el reporte solicitado en el archivo
 *              "ReporteDePagoPorAlumno.txt"y los nombres se imprimen mediante los archivos 
 *              "AlumnosNombres.txt" y "AlumnosApellidos.txt" en el cual el nombre de cada alumno
 *              es procesada mediante una concatenación y modificación de cadenas en la 
 *              función "modificaTexto".
 * Creado el 22 de mayo de 2025, 12:57 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int semestre_usuario, arr_cod_alumno[MAX_CANT_ALUMNOS],
        arr_cant_cursos_alumno[MAX_CANT_ALUMNOS]{}, cant_alumnos,
        arr_cod_curso[MAX_CANT_CURSOS], cant_cursos,
        arr_semestre[MAX_CANT_ESCALAS], cant_escalas;
    char arr_escala_alumno[MAX_CANT_ALUMNOS], arr_escalas[MAX_CANT_ESCALAS];
    double arr_num_creditos_curso[MAX_CANT_CURSOS],
           arr_costo_por_credito_escala[MAX_CANT_ESCALAS],
           arr_cant_creditos_alumno[MAX_CANT_ALUMNOS]{},
           arr_monto_pagado_alumno[MAX_CANT_ALUMNOS]{};
    semestre_usuario = solicitar_datos_al_usuario();
    leer_alumnos("Alumnos.txt", arr_cod_alumno,arr_escala_alumno,cant_alumnos);
    leer_cursos("Cursos.txt", arr_cod_curso,arr_num_creditos_curso,cant_cursos);
    leer_escalas("Escalas.txt", arr_semestre, arr_escalas,
                 arr_costo_por_credito_escala, cant_escalas);
    leer_matricula("Matricula.txt", semestre_usuario,arr_cod_alumno, arr_escala_alumno,
                   arr_cant_cursos_alumno,arr_cant_creditos_alumno, arr_monto_pagado_alumno,
                   cant_alumnos, arr_cod_curso, arr_num_creditos_curso, cant_cursos, arr_semestre,
                   arr_escalas, arr_costo_por_credito_escala, cant_escalas);
    emitir_reporte("ReporteDePagoPorAlumno.txt", semestre_usuario, arr_cod_alumno, arr_escala_alumno,
                   arr_cant_cursos_alumno, arr_cant_creditos_alumno, arr_monto_pagado_alumno,
                   cant_alumnos, "AlumnosNombres.txt", "AlumnosApellidos.txt");
    return 0;
}

