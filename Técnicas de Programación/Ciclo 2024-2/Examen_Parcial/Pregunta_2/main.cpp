

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa tiene como finalidad el control de los platos. El programa lee
 *              el archivo "PlatosOfrecidos.txt" para almacenar los datos que se leen en arreglos
 *              (excepto los datos tipo cadena de caracteres). Seguidamente, lee el archivo
 *              "Clientes.txt" y almacena solamente el DNI del cliente y el descuento del cliente en
 *              arreglos. Se emite un reporte de prueba para verificar la correcta asignación de los
 *              datos en los arreglos. Mediante el archivo "RepartosARealizar.txt", se actualizan las
 *              cantidades y los montos de cada plato. Posterior a ello, se ordenan los arreglos de
 *              forma descendente por la cantidad de platos elaborados (o preparados) y, luego,
 *              se emite un reporte. Finalmente, se eliminan los datos de los arreglos que no pudieron 
 *              atender la demanda (datos que tienen "no atendidos" igual a cero) y se emite un reporte. 
 * Creado el 17 de mayo de 2025, 06:35 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arr_codigo_plato[MAX_CANT_PLATOS],
        cant_platos,arr_dni_cliente[MAX_CANT_CLIENTES],cant_clientes,
        arr_cantidades_plato[3*MAX_CANT_PLATOS]{}; // En ese arreglo, se almacena la cantidad de platos
                                                   // preparados, atendidos y no atendidos por cada plato.
    double arr_precio_plato[MAX_CANT_PLATOS],
           arr_descuento_plato[MAX_CANT_PLATOS],arr_descuento_cliente[MAX_CANT_PLATOS],
           arr_montos_recaudados[3*MAX_CANT_PLATOS]{}; // En ese arreglo, se almacenan los 3 montos
                                                       // recaudados (esperado, bruto, recibido) por plato.
    leer_platos_ofrecidos("PlatosOfrecidos.txt",arr_codigo_plato,arr_precio_plato,
                          arr_cantidades_plato,arr_descuento_plato,arr_montos_recaudados,
                          cant_platos);
    leer_clientes("Clientes.txt",arr_dni_cliente,arr_descuento_cliente,cant_clientes);
    emitir_reporte_prueba("ReporteDePrueba",arr_codigo_plato,arr_precio_plato,
                          arr_cantidades_plato,arr_descuento_plato,arr_montos_recaudados,
                          cant_platos,arr_dni_cliente,arr_descuento_cliente,cant_clientes);
    leer_repartos_a_realizar("RepartosARealizar.txt",arr_codigo_plato,arr_precio_plato,
                             arr_cantidades_plato,arr_descuento_plato,arr_montos_recaudados,
                             cant_platos,arr_dni_cliente,arr_descuento_cliente,cant_clientes);
    ordenar_arreglos(arr_codigo_plato,arr_precio_plato,arr_cantidades_plato,
                     arr_descuento_plato,arr_montos_recaudados,cant_platos);
    emitir_reporte("ReporteDeRelacionDePlatos.txt",arr_codigo_plato,arr_precio_plato,
                   arr_cantidades_plato,arr_descuento_plato,arr_montos_recaudados,cant_platos);
    eliminar_datos_en_los_arreglos(arr_codigo_plato,arr_precio_plato,arr_cantidades_plato,
                                   arr_descuento_plato,arr_montos_recaudados,cant_platos);
    emitir_reporte("ReporteDePlatosConDeficit.txt",arr_codigo_plato,arr_precio_plato,
                   arr_cantidades_plato,arr_descuento_plato,arr_montos_recaudados,
                   cant_platos);
    return 0;
}

