

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee, prmero, el archivo "CarteleraDeCines.txt" para procesar la información
 *              de cada cine que hay línea por línea en este archivo. Segundo, al leer la información de
 *              películas de un cine, se realizará la lectura del archivo "ClientesCine.txt" y solo se podrá
 *              imprimir aquellos clientes que podrían asistir al cine por cada película de un cine. Toda
 *              la impresión se presentará en el archivo "ListadoPersonas.txt".
 * Creado el 20 de abril de 2025, 06:03 PM
 */

#include "Funciones.h"


int main(int argc, char** argv) {
    realizar_listado_personas("CarteleraDeCines.txt","ClientesCine.txt","ListadoPersonas.txt");
    return 0;
}
