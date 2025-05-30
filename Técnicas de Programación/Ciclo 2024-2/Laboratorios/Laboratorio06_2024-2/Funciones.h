

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de mayo de 2025, 10:25 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"
#include "FuncionesCadenas.h"

void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char leer_dato_char(ifstream &input);
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output);
void imprimir_titulo(bool es_prueba, ofstream &output);
void imprimir_encabezado(bool es_prueba, ofstream &output);
double leer_valor_del_descuento(ifstream &input);
double determinar_descuento(ifstream &input);
void leer_un_plato_ofrecido(int &cod_plato_leido, char *plato, double &precio, char *categoria,
                            double &descuento,ifstream &input, bool &fin_de_archivo);
int busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos);
void cambiar_guion_a_espacio_en_blanco(char *cadena);
void pasar_a_mayuscula_la_primera_palabra(char *cadena);
void colocar_la_categoria_al_nombre_del_plato(char *nombre_plato, const char *categoria_plato);
int buscar_caracter(char caracter, const char *cadena);
void insertar_cadena_en_medio_de_otra_cadena(char *cadena, const char *cadena_a_insertar);
void modificar_cadena(char *nombre_plato, const char *categoria_plato ,bool tiene_descuento);
void imprimir_un_plato_vendido(double &total_ingreso_bruto, double &total_ingreso_con_descuento,
                    int n_plato, int codigoPlatos, int numPlatosVendidos, double precio, double ingresoBruto,
                    bool tieneDescuento, double descuento, double total, char *plato_ofrecido,
                    char *categoria_plato,ofstream &output);
void imprimir_todos_los_platos(double &total_ingreso_bruto, double &total_ingreso_con_descuento,
                               int *arrCodigoPlatos, int *arrNumPlatosVendidos, double *arrPrecio,
                               double *arrIngresoBruto, bool *arrTieneDescuento, double *arrDescuento,
                               double *arrTotal, int cant_platos,ifstream &input, ofstream &output);
void imprimir_totales(double total_ingreso_bruto, double total_ingreso_con_descuento, ofstream &output);
void emitir_reporte(const char *nombre_archivo, int *arrCodigoPlatos, int *arrNumPlatosVendidos,
                    double *arrPrecio, double *arrIngresoBruto, double *arrDescuento,double *arrTotal,
                    bool *arrTieneDescuento, int cant_platos, ifstream &input);
void imprimir_juego_de_datos_reporte_prueba(int codigoPlatos,int numPlatosVendidos, double precio,
                        double ingresoBruto,double descuento, double total, bool tieneDescuento,ofstream &output);
void reportePrueba(const char *nombre_archivo, int *arrCodigoPlatos, int *arrNumPlatosVendidos,
                   double *arrPrecio, double *arrIngresoBruto, double *arrDescuento, double *arrTotal,
                   bool *arrTieneDescuento, int cant_platos);
void actualizar_cantidades(int numPlatosVendidos, double &precio, double &ingresoBruto,
                           double &descuento, double &total, bool &tieneDescuento,
                           double precio_asignado, double descuento_asignado);
void actualizar_cantidades_con_platos_ofrecidos(ifstream &input, int *arrCodigoPlatos,
                            int *arrNumPlatosVendidos, double *arrPrecio,double *arrIngresoBruto,
                            double *arrDescuento, double *arrTotal, bool *arrTieneDescuento, int cant_platos);
void insertar_dato_ordenando_descendentemente(int cod_plato, int cant_platos_vendidos,
                                              int *arrCodigoPlatos, int *arrNumPlatosVendidos, int &cant_platos);
void leer_lista_de_platos(int *arrCodigoPlatos, int *arrNumPlatosVendidos, int &cant_platos, ifstream &input);
void leer_repartos_a_realizar(const char *nombre_archivo, int *arrCodigoPlatos,
                              int *arrNumPlatosVendidos, int &cant_platos);

#endif /* FUNCIONES_H */
