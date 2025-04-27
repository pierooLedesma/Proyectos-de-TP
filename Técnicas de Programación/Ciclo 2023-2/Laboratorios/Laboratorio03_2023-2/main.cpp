

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa, primero, procesa el archivo "Canales.txt" en el cual lee e imprime cada
 *              canal. Luego, se procesa el archivo "RegistroDePreferencias.txt" y se procesan los
 *              registros y, por cliente, se buscará el canal procesado y se buscará la información del
 *              televidente. Se busca el nombre del cliente en el archivo "Televidentes.txt" y se imprime
 *              la información del televidente como también se actualizan algunos acumuladores.
 *              Finalmente, se muestra el reporte completo en un archivo llamado "Reporte.txt".
 * Creado el 27 de abril de 2025, 12:35 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    procesar_reporte("Canales.txt","Televidentes.txt",
                                 "RegistroDePreferencias.txt","Reporte.txt");
    return 0;
}

