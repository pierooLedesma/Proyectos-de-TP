

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: Es un programa de prueba para el lab.7 2025-1 a partir de los archivos csv de Prog. 2 
 * Creado el 8 de junio del 2025, 12:46 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arr_cod_infraccion[MAX_CANT_INFRACCIONES], cant_infracciones,
        arrDNI[MAX_CANT_REPRESENTANTES], arrFechaInfraccionMasAntigua[MAX_CANT_REPRESENTANTES],
        arrFechaUltimaPagada[MAX_CANT_REPRESENTANTES]{}, cant_representantes;
    double arr_multas[MAX_CANT_INFRACCIONES];
    char *arr_gravedad[MAX_CANT_INFRACCIONES], *arr_descripcion_infraccion[MAX_CANT_INFRACCIONES],
         *arrNombre[MAX_CANT_REPRESENTANTES], *arrListaDePlacas[MAX_CANT_REPRESENTANTES];
    leer_tabla_de_infracciones("TablaDeInfracciones.csv", arr_cod_infraccion, arr_multas,
                               arr_gravedad, arr_descripcion_infraccion, cant_infracciones);
    leer_empresas_registradas("EmpresasRegistradas.csv", arrDNI, arrNombre,
                              arrListaDePlacas, cant_representantes);
    leer_infracciones_cometidas("InfraccionesCometidas.csv", arr_cod_infraccion, arr_multas, cant_infracciones,
                                arrDNI, arrNombre, arrListaDePlacas, arrFechaInfraccionMasAntigua,
                                arrFechaUltimaPagada, cant_representantes);
    emitir_reporte("Reporte.txt", arrDNI, arrNombre, arrListaDePlacas, 
                   arrFechaInfraccionMasAntigua, arrFechaUltimaPagada, cant_representantes);
    return 0;
}

