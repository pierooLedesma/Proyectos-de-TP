

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee primero el archivo "PlatosOfrecidos.txt" en el que procesará los platos;
 *              seguidamente, lee el archivo "RepartosRealizados.txt" en el que procesa cada reparto
 *              e imprime los datos correspondientes por el dato leído del anterior archivo, este archivo
 *              se leerá más de una vez por cada plato del archivo "PlatosOfrecidos.txt". Finalmente,
 *              se imprime el reporte solicitado por cada dato leido previamente como cálculos realizados.
 * Creado el 18 de abril de 2025, 12:17 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    procesar_reporte("PlatosOfrecidos.txt","RepartosRealizados.txt","Reporte.txt");
    return 0;
}

