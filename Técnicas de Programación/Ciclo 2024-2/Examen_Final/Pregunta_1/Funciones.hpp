

/* 
 * Archivo:   Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de julio del 2025, 10:31 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char *asignar_cadena(const char *buffer);
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura);
int leer_tiempo(ifstream &input);
void imprimir_tiempo(int tiempo, ofstream &output);
void todo_a_mayusculas(char *cadena);
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);
void procesar_lexicon(const char *nombre_archivo, struct Palabra *lexicon, int &cantPlabrasEnLexicon);
void procesar_platos(const char *nombre_archivo, struct Plato *platos, int &cantPlatos);
void procesar_atenciones(const char *nombre_archivo, struct Atencion *atenciones,
                         int &cantAtenciones, struct Plato *platos, int cantPlatos);
int buscar_plato(char *codigo_del_plato_leido, struct Plato *platos, int cantPlatos);
void leer_platos_atendidos(struct Plato *platos_atendidos, int &cantidad_platos_atendidos,
                           struct Plato *platos, int cantPlatos, ifstream &input);
void procesar_comentarios(const char *nombre_archivo, struct Atencion *atenciones,
                          int cantAtenciones, struct Palabra *lexicon, int cantPlabrasEnLexicon);
int buscar_atencion(int numero_de_atencion_leida, struct Atencion *atenciones, int cantAtenciones);
void procesamiento_de_un_comentario(struct Comentario &comentario, const char *comentario_leido,
                                    struct Palabra *lexicon, int cantPlabrasEnLexicon);
void pre_procesar_el_comentario(const char *comentario, char *&comentario_pre_procesado);
void procesar_el_comentario(const char *comentario_pre_procesado, struct Palabra *palabras,
                            int &cantidad_palabras, struct Palabra *lexicon, int cantPlabrasEnLexicon);
int contar_palabras(const char *comentario);
void extraer_palabra(const char *comentario, int n_palabra, char *&palabra_extraida);
int buscar_inicio_de_la_palabra(int n_palabra, const char *comentario);
int buscar_indice_final(int n_palabra, int indice_inicial, const char *comentario);
void copiar_palabra(const char *comentario, int indice_inicial, int indice_final, char *&palabra_extraida);
int buscar_lexicon(const char *palabra_extraida, struct Palabra *lexicon, int cantPlabrasEnLexicon);
void calcular_polaridad_total(struct Palabra *palabras, int cantidad_palabras, int &polaridad_total);
void emitir_reporte(const char *nombre_archivo, struct Atencion *atenciones, int cantAtenciones);
void imprimir_titulo(ofstream &output);
void imprimir_numero_y_hora_de_la_atencion(int numero_de_atencion, int hora_atencion, ofstream &output);
void imprimir_platos(struct Plato *platos_atendidos, int cantidad_platos, ofstream &output);
void imprimir_polaridad_total_de_los_comentarios(struct Comentario *comentarios, int cantidad_comentarios, ofstream &output);

#endif /* FUNCIONES_HPP */


