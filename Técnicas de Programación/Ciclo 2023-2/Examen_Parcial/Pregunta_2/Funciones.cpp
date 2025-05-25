

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de mayo de 2025, 08:18 PM
 */

#include "Funciones.h"



/* ============================================================================================= */
/* ============================= Funciones principales ========================================= */
/* ================= (Funciones que controlan el flujo principal del programa) ================= */
/* ============================================================================================= */




// Módulo que lee el archivo "Alumnos.txt" y almacena los
// códigos de alumnos y sus escalas en arreglos.
void leer_alumnos(const char *nombre_archivo,int *arr_cod_alumno,
                  char *arr_escala_alumno,int &cant_alumnos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int cod_alumno;
    cant_alumnos = 0;
    while(true){
        cod_alumno = leer_tipo_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "Alumnos.txt"
        arr_cod_alumno[cant_alumnos] = cod_alumno;
        ignorar_hasta_delimitador(' ',input);
        arr_escala_alumno[cant_alumnos] = leer_tipo_dato_char(input);
        cant_alumnos++;
    }
}



// Módulo que lee el archivo "Cursos.txt" y almacena los
// códigos de cursos y los números de créditos en arreglos.
void leer_cursos(const char *nombre_archivo,int *arr_cod_cursos,
                 double *arr_num_creditos_curso,int &cant_cursos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int cod_curso;
    cant_cursos = 0;
    while(true){
        cod_curso = leer_tipo_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "Cursos.txt"
        arr_cod_cursos[cant_cursos] = cod_curso;
        ignorar_hasta_delimitador(' ',input);
        arr_num_creditos_curso[cant_cursos] = leer_tipo_dato_double(input);
        cant_cursos++;
    }
}



// Módulo que lee el archivo "Escalas.txt" y almacena los años, ciclos,
// escalas y el valor de crédito de cada escala en arreglos.
void leer_escalas(const char *nombre_archivo,int *arr_anio_escala,int *arr_ciclo_escala,
                  char *arr_escalas,double *arr_valor_credito_escala,int &cant_escalas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int anio,ciclo;
    cant_escalas = 0;
    while(true){
        leer_anio_y_ciclo(anio,ciclo,input);
        if(input.eof()) break; // Validar fin del archivo "Escalas.txt"
        arr_anio_escala[cant_escalas] = anio;
        arr_ciclo_escala[cant_escalas] = ciclo;
        arr_escalas[cant_escalas] = leer_tipo_dato_char(input);
        arr_valor_credito_escala[cant_escalas] = leer_tipo_dato_double(input);
        cant_escalas++;
    }
}




// Módulo que emite el reporte de prueba de escalas para
// verificar la correcta asignación de estos datos en los arreglos.
void emitir_reporte_prueba_escalas(const char *nombre_archivo,int *arr_anio_escala,
                        int *arr_ciclo_escala,char *arr_escalas,double *arr_valor_credito_escala,
                        int cant_escalas){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulos(true,output);
    imprimir_encabezados(true,output);
    for(int indice = 0; indice < cant_escalas; indice++){
        output << setw(3) << ' ';
        imprimir_anio_y_ciclo(arr_anio_escala[indice],arr_ciclo_escala[indice],output);
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) - 4);
        output << arr_escalas[indice];
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 5);
        output << arr_valor_credito_escala[indice] << endl;
    }
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
}





// Módulo que lee el archivo "Matricula.txt" y actualiza los arreglos de "escalas"
// para poder emitir el reporte solicitado.
void leer_matricula(const char *nombre_archivo,int *arr_cod_alumno,char *arr_escala_alumno,
                  int cant_alumnos,int *arr_cod_cursos,double *arr_num_creditos_curso,int cant_cursos,
                  int *arr_anio_escala,int *arr_ciclo_escala,char *arr_escalas,int *arr_cant_alumnos_escalas,
                  double *arr_valor_credito_escala,double *arr_cant_creditos_escala,
                  double *arr_total_ingresos_escala,int cant_escalas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int anio_leido,ciclo_leido,cod_alumno_leido,pos_escala;
    while(true){
        leer_anio_y_ciclo(anio_leido,ciclo_leido,input);
        if(input.eof()) break; // Validar fin del archivo "Matricula.txt"
        cod_alumno_leido = leer_tipo_dato_int(input);
        pos_escala = buscar_escala(anio_leido,ciclo_leido,cod_alumno_leido,arr_cod_alumno,
                                   arr_escala_alumno,cant_alumnos,arr_anio_escala,arr_ciclo_escala,
                                   arr_escalas,cant_escalas);
        if(pos_escala != NO_ENCONTRADO){
            procesar_cursos(arr_cod_cursos,arr_num_creditos_curso,cant_cursos,
                            arr_cant_alumnos_escalas[pos_escala],arr_valor_credito_escala[pos_escala],
                            arr_cant_creditos_escala[pos_escala],arr_total_ingresos_escala[pos_escala],input);
        }
        else  ignorar_hasta_delimitador('\n',input);
    }
}




