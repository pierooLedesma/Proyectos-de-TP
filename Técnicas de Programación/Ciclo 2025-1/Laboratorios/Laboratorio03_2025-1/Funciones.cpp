

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 7 de mayo de 2025, 06:41 PM
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
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "MINISTERIO DE TRANSPORTE" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "MULTAS IMPUESTAS A LAS COMPANIAS" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++)   output.put(caracter);
    output << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime la placa de un vehículo
void imprimir_placa_del_vehiculo(char tipo_de_vehiculo,int num_placa_1,
                                 int num_placa_2,ofstream &output){
    output << setw(3) << ' ' << "PLACA: ";
    output << tipo_de_vehiculo;
    output << num_placa_1 << '-' << num_placa_2;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime el tipo de vehículo (Pequeño, mediano o grande)
void imprimir_tipo_de_vehiculo(char tipo_de_vehiculo,ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 5) << ' ' << "TIPO: ";
    if(tipo_de_vehiculo == 'P')  output << "PEQUENO";
    else if(tipo_de_vehiculo == 'M')  output << "MEDIANO";
    else  output << "GRANDE";  //  tipo_de_vehiculo == 'G'
    output << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime el encabezado de vehículos infraccionados
void imprimir_encabezado_vehiculos_infraccionados(ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 4) << "No.";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 5) << "FECHA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 2) << "INFRACCION";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 2) << "GRAVEDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 2) << "MULTA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 2) << "DESCRIPCION";
    output << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que imprime una fecha en el formato siguiente: DD/MM/AAAA
