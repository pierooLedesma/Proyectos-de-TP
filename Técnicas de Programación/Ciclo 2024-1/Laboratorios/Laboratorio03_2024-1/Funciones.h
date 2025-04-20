

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 19 de abril de 2025, 06:44 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *arch_nombre,ifstream &input);
void aperturar_archivo_escritura(const char *arch_nombre,ofstream &output);
void procesar_reporte(const char *arch_nombre_citas,const char *arch_nombre_medicos,
                      const char *arch_nombre_reporte);
void imprimir_titulo_y_encabezados(ofstream &output);
void procesar_citas(ifstream &input_citas,ifstream &input_medicos,ofstream &output,
        double &monto_paciente_mas_gasto_ha_realizado,int &dni_paciente_mas_gasto_ha_realizado);
void leer_datos_paciente(int &dni_paciente,double &porcentaje_descuento_paciente,int &tiempo_inicial,
        int &tiempo_final,int &cod_medico_citas,double &monto_pagado_por_los_medicamentos,
        ifstream &input_citas,ofstream &output);
void imprimir_datos_paciente(int fecha,int dni_paciente,int tiempo_inicial,int tiempo_final,
        double porcentaje_descuento_paciente,ofstream &output);
void procesar_medico(double porcentaje_descuento_paciente,int cod_medico_citas,
        double monto_pagado_por_los_medicamentos,ifstream &input_medicos,ofstream &output,
        int tiempo_final,int tiempo_inicial,double &pago);
void leer_nombre_y_especialidad_e_imprimir_datos_del_medico(double &pago,int tiempo_inicial,
        int tiempo_final,double porcentaje_descuento_paciente,double monto_pagado_por_los_medicamentos,
        ifstream &input_medicos,ofstream &output);
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_especialidad,
        int tam_cadena_caracteres_y_espacios_en_blanco);
void cambiar_caracter(bool es_especialidad,bool &es_mayuscula,char &caracter);
int leer_fecha(ifstream &input);
void imprimir_fecha(int fecha,ofstream &output);
int leer_tiempo(ifstream &input);
void imprimir_tiempo(int tiempo,ofstream &output);
void imprimir_total_ingresos(double total_ingresos,ofstream &output);
void imprimir_paciente_que_mas_gasto(int dni_paciente_mas_gasto_ha_realizado,
        double monto_paciente_mas_gasto_ha_realizado,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);

#endif /* FUNCIONES_H */
