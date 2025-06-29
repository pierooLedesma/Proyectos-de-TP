

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza un reporte de un listado de infracciones de cada empresa
 *              en el que, por cada empresa, se divide las infracciones que fueron pagadas
 *              como las que no (las adeudadas). El procesamiento del almacenamiento de
 *              datos se da por el uso de listas simplemente enlazadas.
 * Creado el 28 de junio del 2025, 01:35 PM
 */


#include "Funciones.hpp"


int main(int argc, char** argv) {
    struct NodoTablaDeInfracciones *listaTablaDeInfraciones;
    struct NodoEmpresasRegistradas *listaEmpresasRegistradas;
    
    procesarTablaDeInfracciones("TablaDeInfracciones.csv", listaTablaDeInfraciones);
    procesarEmpresasRegistradas("EmpresasRegistradas.csv", listaEmpresasRegistradas);
    procesarPlacasRegistradas("PlacasRegistradas.txt", listaEmpresasRegistradas);
    procesarInfraccionesCometidas("InfraccionesCometidas.csv", listaTablaDeInfraciones, listaEmpresasRegistradas);
    calcular_totales_pagados_y_adeudados(listaEmpresasRegistradas);
    ordenar_infracciones_para_cada_empresa(listaEmpresasRegistradas);
    emitir_reporte("Reporte.txt", listaEmpresasRegistradas);
    
    return 0;
}

