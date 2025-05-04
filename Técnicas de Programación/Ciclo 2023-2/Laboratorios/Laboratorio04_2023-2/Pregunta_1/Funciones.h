

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de mayo de 2025, 06:20 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulo(bool es_reporte_prueba,ofstream &output);
void imprimir_encabezado(bool no_es_reporte_prueba,ofstream &output);
void imprimir_area_perimetro_cantLados_del_poligono(double area,double perimetro,
                                                    int cantidad_de_lados,ofstream &output);
void imprimir_reporte(double area,double perimetro,int cantidad_de_lados,
                      double *arr_coordenada_x,double *arr_coordenada_y,
                      int cant_vertices,const char *nombre_archivo);
double sumatoria_coordenas_para_hallar_el_area(double *arr_coordenada_1,
                                               double *arr_coordenada_2,int cant_vertices);
double calcular_area(double *arr_coordenada_x,double *arr_coordenada_y,int cant_vertices);
void imprimir_reporte(double area,double perimetro,int cantidad_de_lados,
                      double *arr_coordenada_x,double *arr_coordenada_y,
                      int cant_vertices,const char *nombre_archivo);
void calcular_area_perimetro_cantLados(double &area,double &perimetro,
                                       int &cantidad_de_lados,double *arr_coordenada_x,
                                       double *arr_coordenada_y,int cant_vertices);
void imprimir_reporte_de_prueba(const char *nombre_archivo,
        double *arr_coordenada_x,double *arr_coordenada_y,int cant_vertices);
void leer_coordenadas_y_colocar_en_arreglos(const char *nombre_archivo,
        double *arr_coordenada_x,double *arr_coordenada_y,int &cant_vertices);

#endif /* FUNCIONES_H */
