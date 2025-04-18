

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa realiza una serie de preguntas en el cual el usuario ingresará datos
 *              correspondientes para poder realizar el reporte. Estas preguntas son para saber qué
 *              películas podría asistir. Luego, a partir de los datos ingresados por el usuario, se procede
 *              a leer el archivo "CarteleraDeCines.txt" y se mostrará en el reporte la lista de películas
 *              que puede asistir el usuario.
 * Creado el 16 de abril de 2025, 08:19 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    preguntas_y_elaborarcion_del_reporte("CarteleraDeCines.txt","Reporte.txt");
    return 0;
}