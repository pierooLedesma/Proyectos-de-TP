

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa tiene como objetivo gestionar y controlar las infracciones de tránsito cometidas
 *              por vehículos, identificando las multas pagadas y pendientes de pago asociadas a cada
 *              representante legal. Para ello, se hace uso de diversos archivos de entrada y salida, a través
 *              de los cuales se organiza, procesa y reporta la información relevante.
 *                      
 *              Inicialmente, se lee el archivo "TablaDeInfracciones.txt", el cual contiene el código y el valor de
 *              cada tipo de infracción. Esta información se almacena en arreglos, ordenados de forma
 *              ascendente por código de infracción, para facilitar su búsqueda posterior. Como verificación,
 *              se genera el archivo "PruebaTablaInf.txt", que muestra los datos cargados correctamente.
 *                      
 *              Luego, a partir del archivo "InfraccionesCometidas.txt", se registran en arreglos los datos de cada
 *              infracción cometida correspondiente a cada representante legal agrupando la información por
 *              representante legal (DNI). A medida que se procesan cada línea de este archivo, se registra el
 *              DNI y su placa en el archivo "PlacasRegistradas.txt".
 *                      
 *              Finalmente, se genera el archivo "ReporteDeMultas.txt" donde se muestra un resumen detallado
 *              por cada representante legal, incluyendo el total de multas, el total pagado, el total pendiente,
 *              la fecha de la infracción más antigua y la fecha de la última pendiente. Además, se utiliza el
 *              archivo "PlacasRegistradas.txt" para agrupar y mostrar la lista de placas asociadas a cada
 *              representante legal en dicho reporte.
 * Creado el 3 de junio del 2025, 10:43 AM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arrCodInfraccion[MAX_CANT_INFRACCIONES], cant_infracciones,
        arrDni[MAX_CANT_REPRESENTANTES], arrMasMultaAntigua[MAX_CANT_REPRESENTANTES],
        arrUltimaPendiente[MAX_CANT_REPRESENTANTES], cant_representantes;
    double arrMultasInfraccion[MAX_CANT_INFRACCIONES], arrTotalMultas[MAX_CANT_REPRESENTANTES],
           arrTotalPagadas[MAX_CANT_REPRESENTANTES], arrTotalPendientes[MAX_CANT_REPRESENTANTES];
    leer_tabla_de_infracciones("TablaDeInfracciones.txt", arrCodInfraccion,
                               arrMultasInfraccion, cant_infracciones);
    verificar_datos_de_infracciones("PruebaTablaInf.txt", arrCodInfraccion,
                                    arrMultasInfraccion, cant_infracciones);
    leer_infracciones_cometidas("InfraccionesCometidas.txt", arrCodInfraccion, arrMultasInfraccion, 
                                cant_infracciones, arrDni, arrMasMultaAntigua, arrUltimaPendiente,
                                arrTotalMultas, arrTotalPagadas, arrTotalPendientes, cant_representantes,
                                "PlacasRegistradas.txt");
    emitir_reporte("ReporteDeMultas.txt", arrDni, arrMasMultaAntigua, arrUltimaPendiente, arrTotalMultas,
                   arrTotalPagadas, arrTotalPendientes, cant_representantes, "PlacasRegistradas.txt");
    return 0;
}

