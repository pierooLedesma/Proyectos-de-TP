

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee primero el archivo "EmpresasRegistradas.txt"
 *              para procesar la lista de compañías. Por cada companía, se
 *              imprimirá las características de infracción de vehículos de una
 *              empresa mediante el archivo "InfraccionesCometidas.txt".
 *              Seguidamente, se imprimirá la descripción de la infracción
 *              mediante el archivo "TablaDeInfracciones.txt". Toda la impresión
 *              se realizará mediante el archivo "Reporte.txt".
 * Creado el 7 de mayo de 2025, 06:39 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    elaborar_reporte("EmpresasRegistradas.txt",
                     "InfraccionesCometidas.txt",
                     "TablaDeInfracciones.txt",
                     "Reporte.txt");
    return 0;
}

