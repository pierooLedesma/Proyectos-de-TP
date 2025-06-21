

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de junio del 2025, 01:28 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
char* asignar_cadena(const char *buffer);
char* leer_cadena(ifstream &input, char delimitador);
int leer_semestre(ifstream &input);
void elaborar_lineas(char caracter, int cantidad_de_caracteres, ofstream &output);
void imprimir_titulo(int semestre_ingresado, ofstream &output);
void imprimir_encabezado(bool es_de_curso, ofstream &output);
void imprimir_datos_de_un_curso(int n_curso, int codigo, char *nombre_curso,
                                double numeroDeCreditos, ofstream &output);
void imprimir_alumnos(struct Alumno *arrAlumnos, int cantAlumnos, double numCreditos, ofstream &output);
void imprimir_cursos(struct Curso *arrCursos, int cantCursos, 
                     double &monto_total_por_ingresos_de_matricula, ofstream &output);
void imprimir_total_ingresos(double monto_total_por_ingresos_de_matricula, ofstream &output) ;
void emitir_reporte(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos, int semestre_ingresado);
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2);
void ordenar_cursos(struct Curso *arrCursos, int cantCursos);
void intercambiar_struct_alumno(struct Alumno &alumno_1, struct Alumno &alumno_2);
void ordenar_alumnos_de_un_curso(struct Alumno *arrAlumnos, int cantAlumnos);
void ordenar_listas_de_alumnos(struct Curso *arrCursos, int cantCursos);
void ordenar_arreglo_de_cursos_y_listas_de_alumnos(struct Curso *arrCursos, int cantCursos);
void completar_el_ingreso_total_por_curso(struct Curso *arrCursos, int cantCursos);
void leer_un_alumno(int &codigo_alumno_leido, char *&nombre_alumno, char &escala_alumno, ifstream &input);
int buscar_escala(char escala_alumno, int semestre_ingresado, struct Escala *arrEscalas, int cantEscalas);
void completar_campos_restantes_del_alumno(struct Alumno &un_alumno, char *nombre_alumno,
                       char escala_alumno, struct Escala *arrEscalas, int cantEscalas, int semestre_ingresado);
void recorrer_el_arreglo_alumnos_matriculados(struct Alumno *arrAlumnos, int cantAlumnos,
                                              int codigo_alumno_leido, char escala_alumno, int semestre_ingresado,
                                              struct Escala *arrEscalas, int cantEscalas, char *nombre_alumno);
void insertar_alumno_en_cada_curso(int codigo_alumno_leido, char *nombre_alumno, char escala_alumno,
                                   struct Curso *arrCursos, int cantCursos, struct Escala *arrEscalas,
                                   int cantEscalas, int semestre_ingresado);
void completar_el_pago_por_credito_de_cada_alumno(const char *nombre_archivo, struct Curso *arrCursos,
                            int cantCursos, struct Escala *arrEscalas, int cantEscalas, int semestre_ingresado);
int buscar_curso(int codigo_curso, struct Curso *arrCursos, int cantCursos);
bool buscar_alumno(int codigo_alumno, int cantAlumnos, struct Alumno *arrAlumnos);
void procesar_lista_de_cursos(int codigo_alumno, struct Curso *arrCursos, int cantCursos, ifstream &input);
void leer_matricula(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos, int semestre_ingresado);
void pasar_todo_a_mayusculas(char *cadena);
void leer_un_curso(struct Curso &un_curso, ifstream &input);
void leer_cursos(const char *nombre_archivo, struct Curso *arrCursos, int &cantCursos);
void leer_una_escala(struct Escala &una_escala, ifstream &input);
void leer_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cantEscalas);
int solicitar_semestre();

#endif /* FUNCIONES_H */



