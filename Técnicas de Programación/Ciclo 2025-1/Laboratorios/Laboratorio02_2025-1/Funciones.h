
/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de abril de 2025, 08:18 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input);
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_encabezado_vehiculos_infraccionados(ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_fecha(int fecha,ofstream &output);
void imprimir_tipo(char tipo,ofstream &output);
void imprimir_gravedad(char gravedad,ofstream &output);
void imprimir_descripcion(char tipo,int num_1_placa,int num_2_placa,
                          int fecha,int cod_infraccion,ofstream &output);
void imprimir_gravedad_multa_descripcion(bool imprimir_la_descripcion_de_la_infraccion,
        char gravedad,double multa,ofstream &output,ifstream &input);
int leer_fecha(ifstream &input);
void lectura_e_impresion_cadena_caracteres(bool esRepresentante,
        char delimitador,ifstream &input,ofstream &output);
void leer_e_imprimir_representante_legal(int n_representantes,int dni,
                                    ifstream &input,ofstream &output);
void leer_descripcion(char &tipo,int &num_1_placa,int &num_2_placa,int &fecha,
                      int &cod_infraccion,ifstream &input);
void actualizar_acumuladores_de_faltas(int &cant_leves,double &monto_pagado_leves,
        int &cant_graves,double &monto_pagado_graves,int &cant_muy_graves,
        double &monto_pagado_muy_graves,double multa,char gravedad);
void buscar_e_imprimir_infraccion(int cod_infraccion,ifstream &input,ofstream &output);
void procesar_descripcion_de_infracciones(int &cant_leves,double &monto_pagado_leves,
        int &cant_graves,double &monto_pagado_graves,int &cant_muy_graves,
        double &monto_pagado_muy_graves,ifstream &input_inf_com,
        ifstream &input_inf_transito,ofstream &output);
void imprimir_resumen_infracciones_por_representante_legal(int cant_leves,
        double monto_pagado_leves,int cant_graves,double monto_pagado_graves,
        int cant_muy_graves,double monto_pagado_muy_graves,ofstream &output);
void actualizar_totales_recaudados_por_infraccion(int cant_leves,
        double monto_pagado_leves,int cant_graves,double monto_pagado_graves,
        int cant_muy_graves,double monto_pagado_muy_graves,
        int &cant_total_faltas_leves,double &monto_total_del_total__faltas_leves,
        int &cant_total_faltas_graves,double &monto_total_del_total__faltas_graves,
        int &cant_total_faltas_muy_graves,
        double &monto_total_del_total_faltas_muy_graves);
void actualizar_mayor_y_menor_pago_por_infracciones(int &dni_mayor_pago,
        double &total_mayor_pago,int &dni_menor_pago,double &total_menor_pago,
        double pago_total,int dni_representante,ofstream &output);
void procesar_infracciones_cometidas(int &dni_mayor_pago,double &total_mayor_pago,
        int &dni_menor_pago,double &total_menor_pago,ifstream &input_inf_com,
        ifstream &input_inf_transito,ofstream &output,
        int &cant_total_faltas_leves,double &monto_total_del_total_faltas_leves,
        int &cant_total_faltas_graves,double &monto_total_del_total_faltas_graves,
        int &cant_total_faltas_muy_graves,double &monto_total_del_total_faltas_muy_graves);
void imprimir_total_recaudado_por_infracciones(int cant_total_faltas_leves,
        double monto_total_del_total__faltas_leves,int cant_total_faltas_graves,
        double monto_total_del_total__faltas_graves,int cant_total_faltas_muy_graves,
        double monto_total_del_total__faltas_muy_graves,ofstream &output);
void imprimir_compania_con_mayor_y_menor_pago_por_infracciones(int dni_mayor_pago,
        double total_mayor_pago,int dni_menor_pago,double total_menor_pago,
        ofstream &output);
void procesar_reporte(const char *nombre_archivo_infra_cometidas,
                      const char *nombre_archivo_infra_transito,
                      const char *nombre_archivo_reporte);

#endif /* FUNCIONES_H */
