

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa permite procesar los platos enviados a los clientes mediante los
 *              archivos "PlatosOfrecidos.csv", "DistritosDeLima.csv", "Clientes.csv" y 
 *              "PedidosRealizados.txt". El reporte estará en el archivo "Pedidos_Atendidos.txt".
 * Creado el 13 de junio del 2025, 12:53 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    struct Plato arrPlatos[MAX_CANT_PLATOS];
    struct Distrito arrDistritos[MAX_CANT_DISTRITOS];
    struct Cliente arrClientes[MAX_CANT_CLIENTES];
    int cantPlatos, cantDistritos, cantClientes;
    
    leer_platos_ofrecidos("PlatosOfrecidos.csv", arrPlatos, cantPlatos);
    leer_distritos("DistritosDeLima.csv", arrDistritos, cantDistritos);
    leer_clientes("Clientes.csv", arrClientes, cantClientes);
    verificar_datos_en_los_arreglos(arrPlatos, cantPlatos, arrDistritos, cantDistritos, arrClientes, cantClientes);
    leer_pedidos_realizados("PedidosRealizados.txt", arrPlatos, cantPlatos,
                            arrDistritos, cantDistritos, arrClientes, cantClientes);
    ordenar_clientes(arrClientes, cantClientes);
    ordenar_pedidos_de_los_clientes(arrClientes, cantClientes);
    emitir_reporte("Pedidos_Atendidos.txt", arrClientes, cantClientes);
    return 0;
}



