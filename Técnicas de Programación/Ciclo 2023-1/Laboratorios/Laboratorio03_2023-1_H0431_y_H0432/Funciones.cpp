

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 20 de abril de 2025, 06:06 PM
 */


#include "Funciones.h"



// Módulo que apertura un archivo de lectura sin utilizar el constructor
void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que apertura un archivo de escritura sin utilizar el constructor
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que realiza el reporte "ListadoPersonas.txt" con lo archivos "CarteleraDeCines.txt" y "ClientesCine.txt"
void realizar_listado_personas(const char *nombre_archivo_cartelera,
                               const char *nombre_archivo_clientes,
                               const char *nombre_archivo_listado_personas){
    ifstream input_cartelera,input_clientes;
    ofstream output;
    apertura_archivo_lectura(nombre_archivo_cartelera,input_cartelera);
    apertura_archivo_lectura(nombre_archivo_clientes,input_clientes);
    apertura_archivo_escritura(nombre_archivo_listado_personas,output);
    output << fixed << setprecision(2);
    imprimir_titulo("LISTADO DE LAS PERSONAS QUE PODRIAN ASISTIR A LAS SIGUIENTES PELICULAS",output);
    procesar_cartelera(input_cartelera,input_clientes,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que imprime el título del reporte "ListadoPersonas.txt"
void imprimir_titulo(const char *titulo,ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO) / 2) << titulo << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que procesa el archivo "CarteleraDeCines.txt"
void procesar_cartelera(ifstream &input_cartelera,ifstream &input_clientes,ofstream &output){
    int cod_distrito_cartelera;
    while(true){
        // Lectura fija
        input_cartelera >> cod_distrito_cartelera;
        if(input_cartelera.eof()) break; // Salir del bucle si se llegó al fin del archivo "CarteleraDeCines.txt"
        leer_distrito_e_imprimir_distrito_y_su_codigo(cod_distrito_cartelera,input_cartelera,output);
        
        // Lectura variable
        procesar_informacion_de_peliculas_de_un_cine(cod_distrito_cartelera,input_cartelera,input_clientes,output);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el nombre del distrito del cine e imprime su código y su nombre
void leer_distrito_e_imprimir_distrito_y_su_codigo(int cod_distrito_cartelera,ifstream &input_cartelera,
                                                   ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4)  + 1) << "DISTRITO:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 6) << cod_distrito_cartelera << " - ";
    leer_e_imprimir_cadena_caracteres(input_cartelera,output,false);
    elaborar_lineas('-',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que procesa con la lectura de la información de peliculas de un cine (Lectura variable de "CarteleraDeCines.txt")
void procesar_informacion_de_peliculas_de_un_cine(int cod_distrito_cartelera,ifstream &input_cartelera,
                                                  ifstream &input_clientes,ofstream &output){
    int cod_sala_cine,tiempo_inicial,tiempo_final;
    double costo_entrada;
    char ingresar_con_alimentos;
    while(true){
        leer_una_pelicula(cod_sala_cine,costo_entrada,ingresar_con_alimentos,tiempo_inicial,tiempo_final,input_cartelera);
        imprimir_encabezado_de_una_pelicula(output);
        imprimir_datos_de_la_pelicula(cod_sala_cine,costo_entrada,ingresar_con_alimentos,
                tiempo_inicial,tiempo_final,output);
        procesar_clientes_cine(cod_distrito_cartelera,ingresar_con_alimentos,tiempo_inicial,
                tiempo_final-tiempo_inicial,input_clientes,output);
        if(ignorar_cadena_de_caracteres(input_cartelera) == '\n') break; //Salir del bucle si se leyó el cambio de línea
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el encabezado de los datos de una película
void imprimir_encabezado_de_una_pelicula(ofstream &output){
    output << setw(TAM_REPORTE / N_COLUMNAS  - 12) << "SALA";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 8) << "COSTO";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "INICIO";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "FIN";    
    output << setw(TAM_REPORTE / N_COLUMNAS  - 2) << "DURACION";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) ) << "SE PUEDE INGRESAR CON ALIMENTOS" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee datos de una película (una lectura variable del proceso de información de películas de
// un cine del archivo "CarteleraDeCines.txt").
void leer_una_pelicula(int &cod_sala_cine,double &costo_entrada,char &ingresar_con_alimentos,
        int &tiempo_inicial,int &tiempo_final,ifstream &input_cartelera){
    input_cartelera >> cod_sala_cine;
    input_cartelera >> costo_entrada;
    input_cartelera >> ingresar_con_alimentos;
    tiempo_inicial = leer_tiempo(input_cartelera);
    tiempo_final = leer_tiempo(input_cartelera);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/




// Módulo que imprime los datos de una película
void imprimir_datos_de_la_pelicula(int cod_sala_cine,double costo_entrada,char ingresar_con_alimentos,
                                   int tiempo_inicial,int tiempo_final,ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 8) << cod_sala_cine;
    output << setw(TAM_REPORTE / N_COLUMNAS  - 9) << costo_entrada;
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 8) << ' ';
    imprimir_tiempo(tiempo_inicial,output);
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 7) << ' ';
    imprimir_tiempo(tiempo_final,output);
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 6) << ' ';
    imprimir_tiempo(tiempo_final - tiempo_inicial,output);
    
    output << setw(TAM_REPORTE / N_COLUMNAS  + 2) << ' ';
    if(ingresar_con_alimentos == 'S') output << "SI";
    else output << "NO";
    
    output << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/




// Módulo que ignora una cadena de caracteres y retorna el último caracter leído
char ignorar_cadena_de_caracteres(ifstream &input){
    char caracter;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        caracter = input.get();
        if(caracter == '\n'  or  caracter == ' ') break;
    }
    return caracter;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que procesa el archivo "ClienesCine.txt" e imprime los clientes que pueden asistir al cine
void procesar_clientes_cine(int cod_distrito_cartelera,char ingresar_con_alimentos,int tiempo_inicial,
                            int tiempo_duracion,ifstream &input_clientes,ofstream &output){
    int cod_distrito_1,cod_distrito_2,tiempo_inicio_cliente,tiempo_duracion_cliente,dni,cant_clientes=0;
    char cliente_ingresar_alimentos;
    bool hay_un_primer_cliente = true;
    input_clientes.clear(); // Libera el buffer del archivo "ClientesCine.txt" y limpia las banderas levantadas
    input_clientes.seekg(0,ios::beg); // Desplazamiento al inicio del archivo "ClientesCine.txt"
    while(true){
        if(leer_clientes_y_retornar_si_es_fin_de_archivo(cod_distrito_1,cod_distrito_2,tiempo_inicio_cliente,
                tiempo_duracion_cliente,cliente_ingresar_alimentos,dni,input_clientes) ) break; // Salir del bucle si es fin del archivo
        if( (cod_distrito_cartelera == cod_distrito_1 or cod_distrito_cartelera == cod_distrito_2)
                and   tiempo_inicio_cliente <= tiempo_inicial   and   tiempo_duracion_cliente >= tiempo_duracion  and
                (cliente_ingresar_alimentos == ingresar_con_alimentos   or
                (cliente_ingresar_alimentos == 'N' and ingresar_con_alimentos == 'S') ) ){
            if(hay_un_primer_cliente) imprimir_encabezado_clientes(output,hay_un_primer_cliente);
            imprimir_datos_cliente(dni,tiempo_inicio_cliente,tiempo_duracion_cliente,cliente_ingresar_alimentos,
                    input_clientes,output,cant_clientes);
        } else   while(input_clientes.get() != '\n');  // Descartar línea
    }
    imprimir_cant_clientes(cant_clientes,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que lee una línea del archivo "ClientesCine.txt" y retorna el valor "true" o "false" si se leyó el fin de archivo
bool leer_clientes_y_retornar_si_es_fin_de_archivo(int &cod_distrito_1,int &cod_distrito_2,
        int &tiempo_inicio_cliente,int &tiempo_duracion_cliente,char &cliente_ingresar_alimentos,
        int &dni,ifstream &input_clientes){
    input_clientes >> cod_distrito_1;
    if(input_clientes.eof()) return true; // Se ha leído el fin del archivo "ClientesCine.txt"
    input_clientes >> cod_distrito_2;
    tiempo_inicio_cliente = leer_tiempo(input_clientes);
    tiempo_duracion_cliente = leer_tiempo(input_clientes);
    input_clientes >> cliente_ingresar_alimentos >> dni;
    return false; // No se ha leído el fin del archivo "ClientesCine.txt"
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que imprime el encabezado de los clientes que podrían asistir a ver la película
void imprimir_encabezado_clientes(ofstream &output,bool &hay_un_primer_cliente){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / 4  + 2) << "PERSONAS QUE PODRIAN ASISTIR" << endl;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2)  - 6) << "DNI";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 1) << "NOMBRE";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4)  - 10) << "HORA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) ) << "DURACION";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2)  - 2) << "ALIMENTOS" << endl;
    hay_un_primer_cliente = false;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime los datos del cliente