// Módulo que busca la posición de una escala a partir de un año, ciclo y código de alumno.
int buscar_escala(int anio_leido,int ciclo_leido,int cod_alumno_leido,int *arr_cod_alumno,
                  char *arr_escala_alumno,int cant_alumnos,int *arr_anio_escala,
                  int *arr_ciclo_escala,char *arr_escalas,int cant_escalas){
    int indice;
    // Buscar la escala del alumno en los arreglos de alumnos
    for(indice=0; indice < cant_alumnos; indice++){
        if(cod_alumno_leido == arr_cod_alumno[indice]){
            
            // Si el código leído y un código de alumno en en arreglos de
            //alumnos coincide, entonces se obtiene la escala del alumno.
            char escala_alumno = arr_escala_alumno[indice];
            
            // Buscar la posición de la escala de alumno encontrada
            // anteriormente en el arreglo de escalas como la del año y ciclo leído..
            for(int posicion = 0; posicion < cant_escalas; posicion++){
                if(escala_alumno == arr_escalas[posicion] and
                            anio_leido == arr_anio_escala[posicion] and
                                 ciclo_leido == arr_ciclo_escala[posicion]){
                    return posicion; // Se encontró la escala de un determinado año y ciclo.
                }
            }
            return NO_ENCONTRADO; // No se encontró el año, ciclo y escala del alumno en los arreglos de escalas.
        }
    }
    return NO_ENCONTRADO; // No se encontró el código del alumno en los arreglos de alumnos.
}





// Módulo que procesa una lista de cursos del archivo "Matricula.txt"
void procesar_cursos(int *arr_cod_cursos,double *arr_num_creditos_curso,int cant_cursos,
                     int &cant_alumnos_escalas,double valor_credito_escala,
                     double &cant_creditos_escala,double &arr_total_ingresos_escala,ifstream &input){
    int cod_curso_leido,pos_curso;
    
    cant_alumnos_escalas++;
    
    while(true){
        cod_curso_leido = leer_tipo_dato_int(input);
        pos_curso = buscar_curso(cod_curso_leido,arr_cod_cursos,cant_cursos);
        if(pos_curso != NO_ENCONTRADO){
            cant_creditos_escala += arr_num_creditos_curso[pos_curso];
            arr_total_ingresos_escala += valor_credito_escala * arr_num_creditos_curso[pos_curso];
        }
        if(input.get() == '\n') break;
    }
}




// Módulo que busca un curso leído en los arreglos de "cursos"
int buscar_curso(int cod_curso_leido,int *arr_cod_cursos,int cant_cursos){
    for(int indice = 0; indice < cant_cursos; indice++){
        if(cod_curso_leido == arr_cod_cursos[indice]){
            return indice;
        }
    }
    return NO_ENCONTRADO;
}




// Módulo que ordena los arreglos de forma descendente por la
// cantidad de alumnos y ascendentemente por el total de ingresos.
void ordenar_arreglos(int *arr_anio_escala,int *arr_ciclo_escala,char *arr_escalas,
                      int *arr_cant_alumnos_escalas,double *arr_valor_credito_escala,
                      double *arr_cant_creditos_escala,double *arr_total_ingresos_escala,int cant_escalas){
    for(int i=0; i < cant_escalas - 1; i++){
        for(int k = i + 1;  k < cant_escalas;  k++){
            if(arr_cant_alumnos_escalas[i] < arr_cant_alumnos_escalas[k]    or
                        arr_cant_alumnos_escalas[i] == arr_cant_alumnos_escalas[k]    and
                            arr_total_ingresos_escala[i] > arr_total_ingresos_escala[k]){
                intercambiar_int(arr_anio_escala[i],arr_anio_escala[k]);
                intercambiar_int(arr_ciclo_escala[i],arr_ciclo_escala[k]);
                intercambiar_char(arr_escalas[i],arr_escalas[k]);
                intercambiar_int(arr_cant_alumnos_escalas[i],arr_cant_alumnos_escalas[k]);
                intercambiar_double(arr_valor_credito_escala[i],arr_valor_credito_escala[k]);
                intercambiar_double(arr_cant_creditos_escala[i],arr_cant_creditos_escala[k]);
                intercambiar_double(arr_total_ingresos_escala[i],arr_total_ingresos_escala[k]);
            }
        }
    }
}



// Módulo que elabora el reporte solicitado
void emitir_reporte(const char *nombre_archivo,int *arr_anio_escala,int *arr_ciclo_escala,
                    char *arr_escalas,int *arr_cant_alumnos_escalas,double *arr_valor_credito_escala,
                    double *arr_cant_creditos_escala,double *arr_total_ingresos_escala,int cant_escalas){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulos(false,output);
    imprimir_encabezados(false,output);
    for(int indice = 0; indice < cant_escalas; indice++){
        imprimir_un_juego_de_datos_de_escalas(indice+1,arr_anio_escala[indice],arr_ciclo_escala[indice],
                    arr_escalas[indice],arr_cant_alumnos_escalas[indice],arr_valor_credito_escala[indice],
                    arr_cant_creditos_escala[indice],arr_total_ingresos_escala[indice],output);
    }
    elaborar_lineas('=',TAM_REPORTE,output);
}





