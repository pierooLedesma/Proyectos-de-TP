

/* 
 * Archivo:   Funciones.H
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 8 de junio del 2025, 12:49 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
void reservar_memoria_fija(char **arrCadenas);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
char *asignar_cadena(char *buffer);
char *leer_cadena_exacta(ifstream &input, char delimitador);
int leer_fecha(ifstream &input);
void imprimir_fecha(int fecha, ofstream &output);

void emitir_reporte(const char *nombre_archivo, int *arrDNI, char **arrNombre, char **arrListaDePlacas, 
                           int *arrFechaInfraccionMasAntigua, int *arrFechaUltimaPagada, int cant_representantes);


int buscar_infraccion(int dato_buscado, int *arreglo, int cant_datos);


void leer_una_infraccion_cometida(int &fecha_infraccion, char *&placa_leida, int &cod_infraccion_leida,
                                                             int &fecha_pagada, ifstream &input);

int buscar_infraccion(int dato_buscado, int *arreglo, int cant_datos);


int contar_placas(char *listaDePlacas);
void copiar_placa(char *listaDePlacas, int indice_inicial, int indice_final, char *&placa);
void extraer_placa(char *listaDePlacas, int n_placa, char *&placa_extraida);
bool existe_placa(char *placa_buscada, char *listaDePlacas);
int buscar_representante(char *placa_leida, char **arrListaDePlacas, int cant_representantes);
void leer_infracciones_cometidas(const char *nombre_archivo, int *arr_cod_infraccion, double *arr_multas,
                           int cant_infracciones, int *arrDNI, char **arrNombre, char **arrListaDePlacas, 
                           int *arrFechaInfraccionMasAntigua, int *arrFechaUltimaPagada, int cant_representantes);
char *leer_placa(ifstream &input);
void procesar_placas(char *arrListaDePlacas, ifstream &input);
void leer_empresas_registradas(const char *nombre_archivo, int *arrDNI, char **arrNombre,
                                                         char **arrListaDePlacas, int &cant_representantes);
void leer_tabla_de_infracciones(const char *nombre_archivo, int *arr_cod_infraccion, double *arr_multas,
                                                        char **arr_gravedad, char **arr_descripcion_infraccion, int &cant_infracciones);

#endif /* FUNCIONES_H */
