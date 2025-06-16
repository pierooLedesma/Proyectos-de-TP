

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 15 de junio del 2025, 01:12 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura);
int leer_fecha(ifstream &input);
void imprimir_fecha(int fecha, ofstream &output);
void elaborar_lineas(char caracter, int cantidad_de_caracteres, ofstream &output);
void imprimir_titulo_de_empresas(bool es_reporte_de_prueba, ofstream &output);
void imprimir_encabezado_de_empresas(ofstream &output);
void imprimir_datos_de_una_empresa(int n_empresa, int dni, char *nombre, char *distrito, char *listaDePlacas,
                   int fechaInfraccionMasAntigua, int fechaPagoMasReciente, double totalPagadoLeve,
                   double totalPagadoGrave, double totalPagadoMuyGrave, int cantidadDeFaltas, ofstream &output);
void imprimir_datos_de_todas_las_empresas(int *arrDni, char **arrNombre,
                       char **arrDistrito, char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua,
                       int *arrFechaPagoMasReciente, double *arrTotalesPagado, int *arrCantidadDeFaltas,
                       int cant_empresas, ofstream &output, double &total_faltas_pagadas_leves,
                       double &total_faltas_pagadas_graves, double &total_faltas_pagadas_muy_graves,
                       int &cant_faltas_totales);
void imprimir_totales(double total_faltas_pagadas_leves, double total_faltas_pagadas_graves,
                      double total_faltas_pagadas_muy_graves, int cant_faltas_totales, ofstream &output);
void emitir_reporte(const char *nombre_archivo, int *arrDni, char **arrNombre, char **arrDistrito,
                    char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente,
                    double *arrTotalesPagado, int *arrCantidadDeFaltas, int cant_empresas, bool es_reporte_de_prueba);
void intercambiar_int(int &dato_1, int &dato_2);
void intercambiar_double(double &dato_1, double &dato_2);
void intercambiar_cadenas(char *&dato_1, char *&dato_2);
void ordenar_arreglos_de_empresas(int *arrDni, char **arrNombre, char **arrDistrito,
                                  char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente,
                                  double *arrTotalesPagado, int *arrCantidadDeFaltas, int cant_empresas);
void leer_una_infracciones_cometida(int &fecha_infraccion, char *&placa_leida, char *&cod_infraccion_leida,
                                    int &fecha_pagada, ifstream &input);
int buscar_infraccion(char *cod_infraccion_leida, char **arrCodigoInfraccion, int cant_infracciones);
double asignar_multa(char *cod_infraccion_leida, char **arrCodigoInfraccion,
                     double *arrValorMulta, int cant_infracciones);
int contar_placas(const char *listaDePlacas);
void seleccionar_placa_de_la_lista_de_placas(const char *listaDePlacas,
                int indice_inicial_escogido_de_lista_placas, int indice_final_escogido_de_lista_placas,
                char *placa_extraida);
void obtener_placa(const char *listaDePlacas, int n_placa, char *&placa_extraida);
bool verificaSiEstaLaPlaca(const char *listaDePlacas, char *placa);
int buscar_placa_de_una_empresa(char *placa_leida, char **arrListaDePlacas, int cant_empresas);
void actualizar_datos_de_la_empresa(int fecha_infraccion, int fecha_pagada, double multa,
                                    int &fechaInfraccionMasAntigua, int &fechaPagoMasReciente,
                                    double &total_pagado_leves, double &total_pagado_graves,
                                    double &total_pagado_muy_graves, int &cantidadDeFaltas, char *cod_infraccion_leida);
void leer_infracciones_cometidas(const char *nombre_archivo, char **arrListaDePlacas,
                               int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente, int *arrCantidadDeFaltas,
                               double *arrTotalesPagado, int cant_empresas, char **arrCodigoInfraccion,
                               double *arrValorMulta, int cant_infracciones);
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output);
void imprimir_las_infracciones(char **arrCodigoInfraccion, double *arrValorMulta,
                               int cant_infracciones, ofstream &output);
void verificar_los_datos_de_infracciones(const char *nombre_archivo, char **arrCodigoInfraccion,
                                         double *arrValorMulta, int cant_infracciones);
void leer_tabla_de_infracciones(const char *nombre_archivo, char **arrCodigoInfraccion,
                                double *arrValorMulta, int &cant_infracciones);
int buscar_empresa(int dni_leido, int *arrDni, int cant_empresas);
void leer_placas_registradas(const char *nombre_archivo, int *arrDni,
                             char **arrListaDePlacas, int cant_empresas);
void pasar_todo_a_mayusculas(char *cadena);
void leer_empresas_registradas(const char *nombre_archivo, int *arrDni, char **arrNombre, char **arrDistrito,
                               int *arrFechaInfraccionMasAntigua, int &cant_empresas);
void inicializar_el_arreglo_de_placas(char **arrListaDePlacas);

#endif /* FUNCIONES_H */



