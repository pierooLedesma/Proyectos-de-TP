

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de junio del 2025, 12:55 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char* asignar_cadena(const char* buffer);
char* leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura);
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output);
void imprimir_titulo(int opcion, ofstream &output);
void imprimir_encabezados_del_reporte_solicitado(bool es_encabezado_cliente, ofstream &output);
void imprimir_datos_de_un_cliente(const struct Cliente &unCliente, int cantClientes, ofstream &output);
void imprimir_lista_de_pedidos(struct PlatoPedido *listaDePedidos, int cantidadDePedidos, ofstream &output);
void imprimir_clientes(struct Cliente *arrClientes, int cantClientes, ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct Cliente *arrClientes, int cantClientes);
void intercambiarStructPlatoPedido(struct PlatoPedido &platoPedido_1, struct PlatoPedido &platoPedido_2);
void ordenar_una_lista_de_pedidos_de_un_cliente(struct PlatoPedido *arrPlatosPedidos, int cantidadDePedidos);
void ordenar_pedidos_de_los_clientes(struct Cliente *arrClientes, int cantClientes);
void intercambiarStructCliente(struct Cliente &cliente_1, struct Cliente &cliente_2);
void ordenar_clientes(struct Cliente *arrClientes, int cantClientes);
void leer_un_pedido(int &codigoDelPedido, int &dni_leido, char* &cod_plato_leido,
                    int &cantidadPedida, ifstream &input);
int buscar_plato(char* cod_plato_leido, struct Plato *arrPlatos, int cantPlatos);
int buscar_cliente(int dni_leido, struct Cliente *arrClientes, int cantClientes);
void agregar_un_plato_pedido_al_cliente(const struct Plato &unPlato, struct PlatoPedido &unPlatoPedido,
                                        int codigoDelPedido, int cantidadPedida);
int buscar_distrito(char *codigo_distrito_buscado, struct Distrito *arrDistritos, int cantDistritos);
void insertar_nombre_del_distrito_del_cliente(struct Distrito *arrDistritos, int cantDistritos,
                                              struct Distrito &distritoDelCliente);
void completar_los_campos_de_distrito_a_los_clientes(struct Distrito *arrDistritos, int cantDistritos,
                                                     struct Cliente *arrClientes, int cantClientes);
void leer_pedidos_realizados(const char *nombre_archivo, struct Plato *arrPlatos, int cantPlatos,
                             struct Distrito *arrDistritos, int cantDistritos, struct Cliente *arrClientes,
                             int cantClientes);
void imprimir_encabezado_reporte_de_prueba(int opcion, ofstream &output);
void emitir_reporte_de_prueba_de_platos(const char *nombre_archivo, struct Plato *arrPlatos, int cantPlatos);
void emitir_reporte_de_prueba_de_distritos(const char *nombre_archivo, struct Distrito *arrDistritos, int cantDistritos);
void emitir_reporte_de_prueba_de_clientes(const char *nombre_archivo, struct Cliente *arrClientes, int cantClientes);
void verificar_datos_en_los_arreglos(struct Plato *arrPlatos, int cantPlatos, struct Distrito *arrDistritos,
                                     int cantDistritos, struct Cliente *arrClientes, int cantClientes);
void leer_un_cliente(struct Cliente &cliente, ifstream &input);
void leer_clientes(const char *nombre_archivo, struct Cliente *arrClientes, int &cantClientes);
void leer_un_distrito(struct Distrito &distritoDeLima, ifstream &input);
void leer_distritos(const char *nombre_archivo, struct Distrito *arrDistritos, int &cantDistritos);
void leer_un_plato_ofrecido(struct Plato &plato_ofrecido, ifstream &input);
void leer_platos_ofrecidos(const char *nombre_archivo, struct Plato *arrPlatos, int &cantPlatos);

#endif /* FUNCIONES_H */



