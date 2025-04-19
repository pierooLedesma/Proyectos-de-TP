

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de abril de 2025, 12:20 PM
 */

#include "Funciones.h"




// Módulo que apertura el archivo de lectura sin el constructor
void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que apertura el archivo de escritura sin el constructor
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/




// Módulo que procesa el reporte solicitado. Asimismo, apertura los archivos de lectura y escritura.
void procesar_reporte(const char *nombre_archivo_Platos,const char *nombre_archivo_Repartos,
                      const char *nombre_archivo_Reporte){
    ifstream input_platos, input_repartos;
    ofstream output;
    apertura_archivo_lectura(nombre_archivo_Platos,input_platos);
    apertura_archivo_lectura(nombre_archivo_Repartos,input_repartos);
    apertura_archivo_escritura(nombre_archivo_Reporte,output);
    output << fixed << setprecision(2);
    output << setw((TAM_REPORTE + TAM_TITULO)/2);
    output << "EMPRESA DE REPARTOS A DOMICILIO TP S. A." << endl;
    procesar_platos(input_platos,input_repartos,output);
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/




void procesar_platos(ifstream &input_platos,ifstream &input_repartos,ofstream &output){
    int codigo_plato, cant_recaudada = 0;
    double precio, total_recaudado = 0.0;
    while(true){
        input_platos >> codigo_plato;
        if(input_platos.eof()) break; // Salir del bucle si se lee el fin del archivo "PlatosOfrecidos.txt"
        leer_nombre_plato_e_imprimir_codigo_del_plato_y_nombre_del_plato(codigo_plato,input_platos,output);
        input_platos >> precio;
        leer_tipo_e_imprimir_precio_del_plato_y_tipo_del_plato(precio,input_platos,output);
        procesar_repartos(codigo_plato,precio,input_repartos,output,total_recaudado,cant_recaudada);
    }
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "TOTAL RECAUDADO" << setw((TAM_REPORTE/2)/2  - 9) << cant_recaudada;
    output << setw(17) << total_recaudado;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que lee la descripción del plato e imprime el código del plato como su descripción
void leer_nombre_plato_e_imprimir_codigo_del_plato_y_nombre_del_plato(int codigo_plato,
        ifstream &input_platos,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "CODIGO" << left << setw(2) << ':' << right << codigo_plato;
    output << setw(TAM_REPORTE/N_COLUMNAS - 10) << "DESCRIPCION" << left << setw(2) << ':' << right;
    leer_e_imprimir_cadena_caracteres(input_platos,output,true);
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que lee el tipo del plato e imprime el precio del plato como su tipo
void leer_tipo_e_imprimir_precio_del_plato_y_tipo_del_plato(double precio,
        ifstream &input_platos,ofstream &output){
    output << "PRECIO" << left << setw(2) << ':' << right << setw(6) << precio;
    output << setw(TAM_REPORTE/N_COLUMNAS - 20) << "TIPO" << left << setw(2) << ':' << right;
    leer_e_imprimir_cadena_caracteres(input_platos,output,false);
    output << endl;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que lee e imprime una cadena de caracteres
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_descripcion){
    char caracter;
    int cant_caracteres = 0;
    input >> ws;
    while(true){
        caracter = input.get();
        if(caracter == ' '   or   caracter == '\n') break;
        if(caracter == '_') caracter = ' ';
        output.put(caracter);
        cant_caracteres++;
    }
    
    if(es_descripcion){
        // La cadena de caracteres que se ha leído e impreso es una descripción del plato
        int tam_nombre_y_espacios_en_blanco = TAM_REPORTE / N_COLUMNAS + 15;
        for(int i=0; i < tam_nombre_y_espacios_en_blanco - cant_caracteres; i++)  output.put(' ');
    } else {
        // La cadena de caracteres que se ha leído e impreso es un tipo de plato
        output << endl;
    }
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que procesa el archivo "RepartosRealizados.txt"
void procesar_repartos(int codigo_plato,double precio,ifstream &input_repartos,ofstream &output,
                       double &total_recaudado,int &cant_recaudada){
    int dni,tiempo,cant_total = 0;
    double total_recaudado_del_plato = 0.0;
    input_repartos.clear();
    input_repartos.seekg(0,ios::beg); // Desplazarse al inicio del archivo "RepartosRealizados.txt"
    imprimir_encabezado_repartos(output);
    while(true){
        input_repartos >> dni;
        if(input_repartos.eof()) break;
        input_repartos >> ws;
        while(input_repartos.get() != ' ');
        tiempo = leer_tiempo(input_repartos);
        leer_lista_de_platos(codigo_plato,precio,dni,tiempo,input_repartos,output,cant_total,
                total_recaudado_del_plato);
    }
    imprimir_totales_del_plato_procesado(cant_total,total_recaudado_del_plato,output);
    total_recaudado += total_recaudado_del_plato;
    cant_recaudada += cant_total;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que lee la lista de platos e imprime solo si el código del plato leído en "PlatosOfrecidos.txt"
// es el mismo del que se lee en el archivo "RepartosRealizados.txt
void leer_lista_de_platos(int codigo_plato,double precio,int dni,int tiempo,
        ifstream &input_repartos,ofstream &output,int &cant_total,double &total_recaudado_del_plato){
    int cantidad,codigo;
    while(true){
        input_repartos >> cantidad >> codigo;
        if(codigo == codigo_plato){
            output << left << setw((TAM_REPORTE/2)/N_COLUMNAS  + 1) << dni << right;
            imprimir_tiempo(tiempo,output);
            output << setw((TAM_REPORTE/2)/N_COLUMNAS  - 2) << cantidad;
            output << setw((TAM_REPORTE/2)/N_COLUMNAS) << precio*cantidad << endl;
            cant_total += cantidad;
            total_recaudado_del_plato += precio*cantidad;
        }
        if(input_repartos.get() == '\n') break;
    }
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que imprime el encabezado de repartos
void imprimir_encabezado_repartos(ofstream &output){
    output << "REPARTOS REALIZADOS" << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
    output << left << setw((TAM_REPORTE/2)/N_COLUMNAS  - 2) << "REPARTIDOR";
    output << setw((TAM_REPORTE/2)/N_COLUMNAS  + 4) << "HORA DE PARTIDA";
    output << setw((TAM_REPORTE/2)/N_COLUMNAS  - 3) << "CANTIDAD";
    output << "TOTAL PAGADO" << right << endl;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que lee el tiempo y lo retorna en segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que imprime el tiempo en HH:MM:SS
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo/3600 << ':';
    output << setw(2) << tiempo/60%60 << ':';
    output << setw(2) << tiempo%60 << setfill(' ');
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/





// Módulo que imprime de la cantidad total y monto recaudado del plato procesado
void imprimir_totales_del_plato_procesado(int cant_total,double total_recaudado_del_plato,
                                          ofstream &output){
    elaborar_lineas('-',TAM_REPORTE/2,output);
    output << "TOTAL:" << setw((TAM_REPORTE/2)/2) << cant_total;
    output << setw(17) << total_recaudado_del_plato << endl;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************************************************************************/




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i<cant_caracteres; i++) output.put(caracter);
    output << endl;
}