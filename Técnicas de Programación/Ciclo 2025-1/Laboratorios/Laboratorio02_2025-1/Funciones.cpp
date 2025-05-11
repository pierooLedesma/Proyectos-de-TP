

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de abril de 2025, 08:18 PM
 */

#include "Funciones.h"



// Módulo que apertura un archivo de lectura sin usar el constructor
void apertura_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






// Módulo que apertura un archivo de escritura sin usar el constructor
void apertura_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(ofstream &output){
    output << setw( (TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "MINISTERIO DE TRANSPORTE" << endl;
    output << setw( (TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "MULTAS IMPUESTAS A LAS COMPANIAS" << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






// Módulo que imprime el encabezado de los vehiculos infraccionados
void imprimir_encabezado_vehiculos_infraccionados(ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "VEHICULOS INFRACCIONADOS:" << endl;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 9) << "PLACA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 6) << "TIPO";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 1) << "FECHA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 3) << "INFRACCION";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 2) << "GRAVEDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 5) << "MULTA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 5) << "DESCRIPCION";
    output << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que imprime las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que imprime la fecha en DD/MM/AAAA
void imprimir_fecha(int fecha,ofstream &output){
    output << setfill('0') << setw(2) << fecha % 100 << '/';
    output << setw(2) << fecha / 100 % 100 << '/';
    output << fecha / 10000 << setfill(' ');
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







// Módulo que imprime el tipo del vehículo
void imprimir_tipo(char tipo,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 2);
    if(tipo == 'P')  output << "PEQUENO";
    else if(tipo == 'M')  output << "MEDIANO";
    else   output << "GRANDE";  // tipo == 'G'
    output << right;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







// Módulo que imprime la gravedad de la infracción
void imprimir_gravedad(char gravedad,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 1);
    if(gravedad == 'L')  output << "LEVE";
    else if(gravedad == 'G') output << "GRAVE";
    else   output << "MUY GRAVE";  // gravedad == 'M'
    output << right;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






// Módulo que imprime una descripción de la infracción leída del archivo
// "InfraccionesCometidas.txt". Imprimirá el tipo del vehículo, la fecha
// de la infracción, la placa del vehículo y el código de la infracción.
void imprimir_descripcion(char tipo,int num_1_placa,int num_2_placa,
                          int fecha,int cod_infraccion,ofstream &output){
    output << left << setw(2) << '-';
    output << num_1_placa << num_2_placa << tipo;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 10)  - 10) << ' ';
    imprimir_tipo(tipo,output);
    imprimir_fecha(fecha,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) ) << cod_infraccion;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 3) << ' ';
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/









