

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 16 de junio del 2025, 10:51 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
int leer_semestre(ifstream &input);
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output);
void imprimir_titulo(int semestre, ofstream &output);
void imprimir_encabezado(ofstream &output);
void imprimir_datos_de_un_curso(int n_curso, int cod_curso, char *nombre_curso, double numeroDeCreditos,
                                int cantidadDeAlumnosMatriculados, 
                                double montoPagadoDeAlumnosMatriculados, ofstream &output);
void imprimir_todos_los_cursos(struct Curso *arrCursos, int cant_cursos,
                               double &monto_total_pagado, ofstream &output);
void imprimir_monto_total_pagado(double monto_total_pagado, ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct Curso *arrCursos,
                    int cant_cursos, int semestre_ingresado);
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2);
void ordenar_arreglo_cursos(struct Curso *arrCursos, int cant_cursos);
int buscar_escala(char escala_alumno, struct Escala *arrEscalas, int cant_escalas);
int buscar_costo_por_credito(int codigo_alumno_leido, struct Alumno *arrAlumnos,
                             int cant_alumnos, struct Escala *arrEscalas, int cant_escalas);
double asignar_costo_por_credito(int codigo_alumno_leido, struct Alumno *arrAlumnos,
                                 int cant_alumnos, struct Escala *arrEscalas, int cant_escalas);
int buscar_curso(int codigo_curso_buscado, struct Curso *arrCursos, int cant_cursos);
void procesar_lista_de_cursos(struct Curso*arrCursos, int cant_cursos,
                              double costo_por_credito, ifstream &input);
void leer_matricula(const char *nombre_archivo, struct Curso *arrCursos,
                    int cant_cursos, struct Alumno *arrAlumnos, int cant_alumnos,
                    struct Escala *arrEscalas, int cant_escalas, int semestre_ingresado);
void leer_una_escala(struct Escala &una_escala, ifstream &input);
void leer_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cant_escalas);
void pasar_todo_a_mayusculas(char *cadena);
void leer_un_curso(struct Curso &un_curso, ifstream &input);
void leer_cursos(const char *nombre_archivo, struct Curso *arrCursos, int &cant_cursos);
void leer_un_alumno(struct Alumno &un_alumno, ifstream &input);
void leer_alumnos(const char *nombre_archivo, struct Alumno *arrAlumnos, int &cant_alumnos);
int solicitar_semestre();

#endif /* FUNCIONES_H */


