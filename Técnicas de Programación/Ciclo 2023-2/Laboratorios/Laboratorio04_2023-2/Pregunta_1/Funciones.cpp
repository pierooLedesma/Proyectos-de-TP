

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de mayo de 2025, 06:20 PM
 */

#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constrcutor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << "no se pudo abrir." << endl;
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/






// Módulo que apertura un archivo de escritura sin usar el constrcutor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << "no se pudo abrir." << endl;
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/






// Módulo que imprime las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/







// Módulo que imprime el título de los reportes como el reporte bien
// alineado con títulos adecuados y el reporte de prueba.
void imprimir_titulo(bool es_reporte_prueba,ofstream &output){
    if(not es_reporte_prueba){
        output << setw((TAM_REPORTE + TAM_TITULO) / 2);
        output << "REPORTE DEL POLIGONO" << endl;
        elaborar_lineas('=',TAM_REPORTE,output);
    } else {
        // Es el título del reporte de prueba
        elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
        output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
        output << "REPORTE DE PRUEBA" << endl;
        elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/






// Módulo que imprime los encabezados de los reportes de prueba como el
// reporte bien alineado con títulos adecuados.
void imprimir_encabezado(bool no_es_reporte_prueba,ofstream &output){
    if(no_es_reporte_prueba){
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2)) << "No.";
        output << setw(TAM_REPORTE / N_COLUMNAS - 1);
        output << "ABSCISA";
        output << setw(TAM_REPORTE / N_COLUMNAS);
        output << "ORDENADA" << endl;
        elaborar_lineas('-',TAM_REPORTE,output);
    } else {
        // Es el encabezado del reporte de prueba
        output << " COORDENADA X";
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 1));
        output << "COORDENADA Y" << endl;
        elaborar_lineas('-',TAM_REPORTE_PRUEBA,output);
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/





// Módulo que imprime el área, el perímetro y la cantidad de lados del polígono
void imprimir_area_perimetro_cantLados_del_poligono(double area,double perimetro,
                                                    int cantidad_de_lados,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << " AREA DEL POLIGONO:";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1));
    output << area << endl;
    output << " PERIMETRO DEL POLIGONO:";
    output << setw(TAM_REPORTE / N_COLUMNAS + 2);
    output << perimetro << endl;
    output << " CANTIDAD DE LADOS DEL POLIGONO:";
    output <<setw(TAM_REPORTE / (N_COLUMNAS + 2) - 1);
    output << cantidad_de_lados << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/






// Módulo que imprime el reporte del polígono.
void imprimir_reporte(double area,double perimetro,int cantidad_de_lados,
                      double *arr_coordenada_x,double *arr_coordenada_y,
                      int cant_vertices,const char *nombre_archivo){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    imprimir_titulo(false,output);
    imprimir_encabezado(true,output);
    for(int indice = 0; indice < cant_vertices; indice++){
        output << setw(TAM_REPORTE / (N_COLUMNAS + 4)) << ' ';
        output << setfill('0') << setw(2) << indice + 1 << setfill(' ') << ')';
        output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2) << ' ';
        output << '(' << setw(7) << arr_coordenada_x[indice];
        output << "  ; " << setw(7) << arr_coordenada_y[indice] << ')' << endl;
    }
    imprimir_area_perimetro_cantLados_del_poligono(area,perimetro,cantidad_de_lados,output);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/








// Módulo que calcula una sumatoria de coordenadas para hallar el área
double sumatoria_coordenas_para_hallar_el_area(double *arr_coordenada_1,
                                               double *arr_coordenada_2,int cant_vertices){
    double sumatoria = 0.0; // Inicialización de la sumatoria
    
    // Proceso de la sumatoria mientras que el índice  " (índice +1) "
    // sea menor o igual que la cantidad de vértices del polígono.
    for(int indice = 0; indice + 1 <= cant_vertices; indice++){
        int siguiente_indice = (indice + 1) % cant_vertices;  // Me aseguro de volver al índice
                                                              // cero del "arreglo coordenada 1"
                                                              // cuando "indice + 1" sea igual a
                                                              // la cantidad de vértices.
        sumatoria += arr_coordenada_1[siguiente_indice] * arr_coordenada_2[indice];
    }
    
    return sumatoria;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/








// Módulo que calcula el área de un polígono mediante sus vértices
double calcular_area(double *arr_coordenada_x,double *arr_coordenada_y,
                     int cant_vertices){
    double suma_1,suma_2;
    suma_1 = sumatoria_coordenas_para_hallar_el_area(arr_coordenada_x,
                                                     arr_coordenada_y,cant_vertices);
    suma_2 = sumatoria_coordenas_para_hallar_el_area(arr_coordenada_y,
                                                     arr_coordenada_x,cant_vertices);
    return (suma_1 - suma_2) / 2;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/








// Módulo que calcula el perímetro del polígono
double calcular_perimetro(double *arr_coordenada_x,double *arr_coordenada_y,
                          int cant_vertices){
    double perimetro = 0.0;
    for(int indice = 0; indice < cant_vertices; indice++){
        int siguiente_indice = (indice + 1) % cant_vertices; // Me aseguro de cerrar el polígono.
                                                             // Cuando el  " índice + 1 "  llegue a ser
                                                             // igual a la cantidad de vértices, pues
                                                             // este "siguiente índice" será el índice cero.
        perimetro += sqrt(pow(arr_coordenada_x[siguiente_indice] - arr_coordenada_x[indice], 2) +
                          pow(arr_coordenada_y[siguiente_indice] - arr_coordenada_y[indice], 2) );
    }
    return perimetro;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/








// Módulo que calcula el área, el perímetro y la cantidad de lados del polígono
void calcular_area_perimetro_cantLados(double &area,double &perimetro,
                                       int &cantidad_de_lados,double *arr_coordenada_x,
                                       double *arr_coordenada_y,int cant_vertices){
    area = calcular_area(arr_coordenada_x,arr_coordenada_y,cant_vertices);
    perimetro = calcular_perimetro(arr_coordenada_x,arr_coordenada_y,cant_vertices);
    cantidad_de_lados = cant_vertices;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/







// Módulo que imprime el reporte de prueba del llenado de los arreglos
void imprimir_reporte_de_prueba(const char *nombre_archivo,
        double *arr_coordenada_x,double *arr_coordenada_y,int cant_vertices){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulo(true,output);
    imprimir_encabezado(false,output);
    for(int indice=0; indice < cant_vertices; indice++){
        output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS);
        output << arr_coordenada_x[indice];
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 1)  - 1);
        output << arr_coordenada_y[indice] << endl;
    }
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/







// Módulo que realiza una lectura del archivo "Poligonos.txt" y
// llena los datos leídos en arreglos.
void leer_coordenadas_y_colocar_en_arreglos(const char *nombre_archivo,
        double *arr_coordenada_x,double *arr_coordenada_y,int &cant_vertices){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    double coordenada_x;
    cant_vertices = 0;
    while(true){
        input >> coordenada_x;
        if(input.eof()) break; // Validar fin del archivo "Poligonos.txt"
        arr_coordenada_x[cant_vertices] = coordenada_x;
        input >> arr_coordenada_y[cant_vertices];
        cant_vertices++;
    }
}

