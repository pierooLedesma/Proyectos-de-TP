

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 15 de junio del 2025, 01:12 PM
 */

#include "Funciones.h"
#include "Utils.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato de tipo "int"
int leer_dato_int(ifstream &input) {
    int dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo "double"
double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get(); // Lectura de la coma
    return dato;
}



// Módulo que lee un dato de tipo "char"
char leer_dato_char(ifstream &input) {
    char dato;
    input >> dato;
    return dato;
}



// Módulo que asigna una cadena con memoria exacta
char *asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}



// Módulo que lee una cadena de caracteres y lo almacena con memoria exacta.
// Se puede leer la cadena de caracteres mediante el operador de lectura o con "getline()".
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura) {
    char buffer[160], *cadena;
    if(leer_con_el_operador_de_lectura) {
        input >> buffer;
    } else {
        input.getline(buffer, 160, delimitador);
    }
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}




// Módulo que lee una fecha de la forma DD/MM/AAAA y
// retorna esta fecha como un valor entero
int leer_fecha(ifstream &input) {
    int dia, mes, anio;
    char slash;
    
    dia = leer_dato_int(input);
    slash = leer_dato_char(input);
    mes = leer_dato_int(input);
    slash = leer_dato_char(input);
    anio = leer_dato_int(input);
    
    return anio*10000 + mes*100 + dia;
}




// Módulo que imprime una fecha de la forma DD/MM/AAAA
void imprimir_fecha(int fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha%100 << '/';
    output << setw(2) << fecha / 100 % 100 << '/';
    output << fecha / 10000 << setfill(' ');
}




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cantidad_de_caracteres, ofstream &output) {
    for(int i=0; i<cantidad_de_caracteres; i++)  output.put(caracter);
    output << endl;
}






// Módulo que imprime el título del reporte de prueba de empresas o el títutlo del reporte solicitado
void imprimir_titulo_de_empresas(bool es_reporte_de_prueba, ofstream &output) {
    if(es_reporte_de_prueba) {
        output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
        output << "VERIFICAR DATOS DE EMPRESAS" << endl;
    } else {
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "MINISTERIO DE TRANSPORTES" << endl;
        output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
        output << "LISTADO DE INFRACCIONES POR EMPRESA" << endl;
    }
}






// Módulo que imprime el encabezado del reporte de empresas
void imprimir_encabezado_de_empresas(ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(3 * (TAM_REPORTE / (N_COLUMNAS + 3)) - 8) << "EMPRESA";
    output << setw(5 * (TAM_REPORTE / (N_COLUMNAS + 3)) + 5) << "FECHA INF.";
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) / 2  + 9) << "FECHA PAGO";
    output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 3)) + 1) << "TOTAL PAGADO";
    output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 3)) - 3) << "CANTIDAD";
    output << endl;
    output << "No.";
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) / 2  - 5) << "DNI";
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) / 2  + 4) << "NOMBRE";
    output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 3))  + 7) << "DISTRITO";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  + 7) << "PLACAS";
    output << setw(3 * (TAM_REPORTE / (N_COLUMNAS + 3))  + 1) << "MAS ANTIGUA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)) << "MAS RECIENTE";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 1) << "LEVES";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  - 4) << "GRAVES";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)  + 1) << "MUY GRAVES";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)) << "DE FALTAS";
    output << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}








// Módulo que imprime los datos de una empresa.
void imprimir_datos_de_una_empresa(int n_empresa, int dni, char *nombre, char *distrito, char *listaDePlacas,
                   int fechaInfraccionMasAntigua, int fechaPagoMasReciente, double totalPagadoLeve,
                   double totalPagadoGrave, double totalPagadoMuyGrave, int cantidadDeFaltas, ofstream &output) {
    output << setw(2) << n_empresa << ')';
    output << setw(TAM_REPORTE / (N_COLUMNAS + 7) - 5) << dni;
    output << setw((TAM_REPORTE / (N_COLUMNAS + 7)) / 2  - 4) << ' ';
    output << left << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 3)) + 5) << nombre;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 9) << distrito;
    output << setw(3 * (TAM_REPORTE / (N_COLUMNAS + 3)) - 4) << listaDePlacas << right;
    imprimir_fecha(fechaInfraccionMasAntigua, output);
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) / 2) << ' ';
    imprimir_fecha(fechaPagoMasReciente, output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 2) << totalPagadoLeve;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 4) << totalPagadoGrave;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 1) << totalPagadoMuyGrave;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 4) << cantidadDeFaltas;
    output << endl;
}








