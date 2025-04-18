

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 12 de abril de 2025, 08:11 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Utils.h"

void leer_y_procesar_citas_medicas();
void imprimir_encabezado(const char *titulo, const char *subtitulo);
bool leer_linea_de_citas_medicas(int &fecha,int &dni,int &tiempo_inicio,int &tiempo_final,double &tarifa,
                                 char &especialidad_medico,char &hay_medicina,double &monto_medicinas);
int leer_fecha();
int leer_tiempo();
void leer_si_se_recetaron_medicamentos(char &hay_medicina,double &monto_medicinas);
void imprimir_datos_de_cita_medica_leida(int fecha,int dni,int tiempo_inicio,int tiempo_final,double tarifa,
                                         char especialidad_medico,char hay_medicina,double monto_medicinas,
                                         double &total_ingresos,int &cant_pacientes);
void imprimir_fecha(int fecha);
void imprimir_tiempo(int tiempo,int num_para_restar);
void imprimir_especialidad(char especialidad_medico);
void imprimir_total_de_ingresos(double total_ingresos);
void actualizar_estadisticas(int fecha,int tiempo_inicio,int tiempo_final,double tarifa,char especialidad_medico,
        char hay_medicina,double monto_medicinas,int &cant_pacientes_con_medicinas,
        double &total_gasto_por_medicina_recetada,int &cant_pacientes_en_dermatologia,
        double &total_gasto_de_atencion_dermatologia,int &cant_pacientes_no_medicinas,
        int &cant_pacientes_en_pediatria,int &cant_pacientes_en_cardiologia_despues_15012024,
        int &cant_pacientes_no_medicinas_y_mas_de_350);
int es_despues_del_15012024(int fecha,char especialidad_medico);
int no_medicina_y_mayor_350(char hay_medicina,double tarifa);
void imprimir_estadisticas(int cant_pacientes_con_medicinas,double total_gasto_por_medicina_recetada,
        int cant_pacientes_en_dermatologia,double total_gasto_de_atencion_dermatologia,
        int cant_pacientes_no_medicinas,int cant_pacientes_en_pediatria,int cant_pacientes,
        int cant_pacientes_en_cardiologia_despues_15012024,int cant_pacientes_no_medicinas_y_mas_de_350);
void imprimir_primera_parte_de_estadisticas(double total_gasto_por_medicina_recetada,
                                            int cant_pacientes_con_medicinas,
                                            double total_gasto_de_atencion_dermatologia,
                                            int cant_pacientes_no_medicinas,int cant_pacientes);
void imprimir_segunda_parte_de_estadisticas(int cant_pacientes_en_pediatria,int cant_pacientes,
        int cant_pacientes_en_cardiologia_despues_15012024,int cant_pacientes_no_medicinas_y_mas_de_350);
void elaborar_lineas(char caracter,int cant_caracteres);

#endif /* FUNCIONES_H */
