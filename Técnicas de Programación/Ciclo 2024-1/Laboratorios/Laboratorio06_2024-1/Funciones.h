

/*
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de mayo de 2025, 01:24 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"
#include "FuncionesCadenas.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
bool busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos, int &indice);
bool buscar_nombre_facultad(ifstream &input_facultades, char *nombre_facultad, int cod_facultad);
void imprimir_titulo(char *nombre_facultad, ofstream &output);
void imprimir_encabezado(ofstream &output);
int buscar_caracter(const char *cadena, char caracter);
void camelizar(char *cadena);
void modificar_nombre_completo(char *cadena_original);
void imprimir_juego_de_datos_de_un_alumno(int codigoAlumno, char *nombre_completo_alumno,
                                          int numCursos,double sumaPonderada, double numCreditos,
                                          double promedioPonderado, ofstream &output);
void imprimir_alumnos(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                      double *arrNumCreditos, int cant_alumnos, int cod_facultad_usuario,
                      ifstream &input_alumnos, ofstream &output);
void emitir_reporte_solicitado(const char *nombre_archivo_alumnos,
                const char *nombre_archivo_reporte, int *arrCodigoAlumnos,
                int *arrNumCursos, double *arrSumaPonderada, double *arrNumCreditos,
                int cant_alumnos,int cod_facultad_usuario, char *nombre_facultad);
void procesar_la_elaboracion_del_reporte(const char *nombre_archivo_facultades,
                const char *nombre_archivo_alumnos, const char *nombre_archivo_reporte,
                int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                double *arrNumCreditos, int cant_alumnos, int cod_facultad_usuario);
void insertar_o_acumular(int cod_alumno, int nota_alumno, int *arrCodigoAlumnos, int *arrNumCursos,
                         double *arrSumaPonderada, double *arrNumCreditos, int &cant_alumnos,
                         double creditos_curso);
void procesar_lista_de_notas(double creditos_curso, int *arrCodigoAlumnos,
                 int *arrNumCursos, double *arrSumaPonderada,
                 double *arrNumCreditos, int &cant_alumnos, ifstream &input);
void leer_calificaciones(const char *nombre_archivo, int *arrCodigoAlumnos,
                         int *arrNumCursos,double *arrSumaPonderada,
                         double *arrNumCreditos, int &cant_alumnos);
int solicitar_codigo_de_una_facultad_al_usuario();

#endif /* FUNCIONES_H */