// Módulo que imprime toda la información de los arreglos respectivos a empresas.
void imprimir_datos_de_todas_las_empresas(int *arrDni, char **arrNombre,
                       char **arrDistrito, char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua,
                       int *arrFechaPagoMasReciente, double *arrTotalesPagado, int *arrCantidadDeFaltas,
                       int cant_empresas, ofstream &output, double &total_faltas_pagadas_leves,
                       double &total_faltas_pagadas_graves, double &total_faltas_pagadas_muy_graves,
                       int &cant_faltas_totales) {
    
    for(int indice = 0; indice < cant_empresas; indice++) {
        imprimir_datos_de_una_empresa(indice+1, arrDni[indice], arrNombre[indice], arrDistrito[indice],
                                                              arrListaDePlacas[indice], arrFechaInfraccionMasAntigua[indice],
                                                              arrFechaPagoMasReciente[indice], arrTotalesPagado[3*indice],
                                                              arrTotalesPagado[3*indice + 1], arrTotalesPagado[3*indice + 2],
                                                              arrCantidadDeFaltas[indice], output);
        total_faltas_pagadas_leves += arrTotalesPagado[3*indice];
        total_faltas_pagadas_graves += arrTotalesPagado[3*indice + 1];
        total_faltas_pagadas_muy_graves += arrTotalesPagado[3*indice + 2];
        cant_faltas_totales += arrCantidadDeFaltas[indice];
    }
}






// Módulo que imprime los totales del reporte.
void imprimir_totales(double total_faltas_pagadas_leves, double total_faltas_pagadas_graves,
                                     double total_faltas_pagadas_muy_graves, int cant_faltas_totales, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(9 * (TAM_REPORTE / (N_COLUMNAS + 3)) + 5) << "TOTALES:";
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) / 2  + 3) << total_faltas_pagadas_leves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 4) << total_faltas_pagadas_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 1) << total_faltas_pagadas_muy_graves;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 4) << cant_faltas_totales << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}







// Módulo que emite el reporte de prueba de empresas o el reporte solicitado
void emitir_reporte(const char *nombre_archivo, int *arrDni, char **arrNombre, char **arrDistrito,
                                  char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente,
                                  double *arrTotalesPagado, int *arrCantidadDeFaltas, int cant_empresas, bool es_reporte_de_prueba) {
    double total_faltas_pagadas_leves = 0.0, total_faltas_pagadas_graves = 0.0,
                total_faltas_pagadas_muy_graves = 0.0;
    int cant_faltas_totales = 0;
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo_de_empresas(es_reporte_de_prueba, output);
    imprimir_encabezado_de_empresas(output);
    imprimir_datos_de_todas_las_empresas(arrDni, arrNombre, arrDistrito, arrListaDePlacas, arrFechaInfraccionMasAntigua,
                                        arrFechaPagoMasReciente, arrTotalesPagado, arrCantidadDeFaltas, cant_empresas,
                                        output, total_faltas_pagadas_leves, total_faltas_pagadas_graves,
                                        total_faltas_pagadas_muy_graves, cant_faltas_totales);
    imprimir_totales(total_faltas_pagadas_leves, total_faltas_pagadas_graves, total_faltas_pagadas_muy_graves,
                              cant_faltas_totales, output);
}






// Módulo que intercambia los datos de tipo "int"
void intercambiar_int(int &dato_1, int &dato_2) {
    int aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}




// Módulo que intercambia los datos de tipo "double"
void intercambiar_double(double &dato_1, double &dato_2) {
    double aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}




