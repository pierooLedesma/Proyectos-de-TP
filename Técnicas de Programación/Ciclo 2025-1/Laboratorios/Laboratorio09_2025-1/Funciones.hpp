

/* 
 * Archivo:   Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de junio del 2025, 01:12 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_int(ifstream &input, bool leer_caracter);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_operador_lectura);
struct Fecha leer_fecha(ifstream &input);
void imprimir_fecha(struct Fecha una_fecha, ofstream &output);
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_datos_de_la_empresa(int dni, char *nombre, char *distrito, char **arrPlacas, int numPlacas,
                                  int n_empresa_registrada,ofstream &output);
void imprimir_encabezado_infracciones(bool booleano_escogido, ofstream &output);
void imprimir_una_infraccion_cometida(int n_inf, struct Fecha fechaDeInfraccion, char *placa,
                                      char *codigoDeLaInfraccion, char *descripcion, double multa,
                                      struct Fecha fechaDePago, ofstream &output);
void imprimir_arreglo_infracciones(int &indice_infraccion, struct InfraccionCometida *infracciones,
                                   int cantidadDeInfracciones, bool booleano_escogido, ofstream &output);
void imprimir_infracciones_cometidas(struct InfraccionCometida *infracciones, int cantidadDeInfracciones,
                                     double totalPagado, double totalAdeudado, ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
int intercambiar_struct_Empresa(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2);
void ordenar_por_distrito(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void intercambiar_struct_inf_cometida(struct InfraccionCometida &dato_1, struct InfraccionCometida &dato_2);
void ordenar_inf_cometida(struct InfraccionCometida *infraccion, int cantidadDeInfracciones);
void ordenar_arreglos(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void sumar_montos_pagados_y_adeudados(double &totalPagado, double &totalAdeudado,
                                      struct InfraccionCometida *infraccion, int cantidadDeInfracciones);
void calcular_montos_totales_pagados_y_adeudados(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void leer_una_infraccion_cometida(struct Fecha &fechaInfraccion, char *&placa_leida,
                                  char *&cod_inf_leida, struct Fecha &fechaDePago, ifstream &input);
bool existe_placa(char *placa_buscada, char **arrPlacas, int numPlacas);
int buscar_placa(char *placa_buscada, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
int buscar_tabla_infraccion(char *cod_inf_leida, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInf);
void completar_campos_infracciones(struct InfraccionCometida *arrInfraccionesCometidas, int &cantInfracciones,
                                   struct Fecha fechaInfraccion, char *cod_inf_leida, struct Fecha fechaDePago,
                                   struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInf, char *placa_leida);
void procesar_infracciones_cometidas(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones,
                                     int cantTablaInf, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
int buscar_dni(int dni_buscado, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void procesar_placas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas);
void todo_a_mayusculas(char *cadena);
void leer_una_empresa_registrada(struct EmpresasRegistradas &una_empresa, ifstream &input);
void procesar_empresas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int &cantEmpresas);
void leer_una_infraccion_de_la_tabla_de_infracciones(struct TablaDeInfracciones &infraccion, ifstream &input);
void procesar_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones, int &cantTablaInf);

#endif /* FUNCIONES_HPP */



