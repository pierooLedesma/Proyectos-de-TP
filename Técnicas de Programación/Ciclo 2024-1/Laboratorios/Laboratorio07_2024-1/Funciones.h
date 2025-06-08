

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340 
 * Creado el 5 de junio del 2025, 10:41 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
void asignar_memoria_y_copiar_en_cadena_exacta(char *&cadena_exacta, const char *buffer_temporal);
char *leer_cadena_exacta(ifstream &input, char delimitador);
void intercambiar_int(int &dato_1, int &dato_2);
void intercambiar_double(double &dato_1, double &dato_2);
void intercambiar_cadenas(char *&dato_1, char *&dato_2);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
void ordenar_arreglos(int *arrCodigoAlumnos, char **arrAlumno, int *arrNumCursos,
                      double *arrSumaPonderada, double *arrNumCreditos, char **arrFacultad, int cant_alumnos);
void quitar_espacios_en_blanco(char *cadena);
void conseguir_nombre_de_facultades(char *cod_facu_usuario_1, char *&facultad_1,
                                    char *cod_facu_usuario_2, char *&facultad_2, ifstream &input);
void imprimir_titulo(char *facultad_1, char *facultad_2, ofstream &output);
void imprimir_encabezado(ofstream &output);
void imprimir_un_juego_de_datos_de_un_alumno(int codigoAlumno, char *nombreAlumno, int numCursos,
                                             double sumaPonderada, double numCreditos, double promPonderado,
                                             char *codFacultad, ofstream &output);
void imprimir_alumnos(char *cod_facu_usuario_1, char *cod_facu_usuario_2, int *arrCodigoAlumnos,
                      char **arrAlumno, int *arrNumCursos, double *arrSumaPonderada,
                      double *arrNumCreditos, char **arrFacultad, int cant_alumnos,
                      char *&nombre_alumno_con_mayor_credito, int &cod_alumno_mayor_credito,
                      double &alumno_con_mayor_credito, ofstream &output);
void imprimir_alumno_con_mayor_numero_de_creditos(char *nombre_alumno_con_mayor_credito,
                    int cod_alumno_con_mayor_credito, double alumno_con_mayor_credito, ofstream &output);
void emitir_reporte(const char *nombre_archivo_facultad, const char *nombre_archivo_reporte,
                    char *cod_facu_usuario_1, char *cod_facu_usuario_2, int *arrCodigoAlumnos,
                    char **arrAlumno, int *arrNumCursos, double *arrSumaPonderada,
                    double *arrNumCreditos, char **arrFacultad, int cant_alumnos);
int buscar_dato(int dato, int *arreglo, int cant_datos);
void leer_datos_de_un_alumno(int &cod_alumno_leido, char *&nombre_alumno, char *&facultad, ifstream &input);
void leer_alumnos_y_facultad(const char *nombre_archivo, int *arrCodigoAlumnos, char **arrAlumno,
                             char **arrFacultad, int cant_alumnos);
void insertar_o_acumular(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                         double *arrNumCreditos, int &cant_alumnos, double cred_curso,
                         int cod_alumno, int nota);
void leer_lista_de_notas(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                         double *arrNumCreditos, int &cant_alumnos, double cred_curso, ifstream &input);
void leer_calificaciones(const char *nombre_archivo, int *arrCodigoAlumnos, int *arrNumCursos,
                         double *arrSumaPonderada, double *arrNumCreditos, int &cant_alumnos);
void solicitar_dos_codigos_de_facultad_al_usuario(char *&cod_facu_usuario_1, char *&cod_facu_usuario_2);

#endif /* FUNCIONES_H */

