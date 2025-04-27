

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de abril de 2025, 12:38 PM
 */

#include "Funciones.h"



// Módulo que apertura el archivo de lectura sin aplicar el constructor
void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/






// Módulo que apertura el archivo de escritura sin aplicar el constructor
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/






// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/







// Módulo que imprime el título del reporte
void imprimir_titulo(ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw((TAM_REPORTE + TAM_TITULO_1)/2);
    output << "EMPRESA DE OPINION DE MERCADO TP  S. A." << endl;
    
    output << setw((TAM_REPORTE + TAM_TITULO_2)/2);
    output << "AVENIDA UNIVERSITARIA 1234 San Miguel" << endl;
    
    output << setw((TAM_REPORTE + TAM_TITULO_3)/2);
    output << "LIMA  -  PERU" << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
    
    output << setw((TAM_REPORTE + TAM_TITULO_4)/2);
    output << "REGISTRO DE PREFERENCIAS DE LOS TELEVIDENTES POR CANAL DE PREFERENCIA" << endl;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime el encabezado de los televidentes
void imprimir_encabezado_televidentes(ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << left << setw(TAM_REPORTE / N_COLUMNAS  - 5) << "DNI No.";
    output <<setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 2) << "NOMBRE";
    output <<setw(TAM_REPORTE / N_COLUMNAS  - 2) << "SEXO";
    output <<setw(TAM_REPORTE / N_COLUMNAS  - 2) << "CATEGORIA";
    output <<setw(TAM_REPORTE / N_COLUMNAS + 3) << "COMPANIA";
    output <<setw(TAM_REPORTE / N_COLUMNAS) << "RANGO";
    output << "DURACION" << right << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime el tiempo en HH:MM:SS
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo / 3600 << ':';
    output << setw(2) << tiempo / 60 % 60 << ':';
    output << setw(2) << tiempo % 60 << setfill(' ');
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que lee el tiempo y lo retorna en un valor entero en segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/









// Módulo que lee e imprime una cadena de caracteres.
// El formato de la impresión dependerá si la cadena que se lea sea un canal o no.
void leer_and_imprimir_cadena(int tam,char delimitador,bool es_canal,
                              ifstream &input,ofstream &output){
    int n_caracteres = 0;
    bool es_mayuscula = true;
    input >> ws; // Lectura de los espacios en blanco
    if(es_canal) input.get(); // Leer el slash 
    while(true){
        char c = input.get();
        if(c == delimitador) break;
        if(es_canal){
            // Se está leyendo e imprimiendo un canal
            c = (c>='a'   and   c<='z' ? c - 'a' + 'A' : c);
        } else if (c == '_'){
            c = ' ';
        } else if(es_mayuscula){
            es_mayuscula = false;
        } else {
            c = c - 'A' + 'a';
            es_mayuscula = true;
        }
        output.put(c);
        n_caracteres++;
    }
    for(int i=0; i < tam - n_caracteres; i++) output.put(' ');
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime el canal
void imprimir_canal(int canal,ifstream &input_canales,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 9)  - 2);
    output << "CANAL:" << right;
    leer_and_imprimir_cadena(TAM_REPORTE / (N_COLUMNAS - 2),
                             '/',true,input_canales,output);
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 9) - 1);
    output << "NUMERO:" << right << canal << endl;
    output << "LISTADO DE TELEVIDENTES QUE VEN EL CANAL:" << endl;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime el rango y duración del televidente
void imprimir_rango_y_duracion_del_televidente(int tiempo_inicio,int tiempo_final,ofstream &output){
    imprimir_tiempo(tiempo_inicio,output);
    output << " - ";
    imprimir_tiempo(tiempo_final,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5)  - 3) << ' ';
    imprimir_tiempo(tiempo_final - tiempo_inicio,output);
    output << endl;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime el sexo del televidente
void imprimir_sexo(char sexo,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 1) );
    if(sexo == 'M') output << "Masculino";
    else  output << "Femenino"; // sexo == 'F'
    output << right;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime la categoría del televidente
