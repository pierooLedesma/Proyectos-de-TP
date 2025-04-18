

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 16 de abril de 2025, 08:22 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void preguntas_y_elaborarcion_del_reporte(const char *arch_lectura,const char *arch_escritura);
void preguntas_al_usuario(int &distrito_1,int &distrito_2,int &tiempo_a_partir_puede_llegar_al_cine,
                          int &duracion_maxima_cliente,char &lleva_alimentos);
int leer_tiempo_cliente();
void apertura_archivo_lectura(ifstream &input,const char *arch_lectura);
void apertura_archivo_escritura(ofstream &output,const char *arch_escritura);
void procesar_cartelera(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,const char *arch_lectura,const char *arch_escritura);
void imprimir_datos_ingresados(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ofstream &output);
void imprimir_titulo(ofstream &output);
void leer_cartelera_de_cines(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ifstream &input,ofstream &output,
        int &cant_peliculas_que_puede_ver);
void leer_nombre_e_imprimir_distrito(int codigo_distrito,ifstream &input,ofstream &output);
void imprimir_encabezado(ifstream &input,ofstream &output);
void leer_juego_de_datos_de_peliculas(int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ifstream &input,ofstream &output,
        int &cant_peliculas_que_puede_ver);
void leer_juego_de_datos(int &cod_sala_cine,double &costo_entrada,
        char &se_puede_llevar_alimentos_al_cine,int &tiempo_inicio,
        int &tiempo_final,ifstream &input);
void imprimir_juego_de_datos(int cod_sala_cine,double costo_entrada,
        char se_puede_llevar_alimentos_al_cine,int tiempo_inicio,int tiempo_final,ifstream &input,
        ofstream &output,int &cant_peliculas);
void leer_and_imprimir_nombre(ifstream &input,ofstream &output,bool es_pelicula);
void imprimir_cant_peliculas_parciales(int cant_peliculas,ofstream &output);
void imprimir_que_no_hay_peliculas(ofstream &output);
int leer_tiempo_archivo_cartelera(ifstream &input);
void ignorar_cadena_de_caracteres(ifstream &input);
void imprimir_tiempo(int tiempo,ofstream &output);
void impresion_de_cant_peliculas_puede_ver(int cant_peliculas_que_puede_ver,ofstream &output);
void elaborar_lineas(char caracter,int cantCaracteres,ofstream &output);

#endif /* FUNCIONES_H */
