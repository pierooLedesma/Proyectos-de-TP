

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un listado de infracciones de cada empresa como también la tabla de infracciones.
 * Creado el 20 de junio del 2025, 02:23 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    struct TablaDeInfracciones arrTablaDeInfracciones[MAX_CANT_INFRACCIONES];
    struct EmpresasRegistradas arrEmpresasRegistradas[MAX_CANT_EMPRESAS];
    int cantTablaInfracciones, cantEmpresasRegistradas;
    leer_tabla_de_infracciones("TablaDeInfracciones.csv", arrTablaDeInfracciones, cantTablaInfracciones);
    leer_empresas_registradas("EmpresasRegistradas.csv", arrEmpresasRegistradas, cantEmpresasRegistradas);
    leer_placas_registradas("PlacasRegistradas.txt", arrEmpresasRegistradas, cantEmpresasRegistradas);
    leer_infracciones_cometidas("InfraccionesCometidas.csv", arrEmpresasRegistradas,
                                cantEmpresasRegistradas, arrTablaDeInfracciones, cantTablaInfracciones);
    ordenar_empresas(arrEmpresasRegistradas, cantEmpresasRegistradas);
    ordenar_infracciones(arrTablaDeInfracciones, cantTablaInfracciones);
    emitir_reporte("Reporte.txt", arrEmpresasRegistradas, cantEmpresasRegistradas, arrTablaDeInfracciones, cantTablaInfracciones);
    return 0;
}



