

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 7 de mayo de 2025, 06:41 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void imprimir_titulo(ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_placa_del_vehiculo(char tipo_de_vehiculo,int num_placa_1,
                                 int num_placa_2,ofstream &output);
void imprimir_tipo_de_vehiculo(char tipo_de_vehiculo,ofstream &output);
void imprimir_encabezado_vehiculos_infraccionados(ofstream &output);
void imprimir_fecha(int fecha,ofstream &output);
void leer_placa_del_vehiculo(char &tipo_de_vehiculo,int &num_placa_1,
                             int &num_placa_2,ifstream &input);
int leer_fecha(ifstream &input);
void imprimir_gravedad(char gravedad,ofstream &output);
char convertir_a_mayuscula(char c);
char capitalizar_si_es_necesario(char c, bool &mayuscula);
void leer_e_imprimir_cadena_de_caracteres(bool ninguna_modificacion_en_la_cadena,
        bool es_nombre_representante_legal,char delimitador,bool imprimir_espacio_en_blanco,
        ifstream &input,ofstream &output);
void imprimir_datos_del_representante_legal(int &n_compania,int dni_representante_legal,
                                            ifstream &input_empresas,ofstream &output);
void imprimir_infraccion_de_transito(char gravedad,double multa,bool imprimir_descripcion,
                                     ifstream &input_tabla,ofstream &output);
void actualizar_acumuladores_de_faltas(int &cant_faltas_leves,
                    double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                    double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                    double &monto_pagado_faltas_muy_graves,double multa,char gravedad);
void imprimir_descripcion_infraccion_de_transito(char gravedad,int num_infraccion,
                        ifstream &input_tabla,ofstream &output,int &cant_faltas_leves,
                        double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                        double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                        double &monto_pagado_faltas_muy_graves);
void imprimir_caracteristica_de_la_infraccion(int &cant_infracciones,int fecha,
        int num_infraccion,char gravedad,ifstream &input_tabla,ofstream &output,int &cant_faltas_leves,
        double &monto_pagado_faltas_leves,int &cant_faltas_graves,double &monto_pagado_faltas_graves,
        int &cant_faltas_muy_graves,double &monto_pagado_faltas_muy_graves);
void procesar_infracciones_cometidas(char tipo_de_vehiculo,int num_placa_1,int num_placa_2,
                        int &cant_faltas_leves,double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                        double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                        double &monto_pagado_faltas_muy_graves,ifstream &input_infracciones,
                        ifstream &input_tabla,ofstream &output);
void procesar_placas_de_vehiculos_de_la_empresa(int &cant_faltas_leves,                        
                        double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                        double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                        double &monto_pagado_faltas_muy_graves,ifstream &input_empresas,
                        ifstream &input_infracciones,ifstream &input_tabla,ofstream &output);
void imprimir_resumen_de_faltas_de_una_empresa(int cant_faltas_leves,
                        double monto_pagado_faltas_leves,int cant_faltas_graves,
                        double monto_pagado_faltas_graves,int cant_faltas_muy_graves,
                        double monto_pagado_faltas_muy_graves,ofstream &output);
void actualizar_compania_con_mayor_y_menor_pago(int &dni_mayor_pago,
        double &mayor_total_pago,int &dni_menor_pago,double &menor_total_pago,
        int dni_representante_legal,double pago_total);
void procesar_empresas(int &dni_mayor_pago,double &mayor_total_pago,int &dni_menor_pago,
        double &menor_total_pago,ifstream &input_empresas,ifstream &input_infracciones,
        ifstream &input_tabla,ofstream &output);
void imprimir_compania_con_mayor_y_menor_pago_por_infracciones(int dni_mayor_pago,
        double mayor_total_pago,int dni_menor_pago,double menor_total_pago,
        ofstream &output);
void elaborar_reporte(const char *nombre_archivo_empresas,
                      const char *nombre_archivo_infracciones,
                      const char *nombre_archivo_tabla,
                      const char *nombre_archivo_reporte);

#endif /* FUNCIONES_H */