// Módulo que intercambia las cadenas de caracteres
void intercambiar_cadenas(char *&dato_1, char *&dato_2) {
    char *aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}







// Módulo que ordena los arreglos de empresas de forma ascendente por la fecha de infracción más
// antigua y, en caso de igualdad, de forma ascendente por el nombre del representante legal.
void ordenar_arreglos_de_empresas(int *arrDni, char **arrNombre, char **arrDistrito,
                                  char **arrListaDePlacas, int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente,
                                  double *arrTotalesPagado, int *arrCantidadDeFaltas, int cant_empresas) {
    for(int i=0; i<cant_empresas - 1; i++) {
        for(int k=i+1; k<cant_empresas; k++) {
            if(arrFechaInfraccionMasAntigua[i] > arrFechaInfraccionMasAntigua[k]  or 
                        arrFechaInfraccionMasAntigua[i] == arrFechaInfraccionMasAntigua[k]  and
                                          strcmp(arrNombre[i], arrNombre[k]) > 0) {
                intercambiar_int(arrDni[i], arrDni[k]);
                intercambiar_cadenas(arrNombre[i], arrNombre[k]);
                intercambiar_cadenas(arrDistrito[i], arrDistrito[k]);
                intercambiar_cadenas(arrListaDePlacas[i], arrListaDePlacas[k]);
                intercambiar_int(arrFechaInfraccionMasAntigua[i], arrFechaInfraccionMasAntigua[k]);
                intercambiar_int(arrFechaPagoMasReciente[i], arrFechaPagoMasReciente[k]);
                intercambiar_double(arrTotalesPagado[3*i], arrTotalesPagado[3*k]);
                intercambiar_double(arrTotalesPagado[3*i  + 1], arrTotalesPagado[3*k  + 1]);
                intercambiar_double(arrTotalesPagado[3*i  + 2], arrTotalesPagado[3*k  + 2]);
                intercambiar_int(arrCantidadDeFaltas[i], arrCantidadDeFaltas[k]);
            }
        }
    }
}







// Módulo que lee una infracción cometida del archivo "InfraccionesCometidas.csv"
void leer_una_infracciones_cometida(int &fecha_infraccion, char *&placa_leida, char *&cod_infraccion_leida,
                                                                  int &fecha_pagada, ifstream &input) {
    char caracter_de_pago;
    fecha_infraccion = leer_fecha(input);
    if(input.eof()) return;
    input.get(); // Lectura de la coma
    placa_leida = leer_cadena(input, ',', false);
    cod_infraccion_leida = leer_cadena(input, ',', false);
    caracter_de_pago = leer_dato_char(input);
    if(caracter_de_pago == 'P') {
        input.get(); // Lectura de la coma
        fecha_pagada = leer_fecha(input);
    } else {
        // caracter_de_pago == 'N'
        fecha_pagada = 0;
    }
}





// Módulo que busca el código de la infracción en el arreglo de códigos de infracciones
int buscar_infraccion(char *cod_infraccion_leida, char **arrCodigoInfraccion, int cant_infracciones) {
    for(int indice = 0; indice < cant_infracciones; indice++) {
        if(strcmp(arrCodigoInfraccion[indice], cod_infraccion_leida) == 0) return indice;
    }
    return NO_ENCONTRADO;
}






// Módulo que asigna una multa mediante la búsqueda del código de la infracción leída
double asignar_multa(char *cod_infraccion_leida, char **arrCodigoInfraccion,
                                     double *arrValorMulta, int cant_infracciones) {
    int indice_infraccion;
    
    indice_infraccion = buscar_infraccion(cod_infraccion_leida, arrCodigoInfraccion, cant_infracciones);
    
    if(indice_infraccion != NO_ENCONTRADO) {
        return arrValorMulta[indice_infraccion];
    } else {
        return 0.0;
    }
}






