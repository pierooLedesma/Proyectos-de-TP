

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza un reporte del análisis de sentimientos de los comentarios
 *              respecto a una atención de los pedidos dados de un cliente.
 * Creado el 3 de julio del 2025, 10:28 AM
 */


#include "Funciones.hpp"


int main(int argc, char** argv) {
    struct Palabra lexicon[MAX_CANT_PALABRAS_DE_LEXICON];
    int cantPlabrasEnLexicon;
    procesar_lexicon("lexicon.csv", lexicon, cantPlabrasEnLexicon);
    
    struct Plato *platos;
    int cantPlatos;
    platos = new struct Plato[MAX_CANT_PLATOS];
    procesar_platos("platos.csv", platos, cantPlatos);
    
    struct Atencion atenciones[MAX_CANT_ATENCIONES]{};
    int cantAtenciones;
    procesar_atenciones("atenciones.txt", atenciones, cantAtenciones, platos, cantPlatos);
    
    procesar_comentarios("comentarios.csv", atenciones, cantAtenciones, lexicon, cantPlabrasEnLexicon);
    
    emitir_reporte("ReporteAtencionesAnalisisSentimiento.txt", atenciones, cantAtenciones);
    
    return 0;
}

