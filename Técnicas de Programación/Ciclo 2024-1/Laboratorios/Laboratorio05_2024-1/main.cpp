

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee el archivo "Medicos.txt" y el archivo "Medicinas.txt" y los guarda en
 *              arreglos. Luego, se elabora un reporte de prueba para verificar la correcta asignación 
 *              de los datos en los arreglos. Seguidamente, se lee el archivo "CitasMedicas.txt" para
 *              la actualizar montos y totales por cada médico y medicina (estos arreglos son nuevos
 *              respecto a los creados cuando se leyeron los dos archivos anteriores). Posteriormente,
 *              se emite un reporte con el registro de médicos y de medicinas. Luego, se requiere
 *              eliminar a los médicos cuyos ingresos sean menores al promedio de los ingresos totales.
 *              Finalmente, se imprime un nuevo reporte solo con el registro de médicos y con los nuevo
 *              datos de médicos que quedaron en los arreglos respectivos de médicos.
 * Creado el 11 de mayo de 2025, 01:03 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    // Tarea 1: Leer datos del archivo "Medicos.txt" y colocarlos en arreglos.
    int arr_codigo_medico[MAX_CANT_MEDICOS],cant_medicos;
    double arr_tarifa_medico[MAX_CANT_MEDICOS];
    procesarMedicos("Medicos.txt",arr_codigo_medico,arr_tarifa_medico,cant_medicos);
    
    // Tarea 2: Leer datos del archivo "Medicinas.txt" y colocarlos en arreglos.
    int arr_codigo_medicina[MAX_CANT_MEDICINAS],cant_medicinas;
    double arr_precio_medicina[MAX_CANT_MEDICINAS];
    procesarMedicinas("Medicinas.txt",arr_codigo_medicina,arr_precio_medicina,cant_medicinas);
    
    // Tarea 3: Elaborar reporte simple para la verificación de la correcta asignación de los datos en los arreglos.
    elaborar_reporte_prueba("ReporteDePrueba.txt",arr_codigo_medico,arr_tarifa_medico,
                            cant_medicos,arr_codigo_medicina,arr_precio_medicina,cant_medicinas);
    
    // Tarea 4: Con el archivo "CitasMedicas.txt" actualizar montos y totales por cada médico y medicina.
    int arr_totales_clientes[3*MAX_CANT_MEDICOS]{},arr_cant_unidades_vendidas[MAX_CANT_MEDICINAS]{};
    double arr_ingresos_por_medico[3*MAX_CANT_MEDICOS]{},arr_montos_por_medicamento[3*MAX_CANT_MEDICINAS]{};
    actualizar_montos_y_totales("CitasMedicas.txt",arr_codigo_medico,arr_tarifa_medico,cant_medicos,
            arr_ingresos_por_medico,arr_totales_clientes,arr_codigo_medicina,arr_precio_medicina,
            cant_medicinas,arr_cant_unidades_vendidas,arr_montos_por_medicamento);
    
    // Tarea 5: Emitir el reporte "ReporteDeIngresos.txt".
    elaborar_reporte("ReporteDeIngresos.txt",arr_codigo_medico,arr_tarifa_medico,cant_medicos,
            arr_ingresos_por_medico,arr_totales_clientes,arr_codigo_medicina,arr_precio_medicina,
            cant_medicinas,arr_cant_unidades_vendidas,arr_montos_por_medicamento,true);
    
    // Tarea 6: Eliminar médicos cuyos ingresos sean menores al promedio de los ingresos totales.
    eliminar_datos(arr_codigo_medico,arr_tarifa_medico,cant_medicos,arr_ingresos_por_medico,arr_totales_clientes);
    
    // Tarea 7: Emitir reporte "ReporteDeMejoresMedicos.txt" sin mostrar las medicinas.
    elaborar_reporte("ReporteDeMejoresMedicos.txt",arr_codigo_medico,arr_tarifa_medico,cant_medicos,
            arr_ingresos_por_medico,arr_totales_clientes,arr_codigo_medicina,arr_precio_medicina,
            cant_medicinas,arr_cant_unidades_vendidas,arr_montos_por_medicamento,false);
    return 0;
}

