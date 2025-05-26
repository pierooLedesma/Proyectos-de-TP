

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 22 de mayo de 2025, 12:59 PM
 */


#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato de tipo "int"
int leer_dato_tipo_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "double"
double leer_dato_tipo_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "char"
char leer_dato_tipo_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}


// Módulo que ignora todo lo que lee hasta el delimitador
void ignorar_hasta_delimitador(char delimitador, ifstream &input){
    input >> ws; // Lectura de espacios en blanco
    while(input.get() != delimitador);
}



// Módulo que junta dos números enteros (año y ciclo) en un número (semestre)
int convertir_anio_y_ciclo(int anio_usuario, int ciclo_usuario){
    return anio_usuario*10 + ciclo_usuario;
}



// Módulo que lee un semestre (año-ciclo) y lo retorna como un valor entero
int leer_semestre(ifstream &input){
    int anio,ciclo,semestre;
    char guion;
    anio = leer_dato_tipo_int(input);
    guion = leer_dato_tipo_char(input);
    ciclo = leer_dato_tipo_int(input);
    semestre = convertir_anio_y_ciclo(anio, ciclo);
    return semestre;
}




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output){
    for(int i=0; i<cant_caracteres; i++)   output.put(caracter);
    output << endl;
}



// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(int semestre, ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "DETALLE DE PAGOS REALIZADOS POR CICLO" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2  - 3);
    output << "CICLO: ";
    output << semestre / 10 << '-' << semestre % 10;
    output << endl;
}



// Módulo que imprime el encabezado del reporte solicitado
void imprimir_encabezado(ofstream &output){
    elaborar_lineas('=',TAM_REPORTE, output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 11);
    output << "ALUMNOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) - 2);
    output << "No. DE CURSOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2);
    output << "CREDITOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2);
    output << "ESCALA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 4);
    output << "MONTO PAGADO";
    output << endl;
    elaborar_lineas('-',TAM_REPORTE, output);
}





// Módulo que realiza una búsquedad de un dato en un arreglo de tipo
// "int" ordenado ascendentemente mediante el método de búsquedad binaria.
int busquedad_binaria(int dato_buscado, int *arreglo, int cant_datos){
    int limite_inferior = 0,limite_superior = cant_datos - 1,punto_medio;
    while(true){
        if(limite_inferior > limite_superior) return NO_ENCONTRADO;
        punto_medio = (limite_superior + limite_inferior) / 2;
        if(arreglo[punto_medio] == dato_buscado) return punto_medio;
        if(arreglo[punto_medio] > dato_buscado){
            // El dato buscado es menor que el valor del arreglo en el índice
            // "punto medio", entonces actualizo el límite superior.
            limite_superior = punto_medio - 1;
        } else {
            // El dato buscado es mayor que el valor del arreglo en el índice
            // "punto medio", entonces actualizo el límite inferior.
            limite_inferior = punto_medio + 1;
        }
    }
}



// Módulo que busca una escala mediante un semestre y la escala del alumno
// en los arreglos de semestres y de escalas.
int buscar_escala(int semestre_leido, char escala_alumno, int *arr_semestre,
                  char *arr_escalas, int cant_escalas){
    for(int indice = 0; indice < cant_escalas; indice++){
        if(arr_semestre[indice] == semestre_leido  and
                     arr_escalas[indice] == escala_alumno){
            return indice;
        }
    }
    return NO_ENCONTRADO;
}



// Módulo que retorna la posición de un caracter de una cadena
int encontrar_caracter(char caracter, char *cadena){
    for(int i=0; cadena[i]; i++){
        if(cadena[i] == caracter) return i;
    }
    return -1;
}




// Módulo que extrae el apellido paterno y los nombres desde una cadena de caracteres
// con el siguiente formato: "ApellidoPaterno_Nombres"
void extraer_apellido_y_nombres(const char *apellidoPaterno_y_nombres,
                                char *apellidoPaterno, char *nombres){
    char copia[MAX_CARACTERES_NOMBRE_COMPLETO];
    copiar_cadena(copia, apellidoPaterno_y_nombres);  // Copia auxiliar para no alterar la original
    
    int pos = encontrar_caracter('_', copia);  // Buscar el primer guion bajo
    if (pos == NO_ENCONTRADO) {
        // Si no hay guion bajo, devuelve cadenas vacías
        apellidoPaterno[0] = '\0';
        nombres[0] = '\0';
        return;  // Salir de este módulo
    }
    
    copia[pos] = '\0';  // Termina la cadena en el primer guion bajo para aislar el apellido paterno
    copiar_cadena(apellidoPaterno, copia);        // Copiar el apellido paterno
    copiar_cadena(nombres, &copia[pos + 1]);      // Copiar los nombres (después del guion bajo)
}




