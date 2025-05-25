

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de mayo de 2025, 08:21 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &intput);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
int leer_tipo_dato_int(ifstream &input);
double leer_tipo_dato_double(ifstream &input);
char leer_tipo_dato_char(ifstream &input);
void ignorar_hasta_delimitador(char delimitador,ifstream &input);
void leer_anio_y_ciclo(int &anio,int &ciclo,ifstream &input);
void imprimir_anio_y_ciclo(int anio,int ciclo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void leer_e_imprimir_cadena_caracteres(bool todo_a_mayusculas,int tamano_total_cadena,
                                       ifstream &input,ofstream &output);
void solicitar_semestre_al_usuario(int &ciclo,int &anio);
void elaborar_reporte(const char *nombre_archivo_alumnos,const char *nombre_archivo_matricula,
                      const char *nombre_archivo_escalas,const char *nombre_archivo_cursos,
                      const char *nombre_archivo_reporte,int ciclo_usuario,int anio_usuario);
void imprimir_titulo(int anio_usuario,int ciclo_usuario,ofstream &output);
void procesar_alumnos(ifstream &input_alumnos,ifstream&input_matricula,ifstream &input_escalas,
                      ifstream &input_cursos,int &cant_alumnos,double &monto_total_pagado,
                      ofstream &output,int ciclo_usuario,int anio_usuario);
void continuar_lectura_de_un_alumno_e_imprimir_sus_datos(int codigo_alumno,
                        char &escala_alumno,ifstream &input_alumnos,ofstream &output);
double buscar_valor_credito_escala(int anio_usuario,int ciclo_usuario,
                                   char escala_alumno,ifstream &input_escalas);
void procesar_matricula(ifstream &input_matricula,ifstream &input_cursos,
                        int &cant_cursos,double &total_creditos,double &total_monto_pagado,
                        ofstream &output,int ciclo_usuario,int anio_usuario,
                        int codigo_alumno,double valor_credito_escala);
void elaborar_encabezado_cursos(ofstream &output);
void leer_lista_de_cursos(int &cant_cursos,double &total_creditos,double &total_monto_pagado,
                          double valor_credito_escala,ifstream &input_matricula,
                          ifstream &input_cursos,ofstream &output);
void buscar_and_imprimir_curso(int &n_cursos,int cod_curso,double &numero_creditos_curso,
                               double &monto_pagado,double valor_credito_escala,
                               int &cant_cursos,ifstream &input_cursos,ofstream &output);
void imprimir_curso(int n_cursos,int cod_curso,double &numero_creditos_curso,
                    double &monto_pagado,double valor_credito_escala,
                    ifstream &input_cursos,ofstream &output);
void imprimir_resumen_de_un_alumno(double total_creditos,double total_monto_pagado,
                                   ofstream &output);
void imprimir_resumen(int cant_alumnos,double monto_total_pagado,ofstream &output);

#endif /* FUNCIONES_H */
