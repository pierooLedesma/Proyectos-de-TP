

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 22 de mayo de 2025, 12:59 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"
#include "FuncionesCadenas.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_tipo_int(ifstream &input);
double leer_dato_tipo_double(ifstream &input);
char leer_dato_tipo_char(ifstream &input);
void ignorar_hasta_delimitador(char delimitador, ifstream &input);
int convertir_anio_y_ciclo(int anio_usuario, int ciclo_usuario);
int leer_semestre(ifstream &input);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
void imprimir_titulo(int semestre, ofstream &output);
void imprimir_encabezado(ofstream &output);
int busquedad_binaria(int dato_buscado, int *arreglo, int cant_datos);
int buscar_escala(int semestre_leido, char escala_alumno, int *arr_semestre,
                  char *arr_escalas, int cant_escalas);
int encontrar_caracter(char caracter, char *cadena);
void extraer_apellido_y_nombres(const char *apellidoPaterno_y_nombres,
                                char *apellidoPaterno, char *nombres);
void reemplazar_guiones_por_espacios(char *cadena);
void construir_nombre_completo(char *destino, const char *nombres,
                               const char *apellidoPaterno, const char *apellidoMaterno);
void pasar_a_mayusculas(char *cadena);
void modificaTexto(char *apellidoPaterno_nombres, const char *apellido_materno);
void imprimir_un_juego_de_datos_de_un_alumno(int cod_alumno, int cant_cursos_alumno,
                    double cant_creditos_alumno, char escala_alumno, double monto_pagado_alumno,
                    ifstream &input_nombre, ifstream &input_apellido_materno, ofstream &output,
                    double &monto_total_pagado);
void imprimir_alumnos(int *arr_cod_alumno, int *arr_cant_cursos_alumno,
                      double *arr_cant_creditos_alumno, char *arr_escala_alumno,
                      double *arr_monto_pagado_alumno, int cant_alumnos,
                      double &monto_total_pagado, ifstream &input_nombre,
                      ifstream &input_apellido_materno,ofstream &output);
void imprimir_monto_total_pagado(double monto_total_pagado, ofstream &output);
void emitir_reporte(const char *nombre_archivo_reporte,int semestre_usuario,
                    int *arr_cod_alumno,char *arr_escala_alumno,int *arr_cant_cursos_alumno,
                    double *arr_cant_creditos_alumno,double *arr_monto_pagado_alumno,
                    int cant_alumnos,const char *nombre_archivo_nombre,
                    const char *nombre_archivo_apellido_materno);
void procesar_lista_de_cursos(int &cant_cursos_alumno,
                double &cant_creditos_alumno, double &monto_pagado_alumno,
                double costo_por_credito_escala, int *arr_cod_curso,
                double *arr_num_creditos_curso, int cant_cursos,ifstream &input);
void leer_matricula(const char *nombre_archivo, int semestre_usuario,
                    int *arr_cod_alumno, char *arr_escala_alumno, int *arr_cant_cursos_alumno,
                    double *arr_cant_creditos_alumno, double *arr_monto_pagado_alumno,
                    int cant_alumnos,int *arr_cod_curso, double *arr_num_creditos_curso,
                    int cant_cursos, int *arr_semestre, char *arr_escalas,
                    double *arr_costo_por_credito_escala, int cant_escalas);
void leer_escalas(const char *nombre_archivo, int *arr_semestre,
                  char *arr_escalas, double *arr_costo_por_credito_escala,
                  int &cant_escalas);
void insertar_ordenado_cursos(int cod_curso, double num_creditos,
                    int *arr_cod_curso, double *arr_num_creditos_curso, int &cant_cursos);
void leer_cursos(const char *nombre_archivo, int *arr_cod_curso,
                 double *arr_num_creditos_curso, int &cant_cursos);
void insertar_ordenado_alumnos(int cod_alumno, char escala_alumno,
                   int *arr_cod_alumno, char *arr_escala_alumno, int &cant_alumnos);
void leer_alumnos(const char *nombre_archivo, int *arr_cod_alumno,
                  char *arr_escala_alumno, int &cant_alumnos);
int solicitar_datos_al_usuario();

#endif /* FUNCIONES_H */

