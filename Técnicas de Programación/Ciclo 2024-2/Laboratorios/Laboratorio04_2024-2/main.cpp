

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa, primero, llena en arreglos los valores numéricos del archivo
 *              "Platos Ofrecidos,txt". Luego, se realiza el reporte mediante el uso de los
 *              archivos "Repartidores.txt" y "RepartosARealizar.txt" y de los arreglos
 *              llenados anteriormente.
 * Creado el 29 de abril de 2025, 08:33 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    // Tarea 1: Llenar en arreglos los valores numéricos del archivo "PlatosOfrecidos.txt"
    int arr_cod_plato[MAX_PLATOS_OFRECIDOS],cant_platos;
    double arr_precio_plato[MAX_PLATOS_OFRECIDOS];
    procesar_platos_ofrecidos("PlatosOfrecidos.txt",arr_cod_plato,
                              arr_precio_plato,cant_platos);
    
    // Tarea 2: Recibir los arreglos llenados anteriormente y emitir el reporte
    procesar_reporte("Repartidores.txt","RepartosARealizar.txt",
                     "Reporte.txt",arr_cod_plato,arr_precio_plato,cant_platos);
    return 0;
}

