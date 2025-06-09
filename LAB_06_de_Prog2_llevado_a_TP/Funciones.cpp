

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 8 de junio del 2025, 12:49 PM
 */

#include "Funciones.h"


void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


void reservar_memoria_fija(char **arrCadenas) {
    for(int indice = 0; indice < MAX_CANT_REPRESENTANTES; indice++) {
        arrCadenas[indice] = new char[MAX_CARACTERES_LISTA_DE_PLACAS];
    }
}


int leer_dato_int(ifstream &input) {
    int dato;
    input >> dato;
    return dato;
}


double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get(); // Lectura de la coma
    return dato;
}


char leer_dato_char(ifstream &input) {
    char dato;
    input >> dato;
    return dato;
}


char *asignar_cadena(char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}



char *leer_cadena_exacta(ifstream &input, char delimitador) {
    char buffer[150], *cadena;
    input.getline(buffer, 150, delimitador);
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}



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


void imprimir_fecha(int fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha % 100;
    output << '/' << setw(2) << fecha / 100 %100 << '/';
    output << fecha / 10000 << setfill(' ');
}




void emitir_reporte(const char *nombre_archivo, int *arrDNI, char **arrNombre, char **arrListaDePlacas, 
                    int *arrFechaInfraccionMasAntigua, int *arrFechaUltimaPagada, int cant_representantes) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    for(int i=0; i < cant_representantes; i++) {
        output << setw(3) << i +1 << ')' << setw(10) << arrDNI[i] << setw(3) << ' ';
        output << left << setw(45) << arrNombre[i] << setw(55) << arrListaDePlacas[i] << right;
        
        if(arrFechaUltimaPagada[i] == 0){
            output << "NO HAY FECHA PAGADA";
        } else {
            output << "Ultima fecha pagada: ";
            imprimir_fecha(arrFechaUltimaPagada[i], output);
        }
        
        output << endl;
    }
}









void leer_una_infraccion_cometida(int &fecha_infraccion, char *&placa_leida, int &cod_infraccion_leida,
                                  int &fecha_pagada, ifstream &input) {
    char caracter_de_que_se_pago_la_infraccion;
    
    fecha_infraccion = leer_fecha(input);
    
    if(input.eof()) return; // Se llegó al fin del archivo "InfraccionesCometidas.csv", entonces se sale de este módulo
    
    input.get(); // Lectura de la coma
    
    placa_leida = leer_cadena_exacta(input, ',');
    cod_infraccion_leida = leer_dato_int(input);
    
    if(input.get() != '\n') {
        caracter_de_que_se_pago_la_infraccion = leer_dato_char(input);
        input.get(); // Lectura de la coma
        fecha_pagada = leer_fecha(input);
    } else {
        fecha_pagada = 0;
    }
}



int buscar_infraccion(int dato_buscado, int *arreglo, int cant_datos) {
    for(int indice = 0; indice < cant_datos; indice++) {
        if(dato_buscado == arreglo[indice])  return indice;
    }
    return NO_ENCONTRADO;
}


int contar_placas(char *listaDePlacas) {
    if(listaDePlacas[0] == '\0') return 0;
    
    int cant_placas = 1; // Se asume que al menos hay una placa en la lista de placas.
    
    for(int indice = 0; listaDePlacas[indice]; indice++) {
        if(listaDePlacas[indice] == '/') cant_placas++;
    }
    return cant_placas;
}


void copiar_placa(char *listaDePlacas, int indice_inicial, int indice_final, char *&placa) {
    
    placa = new char[indice_final - indice_inicial + 2]; // Asignar memoria
    
    int indice_lista, indice_placa;
    
    indice_lista = indice_inicial;
    indice_placa = 0;
    
    while(indice_lista <= indice_final) {
        placa[indice_placa] = listaDePlacas[indice_lista];
        indice_lista++;
        indice_placa++;
    }
    
    placa[indice_placa] = '\0';
}


void extraer_placa(char *listaDePlacas, int n_placa, char *&placa_extraida) {
    int cantidad_de_placas;
    
    cantidad_de_placas = contar_placas(listaDePlacas);
    
    if(n_placa >= 1  and  n_placa <= cantidad_de_placas) {
        copiar_placa(listaDePlacas, (n_placa - 1)*MAX_CARACTERES_DE_UNA_PLACA,
                     n_placa*MAX_CARACTERES_DE_UNA_PLACA, placa_extraida);
    }
}


