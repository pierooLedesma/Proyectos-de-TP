

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee cuatro archivos en el que se desea presentar los clientes a atender
 *              en un reporte. La lectura empieza con el archivo "Clientes.txt" para procesar la lista
 *              de pedidos por cada cliente. Para procesar la lista de pedidos, se hará uso del archivo 
 *              "RepartosARealizar.txt". Mediante el archivo "PlatosOfrecidos.txt", se imprimirá la
 *              información de un plato. Finalmente, el archivo "Repartidores.txt" se hará uso para
 *              mostrar el repartidor que puede repartir la lista de pedidos de un cliente.
 * Creado el 17 de mayo de 2025, 06:26 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    procesar_reporte("Clientes.txt","RepartosARealizar.txt",
                     "PlatosOfrecidos.txt","Repartidores.txt",
                     "Reporte.txt");
    return 0;
}

