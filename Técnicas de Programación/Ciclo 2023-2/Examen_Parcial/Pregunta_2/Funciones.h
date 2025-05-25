

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de mayo de 2025, 08:18 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void leer_alumnos(const char *nombre_archivo,int *arr_cod_alumno,
                  char *arr_escala_alumno,int &cant_alumnos);
void leer_cursos(const char *nombre_archivo,int *arr_cod_cursos,
                 double *arr_num_creditos_curso,int &cant_cursos);
void leer_escalas(const char *nombre_archivo,int *arr_anio_escala,int *arr_ciclo_escala,
                  char *arr_escalas,double *arr_valor_credito_escala,int &cant_escalas);
void emitir_reporte_prueba_escalas(const char *nombre_archivo,int *arr_anio_escala,
                    int *arr_ciclo_escala,char *arr_escalas,double *arr_valor_credito_escala,
                    int cant_escalas);
void leer_matricula(const char *nombre_archivo,int *arr_cod_alumno,char *arr_escala_alumno,
                int cant_alumnos,int *arr_cod_cursos,double *arr_num_creditos_curso,int cant_cursos,
                int *arr_anio_escala,int *arr_ciclo_escala,char *arr_escalas,int *arr_cant_alumnos_escalas,
                double *arr_valor_credito_escala,double *arr_cant_creditos_escala,
                double *arr_total_ingresos_escala,int cant_escalas);
int buscar_escala(int anio_leido,int ciclo_leido,int cod_alumno_leido,int *arr_cod_alumno,
                  char *arr_escala_alumno,int cant_alumnos,int *arr_anio_escala,
                  int *arr_ciclo_escala,char *arr_escalas,int cant_escalas);
void procesar_cursos(int *arr_cod_cursos,double *arr_num_creditos_curso,int cant_cursos,
                     int &cant_alumnos_escalas,double valor_credito_escala,
                     double &cant_creditos_escala,double &arr_total_ingresos_escala,ifstream &input);
int buscar_curso(int cod_curso_leido,int *arr_cod_cursos,int cant_cursos);
void ordenar_arreglos(int *arr_anio_escala,int *arr_ciclo_escala,char *arr_escalas,
                    int *arr_cant_alumnos_escalas,double *arr_valor_credito_escala,
                    double *arr_cant_creditos_escala,double *arr_total_ingresos_escala,int cant_escalas);
void emitir_reporte(const char *nombre_archivo,int *arr_anio_escala,int *arr_ciclo_escala,
                    char *arr_escalas,int *arr_cant_alumnos_escalas,double *arr_valor_credito_escala,
                    double *arr_cant_creditos_escala,double *arr_total_ingresos_escala,int cant_escalas);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulos(bool es_de_prueba,ofstream &output);
void imprimir_encabezados(bool es_de_prueba,ofstream &output);
void imprimir_un_juego_de_datos_de_escalas(int n_ciclo,int anio_escala,int ciclo_escala,
                    char escala,int cant_alumnos_escalas,double valor_credito_escala,
                    double cant_creditos_escala,double total_ingresos_escala,ofstream &output);
int leer_tipo_dato_int(ifstream &input);
double leer_tipo_dato_double(ifstream &input);
char leer_tipo_dato_char(ifstream &input);
void ignorar_hasta_delimitador(char delimitador,ifstream &input);
void leer_anio_y_ciclo(int &anio,int &ciclo,ifstream &input);
void imprimir_anio_y_ciclo(int anio,int ciclo,ofstream &output);
int intercambiar_int(int &dato_1,int &dato_2);
double intercambiar_double(double &dato_1,double &dato_2);
char intercambiar_char(char &dato_1,char &dato_2);
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &intput);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);

#endif /* FUNCIONES_H */
