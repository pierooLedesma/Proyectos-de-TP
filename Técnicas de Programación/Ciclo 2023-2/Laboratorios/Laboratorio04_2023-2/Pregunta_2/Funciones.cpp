

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 4 de mayo de 2025, 11:40 AM
 */

#include "Funciones.h"



// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/






// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/






// Módulo que imprime las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/







// Módulo que imprime los títulos del reporte de prueba y del reporte solcitado
void imprimir_titulo(bool es_de_prueba,ofstream &output){
    if(es_de_prueba){
        output << setw( (TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
        output << "REPORTE DE PRUEBA DE GANANCIAS EN EL TIEMPO" << endl;
        elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
    } else {
        output << setw( (TAM_REPORTE + TAM_TITULO_1) / 2);
        output << "EMPRESA MULTINACIONAL TP" << endl;
        output << setw( (TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "GANANCIAS A TRAVES DEL TIEMPO" << endl;
    }
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/







// Módulo que imprime los encabezados del reporte de prueba y del reporte solcitado
void imprimir_encabezados(int opcion,ofstream &output){
    switch(opcion){
        case 1: 
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 1) - 4) << "No.";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 5) + 2);
            output << "ANIO" << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 2) - 7);
            output << ' ' << "GANANCIA (en millones de dolares)" << endl;
            elaborar_lineas('-',TAM_REPORTE_PRUEBA,output);
            break;
        case 2:
            elaborar_lineas('=',TAM_REPORTE,output);
            output << "RELACION DE PICOS:" << endl;
            output << setw(TAM_REPORTE / 2 - 3) << "Periodo";
            output << setw(TAM_REPORTE / 2  - 7) << "Ganancia" << endl;
            elaborar_lineas('-',TAM_REPORTE,output);
            break;
        default:
            elaborar_lineas('=',TAM_REPORTE,output);
            output << "RELACION DE VALLES:" << endl;
            output << setw(TAM_REPORTE / 2  - 3) << "Periodo";
            output << setw(TAM_REPORTE / 2  - 7) << "Ganancia" << endl;
            elaborar_lineas('-',TAM_REPORTE,output);
    }
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/






// Módulo que imprime el pico mayor o el menor valle
void imprimir_pico_mayor_o_menor_valle(bool es_pico,int anio,int ganancia,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    if(es_pico){
        // Se imprimirá el pico mayor.
        output << "PICO MAYOR: " << anio << " con ";
        output << ganancia << " millones" << endl;
    } else {
        // Se imprimirá el valle menor.
        output << "VALLE MENOR: " << anio << " con ";
        output << ganancia << " millones" << endl;
    }
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/








// Retorna "true" si el valor numérico del arreglo en dicho indice es un pico o valle
bool es_pico_o_valle(int *arr_ganancia,int indice,int cant_datos,bool imprimir_picos){
    
    /**************************  EL CASO DE ESTAR EN UN EXTREMO  ********************************************/
    
    // Verificar si el índice es cero. En caso negativo, no se procesa nada de esa condición. Si es el 
    // caso en que sea afirmativo, pues, si se imprimen picos, deberá cumplirse que
    // " arr[indice] > arr[indice + 1] "; en caso que NO se impriman picos, deberá cumplirse que 
    // " arr[indice] < arr[indice + 1] ". En caso sí se cumpla el caso elegido, retornará "true";
    // caso contrario, retornará "false".
    if (indice == 0) return (imprimir_picos ? arr_ganancia[indice] > arr_ganancia[indice + 1] : 
                                              arr_ganancia[indice] < arr_ganancia[indice + 1] );
    
    
    // Verificar si el índice en el que se está es igual al último índice del arreglo (cant_datos - 1).
    // En caso negativo, no se procesa nada de esa condición. Si es el caso positivo, pues, si se
    // imprimen picos, deberá cumplirse que " arr[indice] > arr[indice - 1] "; en caso que NO se impriman
    // picos, deberá cumplirse que  " arr[indice] < arr[indice - 1] ". En caso sí se cumpla el caso 
    // elegido, retornará "true"; caso contrario, retornará "false".
    if (indice == cant_datos - 1) return (imprimir_picos ? arr_ganancia[indice] > arr_ganancia[indice - 1] :
                                                           arr_ganancia[indice] < arr_ganancia[indice - 1] );
    
    
    /****************************  EL CASO DE DATOS INTERMEDIOS  ********************************************/
    // Verificar si ese dato "arr_ganancia[indice]" es un pico, un valle o ninguno entre 3 valores.
    return (imprimir_picos ? (arr_ganancia[indice] > arr_ganancia[indice - 1] and
                              arr_ganancia[indice] > arr_ganancia[indice + 1]) : 
                             (arr_ganancia[indice] < arr_ganancia[indice - 1] and
                              arr_ganancia[indice] < arr_ganancia[indice + 1]) );
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/







// Módulo que imprime los picos o valles según sea el caso elegido
void imprimir_picos_o_valles_segun_sea_el_caso(int *arr_anio,int *arr_gananacias,
                                               int cant_datos,bool imprimir_picos,ofstream &output){
    int mejor_anio;
    int mejor_ganancia = imprimir_picos ? 0 : 1e09;

    imprimir_encabezados(imprimir_picos ? 2 : 3, output);

    for (int indice = 0; indice < cant_datos; indice++){
        if (es_pico_o_valle(arr_gananacias, indice, cant_datos, imprimir_picos) ){
            output << setw(TAM_REPORTE / 2 - 4) << arr_anio[indice];
            output << setw(TAM_REPORTE / 3 - 1) << arr_gananacias[indice] << endl;

            if ( (imprimir_picos and arr_gananacias[indice] > mejor_ganancia) or
                 (not imprimir_picos and arr_gananacias[indice] < mejor_ganancia) ){
                mejor_ganancia = arr_gananacias[indice];
                mejor_anio = arr_anio[indice];
            }
        }
    }
    imprimir_pico_mayor_o_menor_valle(imprimir_picos, mejor_anio, mejor_ganancia, output);
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/






// Modulo que elabora el reporte solicitado
void elaborar_reporte_solicitado(const char *nombre_archivo,int *arr_anio,
                                 int *arr_gananacias,int cant_datos){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    imprimir_titulo(false,output);
    imprimir_picos_o_valles_segun_sea_el_caso(arr_anio,arr_gananacias,cant_datos,true,output);
    imprimir_picos_o_valles_segun_sea_el_caso(arr_anio,arr_gananacias,cant_datos,false,output);
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/






// Módulo que elabora el reporte de prueba
void elaborar_reporte_de_prueba(const char *nombre_archivo,int *arr_anio,
                                int *arr_gananacias,int cant_datos){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    imprimir_titulo(true,output);
    imprimir_encabezados(1,output);
    for(int indice = 0; indice < cant_datos; indice++){
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 5)) << ' ';
        output << setw(3) << indice + 1 << ')';
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS+ 3) - 1) << arr_anio[indice];
        output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS) << arr_gananacias[indice];
        output << endl;
    }
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
}
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/







// Módulo que lee el archivo "ganancias,txt" y almacena la información leída en arreglos
void leer_ganancias_y_cargar_arreglos(int *arr_anio,int *arr_gananacias,
                                      int &cant_datos,const char *nombre_archivo){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int anio;
    cant_datos = 0;
    while(true){
        input >> anio;
        if(input.eof()) break; // Validar fin del archivo "ganancias.txt"
        arr_anio[cant_datos] = anio;
        input >> arr_gananacias[cant_datos];
        cant_datos++;
    }
}