// Módulo que reemplaza todos los guiones bajos '_' por espacios ' ' en una cadena
void reemplazar_guiones_por_espacios(char *cadena){
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] == '_') cadena[indice] = ' ';
    }
}



// Módulo que construye el nombre completo en formato "Nombres ApellidoPaterno ApellidoMaterno"
void construir_nombre_completo(char *destino, const char *nombres,
                               const char *apellidoPaterno, const char *apellidoMaterno){
    copiar_cadena(destino, nombres);        // Copia los nombres
    concatenar(destino, " ");               // Añade espacio
    concatenar(destino, apellidoPaterno);   // Añade el apellido paterno
    concatenar(destino, " ");               // Añade otro espacio
    concatenar(destino, apellidoMaterno);   // Añade el apellido materno
}




// Módulo que pasa las letras de la cadena de caracteres a mayúsculas 
void pasar_a_mayusculas(char *cadena){
    for(int indice = 0; cadena[indice]; indice++){
        if(cadena[indice] >= 'a'  and  cadena[indice] <= 'z'){
            cadena[indice] = cadena[indice] - 'a' + 'A';
        }
    }
}




// Módulo que modifica el nombre del alumno y concatena el apellido. Además, reemplaza
// los guiones por espacios en blanco y pasa todos los caracteres a mayúsculas.
void modificaTexto(char *apellidoPaterno_nombres, const char *apellido_materno) {
    char nombres[MAX_CARACTERES_NOMBRES];
    char apellidoPaterno[MAX_CARACTERES_APELLIDO];
    
    // Extraer el apellido paterno y los nombres desde la cadena original "apellidoPaterno_nombres"
    extraer_apellido_y_nombres(apellidoPaterno_nombres, apellidoPaterno, nombres);
    
    // Reemplazar los guiones bajos en los nombres por espacios
    reemplazar_guiones_por_espacios(nombres);
    
    // Construir el nuevo nombre completo en la misma variable original
    construir_nombre_completo(apellidoPaterno_nombres, nombres,
                              apellidoPaterno, apellido_materno);
    
    // Convertir todo a mayúsculas
    pasar_a_mayusculas(apellidoPaterno_nombres);
}




// Módulo que imprime un juego de datos del alumno
void imprimir_un_juego_de_datos_de_un_alumno(int cod_alumno, int cant_cursos_alumno,
                        double cant_creditos_alumno, char escala_alumno, double monto_pagado_alumno,
                        ifstream &input_nombre, ifstream &input_apellido_materno, ofstream &output,
                        double &monto_total_pagado){
    char nombres[MAX_CARACTERES_NOMBRE_COMPLETO],
         apellido_materno[MAX_CARACTERES_APELLIDO];
    output << cod_alumno << " - ";
    
    input_nombre>>nombres;
    input_apellido_materno>>apellido_materno;
    modificaTexto(nombres,apellido_materno);
    output << nombres;
    output << setw( (TAM_REPORTE / (N_COLUMNAS - 3) - 8) - longitud_cadena(nombres) ) << ' ';
    
    output << setw(2) << cant_cursos_alumno;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2)) << cant_creditos_alumno;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 4) << escala_alumno;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 2) << monto_pagado_alumno;
    output << endl;
    
    monto_total_pagado += monto_pagado_alumno;
}




// Módulo que imprime los datos de los alumnos en el reporte solicitado
void imprimir_alumnos(int *arr_cod_alumno, int *arr_cant_cursos_alumno,
                      double *arr_cant_creditos_alumno, char *arr_escala_alumno,
                      double *arr_monto_pagado_alumno, int cant_alumnos,
                      double &monto_total_pagado, ifstream &input_nombre,
                      ifstream &input_apellido_materno,ofstream &output){
    int codigo_alumno_leido,pos_alumno;
    while(true){
        codigo_alumno_leido = leer_dato_tipo_int(input_nombre);
        if(input_nombre.eof()) break; // Validar fin de archivo "AlumnosNombres.txt"
        pos_alumno = busquedad_binaria(codigo_alumno_leido, arr_cod_alumno, cant_alumnos);
        if(pos_alumno != NO_ENCONTRADO){
            imprimir_un_juego_de_datos_de_un_alumno(arr_cod_alumno[pos_alumno],
                        arr_cant_cursos_alumno[pos_alumno], arr_cant_creditos_alumno[pos_alumno],
                        arr_escala_alumno[pos_alumno], arr_monto_pagado_alumno[pos_alumno],
                        input_nombre,input_apellido_materno, output, monto_total_pagado);
        } else {
            ignorar_hasta_delimitador('\n', input_nombre);
            ignorar_hasta_delimitador('\n', input_apellido_materno);
        }
    }
}




// Módulo que imprime el monto toal pagado
void imprimir_monto_total_pagado(double monto_total_pagado, ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "MONTO TOTAL PAGADO:";
    output << setw(3 * (TAM_REPORTE / 4) + 4) << monto_total_pagado << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}




