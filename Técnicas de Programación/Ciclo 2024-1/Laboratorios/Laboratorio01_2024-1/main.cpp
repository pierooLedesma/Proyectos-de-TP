

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee el archivo "CitasMedicas.txt". Lee línea por línea mediante
 *              un bucle y se imprimen los datos línea por línea; se actualizan datos
 *              para la elaboración de las estadísticas. Finalmente, se imprimen las
 *              estadísticas y con ello todo el reporte solicitado. 
 * Creado el 12 de abril de 2025, 08:10 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    leer_y_procesar_citas_medicas();
    return 0;
}