// Módulo que cuenta la cantidad de placas en una lista de placas
int contar_placas(const char *listaDePlacas) {
    if(listaDePlacas[0] == '\0') return 0; // No hay placas en la lista de placas
    int cant_placas = 1; // Se asume que hay al menos una placa en la lista de placas
    for(int indice = 0; listaDePlacas[indice]; indice++) {
        if(listaDePlacas[indice] == '/') cant_placas++;
    }
    return cant_placas;
}







// Módulo que selecciona una placa de la lista de placas mediante índices
void seleccionar_placa_de_la_lista_de_placas(const char *listaDePlacas,
                           int indice_inicial_escogido_de_lista_placas, int indice_final_escogido_de_lista_placas,
                           char *placa_extraida) {
    int indice_lista_placas, indice_placa;
    
    indice_lista_placas = indice_inicial_escogido_de_lista_placas;
    indice_placa = 0;
    
    while(indice_lista_placas <= indice_final_escogido_de_lista_placas) {
        placa_extraida[indice_placa] = listaDePlacas[indice_lista_placas];
        indice_lista_placas++;
        indice_placa++;
    }
    placa_extraida[indice_placa] = '\0';
}





// Módulo que obtiene una placa de la lista de placas
void obtener_placa(const char *listaDePlacas, int n_placa, char *&placa_extraida) {
    
    int cant_placas = contar_placas(listaDePlacas);
    
    // Validar que la "enésima placa" sea mayor o igual que uno y menor o igual que la cantidad de placas
    if(n_placa >= 1  and  n_placa <= cant_placas) {
        placa_extraida = new char[MAX_CARACTERES_DE_UNA_PLACA];
        seleccionar_placa_de_la_lista_de_placas(listaDePlacas,
                                                                          (n_placa - 1) * MAX_CARACTERES_DE_UNA_PLACA,
                                                                          n_placa * MAX_CARACTERES_DE_UNA_PLACA  - 2,
                                                                          placa_extraida);
    }
}





// Módulo que verifica si una placa existe en la lista de placas
bool verificaSiEstaLaPlaca(const char *listaDePlacas, char *placa) {
    int cant_placas;
    char *placa_extraida;
    
    cant_placas = contar_placas(listaDePlacas);
    
    for(int n_placa = 1; n_placa <= cant_placas; n_placa++) {
        obtener_placa(listaDePlacas, n_placa, placa_extraida);
        if(strcmp(placa_extraida, placa) == 0) return true;
    }
    return false; // No se encontró la placa
}







// Módulo que busca una placa de una empresa mediante su lista de placas
int buscar_placa_de_una_empresa(char *placa_leida, char **arrListaDePlacas, int cant_empresas) {
    for(int indice = 0; indice < cant_empresas; indice++) {
        if( verificaSiEstaLaPlaca(arrListaDePlacas[indice], placa_leida) ) return indice;
    }
    return NO_ENCONTRADO;
}








// Módulo que actualiza los datos de la empresa (la fecha de infracción más antigua, la fecha de pago más
// reciente, acumular el total pagado de faltas leves, el total pagado de faltas graves, el total pagado
// de faltas muy graves y la cantidad de faltas).
void actualizar_datos_de_la_empresa(int fecha_infraccion, int fecha_pagada, double multa,
                                            int &fechaInfraccionMasAntigua, int &fechaPagoMasReciente,
                                            double &total_pagado_leves, double &total_pagado_graves,
                                            double &total_pagado_muy_graves, int &cantidadDeFaltas, char *cod_infraccion_leida) {
    
    if(fechaInfraccionMasAntigua > fecha_infraccion)  fechaInfraccionMasAntigua = fecha_infraccion;
    
    if(fechaPagoMasReciente < fecha_pagada) fechaPagoMasReciente = fecha_pagada;
    
    total_pagado_leves += (cod_infraccion_leida[0] == 'L' ? multa : 0.0);
    total_pagado_graves += (cod_infraccion_leida[0] == 'G' ? multa : 0.0);
    total_pagado_muy_graves += (cod_infraccion_leida[0] == 'M' ? multa : 0.0);
    
    cantidadDeFaltas++;
}








