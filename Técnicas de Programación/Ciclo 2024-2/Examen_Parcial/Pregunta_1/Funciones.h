

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de mayo de 2025, 06:28 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
int leer_dato_tipo_int(ifstream &input);
double leer_dato_tipo_double(ifstream &input);
char leer_dato_tipo_char(ifstream &input);
double leer_porcentaje(ifstream &input);
void imprimir_vehiculo(char vehiculo,ofstream &output);
void imprimir_cadena(char delimitador,int tam_total_de_cadena_con_espacios,
                     ifstream &input,ofstream &output);
void ignorar_hasta_delimitador(char delimitador,ifstream &input);
void procesar_reporte(const char *nombre_archivo_clientes,const char *nombre_archivo_repartos,
                      const char *nombre_archivo_platos,const char *nombre_archivo_repartidores,
                      const char *nombre_archivo_reporte);
void imprimir_titulo(ofstream &output);
void procesar_clientes(ifstream &input_clientes,ifstream &input_repartos,
                       ifstream &input_platos,ifstream &input_repartidores,
                       double &total_recaudado_por_los_pedidos_solicitados,
                       double &total_a_pagar_a_los_repartidores,ofstream &output);
void continuar_lectura_de_un_cliente_e_imprimirlo(int dni_cliente,int &cod_distrito,
                                    char &vehiculo_desea_el_cliente,double &descuento_cliente,
                                    ifstream &input_clientes,ofstream &output);
void procesar_repartos(int dni_cliente,double porcentaje_descuento_cliente,
                       double &monto_total_pagado_por_el_cliente,
                       ifstream &input_repartos,double &pago_total_al_repartidor,
                       ifstream &input_platos,ofstream &output,char vehiculo_desea_el_cliente);
void imprimir_encabezado_de_un_pedido(int n_pedido,int cod_pedido,ofstream &output);
void leer_lista_de_platos(double &total_pedido_sin_descuentos,
                  double &descuento_total_por_platos,double &descuento_cliente,
                  double &pago_al_repartidor,ifstream &input_repartos,
                  ifstream &input_platos,ofstream &output,
                  double porcentaje_descuento_cliente,char vehiculo_desea_el_cliente);
void procesar_plato(double &total_pedido_sin_descuentos,
                    double &descuento_total_por_platos,int &n_platos,int cant_pedida,
                    int cod_plato,ifstream &input_platos,ofstream &output);
void continuar_lectura_de_un_plato_e_imprimirlo(int n_platos,int cod_plato,
                           int cant_pedida,double &subtotal,double &el_monto_con_descuento_plato,
                           ifstream &input_platos,ofstream &output);
void imprimir_resumen_de_un_pedido(double total_pedido_sin_descuentos,
                           double descuento_total_por_platos,double descuento_cliente,
                           double pago_al_repartidor,ofstream &output);
void imprimir_resumen_de_un_cliente(double monto_total_pagado_por_el_cliente,
                           double pago_total_al_repartidor,ifstream &input_repartidores,ofstream &output,
                           char vehiculo_desea_el_cliente,int cod_distrito_cliente);
void imprimir_repartidor(double pago_total_al_repartidor,char vehiculo_desea_el_cliente,
                         int cod_distrito_cliente,ifstream &input_repartidores,ofstream &output);
void imprimir_resumen_del_reporte(double total_recaudado_por_los_pedidos_solicitados,
                                  double total_a_pagar_a_los_repartidores,ofstream &output);

#endif /* FUNCIONES_H */
