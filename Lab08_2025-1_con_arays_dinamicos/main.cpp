

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: Módulo que elabora un reporte basado en las infracciones cometidas de cada empresa registrada.
 * Creado el 23 de junio del 2025, 10:28 AM
 */


#include "Funciones.hpp"


int main(int argc, char** argv) {
    struct TablaDeInfracciones *arrInfracciones;
    struct EmpresasRegistradas *arrEmpresas;
    int cantInfracciones, cantEmpresas;
    procesar_tabla_de_infracciones("TablaDeInfracciones.csv", arrInfracciones, cantInfracciones);
    procesar_empresas_registradas("EmpresasRegistradas.csv", arrEmpresas, cantEmpresas);
    procesar_placas("PlacasRegistradas.txt", arrEmpresas, cantEmpresas);
    procesar_infracciones_cometidas("InfraccionesCometidas.csv", arrInfracciones,
                                    cantInfracciones, arrEmpresas, cantEmpresas);
    ordenar_empresas(arrEmpresas, cantEmpresas);
    ordenar_infracciones(arrInfracciones, cantInfracciones);
    emitir_reporte("Reporte.txt", arrInfracciones, cantInfracciones, arrEmpresas, cantEmpresas);
    return 0;
}