// Módulo que lee el archivo "InfraccionesCometidas.csv" y actualiza los arreglos de empresas.
void leer_infracciones_cometidas(const char *nombre_archivo, char **arrListaDePlacas,
                               int *arrFechaInfraccionMasAntigua, int *arrFechaPagoMasReciente, int *arrCantidadDeFaltas,
                               double *arrTotalesPagado, int cant_empresas, char **arrCodigoInfraccion,
                               double *arrValorMulta, int cant_infracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int fecha_infraccion, fecha_pagada, indice_placa_de_una_empresa;
    char *placa_leida, *cod_infraccion_leida;
    double multa;
    while(true) {
        leer_una_infracciones_cometida(fecha_infraccion, placa_leida, cod_infraccion_leida, fecha_pagada, input);
        if(input.eof()) break; // Validar fin del archivo "InfraccionesCometidas.csv"
        multa = asignar_multa(cod_infraccion_leida, arrCodigoInfraccion, arrValorMulta, cant_infracciones);
        indice_placa_de_una_empresa = buscar_placa_de_una_empresa(placa_leida, arrListaDePlacas, cant_empresas);
        if(indice_placa_de_una_empresa != NO_ENCONTRADO) {
            actualizar_datos_de_la_empresa(fecha_infraccion, fecha_pagada, multa,
                                                                 arrFechaInfraccionMasAntigua[indice_placa_de_una_empresa],
                                                                 arrFechaPagoMasReciente[indice_placa_de_una_empresa],
                                                                 arrTotalesPagado[3*indice_placa_de_una_empresa],
                                                                 arrTotalesPagado[3*indice_placa_de_una_empresa + 1],
                                                                 arrTotalesPagado[3*indice_placa_de_una_empresa + 2],
                                                                 arrCantidadDeFaltas[indice_placa_de_una_empresa], cod_infraccion_leida);
        }
    }
}







// Módulo que imprime el título y el encabezado del reporte de prueba de infracciones
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output) {
    
    // Título del reporte de prueba de infracciones
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
    output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
    output << "DATOS ALMACENADOS DE INFRACCIONES" << endl;
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
    
    // Encabezado del reporte de prueba de infracciones
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 5);
    output << "No.";
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 6);
    output << "CODIGO";
    output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3)) + 6);
    output << "VALOR DE LA MULTA" << endl;
    elaborar_lineas('-', TAM_REPORTE_PRUEBA, output);
}








// Módulo que imprime todas las infracciones (código y valor de la infracción).
void imprimir_las_infracciones(char **arrCodigoInfraccion, double *arrValorMulta,
                                                      int cant_infracciones, ofstream &output) {
    for(int indice = 0; indice < cant_infracciones; indice++) {
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 4);
        output << indice + 1 << ')';
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 5);
        output << arrCodigoInfraccion[indice];
        output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3)) + 1);
        output << arrValorMulta[indice];
        output << endl;
    }
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
}








// Módulo que verifica los datos almacenados en un reporte de prueba los
// arreglos de las infracciones (código y valor de la multa).
void verificar_los_datos_de_infracciones(const char *nombre_archivo, char **arrCodigoInfraccion,
                                                                         double *arrValorMulta, int cant_infracciones) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo_y_encabezado_de_infracciones(output);
    imprimir_las_infracciones(arrCodigoInfraccion, arrValorMulta, cant_infracciones, output);
}









// Módulo que lee el archivo "TablaDeInfracciones.csv". Se almacena el código
// y el valor de la multa de la infracción en arreglos.
void leer_tabla_de_infracciones(const char *nombre_archivo, char **arrCodigoInfraccion,
                                                        double *arrValorMulta, int &cant_infracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    char *codigo_de_infraccion, *descripcion;
    cant_infracciones = 0;
    while(true) {
        codigo_de_infraccion = leer_cadena(input, ',', false);
        if(codigo_de_infraccion == nullptr) break;  // Si el código de la infracción es un puntero nulo, entonces
                                                                          //  se llegó al fin del archivo "TablaDeInfracciones.csv",
        arrCodigoInfraccion[cant_infracciones] = codigo_de_infraccion;
        arrValorMulta[cant_infracciones] = leer_dato_double(input);
        descripcion = leer_cadena(input, '\n', false);
        cant_infracciones++;
    }
}







