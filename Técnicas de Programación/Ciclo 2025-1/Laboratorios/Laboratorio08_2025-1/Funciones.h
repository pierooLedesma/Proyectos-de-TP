

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 20 de junio del 2025, 02:26 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
char* asignar_cadena(const char *buffer);
char* leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura);
int leer_fecha(ifstream &input);
struct Fecha retornar_estructura_fecha(int fecha_dada_como_entero);
void imprimir_fecha(struct Fecha fecha, ofstream &output);
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output);
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output);
void imprimr_datos_de_una_infraccion(char *codigo_infraccion, double multa_infraccion,
                                     char *descripcion_infraccion, ofstream &output);
void imprimir_infracciones(const struct TablaDeInfracciones *arrTablaDeInfracciones,
                           int cantTablaInfracciones, ofstream &output);
void imprimir_titulo_y_encabezado_de_empresas(ofstream &output);
void imprimir_placas(char **arrPlacas, int numPlacas, ofstream &output);
void imprimir_datos_de_una_empresa(int n_empresa, struct EmpresasRegistradas &una_empresa, ofstream &output);
void imprimir_empresas_registradas(struct EmpresasRegistradas *arrEmpresasRegistradas,
                                   int cantEmpresasRegistradas,ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                    int cantEmpresasRegistradas, const struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones);
void intercambiar_struct_infracciones(struct TablaDeInfracciones &dato_1, struct TablaDeInfracciones &dato_2);
void ordenar_infracciones(struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones);
void intercambiar_empresas(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2);
void ordenar_empresas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas);
void leer_una_infraccion_cometida(int &fecha_infraccion, char *&placa_leida, char *&cod_infraccion_leida, int &fecha_pagada, ifstream &input);
int buscar_infraccion(char *cod_infraccion_leida, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones);
double asignar_valor_multa(char *cod_infraccion_leida, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones);
bool existe_placa(char *placa_leida, char **arrPlacas, int numPlacas);
int buscar_placa_de_una_empresa(char *placa_leida, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas);
void actualizar_los_campos_restantes_de_una_empresa(struct Fecha &fechaDeInfraccion, int fecha_infraccion,int fecha_pagada,
                                struct Fecha &fechaDePago, int &cantidadDeFaltas, double &totalPagado, double &totalAdeudado, double valor_multa);
void leer_infracciones_cometidas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                                 int cantEmpresasRegistradas, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones);
int buscar_empresa(int dni_leido, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas);
void leer_placas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas);
void todo_a_mayuscula(char *cadena);
void leer_una_empresa_registrada(struct EmpresasRegistradas &unaEmpresa, ifstream &input);
void leer_empresas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int &cantEmpresasRegistradas);
void leer_una_infraccion(struct TablaDeInfracciones &unaInfraccion, ifstream &input);
void leer_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones,int &cantTablaInfracciones);

#endif /* FUNCIONES_H */
