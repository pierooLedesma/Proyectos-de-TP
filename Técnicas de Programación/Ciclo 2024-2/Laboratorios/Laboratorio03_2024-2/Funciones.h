

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de abril de 2025, 12:20 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input);
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output);
void procesar_reporte(const char *nombre_archivo_Platos,const char *nombre_archivo_Repartos,
                      const char *nombre_archivo_Reporte);
void procesar_platos(ifstream &input_platos,ifstream &input_repartos,ofstream &output);
void leer_nombre_plato_e_imprimir_codigo_del_plato_y_nombre_del_plato(int codigo_plato,
        ifstream &input_platos,ofstream &output);
void leer_tipo_e_imprimir_precio_del_plato_y_tipo_del_plato(double precio,
        ifstream &input_platos,ofstream &output);
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_descripcion);
void procesar_repartos(int codigo_plato,double precio,ifstream &input_repartos,ofstream &output,
                       double &total_recaudado,int &cant_recaudada);
void leer_lista_de_platos(int codigo_plato,double precio,int dni,int tiempo,
        ifstream &input_repartos,ofstream &output,int &cant_total,double &total_recaudado_del_plato);
void imprimir_encabezado_repartos(ofstream &output);
int leer_tiempo(ifstream &input);
void imprimir_tiempo(int tiempo,ofstream &output);
void imprimir_totales_del_plato_procesado(int cant_total,double total_recaudado_del_plato,
                                          ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);

#endif /* FUNCIONES_H */