// Módulo que busca una empresa en un arreglo de DNI's mediante un DNI leído del representante legal
int buscar_empresa(int dni_leido, int *arrDni, int cant_empresas) {
    for(int indice = 0; indice < cant_empresas; indice++) {
        if(arrDni[indice] == dni_leido) return indice;
    }
    return NO_ENCONTRADO;
}







// Módulo que lee el archivo "PlacasRegistradas.txt". Se almacena la lista de placas
// para cada empresa en el arreglo de la lista de placas.
void leer_placas_registradas(const char *nombre_archivo, int *arrDni,
                                                   char **arrListaDePlacas, int cant_empresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni_leido, indice_empresa;
    char *placa;
    while(true) {
        dni_leido = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "PlacasRegistradas.txt"
        placa = leer_cadena(input, '\n', true);
        
        indice_empresa = buscar_empresa(dni_leido, arrDni, cant_empresas);
        
        if(indice_empresa != NO_ENCONTRADO) {
            // El DNI leído del representante legal, sí existe en el arreglo de DNI's.
            // Por lo tanto, la empresa sí existe.
            
            if(arrListaDePlacas[indice_empresa][0] == '\0') {
                // Es la primera placa a insertar en la lista de placas de esta empresa
                strcpy(arrListaDePlacas[indice_empresa], placa);
            } else {
                // Insertar la siguiente placa en la lista de placas de esta empresa
                strcat(arrListaDePlacas[indice_empresa], "/");
                strcat(arrListaDePlacas[indice_empresa], placa);
            }
        }
    }
}






// Módulo que pasa todas las letras de una cadena de caracteres a mayúsculas.
void pasar_todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'  and  cadena[indice] <= 'z') {
            // cadena[indice] = cadena[indice] - ('a' - 'A')
            cadena[indice] -= 32; // 32 es igual al codigo ASCCI de la diferencia de ('a' - 'A')
        }
    }
}







// Módulo que lee el archivo "EmpresasRegistradas.csv" y almacena la información que se lee por empresa
// en los distintos arreglos (arreglo de DNI, nombre y distrito). Asímismo, se inicializa para cada empresa,
// el valor por defecto a la fecha de infracción más antigua.
void leer_empresas_registradas(const char *nombre_archivo, int *arrDni, char **arrNombre, char **arrDistrito,
                                                         int *arrFechaInfraccionMasAntigua, int &cant_empresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni;
    cant_empresas = 0;
    while(true) {
        dni = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.csv"
        arrDni[cant_empresas] = dni;
        input.get(); // Lectura de la coma
        arrNombre[cant_empresas] = leer_cadena(input, ',', false);
        pasar_todo_a_mayusculas(arrNombre[cant_empresas]);
        arrDistrito[cant_empresas] = leer_cadena(input, '\n', false);
        pasar_todo_a_mayusculas(arrDistrito[cant_empresas]);
        arrFechaInfraccionMasAntigua[cant_empresas] = VALOR_POR_DEFECTO_A_LA_FECHA_MAS_ANTIGUA;
        cant_empresas++;
    }
}







// Módulo que inicializa el arreglo de placas en el que cada elemento de este
// arreglo de placas sea de una cadena dinámica de 60 caracteres.
void inicializar_el_arreglo_de_placas(char **arrListaDePlacas) {
    for(int indice = 0; indice < MAX_CANT_EMPRESAS; indice++) {
        arrListaDePlacas[indice] = new char[MAX_CARACTERES_LISTA_DE_PLACAS]; // Asignar memoria
        arrListaDePlacas[indice][0] = '\0'; // Inicializar el primer caracter de la cadena con el caracter nulo.
    }
}


