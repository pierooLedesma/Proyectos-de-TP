

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza un reporte de un listado de infracciones de cada empresa
 *              en el que, por cada empresa, se divide las infracciones que fueron pagadas
 *              como las que no (las adeudadas).
 * Creado el 29 de junio del 2025, 01:03 PM
 */


#include "Funciones.hpp"


int main(int argc, char** argv) {
    struct TablaDeInfracciones *arrTablaDeInfracciones;
    struct EmpresasRegistradas *arrEmpresasRegistradas;
    int cantTablaInf, cantEmpresas;
    arrTablaDeInfracciones = new struct TablaDeInfracciones[MAX_CANT_INFRACCIONES];
    arrEmpresasRegistradas = new struct EmpresasRegistradas[MAX_CANT_EMPRESAS];
    procesar_tabla_de_infracciones("TablaDeInfracciones.csv", arrTablaDeInfracciones, cantTablaInf);
    procesar_empresas_registradas("EmpresasRegistradas.csv", arrEmpresasRegistradas, cantEmpresas);
    procesar_placas_registradas("PlacasRegistradas.txt", arrEmpresasRegistradas, cantEmpresas);
    procesar_infracciones_cometidas("InfraccionesCometidas.csv", arrTablaDeInfracciones,
                                    cantTablaInf, arrEmpresasRegistradas, cantEmpresas);
    calcular_montos_totales_pagados_y_adeudados(arrEmpresasRegistradas, cantEmpresas);
    ordenar_arreglos(arrEmpresasRegistradas, cantEmpresas);
    emitir_reporte("Reporte.txt", arrEmpresasRegistradas, cantEmpresas);
    return 0;
}


