

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un listado de infracciones cometidas por cada zona.
 * Creado el 21 de junio del 2025, 12:20 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    struct Zona *arrZonas;
    int cantidad_zonas;
    procesar_zonas("Datos/zonas.txt", arrZonas, cantidad_zonas);
    procesar_drones("Datos", arrZonas, cantidad_zonas);
    procesar_eventos("Datos", arrZonas, cantidad_zonas);
    emitir_reporte("Reporte.txt", arrZonas, cantidad_zonas);
    return 0;
}



