
/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 24 de abril de 2025, 10:48 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_encabezados(int opcion,ofstream &output);
void procesar_reporte(const char *nombre_archivo_medicos,
                      const char *nombre_archivo_citas,
                      const char *nombre_archivo_medicinas,
                      const char *nombre_archivo_reporte);
void imprimir_resumen(int cod_medico_aporto_mas,
        double total_ingresado_por_el_medico,ifstream &input,ofstream &output);
void procesar_medicos(ifstream &input_medicos,ifstream &input_citas,
                      ifstream &input_medicinas,ofstream &output,int &cod_medico_aporto_mas,
                      double &total_ingresado_por_el_medico);
void procesar_citas_medicas(double tarifa,int codigo_medico,double &monto_total_generado_por_el_medico,
                            ifstream &input_citas,ifstream &input_medicinas,ofstream &output);
void leer_cita_medica_hasta_codigo_medico(int &dni_paciente,double &porcentaje_descuento_cliente,
        int &tiempo_inicial,int &tiempo_final,int &cod_medico_que_atendio,double &pago_por_cita,
        double tarifa,ifstream &input_citas);
void leer_cita_medica_hasta_codigo_medico(int &dni_paciente,double &porcentaje_decuento_cliente,
        int &tiempo_inicial,int &tiempo_final,int &cod_medico_que_atendio,ifstream &input_citas);
void leer_and_imprimir_datos_medico(int codigo_medico,ifstream &input_medicos,ofstream &output);
void leer_e_imprimir_tarifa_del_medico(double &tarifa,ifstream &input,ofstream &output);
void imprimir_datos_paciente(int fecha,int dni_paciente,int tiempo_inicial,int tiempo_final,
                             double porcentaje_descuento_cliente,double pago_por_cita,ofstream &output);
void procesar_lista_de_medicinas(double &pago_total_por_medicinas,ifstream &input_citas,
                                 ifstream &input_medicinas,ofstream &output);
void imprimir_medicina(int codigo_medicina,int cantidad,int &cant_medicinas,
                       double &pago_total_por_medicinas,ifstream &input,ofstream &output);
void imprimir_resumen_de_una_cita(double pago_total_por_medicinas,
                                  double monto_total_generado_por_el_medico,ofstream &output);
void imprimir_cadena_caracteres(bool es_medicina,bool es_nombre_medico,
                                char delimitador,ifstream &input,ofstream &output);
int leer_fecha(ifstream &input);
void imprimir_fecha(int fecha,ofstream &output);
int leer_tiempo(ifstream &input);
void imprimir_tiempo(int tiempo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracter,ofstream &output);

#endif /* FUNCIONES_H */