void imprimir_fecha(int fecha,ofstream &output){
    output << setfill('0') << setw(2) << fecha % 100 << '/';
    output << setw(2) << fecha / 100 % 100 << '/';
    output << fecha / 10000 << setfill(' ');
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime la gravedad de una infracción
void imprimir_gravedad(char gravedad,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 1);
    
    if(gravedad == 'L')  output << "LEVE";
    else if(gravedad == 'G')  output << "GRAVE";
    else   output << "MUY GRAVE"; // gravedad == 'M'
    
    output << right;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que lee una placa del vehículo de la siguiente forma:  P201-291
void leer_placa_del_vehiculo(char &tipo_de_vehiculo,int &num_placa_1,
                             int &num_placa_2,ifstream &input){
    char guion;
    input >> tipo_de_vehiculo >> num_placa_1;
    input >> guion >> num_placa_2;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que lee una fecha DD/MM/AAAA y lo retorna en un valor entero
int leer_fecha(ifstream &input){
    int dia,mes,anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
    return anio * 10000  + mes * 100  +  dia;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que convierte una letra
// (un caracter) de minúscula a mayúscula.
char convertir_a_mayuscula(char c){
    return c - 'a' + 'A';
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/






// Módulo que pasa un caracter a mayúscula si es necesario
char capitalizar_si_es_necesario(char c, bool &mayuscula){
    if(mayuscula and (c >= 'a'   and   c <= 'z')) {
        c = convertir_a_mayuscula(c);
        mayuscula = false;
    }
    return c;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que lee e imprime una cadena de caracteres
void leer_e_imprimir_cadena_de_caracteres(bool ninguna_modificacion_en_la_cadena,
        bool es_nombre_representante_legal,char delimitador,bool imprimir_espacio_en_blanco,
        ifstream &input,ofstream &output){
    int n_caracteres = 0;
    bool mayuscula = es_nombre_representante_legal;
    input >> ws; // Lectura de los espacios en blanco

    while (true) {
        char c = input.get(); // Lectura de un caracter
        if(c == delimitador) break;
        if(not ninguna_modificacion_en_la_cadena){
            if (c == '/'  or  c == '-'  or  c == '_'){
                c = ' ';
                if(es_nombre_representante_legal)  mayuscula = true;
            }
            if(es_nombre_representante_legal)  c = capitalizar_si_es_necesario(c, mayuscula);
        }
        output.put(c); // Impresión del caracter
        n_caracteres++; // Actualización de la cantidad de caracteres que se lee
    }
    
    if(imprimir_espacio_en_blanco){
        int tam = TAM_REPORTE / (N_COLUMNAS - 2);
        for(int i=0; i < tam - n_caracteres; i++) output.put(' ');
    } else 
        output << endl; // Se imprime el cambio de línea
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime los datos del representante legal y también realiza el proceso de
// lectura e impresión del nombre del representante legal y del nombre del distrito.
void imprimir_datos_del_representante_legal(int &n_compania,int dni_representante_legal,
                                            ifstream &input_empresas,ofstream &output){
    n_compania++;
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "COMPANIA No. " << setw(2) << n_compania << endl;
    output << "REPRESENTANTE LEGAL: ";
    leer_e_imprimir_cadena_de_caracteres(false,true,' ',true,input_empresas,output);
    output << "DNI: " << dni_representante_legal;
    output << setw(TAM_REPORTE / N_COLUMNAS) << "DISTRITO: ";
    leer_e_imprimir_cadena_de_caracteres(false,false,' ',false,input_empresas,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Imprimir la infracción de tránsito en caso exista en el archivo "TablaDeInfracciones.txt"
void imprimir_infraccion_de_transito(char gravedad,double multa,bool imprimir_descripcion,
                                     ifstream &input_tabla,ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 6) << ' ';
    if(imprimir_descripcion){
        imprimir_gravedad(gravedad,output);
        output << setw(7) << multa;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 10) - 8) << ' ';
        leer_e_imprimir_cadena_de_caracteres(true,false,'\n',false,input_tabla,output);
    } else {
        output << "No se encontro esa infraccion";
        output << endl;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que actualiza los acumuladores de montos pagados de faltas como de los dni's
void actualizar_acumuladores_de_faltas(int &cant_faltas_leves,
                    double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                    double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                    double &monto_pagado_faltas_muy_graves,double multa,char gravedad){
    if(gravedad == 'L'){
        // Fata Leve
        cant_faltas_leves++;
        monto_pagado_faltas_leves += multa;
    } else if(gravedad == 'G') {
        // Falta Grave
        cant_faltas_graves++;
        monto_pagado_faltas_graves += multa;
    } else {
        // gravedad == 'M' -> Falta Muy Grave
        cant_faltas_muy_graves++;
        monto_pagado_faltas_muy_graves += multa;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime una descripción de tránsito mediante el archivo "TablaDeInfracciones.txt"
void imprimir_descripcion_infraccion_de_transito(char gravedad,int num_infraccion,
                        ifstream &input_tabla,ofstream &output,int &cant_faltas_leves,
                        double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                        double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                        double &monto_pagado_faltas_muy_graves){
    char gravedad_leido;
    int num_infraccion_leido;
    double multa = 0.0;
    bool imprimir_descripcion = false, se_actualiza = false;
    input_tabla.clear(); // Libera el buffer del archivo "TablaDeInfracciones.txt" y limpia las banderas levantadas
    input_tabla.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "TablaDeInfracciones.txt"
    while(true){
        input_tabla >> gravedad_leido;
        if(input_tabla.eof()) break; // Validar fin del archivo "TablaDeInfracciones.txt"
        input_tabla >> num_infraccion_leido;
        if(gravedad_leido == gravedad  and  num_infraccion_leido == num_infraccion){
            input_tabla >> multa;
            imprimir_descripcion = se_actualiza = true;
            break;
        } else
            while(input_tabla.get() != '\n'); // Descartar infracción de tránsito
    }
    imprimir_infraccion_de_transito(gravedad,multa,imprimir_descripcion,input_tabla,output);
    if(se_actualiza) actualizar_acumuladores_de_faltas(cant_faltas_leves,
                                   monto_pagado_faltas_leves,cant_faltas_graves,monto_pagado_faltas_graves,
                                   cant_faltas_muy_graves,monto_pagado_faltas_muy_graves,multa,gravedad);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime las características leídas de una infracción del archivo "InfraccionesCometidas.txt"
void imprimir_caracteristica_de_la_infraccion(int &cant_infracciones,int fecha,
        int num_infraccion,char gravedad,ifstream &input_tabla,ofstream &output,int &cant_faltas_leves,
        double &monto_pagado_faltas_leves,int &cant_faltas_graves,double &monto_pagado_faltas_graves,
        int &cant_faltas_muy_graves,double &monto_pagado_faltas_muy_graves){
    cant_infracciones++;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 7) << ' ';
    output << setfill('0') << setw(2) << cant_infracciones << setfill(' ') << ')';
    output << setw(TAM_REPORTE / (N_COLUMNAS + 10) - 10) << ' ';
    imprimir_fecha(fecha,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 10) - 2) << num_infraccion;
    
    // Se procede a buscar e imprimir la descripción de tránsito mediante el archivo "TablaDeInfracciones.txt"
    imprimir_descripcion_infraccion_de_transito(gravedad,num_infraccion,input_tabla,output,
            cant_faltas_leves,monto_pagado_faltas_leves,cant_faltas_graves,monto_pagado_faltas_graves,
            cant_faltas_muy_graves,monto_pagado_faltas_muy_graves);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que procesa el archivo "InfraccionesCometidas.txt". Mediante este achivo se
// imprimen las características de la infracción cometida de un vehículo por medio de su placa.
void procesar_infracciones_cometidas(char tipo_de_vehiculo,int num_placa_1,int num_placa_2,
                         int &cant_faltas_leves,double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                         double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                         double &monto_pagado_faltas_muy_graves,ifstream &input_infracciones,
                         ifstream &input_tabla,ofstream &output){
    int fecha,num_placa_1_leido,num_placa_2_leido,num_infraccion,cant_infracciones = 0;
    char tipo_vehiculo_leido,gravedad;
    bool se_tienen_infracciones = false;
    input_infracciones.clear(); // Libera el buffer del archivo "InfraccionesCometidas.txt" y limpia las banderas levantadas
    input_infracciones.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "InfraccionesCometidas.txt"
    while(true){
        fecha = leer_fecha(input_infracciones);
        if(input_infracciones.eof()) break; // Validar fin del archivo "InfraccionesCometidas.txt"
        leer_placa_del_vehiculo(tipo_vehiculo_leido,num_placa_1_leido,
                                                num_placa_2_leido,input_infracciones);
        if(tipo_vehiculo_leido == tipo_de_vehiculo  and  num_placa_1_leido == num_placa_1  and
           num_placa_2_leido == num_placa_2){
            input_infracciones >> gravedad >> num_infraccion;
            imprimir_caracteristica_de_la_infraccion(cant_infracciones,fecha,num_infraccion,
                    gravedad,input_tabla,output,cant_faltas_leves,monto_pagado_faltas_leves,
                    cant_faltas_graves,monto_pagado_faltas_graves,cant_faltas_muy_graves,
                    monto_pagado_faltas_muy_graves);
            se_tienen_infracciones = true; // Se encontró al menos una infracción
        } else {
            while(input_infracciones.get() != '\n'); // Descartar código de infracción
        }
    }
    
    // Preguntar si no tienen infracciones cometidas
    if(not se_tienen_infracciones){
        output << setw(TAM_REPORTE / N_COLUMNAS  + 5);
        output << "NO TIENE INFRACCIONES REGISTRADAS" << endl;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que procesa las placas de vehículos de una empresa
// del archivo "EmpresasRegistradas.txt" (una lectura variable).
void procesar_placas_de_vehiculos_de_la_empresa(int &cant_faltas_leves,                        
                        double &monto_pagado_faltas_leves,int &cant_faltas_graves,
                        double &monto_pagado_faltas_graves,int &cant_faltas_muy_graves,
                        double &monto_pagado_faltas_muy_graves,ifstream &input_empresas,
                        ifstream &input_infracciones,ifstream &input_tabla,ofstream &output){
    int n_vehiculos = 1,num_placa_1,num_placa_2;
    char tipo_de_vehiculo;
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "VEHICULOS INFRACIONADOS:" << endl;
    while(true){
        leer_placa_del_vehiculo(tipo_de_vehiculo,num_placa_1,num_placa_2,input_empresas);
        output << setw(2) << ' ' << setfill('0') << setw(2) << n_vehiculos << setfill(' ') << ')';
        imprimir_placa_del_vehiculo(tipo_de_vehiculo,num_placa_1,num_placa_2,output);
        imprimir_tipo_de_vehiculo(tipo_de_vehiculo,output);
        imprimir_encabezado_vehiculos_infraccionados(output);
        procesar_infracciones_cometidas(tipo_de_vehiculo,num_placa_1,num_placa_2,
                             cant_faltas_leves,monto_pagado_faltas_leves,cant_faltas_graves,
                             monto_pagado_faltas_graves,cant_faltas_muy_graves,
                             monto_pagado_faltas_muy_graves,input_infracciones,input_tabla,output);
        n_vehiculos++;
        if(input_empresas.get() == '\n') break;
        else  elaborar_lineas('-',TAM_REPORTE,output);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que imprime el resumen de las faltas registradas de una empresa
void imprimir_resumen_de_faltas_de_una_empresa(int cant_faltas_leves,
                    double monto_pagado_faltas_leves,int cant_faltas_graves,
                    double monto_pagado_faltas_graves,int cant_faltas_muy_graves,
                    double monto_pagado_faltas_muy_graves,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "CANTIDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 5);
    output << "MONTO PAGADO" << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS LEVES:" << right;
    output << setw(2) << cant_faltas_leves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 2);
    output << monto_pagado_faltas_leves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS GRAVES:" << right;
    output << setw(2) << cant_faltas_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 2);
    output << monto_pagado_faltas_graves << endl;
    
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 4);
    output << "FALTAS MUY GRAVES:" << right;
    output << setw(2) << cant_faltas_muy_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 2);
    output << monto_pagado_faltas_muy_graves << endl;
    
    elaborar_lineas('-',TAM_REPORTE / (N_COLUMNAS - 2) - 1,output);
    output << left << setw(TAM_REPORTE / N_COLUMNAS) << "PAGO TOTAL:" << right;
    output << setw(8) << monto_pagado_faltas_leves + monto_pagado_faltas_graves +
                         monto_pagado_faltas_muy_graves << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





        
// Módulo que actualiza si la compañía procesada tiene el mayor o menor pago por infracciones
void actualizar_compania_con_mayor_y_menor_pago(int &dni_mayor_pago,
        double &mayor_total_pago,int &dni_menor_pago,double &menor_total_pago,
        int dni_representante_legal,double pago_total){
    // Preguntar si el "pago total" de la empresa procesada es la de
    // mayor pago por infracciones de todas las empresas.
    if(pago_total > mayor_total_pago){
        dni_mayor_pago = dni_representante_legal;
        mayor_total_pago = pago_total;
    }
    
    // Preguntar si el "pago total" de la empresa procesada es la de
    // menor pago por infracciones de todas las empresas.
    if(pago_total < menor_total_pago){
        dni_menor_pago = dni_representante_legal;
        menor_total_pago = pago_total;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que procesa el archivo "EmpresasRegistradas.txt".
void procesar_empresas(int &dni_mayor_pago,double &mayor_total_pago,int &dni_menor_pago,
        double &menor_total_pago,ifstream &input_empresas,ifstream &input_infracciones,
        ifstream &input_tabla,ofstream &output){
    int dni_representante_legal,n_compania = 0;
    while(true){
        // Lectura fija del archivo "EmpresasRegistradas.txt"
        input_empresas >> dni_representante_legal;
        if(input_empresas.eof()) break; // Validar fin del archivo "EmpresasRegistradas.txt"
        imprimir_datos_del_representante_legal(n_compania,dni_representante_legal,
                                               input_empresas,output);
        
        // Lectura variable del archivo "EmpresasRegistradas.txt"
        int cant_faltas_leves = 0,cant_faltas_graves = 0,cant_faltas_muy_graves = 0;
        double monto_pagado_faltas_leves = 0.0,monto_pagado_faltas_graves = 0.0,
                    monto_pagado_faltas_muy_graves = 0.0;
        procesar_placas_de_vehiculos_de_la_empresa(cant_faltas_leves,
                    monto_pagado_faltas_leves,cant_faltas_graves,monto_pagado_faltas_graves,
                    cant_faltas_muy_graves,monto_pagado_faltas_muy_graves,input_empresas,
                    input_infracciones,input_tabla,output);
        
        // Impresión del resumen de una empresa y actualización de mayor y menor pago por infracciones
        imprimir_resumen_de_faltas_de_una_empresa(cant_faltas_leves,
                    monto_pagado_faltas_leves,cant_faltas_graves,monto_pagado_faltas_graves,
                    cant_faltas_muy_graves,monto_pagado_faltas_muy_graves,output),
        actualizar_compania_con_mayor_y_menor_pago(dni_mayor_pago,mayor_total_pago,
                                        dni_menor_pago,menor_total_pago,dni_representante_legal,
                                        monto_pagado_faltas_leves + monto_pagado_faltas_graves +
                                        monto_pagado_faltas_muy_graves);
    }
    elaborar_lineas('=',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/








// Módulo que imprime la compañía con mayor y menor pago por infracciones
void imprimir_compania_con_mayor_y_menor_pago_por_infracciones(int dni_mayor_pago,
        double mayor_total_pago,int dni_menor_pago,double menor_total_pago,
        ofstream &output){
    elaborar_lineas('+',TAM_REPORTE / (N_COLUMNAS - 2) - 1,output);
    output << "+ COMPANIA CON MAYOR PAGO POR INFRACCIONES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 10) - 2) << '+' << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 4);
    output << "+ DNI:" << right;
    output << dni_mayor_pago << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 7);
    output << '+' << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1);
    output << "+ TOTAL PAGADO:" << right;
    output << setw(7) << mayor_total_pago;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 7) << '+' << endl;
    
    elaborar_lineas('+',TAM_REPORTE / (N_COLUMNAS - 2) - 1,output);
    output << "+ COMPANIA CON MENOR PAGO POR INFRACCIONES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 10) - 2) << '+' << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 4);
    output << "+ DNI:" << right;
    output << dni_menor_pago << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 7);
    output << '+' << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5));
    output << "+ TOTAL PAGADO:" << right;
    output << setw(7) << menor_total_pago;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 7) << '+' << endl;
    elaborar_lineas('+',TAM_REPORTE / (N_COLUMNAS - 2) - 1,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/







// Módulo que elabora el reporte solicitado
void elaborar_reporte(const char *nombre_archivo_empresas,
                      const char *nombre_archivo_infracciones,
                      const char *nombre_archivo_tabla,
                      const char *nombre_archivo_reporte){
    ifstream input_empresas,input_infracciones,input_tabla;
    ofstream output;
    int dni_mayor_pago,dni_menor_pago;
    double mayor_total_pago = 0.0,menor_total_pago = 1e09;
    aperturar_archivo_lectura(nombre_archivo_empresas,input_empresas);
    aperturar_archivo_lectura(nombre_archivo_infracciones,input_infracciones);
    aperturar_archivo_lectura(nombre_archivo_tabla,input_tabla);
    aperturar_archivo_escritura(nombre_archivo_reporte,output);
    output << fixed << setprecision(2);
    imprimir_titulo(output);
    procesar_empresas(dni_mayor_pago,mayor_total_pago,dni_menor_pago,menor_total_pago,
                      input_empresas,input_infracciones,input_tabla,output);
    imprimir_compania_con_mayor_y_menor_pago_por_infracciones(dni_mayor_pago,
                        mayor_total_pago,dni_menor_pago,menor_total_pago,output);
}

