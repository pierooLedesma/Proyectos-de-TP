

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de abril de 2025, 08:51 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_encabezados(bool esRepartidor,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void leer_and_imprimir_cadena_de_caracteres(bool es_vehiculo,bool imprimir_cambio_de_linea,
        bool pasar_todo_a_mayuscula,char delimitador,ifstream &input,ofstream &output);
void leer_and_imprimir_datos_del_repartidor(int dni,char &vehiculo,int &cod_distrito,
        int n_repartidores,ifstream &input_repartidores,ofstream &output);
void imprimir_un_pedido_del_cliente(int n_platos_pedidos,int cod_plato_leido,int cantidad_pedida,
                                    double precio_del_plato,double subtotal,ofstream &output);
int buscar_precio_del_plato(int cod_plato_leido,int *arr_cod_plato,int cant_platos);
void procesar_lista_de_platos_pedidos_por_el_cliente(double &total_a_pagar,
                        ifstream &input_repartos,ofstream &output,int *arr_cod_plato,
                        double *arr_precio_plato,int cant_platos);
double calcular_pago_al_repartidor(char vehiculo,double total_a_pagar);
void impresion_de_totales_de_un_cliente(double total_a_pagar,double pago_al_repartidor,
                                        ofstream &output);
void procesar_repartos(char vehiculo,int cod_distrito,ifstream &input_repartos,
                       ofstream &output,int *arr_cod_plato,double *arr_precio_plato,
                       int cant_platos,int &n_clientes,
                       double &total_recaudado_por_todos_los_pedidos,
                       double &total_a_pagar_a_los_repartidores);
void procesar_repartidores(double &total_recaudado_por_todos_los_pedidos,
                           double &total_a_pagar_a_los_repartidores,
                           ifstream &input_repartidores,ifstream &input_repartos,
                           ofstream &output,int *arr_cod_plato,double *arr_precio_plato,
                           int cant_platos);
void imprimir_resumen_del_reporte(double total_recaudado_por_todos_los_pedidos,
                            double total_a_pagar_a_los_repartidores,ofstream &output);
void procesar_reporte(const char *nombre_archivo_repartidores,
                      const char *nombre_archivo_repartos,
                      const char *nombre_archivo_reporte,
                      int *arr_cod_plato,double *arr_precio_plato,int cant_platos);
void ignorar_cadena_caracteres(int longitud_cadena,char delimitador,ifstream &input);
void procesar_platos_ofrecidos(const char *nombre_archivo_platos,int *arr_cod_plato,
                               double *arr_precio_plato,int &cant_platos);

#endif /* FUNCIONES_H */