void imprimir_datos_cliente(int dni,int tiempo_inicio_cliente,int tiempo_duracion_cliente,
        char cliente_ingresar_alimentos,ifstream &input_clientes,ofstream &output,int &cant_clientes){
    output << setw(TAM_REPORTE / (N_COLUMNAS+1) - 5) << dni << setw(3) << ' ';
    
    leer_e_imprimir_cadena_caracteres(input_clientes,output,true);
    
    imprimir_tiempo(tiempo_inicio_cliente,output);
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 5) << ' ';
    imprimir_tiempo(tiempo_duracion_cliente,output);
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3) << ' ';
    if(cliente_ingresar_alimentos == 'S') output << "SI";
    else output << "NO";
    
    output << endl;
    cant_clientes++;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee e imprime una cadena de caracteres
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_nombre_cinefilo){
    int n_caracteres = 0;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        char caracter = input.get();
        if(caracter == ' '    or    caracter == '\n') break;
        if(caracter == '_')  caracter = ' ';
        output.put(caracter);
        n_caracteres++;
    }
    if(es_nombre_cinefilo){
        // La cadena de caracteres leída es el nombre de un cinéfilo (cliente de cine), entonces
        // se imprimirán, a continuación, espacios en blanco.
        int tam = TAM_REPORTE / (N_COLUMNAS - 4) - 10;
        for(int i=0; i< tam - n_caracteres; i++) output.put(' ');
    } else {
        output << endl; // Se leyó el nombre de un distrito, entonces se imprimirá un cambio de línea
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que imprime el resumen de la cantidad de clientes
void imprimir_cant_clientes(int cant_clientes,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    if(cant_clientes != 0){
        output << setw(TAM_REPORTE / N_COLUMNAS  + 4);
        output << "TOTAL DE PERSONAS = " << cant_clientes << endl;
    } else {
        output << setw(2*(TAM_REPORTE/3) - 5);
        output << "Ningun cinefilo cumple con las condiciones para asistir a este distrito" << endl;
    }
    elaborar_lineas('=',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el tiempo en HH:MM:SS y retorna este tiempo en un valor entero de segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el tiempo en HH:MM:SS
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo / 3600 << ':';
    output << setw(2) << tiempo/60%60 << ':';
    output << setw(2) << tiempo % 60 << setfill(' ');
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracter,ofstream &output){
    for(int i=0; i<cant_caracter; i++) output.put(caracter);
    output << endl;
}