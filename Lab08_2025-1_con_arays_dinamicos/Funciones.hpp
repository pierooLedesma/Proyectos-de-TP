

/* 
 * Archivo:   Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 23 de junio del 2025, 10:32 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escriura(const char *nombre_archivo, ofstream &output);
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_operador_lectura);
struct Fecha leer_fecha(ifstream &input);
void imprimir_fecha(struct Fecha fecha, ofstream &output);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
void imprimir_titulo_y_encabezado_de_empresas(ofstream &output);
void imprimir_placas(char **arrPlacas, int numPlacas, ofstream &output);
void imprimir_datos_de_una_empresa(int n_empresa, struct EmpresasRegistradas &una_empresa, ofstream &output);
void imprimir_empresas(struct EmpresasRegistradas *arrEmpresas, int cantEmpresas, ofstream &output);
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output);
void imprimir_infracciones(struct TablaDeInfracciones *arrInfracciones, int cantInfracciones, ofstream &output);
void emitir_reporte(const char *nombre_archivo, struct TablaDeInfracciones *arrInfracciones,
                    int cantInfracciones, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
void intercambiar_struct_infracciones(struct TablaDeInfracciones &dato_1, struct TablaDeInfracciones &dato_2);
void ordenar_infracciones(struct TablaDeInfracciones *arrInfracciones, int cantInfracciones);
void intercambiar_struct_empresas(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2);
void ordenar_empresas(struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
void leer_una_infraccion_cometida(struct Fecha &fechaInfraccion, char *&placa_leida,
                                  char *&cod_infraccion_leida, struct Fecha &fechaDePago, ifstream &input);
bool existe_placa(char *placa_buscada, char **arrPlacas, int num_placas);
int buscar_placa(char *placa_buscada, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
int buscar_infraccion(char *cod_infraccion_leida, struct TablaDeInfracciones *arrInfracciones, int cantInfracciones);
double asignar_multa(char *cod_infraccion_leida, struct TablaDeInfracciones *arrInfracciones, int cantInfracciones);
void actualizar_datos_de_una_empresa(struct EmpresasRegistradas &una_empresa, struct Fecha fechaInfraccion,
                                     struct Fecha fechaDePago, double multa);
void procesar_infracciones_cometidas(const char *nombre_archivo, struct TablaDeInfracciones *arrInfracciones,
                                     int cantInfracciones, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
int buscar_dni(int dni_buscado, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
void procesar_placas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas);
void todo_a_mayusculas(char *cadena);
void inicializar_struct_fecha(struct Fecha &fecha, bool es_de_pago);
void leer_una_empresa_registrada(struct EmpresasRegistradas &una_empresa, ifstream &input);
void procesar_empresas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *&arrEmpresas, int &cantEmpresas);
void leer_una_infraccion_de_la_tabla_de_infracciones(struct TablaDeInfracciones &una_infraccion, ifstream &input);
void procesar_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *&arrInfracciones, int &cantInfracciones);

#endif /* FUNCIONES_HPP */


