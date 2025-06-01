

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa genera un reporte con el monto que debe pagar cada alumno en un semestre
 *              determinado, en función de la cantidad de créditos matriculados. Para ello, primero solicita
 *              al usuario que ingrese el semestre en formato año-ciclo (por ejemplo, 2024-1). A continuación,
 *              el programa inicia la elaboración del reporte. Lee y almacena en arreglos los datos de los
 *              archivos "Alumnos.txt", "Cursos.txt" y "Escalas.txt", exceptuando los datos de tipo cadena de
 *              caracteres. Posteriormente, procesa el archivo "Matricula.txt", a partir del cual se actualiza para
 *              cada alumno la cantidad de cursos matriculados, el total de créditos y el monto a pagar.
 *              Finalmente, se genera el archivo "ReporteDePagoPorAlumno.txt", que contiene la información
 *              consolidada por estudiante. Para mostrar los nombres completos, se utilizan los archivos
 *              "AlumnosNombres.txt" y "AlumnosApellidos.txt", cuyos contenidos son procesados y formateados
 *              adecuadamente mediante la función "modificaTexto", que se encarga de concatenar y ajustar las
 *              cadenas para su presentación final.
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