// Módulo que imprime la gravedad de la infracción, la multa
// correspondiente y la descripción de la infracción que
// fue leída del archivo "InfraccionesDeTransito.txt".
void imprimir_gravedad_multa_descripcion(bool imprimir_la_descripcion_de_la_infraccion,
        char gravedad,double multa,ofstream &output,ifstream &input){
    if(imprimir_la_descripcion_de_la_infraccion){
        imprimir_gravedad(gravedad,output);
        output << setw(7) << multa;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 18) - 1) << ' ';
        lectura_e_impresion_cadena_caracteres(false,'\n',input,output);
    } else {
        output << "----" << setw(TAM_REPORTE / N_COLUMNAS) << "-----";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 3));
        output << "NO SE ENCONTRO LA INFRACCION.";
        output << endl;
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que imprime la fecha en DD/MM/AAAA
int leer_fecha(ifstream &input){
    int dia,mes,anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que imprime una cadena de caracteres y dependerá el
// formato de la impresión si es o no es el nombre del representante
void lectura_e_impresion_cadena_caracteres(bool esRepresentante,
        char delimitador,ifstream &input,ofstream &output){
    int n_caracteres = 0;
    bool bandera_mayuscula = true;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        char c = input.get();
        if(c == delimitador) break;
        if(esRepresentante){
            if(c == '-'  or  c == '/'){
                c = ' ';
                bandera_mayuscula = true; // La siguiente letra debe ser impresa en mayúscula
            } else if (bandera_mayuscula){
                bandera_mayuscula = false; // La siguiente letra debe ser impresa en minúscula
            } else {
                c = c - 'A' + 'a'; // Conversión de mayúscula a minúscula
            }
        }
        output.put(c);
        n_caracteres++;
    }
    if(esRepresentante) for(int i=0; i < (TAM_REPORTE / 2) - n_caracteres; i++) output.put(' ');
    else  output << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/









// Módulo que lee el nombre del representante legal
// e imprime los datos de este representante legal (nombre y su DNI).
void leer_e_imprimir_representante_legal(int n_representantes,int dni,
                                    ifstream &input,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "COMPANIA No. " << setfill('0') << setw(2);
    output << n_representantes << setfill(' ') << endl;
    output << "REPRESENTANTE LEGAL:  ";
    lectura_e_impresion_cadena_caracteres(true,' ',input,output);
    output << "DNI:  " << dni << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







// Módulo que lee una descripción de infracción del archivo
// "InfraccionesCometidas.txt" (la placa, la fecha de la infracción
// y el código de la infracción cometida).
void leer_descripcion(char &tipo,int &num_1_placa,int &num_2_placa,int &fecha,
                      int &cod_infraccion,ifstream &input){
    char guion;
    input >> tipo >> num_1_placa >> guion >> num_2_placa;
    fecha = leer_fecha(input);
    input >> cod_infraccion;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







// Módulo que actualiza los acumuladores de las faltas (leve, grave, muy grave).
void actualizar_acumuladores_de_faltas(int &cant_leves,double &monto_pagado_leves,
        int &cant_graves,double &monto_pagado_graves,int &cant_muy_graves,
        double &monto_pagado_muy_graves,double multa,char gravedad){
    if(gravedad == 'L'){
        cant_leves++;
        monto_pagado_leves += multa;
    } else if(gravedad == 'G') {
        cant_graves++;
        monto_pagado_graves += multa;
    } else {
        // La falta es "MUY GRAVE"  (gravedad == 'M')
        cant_muy_graves++;
        monto_pagado_muy_graves += multa;
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que procesa el archivo "InfraccionesDeTransito.txt".
// Busca e imprime la descripción de la infracción mediante este archivo.
void buscar_e_imprimir_infraccion(int cod_infraccion,ifstream &input,
        ofstream &output,int &cant_leves,double &monto_pagado_leves,
        int &cant_graves,double &monto_pagado_graves,int &cant_muy_graves,
        double &monto_pagado_muy_graves){
    char gravedad;
    int cod_infraccion_leido;
    double multa;
    bool imprimir_la_descripcion_de_la_infraccion = false;
    
    input.clear();// Libera el buffer del archivo "InfraccionesDeTransito.txt" y limpia las banderas levantadas
    input.seekg(0,ios::beg);// Devuelve el puntero al inicio del archivo "InfraccionesDeTransito.txt"
    
    while(true){
        input >> gravedad >> cod_infraccion_leido;
        if(input.eof()) break; // Validar fin del archivo "InfraccionesDeTransito.txt"
        input >> multa;
        if(cod_infraccion_leido == cod_infraccion){
            actualizar_acumuladores_de_faltas(cant_leves,monto_pagado_leves,
                    cant_graves,monto_pagado_graves,
                    cant_muy_graves,monto_pagado_muy_graves,multa,gravedad);
            imprimir_la_descripcion_de_la_infraccion = true;
            break;
        } else {
            while(input.get() != '\n'); // Descartar descripción de infracción
        }
    }
    imprimir_gravedad_multa_descripcion(imprimir_la_descripcion_de_la_infraccion,
                                        gravedad,multa,output,input);
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/










// Módulo que procesa las descripciones de infracciones.
// Es la lectura variable del archivo "InfraccionesCometidas.txt".
void procesar_descripcion_de_infracciones(int &cant_leves,double &monto_pagado_leves,
        int &cant_graves,double &monto_pagado_graves,int &cant_muy_graves,
        double &monto_pagado_muy_graves,ifstream &input_inf_com,
        ifstream &input_inf_transito,ofstream &output){
    int num_1_placa,num_2_placa,fecha,cod_infraccion;
    char tipo;
    imprimir_encabezado_vehiculos_infraccionados(output);
    while(true){
        leer_descripcion(tipo,num_1_placa,num_2_placa,fecha,cod_infraccion,input_inf_com);
        imprimir_descripcion(tipo,num_1_placa,num_2_placa,fecha,cod_infraccion,output);
        buscar_e_imprimir_infraccion(cod_infraccion,input_inf_transito,output,
                cant_leves,monto_pagado_leves,cant_graves,monto_pagado_graves,
                cant_muy_graves,monto_pagado_muy_graves);
        if(input_inf_com.get() == '\n') break;
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/










// Módulo que imprime el resumen de infracciones
// por representante legal (es decir, por compañía).
void imprimir_resumen_infracciones_por_representante_legal(int cant_leves,
        double monto_pagado_leves,int cant_graves,double monto_pagado_graves,
        int cant_muy_graves,double monto_pagado_muy_graves,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "CANTIDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 5);
    output << "MONTO PAGADO" << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS LEVES:" << right;
    output << setw(2) << cant_leves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_pagado_leves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS GRAVES:" << right;
    output << setw(2) << cant_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_pagado_graves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS MUY GRAVES:" << right;
    output << setw(2) << cant_muy_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_pagado_muy_graves << endl;
    
    elaborar_lineas('-',TAM_REPORTE / (N_COLUMNAS - 2) - 1,output);
    output << left << setw(TAM_REPORTE / N_COLUMNAS) << "PAGO TOTAL:" << right;
    output << setw(8) << monto_pagado_leves + monto_pagado_graves +
                         monto_pagado_muy_graves << endl;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que actualiza los totales recaudados por infracción
void actualizar_totales_recaudados_por_infraccion(int cant_leves,
        double monto_pagado_leves,int cant_graves,double monto_pagado_graves,
        int cant_muy_graves,double monto_pagado_muy_graves,
        int &cant_total_faltas_leves,double &monto_total_del_total__faltas_leves,
        int &cant_total_faltas_graves,double &monto_total_del_total__faltas_graves,
        int &cant_total_faltas_muy_graves,
        double &monto_total_del_total_faltas_muy_graves){
    cant_total_faltas_leves += cant_leves;
    monto_total_del_total__faltas_leves += monto_pagado_leves;
    
    cant_total_faltas_graves += cant_graves;
    monto_total_del_total__faltas_graves += monto_pagado_graves;
    
    cant_total_faltas_muy_graves += cant_muy_graves;
    monto_total_del_total_faltas_muy_graves += monto_pagado_muy_graves;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/









// Módulo que actualiza la compañía con el mayor y menor pago por infracción
void actualizar_mayor_y_menor_pago_por_infracciones(int &dni_mayor_pago,
        double &total_mayor_pago,int &dni_menor_pago,double &total_menor_pago,
        double pago_total,int dni_representante,ofstream &output){
    if(total_mayor_pago < pago_total){
        dni_mayor_pago = dni_representante;
        total_mayor_pago = pago_total;
    }
    if(total_menor_pago > pago_total){
        dni_menor_pago = dni_representante;
        total_menor_pago = pago_total;
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/










// Módulo que procesa el archivo "InfraccionesCometidas.txt"
void procesar_infracciones_cometidas(int &dni_mayor_pago,double &total_mayor_pago,
        int &dni_menor_pago,double &total_menor_pago,ifstream &input_inf_com,
        ifstream &input_inf_transito,ofstream &output,
        int &cant_total_faltas_leves,double &monto_total_del_total__faltas_leves,
        int &cant_total_faltas_graves,double &monto_total_del_total__faltas_graves,
        int &cant_total_faltas_muy_graves,double &monto_total_del_total__faltas_muy_graves){
    int dni_representante,n_representantes = 0;
// 82031355  EGUSQUIZA/BERROCAL/DORIS-NANCY  P386-900  10/02/2023   2019  M599-949   29/05/2023   2065
    while(true){
        // Lectura fija de archivo "InfraccionesCometidas.txt"
        input_inf_com >> dni_representante;
        if(input_inf_com.eof()) break; // Validar fin del archivo "InfraccionesCometidas.txt"
        n_representantes++;
        leer_e_imprimir_representante_legal(n_representantes,dni_representante,input_inf_com,output);
        
        // Lectura variable de archivo "InfraccionesCometidas.txt"
        int cant_leves = 0, cant_graves = 0, cant_muy_graves = 0;
        double monto_pagado_leves = 0.0, monto_pagado_graves = 0.0, monto_pagado_muy_graves = 0.0;
        procesar_descripcion_de_infracciones(cant_leves,monto_pagado_leves,
                cant_graves,monto_pagado_graves,cant_muy_graves,monto_pagado_muy_graves,
                input_inf_com,input_inf_transito,output);
        imprimir_resumen_infracciones_por_representante_legal(cant_leves,monto_pagado_leves,
                cant_graves,monto_pagado_graves,cant_muy_graves,monto_pagado_muy_graves,output);
        actualizar_totales_recaudados_por_infraccion(cant_leves,
                monto_pagado_leves,cant_graves,monto_pagado_graves,
                cant_muy_graves,monto_pagado_muy_graves,cant_total_faltas_leves,
                monto_total_del_total__faltas_leves,cant_total_faltas_graves,
                monto_total_del_total__faltas_graves,
                cant_total_faltas_muy_graves,monto_total_del_total__faltas_muy_graves);
        actualizar_mayor_y_menor_pago_por_infracciones(dni_mayor_pago,
                total_mayor_pago,dni_menor_pago,total_menor_pago,
                monto_pagado_leves + monto_pagado_graves + monto_pagado_muy_graves,
                dni_representante,output);
    }
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/









// Módulo que imprime el total recaudado por infracciones
void imprimir_total_recaudado_por_infracciones(int cant_total_faltas_leves,
        double monto_total_del_total__faltas_leves,int cant_total_faltas_graves,
        double monto_total_del_total__faltas_graves,int cant_total_faltas_muy_graves,
        double monto_total_del_total__faltas_muy_graves,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "TOTAL RECAUDADO POR INFRACCIONES" << endl;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 1) << "CANTIDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 5) << "MONTO PAGADO" << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 2);
    output << "TOTAL DE FALTAS LEVES:" << right;
    output << setw(4) << cant_total_faltas_leves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_total_del_total__faltas_leves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 2);
    output << "TOTAL DE FALTAS GRAVES:" << right;
    output << setw(4) << cant_total_faltas_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_total_del_total__faltas_graves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 2);
    output << "TOTAL DE FALTAS MUY GRAVES:" << right;
    output << setw(4) << cant_total_faltas_muy_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 3);
    output << monto_total_del_total__faltas_muy_graves << endl;
    
    output << left << setw(TAM_REPORTE / N_COLUMNAS + 3) << "PAGO TOTAL:" << right;
    output << setw(12) << monto_total_del_total__faltas_leves +
                          monto_total_del_total__faltas_graves +
                          monto_total_del_total__faltas_muy_graves << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/









// Módulo que imprime la companía con mayor y menor pago por infracciones
void imprimir_compania_con_mayor_y_menor_pago_por_infracciones(int dni_mayor_pago,
        double total_mayor_pago,int dni_menor_pago,double total_menor_pago,
        ofstream &output){
    output << endl;
    elaborar_lineas('/',TAM_REPORTE / (N_COLUMNAS - 2) - 3,output);
    output << "//COMPANIA CON MAYOR PAGO POR INFRACCIONES:  //" << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 2);
    output << "//DNI:" << right;
    output << dni_mayor_pago << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1);
    output << ' ' << "//" << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1);
    output << "//TOTAL PAGADO:" << right;
    output << setw(7) << total_mayor_pago;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) -1) << ' ' << "//" << endl;
    
    elaborar_lineas('/',TAM_REPORTE / (N_COLUMNAS - 2) - 3,output);
    output << "//COMPANIA CON MENOR PAGO POR INFRACCIONES:  //" << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 2);
    output << "//DNI:" << right;
    output << dni_menor_pago << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1);
    output << ' ' << "//" << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1);
    output << "//TOTAL PAGADO:" << right;
    output << setw(7) << total_menor_pago;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) -1) << ' ' << "//" << endl;
    elaborar_lineas('/',TAM_REPORTE / (N_COLUMNAS - 2) - 3,output);
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








// Módulo que procesa el reporte solicitado. En este módulo se inicializan
// los acumuladores para el cálculo de los totales recaudados por infracción
// y de la compañía con mayor y menor pago.
void procesar_reporte(const char *nombre_archivo_infra_cometidas,
                      const char *nombre_archivo_infra_transito,
                      const char *nombre_archivo_reporte){
    ifstream input_inf_com,input_inf_transito;
    ofstream output;
    int dni_mayor_pago,dni_menor_pago,cant_total_faltas_leves=0,
        cant_total_faltas_graves=0,cant_total_faltas_muy_graves=0;
    double total_mayor_pago = 0.0,total_menor_pago=1e09,
           monto_total_del_total__faltas_leves=0.0,
           monto_total_del_total__faltas_graves=0.0,
           monto_total_del_total__faltas_muy_graves=0.0;
    apertura_archivo_lectura(nombre_archivo_infra_cometidas,input_inf_com);
    apertura_archivo_lectura(nombre_archivo_infra_transito,input_inf_transito);
    apertura_archivo_escritura(nombre_archivo_reporte,output);
    output << fixed << setprecision(2);
    imprimir_titulo(output);
    procesar_infracciones_cometidas(dni_mayor_pago,total_mayor_pago,
            dni_menor_pago,total_menor_pago,input_inf_com,input_inf_transito,
            output,cant_total_faltas_leves,monto_total_del_total__faltas_leves,
            cant_total_faltas_graves,monto_total_del_total__faltas_graves,
            cant_total_faltas_muy_graves,monto_total_del_total__faltas_muy_graves);
    imprimir_total_recaudado_por_infracciones(cant_total_faltas_leves,
            monto_total_del_total__faltas_leves,cant_total_faltas_graves,
            monto_total_del_total__faltas_graves,cant_total_faltas_muy_graves,
            monto_total_del_total__faltas_muy_graves,output);
    imprimir_compania_con_mayor_y_menor_pago_por_infracciones(dni_mayor_pago,
            total_mayor_pago,dni_menor_pago,total_menor_pago,output);
}