// Módulo que emite el reporte solicitado según el semestre ingresado por el usuario
void emitir_reporte(const char *nombre_archivo_reporte,int semestre_usuario,
                    int *arr_cod_alumno,char *arr_escala_alumno,int *arr_cant_cursos_alumno,
                    double *arr_cant_creditos_alumno,double *arr_monto_pagado_alumno,
                    int cant_alumnos,const char *nombre_archivo_nombre,
                    const char *nombre_archivo_apellido_materno){
    ifstream input_nombre,input_apellido_materno;
    ofstream output;
    aperturar_archivo_lectura(nombre_archivo_nombre, input_nombre);
    aperturar_archivo_lectura(nombre_archivo_apellido_materno, input_apellido_materno);
    aperturar_archivo_escritura(nombre_archivo_reporte, output);
    imprimir_titulo(semestre_usuario, output);
    imprimir_encabezado(output);
    output << fixed << setprecision(2);
    double monto_total_pagado = 0.0;
    imprimir_alumnos(arr_cod_alumno, arr_cant_cursos_alumno, arr_cant_creditos_alumno,
                     arr_escala_alumno, arr_monto_pagado_alumno, cant_alumnos,
                     monto_total_pagado, input_nombre, input_apellido_materno,output);
    imprimir_monto_total_pagado(monto_total_pagado, output);
}





// Módulo que procesa la lista de cursos de un alumno llevado en
// un semestre del archivo "Matricula.txt"
void procesar_lista_de_cursos(int &cant_cursos_alumno,
                double &cant_creditos_alumno, double &monto_pagado_alumno,
                double costo_por_credito_escala, int *arr_cod_curso,
                double *arr_num_creditos_curso, int cant_cursos,ifstream &input){
    int cod_curso,pos_curso;
    while(true){
        cod_curso = leer_dato_tipo_int(input);
        pos_curso = busquedad_binaria(cod_curso, arr_cod_curso, cant_cursos);
        if(pos_curso != NO_ENCONTRADO){
            cant_cursos_alumno++;
            cant_creditos_alumno += arr_num_creditos_curso[pos_curso];
            monto_pagado_alumno += arr_num_creditos_curso[pos_curso] *
                                   costo_por_credito_escala;
        }
        if(input.get() == '\n') break;
    }
}





// Módulo que lee el archivo "Matricula.txt". Mediante este archivo se actualiza la cantidad de cursos
// la cantidad de créditos y el monto pagado por cada alumno según el semestre del usuario.
void leer_matricula(const char *nombre_archivo, int semestre_usuario,
                    int *arr_cod_alumno, char *arr_escala_alumno, int *arr_cant_cursos_alumno,
                    double *arr_cant_creditos_alumno, double *arr_monto_pagado_alumno,
                    int cant_alumnos,int *arr_cod_curso, double *arr_num_creditos_curso,
                    int cant_cursos, int *arr_semestre, char *arr_escalas,
                    double *arr_costo_por_credito_escala, int cant_escalas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int semestre_leido,pos_escala,cod_alumno_leido,pos_alumno;
    double costo_credito_escala;
    while(true){
        semestre_leido = leer_semestre(input);
        if(input.eof()) break; // Validar fin del archivo "Matricula.txt"
        if(semestre_leido == semestre_usuario){
            cod_alumno_leido = leer_dato_tipo_int(input);
            pos_alumno = busquedad_binaria(cod_alumno_leido, arr_cod_alumno, cant_alumnos);
            if(pos_alumno != NO_ENCONTRADO){
                pos_escala = buscar_escala(semestre_leido,arr_escala_alumno[pos_alumno],
                                           arr_semestre,arr_escalas,cant_escalas);
                costo_credito_escala = (pos_escala != NO_ENCONTRADO ? 
                                        arr_costo_por_credito_escala[pos_escala] : 0.0);
                procesar_lista_de_cursos(arr_cant_cursos_alumno[pos_alumno],
                                         arr_cant_creditos_alumno[pos_alumno],
                                         arr_monto_pagado_alumno[pos_alumno],
                                         costo_credito_escala, arr_cod_curso, arr_num_creditos_curso,
                                         cant_cursos,input);
            }
            else ignorar_hasta_delimitador('\n',input);
        }
        else ignorar_hasta_delimitador('\n',input);
    }
}








// Módulo que lee el archivo "Escalas.txt" y almacena la información del
// semestre(año y ciclo), escala y el costo por credito en arreglos.
void leer_escalas(const char *nombre_archivo, int *arr_semestre,
                  char *arr_escalas, double *arr_costo_por_credito_escala,
                  int &cant_escalas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int semestre;
    cant_escalas = 0;
    while(true){
        semestre = leer_semestre(input);
        if(input.eof())break; // Validar fin del archivo "Escalas.txt"
        arr_semestre[cant_escalas] = semestre;
        arr_escalas[cant_escalas] = leer_dato_tipo_char(input);
        arr_costo_por_credito_escala[cant_escalas] = leer_dato_tipo_double(input);
        cant_escalas++;
    }
}





