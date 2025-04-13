

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de abril de 2025, 12:21 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void leer_y_procesar_envios();
int leer_fecha();
void imprimir_titulo_and_subtitulo(const char *titulo,const char *subtitulo,int fecha);
void leer_nombre_and_dni(int dni);
void procesar_datos_entrega(int dni,double &menor_distancia,int &dni_menor,double &mayor_distancia,
        int &dni_mayor);
void imprimir_encabezado_tramos();
void leer_and_actualizar_los_datos_de_entrega_por_repartidor(double &velocidad,int &tiempo_dos,
        double &direccion,double &distancia,double &abscisa_2,double &ordenada_2,
        double &pago,double &pago_total,int tiempo_uno);
int leer_tiempo();
double leer_direccion();
double calcular_distancia(int tiempo_en_segundos,double velocidad);
void calcular_puntos(double distancia,double direccion,double &abscisa,double &ordenada);
double pasar_sexagesimal_a_radianes(double angulo_en_sexagesimales);
double calcular_pago_por_tramo(double distancia);
void imprimir_datos_de_entrega(int cant_tramos,int &tiempo_uno,int tiempo_dos,double velocidad,
        double distancia,double abscisa_1,double ordenada_1,double abscisa_2,double ordenada_2,
        double &distancia_acumulada,double pago,bool es_el_retorno);
void imprimir_hora(int tiempo);
void imprimir_puntos(double abscisa,double ordenada);
void actualizar_datos_de_los_tramos(int &cant_tramos,int &tiempo_uno,int tiempo_dos,double &abscisa_1,
        double abscisa_2,double &ordenada_1,double ordenada_2);
void imprimir_pago_total_al_repartidor(double pago_total);
void calcular_datos_faltantes_de_retorno(int tiempo_uno,int &tiempo_dos,double &distancia,
        double velocidad,double abscisa_1,double ordenada_1,double &abscisa_2,double &ordenada_2);
void actualizar_distancias(int dni,double distancia_acumulada,double &menor_distancia,int &dni_menor,
        double &mayor_distancia,int &dni_mayor);
void imprimir_resumen(double menor_distancia,int dni_menor,double mayor_distancia,int dni_mayor);
void elaborar_lineas(char caracter,int cant_caracteres);

#endif /* FUNCIONES_H */
