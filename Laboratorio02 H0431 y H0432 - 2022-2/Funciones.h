

/* 
 * File:   Funciones.h
 * Author: Alessandro Piero Ledesma Guerra
 * Código: 20217340
 * Creado el 29 de marzo de 2025, 11:20 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void elaborarReporteSolicitado(const char *nombre_archivo_medicos_txt,
                               const char *nombre_archivo_pacientes_txt,
                               const char *nombre_archivo_citas_txt,
                               const char *nombre_archivo_reporte_txt);
void procesarMedicos(ifstream &archMedicos,ifstream &archCitas,ifstream &archPacientes,
                     ofstream &archReporte);
void procesarCitas(int codigo_del_medico,double tarifa,double &totalRecaudado,ifstream &archCitas,
                   ifstream &archPacientes,ofstream &archReporte);
void procesarPaciente(int dia,int mes,int anio,int dni_paciente,int hora_Inicio,int minuto_Inicio,int segundo_Inicio,
                      int hora_Fin,int minuto_Fin,int segundo_Fin,double tarifa,double &totalRecaudado,
                      ifstream &archPacientes,ofstream &archReporte,double &total_gasto_citas);
void impresionDelPacienteConSuCitaMedica(int dia,int mes,int anio,int dni_paciente,int hora_Inicio,
                                         int minuto_Inicio,int segundo_Inicio,int hora_Fin,int minuto_Fin,
                                         int segundo_Fin,double tarifa,double &totalRecaudado,
                                         ifstream &archPacientes,ofstream &archReporte,
                                         double &total_gasto_citas);
void imprimirNombre(ifstream &archLectura,bool esPaciente,int longitud_total_entre_nombre_y_espacios,
                    char caracter_de_finalizacion,ofstream &archReporte);

void elaborarEncabezados(int opcion,ofstream &archReporte);
void elaborarLineas(char caracter,int cantidad_de_lineas,ofstream &archReporte);

#endif /* FUNCIONES_H */