bool existe_placa(char *placa_buscada, char *listaDePlacas) {
    int cant_placas;
    char *placa_extraida;
    
    cant_placas = contar_placas(listaDePlacas);
    
    for(int n_placa = 1; n_placa <= cant_placas; n_placa++) {
        extraer_placa(listaDePlacas, n_placa, placa_extraida);
        if(strcmp(placa_extraida, placa_buscada) == 0) return true;
    }
    return false;
}


int buscar_representante(char *placa_leida, char **arrListaDePlacas, int cant_representantes) {
    for(int indice=0; indice < cant_representantes; indice++) {
        if( existe_placa(placa_leida, arrListaDePlacas[indice]) ) return indice;
    }
    return NO_ENCONTRADO;
}




void leer_infracciones_cometidas(const char *nombre_archivo, int *arr_cod_infraccion, double *arr_multas,
                           int cant_infracciones, int *arrDNI, char **arrNombre, char **arrListaDePlacas, 
                           int *arrFechaInfraccionMasAntigua, int *arrFechaUltimaPagada, int cant_representantes) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int fecha_infraccion, cod_infraccion_leida, fecha_pagada, pos_infraccion, pos_representante;
    char *placa_leida;
    double multa;
    while(true) {
        leer_una_infraccion_cometida(fecha_infraccion, placa_leida, cod_infraccion_leida, fecha_pagada, input);
        if(input.eof()) break;
        
        pos_infraccion = buscar_infraccion(cod_infraccion_leida, arr_cod_infraccion, cant_infracciones);
        if(pos_infraccion != NO_ENCONTRADO) multa = arr_multas[pos_infraccion];
        else  multa = 0.0;
        
        pos_representante = buscar_representante(placa_leida, arrListaDePlacas, cant_representantes);
        if(pos_representante != NO_ENCONTRADO) {
            if(arrFechaUltimaPagada[pos_representante] < fecha_pagada) {
                arrFechaUltimaPagada[pos_representante] = fecha_pagada;
            }
            
        }
    }
}





char *leer_placa(ifstream &input) {
    char buffer[MAX_CARACTERES_DE_UNA_PLACA], *placa;
    input.get(buffer, MAX_CARACTERES_DE_UNA_PLACA, ',');
    placa = asignar_cadena(buffer);
    return placa;
}



void procesar_placas(char *listaDePlacas, ifstream &input) {
    char *placa;
    char buffer[MAX_CARACTERES_DE_UNA_PLACA];
    bool primera_placa_a_ingresar = true;
    while(true) {
        placa = leer_placa(input);
        if(not primera_placa_a_ingresar) {
            strcat(listaDePlacas, "/");
            strcat(listaDePlacas, placa);
        } else {
            strcpy(listaDePlacas, placa);
            primera_placa_a_ingresar = false;
        }
        if(input.get() == '\n') break;
    }
}



void leer_empresas_registradas(const char *nombre_archivo, int *arrDNI, char **arrNombre,
                               char **arrListaDePlacas, int &cant_representantes) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni;
    cant_representantes = 0;
    reservar_memoria_fija(arrListaDePlacas);
    char *lista_de_placas;
    while(true) {
        dni = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.csv"
        arrDNI[cant_representantes] = dni;
        input.get();
        arrNombre[cant_representantes] = leer_cadena_exacta(input, ',');
        procesar_placas(arrListaDePlacas[cant_representantes], input);
        cant_representantes++;
    }
}



void leer_tabla_de_infracciones(const char *nombre_archivo, int *arr_cod_infraccion, double *arr_multas,
                                char **arr_gravedad, char **arr_descripcion_infraccion, int &cant_infracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int cod_infraccion;
    cant_infracciones = 0;
    while(true) {
        cod_infraccion = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "TablaDeInfracciones.csv"
        arr_cod_infraccion[cant_infracciones] = cod_infraccion;
        input.get(); // Lectura de la coma
        arr_multas[cant_infracciones] = leer_dato_double(input);
        arr_gravedad[cant_infracciones] = leer_cadena_exacta(input, ',');
        arr_descripcion_infraccion[cant_infracciones] = leer_cadena_exacta(input, '\n');
        cant_infracciones++;
    }
}

