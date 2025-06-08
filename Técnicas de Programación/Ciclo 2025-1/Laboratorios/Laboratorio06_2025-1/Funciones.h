

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de junio del 2025, 10:44 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"
#include "FuncionesCadenas.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
int leer_fecha(ifstream &input);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
void imprimir_fecha(int fecha, ofstream &output);
void imprimir_titulo(bool es_de_prueba, ofstream &output);
bool busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos, int &indice_buscado);
void imprimir_encabezado_del_reporte_solicitado(ofstream &output);
int contar_placas(const char *listaDePlacas);
void copiar_placa_de_la_lista_de_placas(const char *listaDePlacas, int indice_inicial, int indice_final, char *placa);
void obtenerPlaca(const char *listaDePlacas, int n, char *placa);
void agregarPlaca(char *listaDePlacas, const char *placa);
void obtener_lista_de_placas(int dni, char *listaDePlacas, ifstream &input);
void imprimir_un_juego_de_datos_de_un_representante_legal(int n_representante, int dni,
                            int fecha_masMultaAntigua, int fecha_ultimaPendiente, double totalMultas,
                            double totalPagadas, double totalPendientes, ifstream &input, ofstream &output);
void imprimir_listado_de_infracciones(double &total_de_total_multas, double &total_de_multas_pagadas,
                           double &total_de_multas_pendientes, int *arrDni, int *arrMasMultaAntigua,
                           int *arrUltimaPendiente, double *arrTotalMultas, double *arrTotalPagadas,
                           double *arrTotalPendientes, int cant_representantes, ofstream &output, ifstream &input);
void imprimir_totales_del_listado_de_infracciones(double total_de_total_multas,
                           double total_de_multas_pagadas, double total_de_multas_pendientes, ofstream &output);
void emitir_reporte(const char *nombre_archivo_reporte, int *arrDni, int *arrMasMultaAntigua,
                    int *arrUltimaPendiente, double *arrTotalMultas, double *arrTotalPagadas,
                    double *arrTotalPendientes, int cant_representantes,
                    const char *nombre_archivo_placas_registradas);
bool leer_una_infraccion_cometida(ifstream &input, int &fecha_infraccion, char *placa, int &dni,
                                  int &cod_infraccion, int &fecha_pago);
void desplazar_valores_en_los_arreglos(int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                                       double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                                       int &cant_representantes, int ind_buscado);
void insertar_o_acumular_representante_legal(int fecha_infraccion, int dni, int cod_infraccion,
                                int fecha_pago, int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                                double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                                int &cant_representantes, double valor_multa);
void leer_infracciones_cometidas(const char *nombre_archivo_infracciones_cometidas,
                                 int *arrCodInfraccion, double *arrMultasInfraccion, int cant_infracciones,
                                 int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                                 double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                                 int &cant_representantes, const char *nombre_archivo_placas_registradas);
void imprimir_encabezado_de_reporte_de_prueba(ofstream &output);
void verificar_datos_de_infracciones(const char *nombre_archivo, int *arrCodInfraccion,
                                     double *arrMultasInfraccion, int &cant_infracciones);
void insertar_ascendentemente_por_codigo_de_infraccion(int cod_infraccion, double valor_multa,
                                    int *arrCodInfraccion, double *arrMultasInfraccion, int &cant_infracciones);
void leer_tabla_de_infracciones(const char *nombre_archivo, int *arrCodInfraccion,
                                double *arrMultasInfraccion, int &cant_infracciones);

#endif /* FUNCIONES_H */

