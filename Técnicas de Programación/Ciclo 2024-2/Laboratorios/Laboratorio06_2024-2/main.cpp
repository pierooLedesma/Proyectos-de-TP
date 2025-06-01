

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa genera un reporte de platos vendidos. Para ello, primero se lee el archivo 
 *              "RepartosARealizar.txt" y se almacenan en arreglos los datos correspondientes a cada plato 
 *              (código y cantidad vendida), ordenados de forma descendente. Luego, utilizando la información
 *              del archivo "PlatosOfrecidos.txt", se actualizan los datos de cada plato: precio, ingreso bruto,
 *              descuento aplicado y el total recaudado por cada uno.
 *              Se emite un reporte preliminar llamado "ReporteDePruebaDeCargaDeDatos.txt" para verificar
 *              que los datos se hayan almacenado y asignado correctamente. Finalmente, se genera el reporte
 *              definitivo en el archivo "ReporteDePlatosVendidos.txt", nuevamente haciendo uso del archivo
 *              "PlatosOfrecidos.txt".
 *              La búsqueda dentro de los arreglos se realiza mediante el algoritmo de búsqueda binaria,
 *              mientras que la modificación de cadenas de texto se lleva a cabo mediante la función 
 *              "modificarCadena".
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