// Módulo que inserta un nuevo curso en los arreglos de código y número de
// créditos del curso manteniendo el orden ascendente según el código del curso.
void insertar_ordenado_cursos(int cod_curso, double num_creditos,
                int *arr_cod_curso, double *arr_num_creditos_curso, int &cant_cursos){
    
    int indice;
    
    
    // Recorrer el arreglo desde el último elemento hacia el inicio,
    // desplazando hacia el índice siguiente aquellos cursos cuyo código sea
    // mayor que el código del nuevo curso para generar un espacio en la
    // posición correcta.
    for(indice = cant_cursos - 1; indice >= 0; indice--){
        if(cod_curso < arr_cod_curso[indice]){
            arr_cod_curso[indice + 1] = arr_cod_curso[indice];
            arr_num_creditos_curso[indice + 1] = arr_num_creditos_curso[indice];
        } else {
            // Se encontró la posición correcta para insertar el nuevo curso.
            break; // Se sale del bucle.
        }
    }
    
    // Insertar los datos del nuevo curso en los arreglos en la posición correcta.
    arr_cod_curso[indice + 1] = cod_curso;
    arr_num_creditos_curso[indice + 1] = num_creditos;
    
    // Incrementar la cantidad de cursos.
    cant_cursos++;
}





// Módulo que lee el archivo "Cursos.txt". Almacena los datos que se lee
// de código del curso y del número de créditos del curso en arreglos.
void leer_cursos(const char *nombre_archivo, int *arr_cod_curso,
                 double *arr_num_creditos_curso, int &cant_cursos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int cod_curso;
    double num_creditos;
    cant_cursos = 0;
    while(true){
        cod_curso = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "Cursos.txt"
        ignorar_hasta_delimitador(' ',input);
        num_creditos = leer_dato_tipo_double(input);
        insertar_ordenado_cursos(cod_curso, num_creditos, arr_cod_curso,
                                 arr_num_creditos_curso, cant_cursos);
    }
}





// Módulo que inserta un nuevo alumno en los arreglos de código y escala
// del alumno manteniendo el orden ascendente según el código del alumno.
void insertar_ordenado_alumnos(int cod_alumno, char escala_alumno,
                    int *arr_cod_alumno, char *arr_escala_alumno, int &cant_alumnos){
    
    // Iniciar desde el último elemento actual del arreglo.
    int indice = cant_alumnos - 1;
    
    
    // Mientras el arreglo tenga elementos y el nuevo código sea menor que los
    // existentes, se desplazan hacia el índice siguiente los elementos
    // para generar un espacio en los arreglos.
    while(indice >= 0   and   cod_alumno < arr_cod_alumno[indice]){
        
        arr_cod_alumno[indice + 1] = arr_cod_alumno[indice]; // Desplazar código
        arr_escala_alumno[indice + 1] = arr_escala_alumno[indice]; // Desplazar escala
        indice--;
    }
    
    // Insertar los datos del nuevo alumno en los arreglos en la posición correcta.
    arr_cod_alumno[indice + 1] = cod_alumno;
    arr_escala_alumno[indice + 1] = escala_alumno;
    
    // Incrementar la cantidad de alumnos.
    cant_alumnos++;
}






// Módulo que lee el archivo "Alumnos.txt". Almacena los datos que se lee
// de código del alumno y de la escala del alummno en arreglos.
void leer_alumnos(const char *nombre_archivo, int *arr_cod_alumno,
                  char *arr_escala_alumno, int &cant_alumnos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int cod_alumno;
    char escala_alumno;
    cant_alumnos = 0;
    while(true){
        cod_alumno = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "Alumnos.txt"
        escala_alumno = leer_dato_tipo_char(input);
        insertar_ordenado_alumnos(cod_alumno, escala_alumno, arr_cod_alumno,
                                  arr_escala_alumno,cant_alumnos);
    }
}





// Módulo que solicita los datos de año y ciclo al usuario que ingresa
// estos datos por teclado (ingreso de forma manual).
int solicitar_datos_al_usuario(){
    int anio_usuario,ciclo_usuario,semestre_usuario;
    char guion;
    cout << "Ingrese el anio y el ciclo (por ejemplo, de la";
    cout << " siguiente forma: 2020-1): ";
    cin >> anio_usuario >> guion >> ciclo_usuario;
    semestre_usuario = convertir_anio_y_ciclo(anio_usuario, ciclo_usuario);
    return semestre_usuario;
}


