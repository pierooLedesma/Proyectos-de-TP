

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa, primero, lee el archivo "InfraccionesCometidas.txt" y
*               realiza todo el proceso de las infracciones por cada representante
*               legal. Mediante el archivo "InfraccionesDeTransito.txt", se imprimirá
*               la descripción de la infracción. Finalmente, todo se imprimirá en el
*               archivo "Reporte.txt" cuya parte final de este archivo presentará al
*               representante legal que tiene mayor pago de infracciones y al de
*               menor pago de infracciones como también el total recaudado por
*               las infracciones.
 * Creado el 27 de abril de 2025, 08:14 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    procesar_reporte("InfraccionesCometidas.txt",
                     "InfraccionesDeTransito.txt",
                     "Reporte.txt");
    return 0;
}

