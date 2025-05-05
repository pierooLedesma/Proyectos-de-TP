

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 4 de mayo de 2025, 11:40 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulo(bool es_de_prueba,ofstream &output);
void imprimir_encabezados(int opcion,ofstream &output);
void imprimir_pico_mayor_o_menor_valle(bool es_pico,int anio,int ganancia,ofstream &output);
bool es_pico_o_valle(int *arr_ganancia,int indice,int cant_datos,bool es_pico);
void imprimir_picos_o_valles_segun_sea_el_caso(int *arr_anio,int *arr_gananacias,
                                               int cant_datos,bool es_pico,ofstream &output);
void elaborar_reporte_solicitado(const char *nombre_archivo,int *arr_anio,
                                 int *arr_gananacias,int cant_datos);
void elaborar_reporte_de_prueba(const char *nombre_archivo,int *arr_anio,
                                int *arr_gananacias,int cant_datos);
void leer_ganancias_y_cargar_arreglos(int *arr_anio,int *arr_gananacias,
                                      int &cant_datos,const char *nombre_archivo);

#endif /* FUNCIONES_H */
