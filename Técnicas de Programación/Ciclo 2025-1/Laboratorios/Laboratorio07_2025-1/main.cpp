

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa elabora un listado de infracciones por cada empresa mediante los siguientes
 *                      archivos: "EmpresasRegistradas.csv", "PlacasRegistradas.txt", "TablaDeInfracciones.csv",
 *                      "InfraccionesCometidas.csv". El reporte se elabora mediante el archivo "Reporte.txt".
 * Creado el 15 de junio del 2025, 01:10 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arrDni[MAX_CANT_EMPRESAS], arrFechaInfraccionMasAntigua[MAX_CANT_EMPRESAS],
         arrFechaPagoMasReciente[MAX_CANT_EMPRESAS]{}, arrCantidadDeFaltas[MAX_CANT_EMPRESAS]{},
         cant_empresas, cant_infracciones;
    char *arrNombre[MAX_CANT_EMPRESAS], *arrDistrito[MAX_CANT_EMPRESAS],
            *arrListaDePlacas[MAX_CANT_EMPRESAS], *arrCodigoInfraccion[MAX_CANT_INFRACCIONES];
    double arrValorMulta[MAX_CANT_INFRACCIONES], arrTotalesPagado[3*MAX_CANT_EMPRESAS]{};
    inicializar_el_arreglo_de_placas(arrListaDePlacas);
    leer_empresas_registradas("EmpresasRegistradas.csv", arrDni, arrNombre, arrDistrito,
                                                arrFechaInfraccionMasAntigua, cant_empresas);
    leer_placas_registradas("PlacasRegistradas.txt", arrDni, arrListaDePlacas, cant_empresas);
    emitir_reporte("ReporteDePrueba01.txt", arrDni, arrNombre, arrDistrito, arrListaDePlacas,
                           arrFechaInfraccionMasAntigua, arrFechaPagoMasReciente, arrTotalesPagado,
                           arrCantidadDeFaltas, cant_empresas, true);
    leer_tabla_de_infracciones("TablaDeInfracciones.csv", arrCodigoInfraccion, arrValorMulta, cant_infracciones);
    verificar_los_datos_de_infracciones("ReporteDePrueba02.txt", arrCodigoInfraccion, arrValorMulta, cant_infracciones);
    leer_infracciones_cometidas("InfraccionesCometidas.csv", arrListaDePlacas, arrFechaInfraccionMasAntigua,
                                                  arrFechaPagoMasReciente, arrCantidadDeFaltas, arrTotalesPagado,
                                                  cant_empresas, arrCodigoInfraccion, arrValorMulta, cant_infracciones);
    ordenar_arreglos_de_empresas(arrDni, arrNombre, arrDistrito, arrListaDePlacas,
                                            arrFechaInfraccionMasAntigua, arrFechaPagoMasReciente, arrTotalesPagado,
                                            arrCantidadDeFaltas, cant_empresas);
    emitir_reporte("Reporte.txt", arrDni, arrNombre, arrDistrito, arrListaDePlacas,
                           arrFechaInfraccionMasAntigua, arrFechaPagoMasReciente, arrTotalesPagado,
                           arrCantidadDeFaltas, cant_empresas, false);
    return 0;
}



