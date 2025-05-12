

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 11 de mayo de 2025, 01:05 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output);
void imprimir_titulo(bool es_para_medicos,ofstream &output);
void imprimir_encabezado_medico(ofstream &output);
void leer_fecha(ifstream &input);
int leer_tiempo(ifstream &input);
int leer_dato_tipo_int(ifstream &input);
double leer_dato_tipo_double(ifstream &input);
char leer_dato_tipo_char(ifstream &input);
void ignorar_hasta_delimitador(char delimitador,bool es_nombre_medico,ifstream &input);
void eliminar_datos_de_un_arreglo(int indice_de_datos_a_eliminar,
                        int *arr_codigo_medico,double *arr_tarifa_medico,int &cant_medicos,
                        double *arr_ingresos_por_medico,int *arr_totales_clientes);
void eliminar_datos(int *arr_codigo_medico,double *arr_tarifa_medico,int &cant_medicos,
                    double *arr_ingresos_por_medico,int *arr_totales_clientes);
void imprimir_juego_de_datos_de_un_medico(int codigo_medico,double tarifa_medico,
        double ingresos_por_cita_de_un_medico,double ingresos_por_medicamentos_por_medicos,
        double total_ingresado,int pacientes_atendidos_con_medicina_por_medico,
        int pacientes_atendidos_sin_medicina_por_medico,int total_pacientes_por_medico,
        int indice,ofstream &output);
void actualizar_montos_y_totales_del_registro_de_medicos(double &total_ingreso_citas,
                    double &total_ingreso_medicamentos,double &total_del_total_ingresado,
                    int &total_pacientes_con_medicinas,int &total_pacientes_sin_medicinas,
                    int &total_del_total_pacientes,double ingresos_por_cita_de_un_medico,
                    double ingresos_por_medicamentos_por_medicos,double total_ingresado,
                    int pacientes_atendidos_con_medicina_por_medico,
                    int pacientes_atendidos_sin_medicina_por_medico,int total_pacientes_por_medico);
void imprimir_totales_del_registro_de_medicos(double total_ingreso_citas,
            double total_ingreso_medicamentos,double total_del_total_ingresado,
            int total_pacientes_con_medicinas,int total_pacientes_sin_medicinas,
            int total_del_total_pacientes,ofstream &output);
void imprimir_registro_de_medicos(ofstream &output,int *arr_codigo_medico,
        double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
        int *arr_totales_clientes);
void imprimir_juego_de_datos_de_una_medicina(int indice,int codigo_medicina,
        double precio_medicina,int cant_unidades_vendidas,
        double ingresos_sin_descuentos_por_medicamento,
        double descuentos_por_los_seguros_por_medicamento,double total_ingresado,ofstream &output);
void actualizar_montos_y_totales_del_registro_de_medicinas(int &total_cant_unidades,
        double &total_ingreso_sin_descuento,double &total_ingreso_con_descuento,
        double &total_del_total_ingresado,double ingresos_sin_descuentos_por_medicamento,
        double descuentos_por_los_seguros_por_medicamento,double total_ingresado,
        int cant_unidades_vendidas);
void imprimir_totales_del_registro_de_medicos(int total_cant_unidades,
        double total_ingreso_sin_descuento,double total_ingreso_con_descuento,
        double total_del_total_ingresado,ofstream &output);
void imprimir_registro_de_medicinas(int *arr_codigo_medicina,double *arr_precio_medicina,
        int cant_medicinas,int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,
        ofstream &output);
void elaborar_reporte(const char *nombre_archivo,int *arr_codigo_medico,
        double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
        int *arr_totales_clientes,int *arr_codigo_medicina,double *arr_precio_medicina,int cant_medicinas,
        int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,bool imprimir_medicinas);
int buscar_dato_tipo_int_en_un_arreglo(int dato,int *arreglo,int cant_datos);
void leer_datos_fijos_de_CitasMedicas(double &porcentaje_descuento_cliente,int &tiempo_inicio,
                                      int &tiempo_fin,int &codigo_medico_leido,ifstream &input);
void procesar_lista_de_medicamentos(double tarifa_medico,double &ingreso_por_las_citas,
        double &ingreso_por_los_medicamentos,int &cant_pacientes_con_medicinas,
        int &cant_pacientes_sin_medicinas,int *arr_codigo_medicina,double *arr_precio_medicina,
        int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,int cant_medicinas,
        ifstream &input,double porcentaje_descuento_cliente,int duracion_en_segundos);
void actualizar_totales_medicinas_y_de_medicos(int *arr_totales_clientes,
                                           double *arr_ingresos_por_medico,int cant_medicos,
                                           double *arr_montos_por_medicamento,int cant_medicinas);
void actualizar_montos_y_totales(const char *nombre_archivo,int *arr_codigo_medico,
                   double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
                   int *arr_totales_clientes,int *arr_codigo_medicina,double *arr_precio_medicina,
                   int cant_medicinas,int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento);
void imprimir_datos_arreglo_para_reporte_prueba(int *arr_codigos,
                              double *arr_precios,int cant_datos,ofstream &output);
void elaborar_reporte_prueba(const char *nombre_archivo,int *arr_codigo_medico,
                            double *arr_tarifa_medico,int cant_medicos,int *arr_codigo_medicina,
                            double *arr_precio_medicina,int cant_medicinas);
void procesarMedicinas(const char *nombre_archivo,int *arr_codigo_medicina,
                       double *arr_precio_medicina,int &cant_medicinas);
void procesarMedicos(const char *nombre_archivo,int *arr_codigo_medico,
                     double *arr_tarifa_medico,int &cant_medicos);

#endif /* FUNCIONES_H */
