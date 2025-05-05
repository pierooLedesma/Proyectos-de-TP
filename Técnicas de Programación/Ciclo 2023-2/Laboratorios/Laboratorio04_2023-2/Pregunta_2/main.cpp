

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee el archivo "ganancias.txt" y carga la información leída
 *              en arreglos. Luego, elabora un reporte sencillo para verificar que los
 *              datos en los arreglos fueron leídos correctamente. Finalmente, se
 *              elabora el reporte solicitado imprimiendo los picos y valles de las
 *              ganancias a través del tiempo.
 * Creado el 4 de mayo de 2025, 11:38 AM
 */

#include "Funciones.h"


int main(int argc, char** argv) {
    // Tarea 1: Leer el archivo "ganancias.txt" y cargar la información en arreglos.
    int arr_anio[MAX_DATOS],arr_gananacias[MAX_DATOS],cant_datos;
    leer_ganancias_y_cargar_arreglos(arr_anio,arr_gananacias,cant_datos,"ganancias.txt");
    
    // Tarea 2: Elaborar un reporte de prueba para verificar los datos almacenados en los arreglos
    elaborar_reporte_de_prueba("ReporteDePrueba.txt",arr_anio,arr_gananacias,cant_datos);
    
    // Tarea 3: Emitir el reporte solicitado identificando los picos y los valles.
    elaborar_reporte_solicitado("Reporte.txt",arr_anio,arr_gananacias,cant_datos);
    return 0;
}

