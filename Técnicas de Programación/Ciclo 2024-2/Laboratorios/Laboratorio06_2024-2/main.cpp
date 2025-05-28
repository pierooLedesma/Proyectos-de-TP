

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza un reporte de platos vendidos. Se lee el archivo "RepartosARealizar.txt"
 *              y se almacena los datos (el código del plato y la cantidad vendida) de los platos en arreglos
 *              de forma descendente. Mediante el archivo "PlatosOfrecidos.txt", se actualizan las cantidades
 *              (precio, ingreso bruto, descuento del plato y el total ingresado por el plato). Se emite un reporte
 *              de prueba para verificar la correcta asignación de los datos almacenados en arreglos. Finalmente,
 *              se emite el reporte solicitado, nuevamente, mediante el archivo "PlatosOfrecidos.txt". La función
 *              de búsquedad en los arreglos es realizada mediante el método de búsqueda binaria y la
 *              modificación de una cadena de caracteres es dada por la función "modificarCadena".
 * Creado el 27 de mayo de 2025, 10:23 AM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arrCodigoPlatos[MAX_CANT_PLATOS], arrNumPlatosVendidos[MAX_CANT_PLATOS], cant_platos;
    double arrPrecio[MAX_CANT_PLATOS], arrIngresoBruto[MAX_CANT_PLATOS],
           arrDescuento[MAX_CANT_PLATOS], arrTotal[MAX_CANT_PLATOS];
    bool arrTieneDescuento[MAX_CANT_PLATOS];
    leer_repartos_a_realizar("RepartosARealizar.txt", arrCodigoPlatos, arrNumPlatosVendidos, cant_platos);
    ifstream input_platos_ofrecidos;
    aperturar_archivo_lectura("PlatosOfrecidos.txt", input_platos_ofrecidos);
    actualizar_cantidades_con_platos_ofrecidos(input_platos_ofrecidos, arrCodigoPlatos, arrNumPlatosVendidos,
                           arrPrecio,arrIngresoBruto, arrDescuento, arrTotal, arrTieneDescuento, cant_platos);
    reportePrueba("ReporteDePruebaDeCargaDeDatos.txt", arrCodigoPlatos, arrNumPlatosVendidos,
                  arrPrecio, arrIngresoBruto, arrDescuento, arrTotal, arrTieneDescuento, cant_platos);
    emitir_reporte("ReporteDePlatosVendidos.txt", arrCodigoPlatos, arrNumPlatosVendidos, arrPrecio,
              arrIngresoBruto, arrDescuento, arrTotal, arrTieneDescuento, cant_platos, input_platos_ofrecidos);
    return 0;
}

