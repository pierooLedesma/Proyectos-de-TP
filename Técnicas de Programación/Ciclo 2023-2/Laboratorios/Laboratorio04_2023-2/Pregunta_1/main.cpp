

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa, primero, lee el archivo "Poligonos.txt" y almacena
 *              los datos leídos en arreglos. Seguidamente, imprime un reporte
 *              de prueba de los datos almacenados en los arreglos. Luego,
 *              calcula el área, perímetro y cantidad de lados del polígono.
 *              Finalmente, imprime en un reporte todos los datos del polígono.
 * Creado el 3 de mayo de 2025, 06:17 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    // Tarea 1: Leer las coordenadas del polígono del archivo "Poligonos.txt"
    //          y llenar estas coordenadas en arreglos. 
    double arr_coordenada_x[MAX_VERTICES],arr_coordenada_y[MAX_VERTICES];
    int cant_vertices;
    leer_coordenadas_y_colocar_en_arreglos("Poligono.txt",arr_coordenada_x,
                                           arr_coordenada_y,cant_vertices);
    
    // Tarea 2: Imprimir un reporte sencillo que se muestren los datos cargados 
    //          de los arreglos y estos datos alineados correctamente.
    imprimir_reporte_de_prueba("ReporteDePrueba.txt",arr_coordenada_x,
                               arr_coordenada_y,cant_vertices);
    
    // Tarea 3: Calcular el área, perímetro y cantidad de lados del polígono
    double area, perimetro;
    int cantidad_de_lados;
    calcular_area_perimetro_cantLados(area,perimetro,cantidad_de_lados,
                                      arr_coordenada_x,arr_coordenada_y,cant_vertices);
    
    // Tarea 4: Mostrar las coordenadas y resultados en un reporte bien alineado,
    //          con títulos y etiquetas adecuadas.
    imprimir_reporte(area,perimetro,cantidad_de_lados,arr_coordenada_x,
                     arr_coordenada_y,cant_vertices,"Reporte");
    return 0;
}

