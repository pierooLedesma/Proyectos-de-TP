

/* 
 * Archivo:   Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 2 de julio del 2025, 10:27 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador);
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);
void concatenar_numero(char *cadena, int numero);
void concatenar_semestre(char *cadena, int anho_usuario, int ciclo_usuario);
void escoger_nombre_del_archivo(int anho_usuario, int ciclo_usuario, bool es_reporte_final, char *nombre_archivo);
void imprimir_titulo(bool es_reporte_final, int anho_usuario, int ciclo_usuario, ofstream &output);
void imprimir_un_alumno_matriculado(int codAlumno, char *nombre, char escala, double valorCred, ofstream &output);
void imprimir_cursos_matriculados_de_un_alumno(struct Curso *arrCursos, int cantidadCursos,
                                               double valorCred, ofstream &output);
void imprimir_totales_de_un_alumno(double totalCreditos, double totalPago, ofstream &output);
void imprimir_alumnos_matriculados(struct Alumno *arrAlumnos, int cantAlumnos, int &cantidad_alumnos_matriculados,
                                   double &total_monto_pagado, bool es_reporte_final, ofstream &output);
void imprimir_resumen_del_reporte(int cantidad_alumnos_matriculados, double total_monto_pagado, ofstream &output);
void emitir_reporte(int anho_usuario, int ciclo_usuario, struct Alumno *arrAlumnos, int cantAlumnos, bool es_reporte_final);
void intercambiar_struct_alumno(struct Alumno &alumno_1, struct Alumno &alumno_2);
void ordenar_alumnos(struct Alumno *arrAlumnos, int cantAlumnos);
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2);
void ordenar_cursos(struct Curso *arrCursos, int cantCursos);
void ordenar_arreglo_alumnos(struct Alumno *arrAlumnos, int cantAlumnos);
void solicitar_anho_y_ciclo_al_usuario(int &anho_usuario, int &ciclo_usuario);
int buscar_alumno(int codAlumno_leido, struct Alumno *arrAlumnos, int cantAlumnos);
int buscar_escala(int anho_leido, int ciclo_leido, char escalaAlumno, struct Escala *arrEscalas, int cantEscalas);
void completar_campo_escala_del_alumno(struct Escala &escala_de_un_alumno, int anho_leido, int ciclo_leido,
                                       struct Escala *arrEscalas, int cantEscalas);
int buscar_curso(int codCurso_leido, struct Curso *arrCursos, int cantCursos);
void leer_cursos_matriculados_de_un_alumno(struct Curso *arrCursosAlumno, int &cantidadCursosAlumno,
                            double &totalCreditos, double &totalPago, double valorCredAlumno,
                            struct Curso *arrCursos,int cantCursos, ifstream &input);
void procesar_matricula(const char *nombre_archivo, int &anho_usuario, int &ciclo_usuario, struct Curso *arrCursos,
                        int cantCursos, struct Escala *arrEscalas, int cantEscalas, struct Alumno *arrAlumnos, int cantAlumnos);
void todo_a_mayuscula(char *cadena);
void leer_un_alumno(struct Alumno &un_alumno, ifstream &input);
void procesar_alumnos(const char *nombre_archivo, struct Alumno *arrAlumnos, int &cantAlumnos);
void imprimir_titulo_y_encabezado_del_reporte_prueba_escalas(ofstream &output);
void verificar_asignacion_de_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int cantEscalas);
void leer_una_escala(struct Escala &una_escala, ifstream &input);
void procesarEscalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cantEscalas);
void imprimir_titulo_y_encabezado_del_reporte_prueba_curso(ofstream &output);
void verificar_asignacion_de_cursos(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos);
void leer_un_curso(struct Curso &un_curso, ifstream &input);
void procesarCursos(const char *nombre_archivo, struct Curso *arrCursos, int &cantCursos);

#endif /* FUNCIONES_HPP */

