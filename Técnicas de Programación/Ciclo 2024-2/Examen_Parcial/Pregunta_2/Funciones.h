

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de mayo de 2025, 06:36 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void leer_platos_ofrecidos(const char *nombre_archivo,int *arr_codigo_plato,
                           double *arr_precio_plato,int *arr_cantidades_plato,
                           double *arr_descuento_plato,double *arr_montos_recaudados,
                           int &cant_platos);
void leer_clientes(const char *nombre_archivo,int *arr_dni_cliente,
                   double *arr_descuento_cliente,int &cant_clientes);
void emitir_reporte_prueba(const char *nombre_archivo,int *arr_codigo_plato,
                           double *arr_precio_plato,int *arr_cantidades_plato,double *arr_descuento_plato,
                           double *arr_montos_recaudados,int cant_platos,int *arr_dni_cliente,
                           double *arr_descuento_cliente,int cant_clientes);
void leer_repartos_a_realizar(const char *nombre_archivo,int *arr_codigo_plato,
                      double *arr_precio_plato,int *arr_cantidades_plato,double *arr_descuento_plato,
                      double *arr_montos_recaudados,int cant_platos,int *arr_dni_cliente,
                      double *arr_descuento_cliente,int cant_clientes);
void procesar_lista_de_platos(int *arr_codigo_plato,double *arr_precio_plato,int *arr_cantidades_plato,
                              double *arr_descuento_plato,double *arr_montos_recaudados,
                              int cant_platos,double descuento_cliente,ifstream &input);
void ordenar_arreglos(int *arr_codigo_plato,double *arr_precio_plato,int *arr_cantidades_plato,
                      double *arr_descuento_plato,double *arr_montos_recaudados,
                      int cant_platos);
void emitir_reporte(const char *nombre_archivo,int *arr_codigo_plato,
                    double *arr_precio_plato,int *arr_cantidades_plato,
                    double *arr_descuento_plato,double *arr_montos_recaudados,int cant_platos);
void eliminar_datos_en_los_arreglos(int *arr_codigo_plato,double *arr_precio_plato,
                                    int *arr_cantidades_plato,double *arr_descuento_plato,
                                    double *arr_montos_recaudados,int &cant_platos);
void eliminar_datos(int posicion_a_eliminar,int *arr_codigo_plato,double *arr_precio_plato,
                    int *arr_cantidades_plato,double *arr_descuento_plato,
                    double *arr_montos_recaudados,int &cant_platos);
void imprimir_titulo(int opcion,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void elaborar_encabezado(bool es_para_platos,ofstream &output);
void imprimir_clientes(int *arr_dni_cliente,double *arr_descuento_cliente,
                       int cant_clientes,ofstream &output);
void imprimir_un_juego_de_datos_de_platos(int cod_plato,double precio_plato,
                                          int cant_platos_preparados,int cant_platos_atendidos,
                                          int cant_platos_no_atendidos,double descuento_plato,
                                          double monto_total_esperado,double monto_total_bruto,
                                          double monto_total_recibido,ofstream &output);
void imprimir_resumen_de_totales(double total_del_monto_esperado,
                  double total_del_monto_bruto,double total_del_monto_recibido,ofstream &output);
int leer_dato_tipo_int(ifstream &input);
double leer_dato_tipo_double(ifstream &input);
char leer_dato_tipo_char(ifstream &input);
void ignorar_hasta_delimitador(char delimitador,ifstream &input);
int buscar_posicion(int dato,int *arreglo,int cant_datos);
void actualizar_cantidad_de_platos_atendidos_y_no_atendidos(int &cant_atendida,
                            int cantidad_pedida,int cant_platos_preparados,
                            int &total_cant_platos_atendidos,int &total_cant_platos_no_atendidos);
void actualizar_monto_bruto_y_monto_recibido(double &total_monto_bruto,
                    double &total_monto_recibido,int cant_atendida,double precio_plato,
                    double descuento_plato,double descuento_cliente);
void intercambiar_int(int &dato_1,int &dato_2);
void intercambiar_double(double &dato_1,double &dato_2);
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);

#endif /* FUNCIONES_H */