void imprimir_categoria(int anio,ofstream &output){
    output << left << setw(TAM_REPORTE / N_COLUMNAS - 2);
    if(anio > 2009) output << "Menor";
    else if(anio > 1988) output << "Joven"; // 1988 < anio < = 2009
    else   output << "Adulto"; // anio < = 1988
    output << right;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que imprime la campañía
void imprimir_compania(char compania,ofstream &output){
    output << left << setw(TAM_REPORTE / N_COLUMNAS  - 4);
    if(compania == 'A')  output << "TVPUCP";
    else if(compania == 'B')  output << "CableMas";
    else  output << "TPVision";  // compania == 'C'
    output << right;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/






// Módulo que retorna si es un menor (1)  o  no (0)
int es_menor(int anio){
    return (anio > 2009);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/





// Módulo que retorna si es joven (1)  o no (0)
int es_joven(int anio){
    return (anio > 1988  and anio <= 2009);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/





// Módulo que retorna si es un adulto (1)  o  no (0)
int es_adulto(int anio){
    return (anio <= 1988);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que continua con la lectura del televidente a imprimir (lee la fecha de cumpleaños,
// el sexo, la categoría y la compañía);
void continuar_lectura_del_televidente_e_imprimirlo(int &cant_menores,int &cant_jovenes,
        int &cant_adultos,ifstream &input_televidentes,ofstream &output){
    int dia,mes,anio;
    char slash,sexo,compania;
    input_televidentes >> dia >> slash >> mes >> slash >> anio >> sexo >> compania;
    imprimir_sexo(sexo,output);
    imprimir_categoria(anio,output);
    imprimir_compania(compania,output);
    cant_menores += es_menor(anio);
    cant_jovenes += es_joven(anio);
    cant_adultos += es_adulto(anio);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que procesa el archivo "Televidentes.txt". Busca el cliente a imprimir
void buscar_e_imprimir_televidente(int dni,int &cant_menores,int &cant_jovenes,
                                   int &cant_adultos,ifstream &input_televidentes,
                                   ofstream &output){
    int dni_leido;
    input_televidentes.clear();
    input_televidentes.seekg(0,ios::beg);
    // 69323674      ROSARIO_MENDOZA_EGUSQUIZA  31/03/2013      F       B
    while(true){
        input_televidentes >> dni_leido;
        if(input_televidentes.eof()) break;
        if(dni_leido == dni){
            output << left << setw(TAM_REPORTE / N_COLUMNAS  - 5) << dni << right;
            leer_and_imprimir_cadena(TAM_REPORTE / (N_COLUMNAS - 3) + 2,
                                     ' ',false,input_televidentes,output);
            continuar_lectura_del_televidente_e_imprimirlo(cant_menores,cant_jovenes,
                                                           cant_adultos,input_televidentes,output);
        } else {
            while(input_televidentes.get() != '\n'); // Descartar televidente
        }
    }
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que procesa la lista de canales de un registro
void procesar_lista_de_canales(int dni,int canal,ifstream &input_registro,ifstream &input_televidentes,
                               ofstream &output,int &sumar_tiempo,int &cant_menores,
                               int &cant_jovenes,int &cant_adultos,int &total_personas){
    int canal_leido,tiempo_inicio,tiempo_final,cant_canales = 0;
    while(true){
        input_registro >> canal_leido;
        tiempo_inicio = leer_tiempo(input_registro);
        tiempo_final = leer_tiempo(input_registro);
        if(canal_leido == canal){
            cant_canales++;
            buscar_e_imprimir_televidente(dni,cant_menores,cant_jovenes,
                                          cant_adultos,input_televidentes,output);
            imprimir_rango_y_duracion_del_televidente(tiempo_inicio,tiempo_final,output);
            sumar_tiempo += (tiempo_final - tiempo_inicio);
        }
        if(input_registro.get() == '\n') break;
    }
    if(cant_canales > 0) total_personas++;
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que procesa el archivo "RegistroDePreferencias.txt". Buscará los
// registros que ha visto un cliente el canal que se ha procesado.
void procesar_registro(int canal,int &sumar_tiempo,int &cant_menores,
                       int &cant_jovenes,int &cant_adultos,int &total_personas,
                       ifstream &input_registro,ifstream &input_televidentes,ofstream &output){
    int dni;
    input_registro.clear(); // Libera el buffer del archivo "RegistroDePreferencias.txt" y limpiar las banderas levantadas
    input_registro.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "RegistroDePreferencias.txt"
    // 77017851   550   10:53:35   13:37:36  705     20:12:08   22:06:12
    while(true){
        // Lectura fija del archivo "RegistroDePreferencias.txt"
        input_registro >> dni;
        if(input_registro.eof()) break; // Validar fin del archivo "RegistroDePreferencias.txt"
        
        // Lectura variable del archivo "RegistroDePreferencias.txt"
        procesar_lista_de_canales(dni,canal,input_registro,input_televidentes,output,sumar_tiempo,
                                  cant_menores,cant_jovenes,cant_adultos,total_personas);
    }
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/









// Módulo que imprime el resumen de un canal
void imprimir_resumen_por_canal(int sumar_tiempo,int cant_menores,int cant_jovenes,
                                int cant_adultos,int total_personas,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "PROMEDIO DE TIEMPO QUE VEN LOS TELEVIDENTES EL CANAL:  ";
    imprimir_tiempo( sumar_tiempo / total_personas,output);
    output << endl;
    
    output << "PORCENTAJES SEGUN SU EDAD:" << endl;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 4) << ' ' << "MENORES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 9) << ' ' << setw(6);
    output << ( (double)cant_menores / total_personas ) * 100 << '%' << endl;
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 4) << ' ' << "JOVENES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 9) << ' ' << setw(6);
    output << ( (double)cant_jovenes / total_personas ) * 100 << '%' << endl;
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 4) << ' ' << "ADULTOS:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 9) << ' ' << setw(6);
    output << ( (double)cant_adultos / total_personas ) * 100 << '%' << endl;
    
    output << "TOTAL DE PERSONAS QUE VEN EL CANAL:  " << total_personas << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/









// Módulo que procesa el archivo "Canales.txt"
void procesar_canales(ifstream &input_canales,ifstream &input_registro,
                      ifstream &input_televidentes,ofstream &output){
    int canal;
    // 555       /Deportes Internacional/
    while(true){
        input_canales >> canal;
        if(input_canales.eof()) break; // Validar fin del archivo "Canales.txt"
        int total_personas = 0,cant_menores = 0,cant_jovenes = 0,cant_adultos = 0,sumar_tiempo=0.0;
        imprimir_canal(canal,input_canales,output);
        imprimir_encabezado_televidentes(output);
        procesar_registro(canal,sumar_tiempo,cant_menores,cant_jovenes,
                          cant_adultos,total_personas,input_registro,input_televidentes,output);
        imprimir_resumen_por_canal(sumar_tiempo,cant_menores,cant_jovenes,
                                   cant_adultos,total_personas,output);
    }
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/








// Módulo que procesa el reporte solicitado
void procesar_reporte(const char *nombre_archivo_canales,
                      const char *nombre_archivo_televidentes,
                      const char *nombre_archivo_registro,
                      const char *nombre_archivo_reporte){
    ifstream input_canales,input_televidentes,input_registro;
    ofstream output;
    apertura_archivo_lectura(nombre_archivo_canales,input_canales);
    apertura_archivo_lectura(nombre_archivo_registro,input_registro);
    apertura_archivo_lectura(nombre_archivo_televidentes,input_televidentes);
    apertura_archivo_escritura(nombre_archivo_reporte,output);
    imprimir_titulo(output);
    output << fixed << setprecision(2);
    procesar_canales(input_canales,input_registro,input_televidentes,output);
}
