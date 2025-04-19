

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de abril de 2025, 08:15 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void procesar_infracciones();
void leer_las_dos_fechas_iniciales_e_imprimirlas(int &fecha_1,int &fecha_2);
void procesar_archivo_infracciones(int fecha_1,int fecha_2);
void leer_nombre_e_imprimir_dni_nombre(int dni,int n_compania);
void procesar_descripcion_infracciones(int fecha_1,int fecha_2,double &total_recaudado_por_infracciones,
        double &compania_menor_pago,int &dni_menor_pago,double &compania_mayor_pago,
        int &dni_mayor_pago,int dni);
void imprimir_encabezado_descripcion_infracciones();
void leer_e_imprimir_descripcion_infracciones(int fecha_1,int fecha_2,double &total_multas,
        double &total_fecha,double &total_hora,double &total_tipo,double &total_total_a_pagar);
void leer_imprimir_placa(char &tipo_vehiculo);
void imprimir_tipo_vehiculo(char tipo_vehiculo);
void imprimir_gravedad(char &gravedad);
double imprimir_multa(char gravedad);
double imprimir_incremento_tipo(char tipo_vehiculo,double multa);
double imprimir_incremento_fecha(int fecha,int fecha_1,int fecha_2,double multa);
double imprimir_incremento_hora(int tiempo,double multa);
void imprimir_montos_totales(double total_multas,double total_fecha,double total_hora,
        double total_tipo,double total_total_a_pagar);
int leer_fecha();
void imprimir_fecha(int fecha);
int leer_tiempo();
void imprimir_tiempo(int tiempo);
void imprimir_total_recaudado(double total_recaudado_por_infracciones);
void imprimir_resumen(int dni_mayor_pago,double compania_mayor_pago,
        int dni_menor_pago,double compania_menor_pago);
void elaborar_lineas(char caracter,int cant_caracteres);

#endif /* FUNCIONES_H */
