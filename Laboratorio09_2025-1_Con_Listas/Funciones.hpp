

/* 
 * Archivo:   Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 28 de junio del 2025, 01:37 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura);
struct Fecha leer_fecha(ifstream &input);
void imprimir_fecha(struct Fecha una_fecha, ofstream &output);
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_datos_de_la_empresa(int dni, char *nombre, char *distrito, char **placas, int numPlacas,
                                  int n_empresa_registrada,ofstream &output);
void imprimir_encabezado_infracciones(bool booleano_escogido, ofstream &output);
void imprimir_una_infraccion_cometida(int n_inf, struct Fecha fechaDeInfraccion, char *placa,
                                      char *codigoDeLaInfraccion, char *descripcion, double multa,
                                      struct Fecha fechaDePago, ofstream &output);
void imprimir_arreglo_infracciones(int &indice_infraccion, struct InfraccionCometida *infracciones,
                                   int cantidadDeInfracciones, bool booleano_escogido, ofstream &output);
void imprimir_infracciones_cometidas(struct InfraccionCometida *infracciones, int cantidadDeInfracciones,
                                     double totalPagado, double totalAdeudado, ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
void intercambiar_struct_infraccion_cometida(struct InfraccionCometida &infraccion_1, struct InfraccionCometida &infraccion_2);
void ordenar_infracciones(struct InfraccionCometida *infracciones, int cantidadDeInfracciones);
void ordenar_infracciones_para_cada_empresa(struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
void actualizar_totalPagado_y_totalAdeudado_de_una_empresa(struct InfraccionCometida *infracciones,
                                    int cantidadDeInfracciones, double &totalPagado, double &totalAdeudado);
void calcular_totales_pagados_y_adeudados(struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
void leer_una_infraccion_cometida(struct Fecha &fechaDeInfraccion, char *&placa_leida, char *&codInfraccion_leida,
                                  struct Fecha &fechaDePago, ifstream &input);
bool existe_placa(char *placa_buscada, char **arrPlacas, int numPlacas);
struct NodoEmpresasRegistradas *buscar_placa(char *placa_buscada, struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
struct NodoTablaDeInfracciones *buscarTablaInfraccion(char *codInfraccion_leida, struct NodoTablaDeInfracciones *listaTablaDeInfraciones);
void completar_campos_de_infraccion_cometida(struct Fecha fechaDeInfraccion, struct Fecha fechaDePago,
                                    char *codInfraccion_leida, struct NodoTablaDeInfracciones *listaTablaDeInfraciones,
                                    struct InfraccionCometida *arrInfracciones, int &cantidadDeInfracciones, char *placa_leida);
void procesarInfraccionesCometidas(const char *nombre_archivo, struct NodoTablaDeInfracciones *listaTablaDeInfraciones,
                                   struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
struct NodoEmpresasRegistradas *buscar_empresa_registrada(int dni_leido, struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
void procesarPlacasRegistradas(const char *nombre_archivo, struct NodoEmpresasRegistradas *listaEmpresasRegistradas);
void todo_a_mayusculas(char *cadena);
void leer_una_empresa(int &dni, char *&nombre, char *&distrito, ifstream &input);
void asignar_datos_empresa(int dni, char *nombre, char *distrito, struct EmpresasRegistradas &empresa);
void insertar_ordenado_lista_empresas(int dni, char *nombre, char *distrito, struct NodoEmpresasRegistradas *&listaEmpresasRegistradas);
void procesarEmpresasRegistradas(const char *nombre_archivo, struct NodoEmpresasRegistradas *&listaEmpresasRegistradas);
void leer_una_linea_de_tabla_de_infracciones(char *&codInfraccion, double &multa, char *&descripcion, ifstream &input);
void insertar_nuevo_nodo_tabla_de_infracciones(char *codInfraccion, double multa, char *descripcion,
                                               struct NodoTablaDeInfracciones *&listaTablaDeInfraciones);
void procesarTablaDeInfracciones(const char *nombre_archivo, struct NodoTablaDeInfracciones *&listaTablaDeInfraciones);

#endif /* FUNCIONES_HPP */