/* =============================================================================================== */










/* =============================================================================================== */
/* ================================= Funciones de Reportería ===================================== */
/* ==================== (Funciones que ayudan en la elaboración de un reporte) =================== */
/* =============================================================================================== */



// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i = 0;  i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}



// Módulo que imprime el título del reporte de prueba y el del reporte solicitado
void imprimir_titulos(bool es_de_prueba,ofstream &output){
    if(es_de_prueba){
         // Título del reporte de prueba
        elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
        output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
        output << "DATOS ALMACENADOS DE ESCALAS" << endl;
        elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
    } else {
        // Título del reporte solicitado
        output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
        output << "INSTITUCION EDUCATIVA_TP" << endl << endl;
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "RELACION DE INGRESOS POR CICLOS Y ESCALAS" << endl << endl;
    }
}




// Módulo que imprime el encabezado del reporte de prueba y el del reporte solicitado
void imprimir_encabezados(bool es_de_prueba,ofstream &output){
    if(es_de_prueba){
        // Encabezado del reporte de prueba
        output << setw(3) << ' ' << "CICLO";
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3));
        output << "ESCALA";
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 3) + 5);
        output << "VALOR CREDITO" << endl;
        elaborar_lineas('-',TAM_REPORTE_PRUEBA,output);
    } else {
        // Encabezado del reporte solicitado
        elaborar_lineas('=',TAM_REPORTE,output);
        output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 2);
        output << "CICLO";
        output << setw(TAM_REPORTE / N_COLUMNAS  - 3);
        output << "ESCALA";
        output << setw(TAM_REPORTE / N_COLUMNAS);
        output << "CANT.ALUMNOS";
        output << setw(TAM_REPORTE / N_COLUMNAS);
        output << "VALOR.CREDITO";
        output << setw(TAM_REPORTE / N_COLUMNAS  + 2);
        output << "CANT.CREDITOS";
        output << setw(TAM_REPORTE / N_COLUMNAS  + 6);
        output << "TOTAL DE INGRESOS" << endl;
        elaborar_lineas('-',TAM_REPORTE,output);
    }
}




// Módulo que imprime un juego de datos de los arreglos de "escala"
void imprimir_un_juego_de_datos_de_escalas(int n_ciclo,int anio_escala,int ciclo_escala,
                        char escala,int cant_alumnos_escalas,double valor_credito_escala,
                        double cant_creditos_escala,double total_ingresos_escala,ofstream &output){
    output << setfill('0') << setw(2) << n_ciclo << setfill(' ') << ')';
    output << setw(2) << ' ';
    imprimir_anio_y_ciclo(anio_escala,ciclo_escala,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 7) << escala;
    output << setw(TAM_REPORTE / N_COLUMNAS  - 2) << cant_alumnos_escalas;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 1) << valor_credito_escala;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 2) << cant_creditos_escala;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 5) << total_ingresos_escala;
    output << endl;
}






/* =============================================================================================== */









/* ================================================================================================ */
/* ==================================== Funciones Auxiliares ====================================== */
/* ============== (Funciones pequeñas que realizan una lectura o actualización de datos) =========== */
/* ================================================================================================ */


// Módulo que lee un dato de tipo "int"
int leer_tipo_dato_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "double"
double leer_tipo_dato_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "char"
char leer_tipo_dato_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}


// Módulo que ignora hasta el delimitador
void ignorar_hasta_delimitador(char delimitador,ifstream &input){
    input >> ws; // Lectura de espacios en blanco
    while(input.get() != delimitador);
}



// Módulo que lee el año y ciclo de la siguiente forma: 2021-2
void leer_anio_y_ciclo(int &anio,int &ciclo,ifstream &input){
    char guion;
    anio = leer_tipo_dato_int(input);
    guion = leer_tipo_dato_char(input);
    ciclo = leer_tipo_dato_int(input);
}


// Módulo que imprime el año y ciclo de la siguiente forma: 2021-2
void imprimir_anio_y_ciclo(int anio,int ciclo,ofstream &output){
    output << anio;
    output << '-';
    output << ciclo;
}


// Módulo que intercambia datos de tipo  " int "
int intercambiar_int(int &dato_1,int &dato_2){
    int auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}


// Módulo que intercambia datos de tipo   " double "
double intercambiar_double(double &dato_1,double &dato_2){
    double auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}


// Módulo que intercambia datos de tipo  " char "
char intercambiar_char(char &dato_1,char &dato_2){
    char auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}





/* =============================================================================================== */










/* ================================================================================================= */
/* ==================================== Funciones de soporte ======================================= */
/* ========== (Funciones que realizan la apertura de un archivo de lectura o de escritura) ========= */
/* ================================================================================================= */



// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}

/* =============================================================================================== */

