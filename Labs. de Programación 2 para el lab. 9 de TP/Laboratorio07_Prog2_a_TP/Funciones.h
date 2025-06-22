

/* 
 * Archivo:   Funciones.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el  21 de junio del 2025, 12:23 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
char *asignar_cadena(const char *buffer);
char* obtener_ruta(const char *nombre_carpeta, const char *nombre_tipo_archivo, const char *nombre_zona);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char *leer_cadena(ifstream &input, char delimitador);
int leer_fecha(ifstream &input);
struct Fecha retornar_estructura_fecha(int fecha_dada_como_entero);
void imprimir_fecha(const struct Fecha fecha_proporcionada, ofstream &output);
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);
void imprimir_titulo(ofstream &output);
void imprimir_titulo_zona(char *zona, ofstream &output);
void imprimir_encabezado_drones(int opcion_drone, ofstream &output);
void imprimir_encabezado_infracciones(ofstream &output);
void imprimir_dato_de_un_drone(int n_drone, const struct Drone un_drone, ofstream &output);
void imprimir_infracciones(const struct Infraccion *infracciones, int cantidad_infracciones, ofstream &output);
void imprimir_dato_de_un_drone(int n_drone, const struct Drone *un_drone, ofstream &output);
void imprimir_drones_velocidad(const struct DroneDeVelocidad *drones_velocidad, int n_drones, ofstream &output) ;
void imprimir_drones_semaforo(const struct DroneSemaforo *drones_semaforo, int n_drones, ofstream &output);
void imprimir_drones_estacionamiento(const struct DroneEstacionamiento *drones_estacionamiento, int n_drones, ofstream &output);
void imprimir_totales_de_la_zona(int cantidad_multas_registradas, double total_multas_acumuladas, ofstream &output);
void emitir_reporte(const char *nombre_archivo, const struct Zona *arrZonas, int cantidad_zonas);
void leer_un_evento_de_la_zona(char *&id_leido, char *&placa, int &fecha_infraccion, int &aviso_observado, ifstream &input);
bool encontrar_drone_velocidad(char *id_leido, const struct DroneDeVelocidad *drones_velocidad,
                                                          int n_drones_velocidad, int &indice_a_retornar);
bool encontrar_drone_semaforo(char *id_leido, const struct DroneSemaforo *drones_semaforo,
                                                         int n_drones_semaforo, int &indice_a_retornar);
bool encontrar_drone_estacionamiento(char *id_leido, const struct DroneEstacionamiento *drones_estacionamiento,
                                                                      int n_drones_estacionamiento, int &indice_a_retornar);
void actualizar_infracciones(struct Infraccion *infracciones, int &cantidad_infracciones, char *placa, 
                                                 int fecha_infraccion, int aviso_observado, int aviso_permitido,
                                                 int &cantidad_multas_registradas, double &total_multas_acumuladas);
void procesar_eventos_de_una_zona(struct DroneDeVelocidad *drones_velocidad,
                                int n_drones_velocidad, struct DroneSemaforo *drones_semaforo, int n_drones_semaforo,
                                struct DroneEstacionamiento *drones_estacionamiento, int n_drones_estacionamiento,
                                int &cantidad_multas_registradas, double &total_multas_acumuladas, ifstream &input);
void procesar_eventos(const char *nombre_carpeta, struct Zona *arrZonas, int cantidad_zonas);
void leer_datos_de_un_drone(char *&tipo_de_drone, char *&id, char *&ubicacion,
                                                     int &capacidad_de_almacenamiento, int &aviso, ifstream &input);
void completar_campo_estructura_drone(struct Drone &un_drone, char *id, char *ubicacion, int capacidad);
void cargar_datos_de_un_drone(struct DroneDeVelocidad *drones_velocidad, int &n_drones_velocidad,
                                                         struct DroneSemaforo *drones_semaforo, int &n_drones_semaforo,
                                                         struct DroneEstacionamiento *drones_estacionamiento, int &n_drones_estacionamiento,ifstream &input);
void procesar_drones(const char *nombre_carpeta, struct Zona *arrZonas, int cantidad_zonas);
void pasar_todo_a_mayusculas(char *cadena);
void procesar_zonas(const char *ruta_de_archivo, struct Zona *&arrZonas, int &cantidad_zonas);

#endif /* FUNCIONES_H */


