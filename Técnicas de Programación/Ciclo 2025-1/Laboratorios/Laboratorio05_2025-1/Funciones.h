

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 14 de mayo de 2025, 05:32 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulos(bool es_empresa,ofstream &output);
void imprimir_encabezados(bool es_empresa,ofstream &output);
void imprimir_cantidades_y_multas_de_una_empresa(int cant_faltas_leves,
                double total_multas_leves,int cant_faltas_graves,double total_multas_graves,
                int cant_faltas_muy_graves,double total_multas_muy_graves,int cant_faltas_totales,
                double total_multas,ofstream &output);
void imprimir_datos_de_una_infraccion(int cod_infraccion,char gravedad,
                double valor_multa,int cant_impuesta_por_infraccion,
                double monto_total_por_infraccion,ofstream &output);
void imprimir_gravedad(char gravedad,ofstream &output);
void imprimir_resumen_de_totales_de_infracciones(int total_de_cantidad,
                                                 double total_de_monto_total,ofstream &output);
void ignorar_hasta_delimitador(char delimitador,ifstream &input);
int leer_dato_tipo_int(ifstream &input);
double leer_dato_tipo_double(ifstream &input);
char leer_dato_tipo_char(ifstream &input);
void leer_placa(char &tipo_vehiculo,int &num_placa_1,
                int &num_placa_2,ifstream &input);
void leer_fecha(ifstream &input);
int buscar_posicion_dni_representante(char tipo_vehiculo_leido,
        int num_placa_1_leido,int num_placa_2_leido,int *arr_dni_placa,
        char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,
        int cant_vehiculos,int *arr_dni_representante,int cant_empresas);
int buscar_posicion_infracciones(char gravedad_leida,int cod_infraccion_leida,
                            char *arr_gravedad,int *arr_cod_infraccion,int cant_infracciones);
void intercambiar_int(int &dato_1,int &dato_2);
void intercambiar_double(double &dato_1,double &dato_2);
void intercambiar_char(char &dato_1,char &dato_2);
void imprimir_empresas(int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas,ofstream &output);
void imprimir_infracciones(int *arr_cod_infraccion,char *arr_gravedad,
            double *arr_valor_multa,int *arr_cant_impuesta_por_infraccion,
            double *arr_monto_total_por_infraccion,int cant_infracciones,ofstream &output);
void emitir_reporte(const char *nombre_archivo,int *arr_cod_infraccion,
            char *arr_gravedad,double *arr_valor_multa,
            int *arr_cant_impuesta_por_infraccion,double *arr_monto_total_por_infraccion,
            int cant_infracciones,int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas);
void ordenar_empresas(int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas);
void ordenar_infracciones(int *arr_cod_infraccion,char *arr_gravedad,double *arr_valor_multa,
            int *arr_cant_impuesta_por_infraccion,double *arr_monto_total_por_infraccion,
            int cant_infracciones);
void ordenar_datos(int *arr_cod_infraccion,char *arr_gravedad,double *arr_valor_multa,
            int *arr_cant_impuesta_por_infraccion,double *arr_monto_total_por_infraccion,
            int cant_infracciones,int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas);
void actualizar_cantidades_y_montos(char gravedad,double valor_multa,
             int &cant_impuesta_por_infraccion,double &arr_monto_total_por_infraccion,
             int &cant_faltas_leves_por_empresa,int &cant_faltas_graves_por_empresa,
             int &cant_faltas_muy_graves_por_empresa,int &cant_faltas_totales_por_empresa,
             double &total_multas_leves_por_empresa,double &total_multas_graves_por_empresa,
             double &total_multas_muy_graves_por_empresa,double &total_multas_totales_por_empresa);
void leer_infracciones_cometidas(const char *nombre_archivo,int *arr_cod_infraccion,
            char *arr_gravedad,double *arr_valor_multa,int *arr_cant_impuesta_por_infraccion,
            double *arr_monto_total_por_infraccion,int cant_infracciones,
            int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas,int *arr_dni_placa,
            char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,int cant_vehiculos);
void leer_placas_registradas(const char *nombre_archivo,int *arr_dni_placa,
        char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,int &cant_vehiculos);
void leer_empresas_registradas(const char *nombre_archivo,
                               int *arr_dni_representante,int &cant_empresas);
void leer_tabla_infracciones(const char *nombre_archivo,int *arr_cod_infraccion,
                             char *arr_gravedad,double *arr_valor_multa,int &cant_infracciones);

#endif /* FUNCIONES_H */
