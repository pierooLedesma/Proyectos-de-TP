

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de abril de 2025, 12:38 PM
 */


#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input);
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_encabezado_televidentes(ofstream &output);
void imprimir_tiempo(int tiempo,ofstream &output);
int leer_tiempo(ifstream &input);
void leer_and_imprimir_cadena(int tam,char delimitador,bool es_canal,
                              ifstream &input,ofstream &output);
void imprimir_canal(int canal,ifstream &input_canales,ofstream &output);
void imprimir_rango_y_duracion_del_televidente(int tiempo_inicio,int tiempo_final,ofstream &output);
void imprimir_sexo(char sexo,ofstream &output);
void imprimir_categoria(int anio,ofstream &output);
void imprimir_compania(char compania,ofstream &output);
int es_menor(int anio);
int es_joven(int anio);
int es_adulto(int anio);
void continuar_lectura_del_televidente_e_imprimirlo(int &cant_menores,int &cant_jovenes,
                                                    int &cant_adultos,ifstream &input_televidentes,ofstream &output);
void buscar_e_imprimir_televidente(int dni,int &cant_menores,int &cant_jovenes,
                                   int &cant_adultos,ifstream &input_televidentes,
                                   ofstream &output);
void procesar_lista_de_canales(int dni,int canal,ifstream &input_registro,ifstream &input_televidentes,
                               ofstream &output,int &sumar_tiempo,int &cant_menores,
                               int &cant_jovenes,int &cant_adultos,int &total_personas);
void procesar_registro(int canal,int &sumar_tiempo,int &cant_menores,
                       int &cant_jovenes,int &cant_adultos,int &total_personas,
                       ifstream &input_registro,ifstream &input_televidentes,ofstream &output);
void imprimir_resumen_por_canal(int sumar_tiempo,int cant_menores,int cant_jovenes,
                                int cant_adultos,int total_personas,ofstream &output);
void procesar_canales(ifstream &input_canales,ifstream &input_registro,
                      ifstream &input_televidentes,ofstream &output);
void procesar_reporte(const char *nombre_archivo_canales,
                      const char *nombre_archivo_televidentes,
                      const char *nombre_archivo_registro,
                      const char *nombre_archivo_reporte);

#endif /* FUNCIONES_H */
