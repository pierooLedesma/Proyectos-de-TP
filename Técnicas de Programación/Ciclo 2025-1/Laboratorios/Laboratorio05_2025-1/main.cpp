

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee los archivos "TablaDeInfracciones.txt", "EmpresasRegistradas.txt",
 *              "PlacasRegistradas.txt" y los almacena en arreglos. Mediante el archivo
 *              "InfraccionesCometidas.txt", se calculan las cantidades y montos para infracciones
 *              y para las empresas. Luego, se ordenan los datos de los arreglos de empresa  de
 *              forma ascendente por el DNI del representante legal y los datos de los arreglos de
 *              infracciones de forma ascendente por el código de infracción (la parte numérica).
 *              Finalmente, se emite el reporte solicitado.
 * Creado el 14 de mayo de 2025, 05:28 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    int arr_cod_infraccion[MAX_CANT_INFRACCIONES],
         arr_cant_impuesta_por_infraccion[MAX_CANT_INFRACCIONES]{},cant_infracciones,
         arr_dni_representante[MAX_CANT_EMPRESAS],
         arr_cant_faltas_por_empresa[4*MAX_CANT_EMPRESAS]{},cant_empresas,
         arr_dni_placa[MAX_CANT_VEHICULOS],arr_num_placa_1[MAX_CANT_VEHICULOS],
         arr_num_placa_2[MAX_CANT_VEHICULOS],cant_vehiculos;
    double arr_valor_multa[MAX_CANT_INFRACCIONES],
                arr_monto_total_por_infraccion[MAX_CANT_INFRACCIONES]{},
                arr_total_multas_por_empresa[4*MAX_CANT_EMPRESAS]{};
    char arr_gravedad[MAX_CANT_INFRACCIONES],arr_tipo_vehiculo[MAX_CANT_VEHICULOS];
    leer_tabla_infracciones("TablaDeInfracciones.txt",arr_cod_infraccion,
                            arr_gravedad,arr_valor_multa,cant_infracciones);
    leer_empresas_registradas("EmpresasRegistradas.txt",arr_dni_representante,cant_empresas);
    leer_placas_registradas("PlacasRegistradas.txt",arr_dni_placa,arr_tipo_vehiculo,
                            arr_num_placa_1,arr_num_placa_2,cant_vehiculos);
    leer_infracciones_cometidas("InfraccionesCometidas.txt",arr_cod_infraccion,
            arr_gravedad,arr_valor_multa,arr_cant_impuesta_por_infraccion,
            arr_monto_total_por_infraccion,cant_infracciones,arr_dni_representante,
            arr_cant_faltas_por_empresa,arr_total_multas_por_empresa,cant_empresas,
            arr_dni_placa,arr_tipo_vehiculo,arr_num_placa_1,arr_num_placa_2,cant_vehiculos);
    ordenar_datos(arr_cod_infraccion,arr_gravedad,arr_valor_multa,arr_cant_impuesta_por_infraccion,
            arr_monto_total_por_infraccion,cant_infracciones,arr_dni_representante,
            arr_cant_faltas_por_empresa,arr_total_multas_por_empresa,cant_empresas);
    emitir_reporte("Reporte.txt",arr_cod_infraccion,arr_gravedad,arr_valor_multa,
            arr_cant_impuesta_por_infraccion,arr_monto_total_por_infraccion,cant_infracciones,
            arr_dni_representante,arr_cant_faltas_por_empresa,arr_total_multas_por_empresa,cant_empresas);
    return 0;
}

