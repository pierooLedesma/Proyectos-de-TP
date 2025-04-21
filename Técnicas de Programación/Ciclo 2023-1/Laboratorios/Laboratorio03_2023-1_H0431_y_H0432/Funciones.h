

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 20 de abril de 2025, 06:06 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input);
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output);
void realizar_listado_personas(const char *nombre_archivo_cartelera,
                               const char *nombre_archivo_clientes,
                               const char *nombre_archivo_listado_personas);
void imprimir_titulo(const char *titulo,ofstream &output);
void procesar_cartelera(ifstream &input_cartelera,ifstream &input_clientes,ofstream &output);
void leer_distrito_e_imprimir_distrito_y_su_codigo(int cod_distrito_cartelera,ifstream &input_cartelera,
                                                   ofstream &output);
void procesar_informacion_de_peliculas_de_un_cine(int cod_distrito_cartelera,ifstream &input_cartelera,
                                                  ifstream &input_clientes,ofstream &output);
void imprimir_encabezado_de_una_pelicula(ofstream &output);
void leer_una_pelicula(int &cod_sala_cine,double &costo_entrada,char &ingresar_con_alimentos,
        int &tiempo_inicial,int &tiempo_final,ifstream &input_cartelera);
void imprimir_datos_de_la_pelicula(int cod_sala_cine,double costo_entrada,char ingresar_con_alimentos,
        int tiempo_inicial,int tiempo_final,ofstream &output);
char ignorar_cadena_de_caracteres(ifstream &input);
void procesar_clientes_cine(int cod_distrito_cartelera,char ingresar_con_alimentos,int tiempo_inicial,
        int tiempo_duracion,ifstream &input_clientes,ofstream &output);
bool leer_clientes_y_retornar_si_es_fin_de_archivo(int &cod_distrito_1,int &cod_distrito_2,
        int &tiempo_inicio_cliente,int &tiempo_duracion_cliente,char &cliente_ingresar_alimentos,
        int &dni,ifstream &input_clientes);
void imprimir_encabezado_clientes(ofstream &output,bool &hay_un_primer_cliente);
void imprimir_datos_cliente(int dni,int tiempo_inicio_cliente,int tiempo_duracion_cliente,
        char cliente_ingresar_alimentos,ifstream &input_clientes,ofstream &output,int &cant_clientes);
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_nombre_cinefilo);
void imprimir_cant_clientes(int cant_clientes,ofstream &output);
int leer_tiempo(ifstream &input);
void imprimir_tiempo(int tiempo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracter,ofstream &output);

#endif /* FUNCIONES_H */
