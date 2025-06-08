

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340 
 * Creado el 5 de junio del 2025, 10:41 AM
 */

#include "Funciones.h"


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



// Módulo que lee un archivo de tipo "double"
double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}



// Módulo que asigna memoria dinámica y copia una cadena exacta desde un buffer temporal
void asignar_memoria_y_copiar_en_cadena_exacta(char *&cadena_exacta, const char *buffer_temporal) {
    
    // Se asigna memoria dinámica suficiente para almacenar la cadena del buffer más el carácter nulo '\0'
    cadena_exacta = new char[strlen(buffer_temporal) + 1];
    
    // Se copia el contenido del buffer temporal a la cadena exacta
    strcpy(cadena_exacta, buffer_temporal);
}




// Módulo que lee una cadena exacta hasta un delimitador
char *leer_cadena_exacta(ifstream &input, char delimitador) {
    // Se declara un buffer temporal donde se almacenará la cadena leída
    char buffer_temporal[80], *cadena_exacta;
    
    // Se lee hasta encontrar el delimitador o hasta 79 caracteres (dejando espacio para el '\0')
    input.getline(buffer_temporal, 80, delimitador);
    
    // Si se llegó al final del archivo, se retorna un puntero nulo
    if(input.eof()) return nullptr;
    
    // Se asigna memoria dinámica y se copia el contenido del buffer a 'cadena_exacta'
    asignar_memoria_y_copiar_en_cadena_exacta(cadena_exacta, buffer_temporal);
    
    // Se retorna la cadena exacta (en memoria dinámica)
    return cadena_exacta;
}



// Módulo que intercambia datos de tipo "int"
void intercambiar_int(int &dato_1, int &dato_2) {
    int aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}



// Módulo que intercambia datos de tipo "double"
void intercambiar_double(double &dato_1, double &dato_2) {
    double aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}



// Módulo que intercambia "cadena de caracteres"
void intercambiar_cadenas(char *&dato_1, char *&dato_2) {
    char *aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}



// Módulo que elabora las líneas del reporete
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output) {
    for(int i=0; i<cant_caracteres; i++) output.put(caracter);
    output << endl;
}




// Módulo que ordena los arreglos de forma ascendente por código de facultad
// y de forma descendente por el promedio ponderado
void ordenar_arreglos(int *arrCodigoAlumnos, char **arrAlumno, int *arrNumCursos,
                      double *arrSumaPonderada, double *arrNumCreditos, char **arrFacultad, int cant_alumnos) {
    
    // Algoritmo de ordenamiento de burbuja mejorado (doble for)
    for(int i = 0; i < cant_alumnos - 1; i++) {
        for(int k = i + 1; k < cant_alumnos; k++) {
            
            // Compara alfabéticamente las facultades (ascendente).
            // Si son iguales, compara los promedios ponderados (descendente).
            if(strcmp(arrFacultad[i], arrFacultad[k]) > 0 or
                  strcmp(arrFacultad[i], arrFacultad[k]) == 0 and
                      arrSumaPonderada[i] / arrNumCreditos[i] < arrSumaPonderada[k] / arrNumCreditos[k]) {
                
                // Intercambia todos los datos asociados entre la posición  ' i '  y  ' k '
                intercambiar_int(arrCodigoAlumnos[i], arrCodigoAlumnos[k]);
                intercambiar_cadenas(arrAlumno[i], arrAlumno[k]);
                intercambiar_int(arrNumCursos[i], arrNumCursos[k]);
                intercambiar_double(arrSumaPonderada[i], arrSumaPonderada[k]);
                intercambiar_double(arrNumCreditos[i], arrNumCreditos[k]);
                intercambiar_cadenas(arrFacultad[i], arrFacultad[k]);
            }
        }
    }
}




// Módulo que reemplaza los caracteres de guion bajo ('_') por espacios
// en blanco (' ') en una cadena de caracteres
void quitar_espacios_en_blanco(char *cadena) {
    
    // Recorre cada carácter de la cadena hasta encontrar el carácter nulo '\0'
    for(int indice = 0; cadena[indice]; indice++) {
        
        // Si el carácter actual es un guion bajo ('_'), lo reemplaza por un espacio (' ')
        if(cadena[indice] == '_') cadena[indice] = ' ';
    }
}





// Módulo que busca y asigna los nombres de dos facultades a partir de sus códigos
// leyendo los datos desde un "Facultades.txt". Se detiene la búsqueda cuando encuentra ambas facultades.
void conseguir_nombre_de_facultades(char *cod_facu_usuario_1, char *&facultad_1,
                                    char *cod_facu_usuario_2, char *&facultad_2, ifstream &input) {
    
    // Punteros para almacenar temporalmente el nombre y código de la facultad leídos del archivo
    char *nombre_facultad, *codigo_facultad;
    
    // Banderas para verificar si ya se encontró el nombre de cada facultad
    bool nombre_uno_de_facultad_conseguido = false, nombre_dos_de_facultad_conseguido = false;
    
    // Bucle que se ejecuta hasta que se encuentren ambas facultades o se termine el archivo "Facultades.txt"
    while(true) {
        nombre_facultad = leer_cadena_exacta(input, ' '); // Lee el nombre de la facultad
        if(nombre_facultad == nullptr) break; // Validar fin del archivo "Facultades.txt"
        quitar_espacios_en_blanco(nombre_facultad); // Reemplazar guiones bajos por espacios en blanco
        while(input.get() == ' '); // Leer los espacios en blanco entre el nombre y el código de la facultad
        input.unget(); // Devolver el último carácter leído (que no fue un espacio en blanco)
        codigo_facultad = leer_cadena_exacta(input, '\n'); // Lee el código de la facultad
        
        // Compara el código leído con el primer código buscado
        if(strcmp(cod_facu_usuario_1, codigo_facultad) == 0) {
            facultad_1 = nombre_facultad;
            nombre_uno_de_facultad_conseguido = true;
        }
        
        // Compara el código leído con el segundo código buscado
        if(strcmp(cod_facu_usuario_2, codigo_facultad) == 0) {
            facultad_2 = nombre_facultad;
            nombre_dos_de_facultad_conseguido = true;
        }
        
        // Si ya se encontraron ambos nombres, se puede salir del bucle
        if(nombre_uno_de_facultad_conseguido and nombre_dos_de_facultad_conseguido) break;
    }
}





// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(char *facultad_1, char *facultad_2, ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "PROMEDIO PONDERADO DE LOS ALUMNOS MATRICULADOS" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
    output << "CICLO: 2024-1" << endl;
    output << setw((TAM_REPORTE + strlen(facultad_1)) / 2);
    output << facultad_1 << endl;
    output << setw((TAM_REPORTE + 1) / 2) << 'Y' << endl;
    output << setw((TAM_REPORTE + strlen(facultad_2)) / 2);
    output << facultad_2 << endl;
}





// Módulo que imprime el encabezado del reporte solicitado
void imprimir_encabezado(ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 1);
    output << "Alumno";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) + 3);
    output << "No. de Cursos";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 4);
    output << "Suma Ponderada";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 2);
    output << "No. de Creditos";
    output << setw(TAM_REPORTE / N_COLUMNAS - 2);
    output << "Prom. Ponderado";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 1);
    output << "Facultad";
    output << endl;
    elaborar_lineas('-', TAM_REPORTE, output);
}




// Módulo que imprime un juego de datos de un alumno
void imprimir_un_juego_de_datos_de_un_alumno(int codigoAlumno, char *nombreAlumno, int numCursos,
                                             double sumaPonderada, double numCreditos, double promPonderado,
                                             char *codFacultad, ofstream &output) {
    output << codigoAlumno << " - ";
    output << left << setw(TAM_REPORTE / (N_COLUMNAS - 3) - 3);
    output << nombreAlumno << right;
    output << setw(2) << numCursos;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) + 6) << sumaPonderada;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) + 6) << numCreditos;
    output << setw(TAM_REPORTE / N_COLUMNAS - 2) << promPonderado;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 3) << ' ';
    output << codFacultad;
    output << endl;
}






// Módulo que imprime los datos de los alumnos pertenecientes a dos facultades específicas
// y determina cuál de ellos tiene la mayor cantidad de créditos acumulados.
void imprimir_alumnos(char *cod_facu_usuario_1, char *cod_facu_usuario_2, int *arrCodigoAlumnos,
                      char **arrAlumno, int *arrNumCursos, double *arrSumaPonderada,
                      double *arrNumCreditos, char **arrFacultad, int cant_alumnos,
                      char *&nombre_alumno_con_mayor_credito, int &cod_alumno_mayor_credito,
                      double &alumno_con_mayor_credito, ofstream &output) {
    // Recorrer el arreglo de alumnos
    for(int indice=0; indice < cant_alumnos; indice++) {
        // Verifica si el alumno pertenece a una de las dos facultades seleccionadas
        if(strcmp(arrFacultad[indice], cod_facu_usuario_1) == 0  or 
                    strcmp(arrFacultad[indice], cod_facu_usuario_2) == 0 ) {
            imprimir_un_juego_de_datos_de_un_alumno(arrCodigoAlumnos[indice], arrAlumno[indice],
                        arrNumCursos[indice], arrSumaPonderada[indice], arrNumCreditos[indice],
                        arrSumaPonderada[indice] / arrNumCreditos[indice], arrFacultad[indice], output);
            
            // Actualizar el alumno con mayor cantidad de créditos si corresponde
            if(alumno_con_mayor_credito < arrNumCreditos[indice]) {
                alumno_con_mayor_credito = arrNumCreditos[indice];
                cod_alumno_mayor_credito = arrCodigoAlumnos[indice];
                nombre_alumno_con_mayor_credito = arrAlumno[indice];
            }
        }
    }
}




// Módulo que imprime la información del alumno con el mayor número de créditos matriculados
void imprimir_alumno_con_mayor_numero_de_creditos(char *nombre_alumno_con_mayor_credito,
                  int cod_alumno_con_mayor_credito, double alumno_con_mayor_credito, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "Alumno con mayor numero de creditos matriculados: ";
    output << nombre_alumno_con_mayor_credito;
    output << " [" << cod_alumno_con_mayor_credito << ']';
    output << " con " << alumno_con_mayor_credito << " creditos" << endl;;
}






// Módulo que emite un reporte de alumnos de dos facultades específicas, ordenados y
// filtrados, e imprime al alumno con mayor número de créditos.
void emitir_reporte(const char *nombre_archivo_facultad, const char *nombre_archivo_reporte,
                    char *cod_facu_usuario_1, char *cod_facu_usuario_2, int *arrCodigoAlumnos,
                    char **arrAlumno, int *arrNumCursos, double *arrSumaPonderada,
                    double *arrNumCreditos, char **arrFacultad, int cant_alumnos) {
    // Ordena los arreglos según facultad (ascendente) y promedio ponderado (descendente)
    ordenar_arreglos(arrCodigoAlumnos, arrAlumno, arrNumCursos, arrSumaPonderada,
                     arrNumCreditos, arrFacultad, cant_alumnos);
    ifstream input;
    ofstream output;
    
    aperturar_archivo_lectura(nombre_archivo_facultad, input);
    aperturar_archivo_escritura(nombre_archivo_reporte, output);
    output << fixed << setprecision(2);
    
    char *facultad_1, *facultad_2, *nombre_alumno_con_mayor_credito;
    int cod_alumno_con_mayor_credito;
    double alumno_con_mayor_credito = 0.0;
    
    // Busca y asigna los nombres completos de las dos facultades a partir de sus códigos
    conseguir_nombre_de_facultades(cod_facu_usuario_1, facultad_1, cod_facu_usuario_2, facultad_2, input);
    imprimir_titulo(facultad_1, facultad_2, output); // Imprimir el título del reporte (con nombres de las facultades)
    imprimir_encabezado(output); // Imprime el encabezado del reporte
    
    // Imprimir los datos de los alumnos de las dos facultades seleccionadas y
    // determinar el alumno con mayor número de créditos
    imprimir_alumnos(cod_facu_usuario_1, cod_facu_usuario_2, arrCodigoAlumnos, arrAlumno, arrNumCursos,
                     arrSumaPonderada, arrNumCreditos, arrFacultad, cant_alumnos,
                     nombre_alumno_con_mayor_credito, cod_alumno_con_mayor_credito,
                     alumno_con_mayor_credito, output);
    
    // Imprimir los datos del alumno con el mayor número de créditos
    imprimir_alumno_con_mayor_numero_de_creditos(nombre_alumno_con_mayor_credito,
                        cod_alumno_con_mayor_credito, alumno_con_mayor_credito, output);
}






// Módulo que busca un dato entero en un arreglo de enteros
int buscar_dato(int dato, int *arreglo, int cant_datos) {
    // Recorre el arreglo desde el primer elemento hasta el último
    for(int indice = 0; indice < cant_datos; indice++) {
        // Si el dato en la posición actual coincide con el dato buscado
        if(arreglo[indice] == dato) return indice; // Retorna el índice encontrado
    }
    // Si no se encontró el dato en ninguna posición del arreglo
    return NO_ENCONTRADO;
}





// Módulo que lee los datos de un alumno de "Alumnos.csv".
// Ejemplo de lectura: 20226271,VELASQUEZ HUAYANAY EDGARD HENRY,FARQUITURB
void leer_datos_de_un_alumno(int &cod_alumno_leido, char *&nombre_alumno,
                             char *&facultad, ifstream &input) {
    
    // Leer el código del alumno (parte numérica antes de la primera coma)
    cod_alumno_leido = leer_dato_int(input);
    
    if(input.eof()) return; // Verificar si llegó al fin del archivo luego de leer el código del alumno
    
    input.get(); // Leer una coma
    
    // Leer el nombre del alumno hasta la siguiente coma
    nombre_alumno = leer_cadena_exacta(input, ',');
    
    // Leer el nombre de la facultad hasta el fin de línea
    facultad = leer_cadena_exacta(input, '\n');
}




// Módulo que lee los datos de alumnos y su facultad desde el archivo "Alumnos.csv"
// y actualiza los arreglos correspondientes si el alumno ya está registrado.
void leer_alumnos_y_facultad(const char *nombre_archivo, int *arrCodigoAlumnos, char **arrAlumno,
                             char **arrFacultad, int cant_alumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int cod_alumno_leido, indice_alumno;
    char *nombre_alumno, *facultad;
    while(true) {
        // Leer los datos de un alumno
        leer_datos_de_un_alumno(cod_alumno_leido, nombre_alumno, facultad, input);
        
        if(input.eof()) break; // Validar el fin del archivo "Alumnos.csv"
        
        // Buscar si el código del alumno leído está en el arreglo de alumnos registrados
        indice_alumno = buscar_dato(cod_alumno_leido, arrCodigoAlumnos, cant_alumnos);
        
        // Si el alumno está registrado, se actualizan su nombre y facultad
        if(indice_alumno != NO_ENCONTRADO) {
            arrAlumno[indice_alumno] = nombre_alumno;
            arrFacultad[indice_alumno] = facultad;
        }
    }
}





// Módulo que inserta un nuevo alumno o acumula sus datos si ya existe
void insertar_o_acumular(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                         double *arrNumCreditos, int &cant_alumnos, double cred_curso,
                         int cod_alumno, int nota) {
    
    // Buscar si el alumno ya está registrado en el arreglo
    int indice_alumno = buscar_dato(cod_alumno, arrCodigoAlumnos, cant_alumnos);
    
    if(indice_alumno == NO_ENCONTRADO) {
        // Es un nuevo alumno, entonces se inserta los datos del nuevo alumno
        arrCodigoAlumnos[cant_alumnos] = cod_alumno;
        arrNumCursos[cant_alumnos]++;
        arrSumaPonderada[cant_alumnos] += cred_curso * nota;
        arrNumCreditos[cant_alumnos] += cred_curso;
        cant_alumnos++;
    } else {
        // El alumno existe, entonces solo se acumulan los arreglos
        arrNumCursos[indice_alumno]++;
        arrSumaPonderada[indice_alumno] += cred_curso * nota;
        arrNumCreditos[indice_alumno] += cred_curso;
    }
}





// Módulo que lee una línea de calificaciones de alumnos de un curso específico
void leer_lista_de_notas(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                         double *arrNumCreditos, int &cant_alumnos, double cred_curso, ifstream &input) {
    int cod_alumno, nota;
    
    // Leer la lista de códigos de alumno y notas hasta el fin de línea
    while(true) {
        cod_alumno = leer_dato_int(input);  // Leer código de un alumno
        nota = leer_dato_int(input);  // Leer su nota
        
        // Insertar o acumular los datos del alumno leído
        insertar_o_acumular(arrCodigoAlumnos, arrNumCursos, arrSumaPonderada,
                            arrNumCreditos, cant_alumnos, cred_curso, cod_alumno, nota);
        
        // Verificar si se llegó al fin de línea
        if(input.get() == '\n') break;
    }
}




// Módulo que procesa el archivo "Calificaciones.txt" y almacena la información de cada alumno
void leer_calificaciones(const char *nombre_archivo, int *arrCodigoAlumnos, int *arrNumCursos,
                         double *arrSumaPonderada, double *arrNumCreditos, int &cant_alumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    char *codigo_del_curso;
    double cred_curso;
    cant_alumnos = 0;
    while(true) {
        codigo_del_curso = leer_cadena_exacta(input, ' ');  // Leer código del curso
        if(codigo_del_curso == nullptr) break;   // Salir del bucle si ya no hay más cursos por leer
        cred_curso = leer_dato_double(input);  // Leer los créditos del curso
        
        // Leer la lista de calificaciones para ese curso
        leer_lista_de_notas(arrCodigoAlumnos, arrNumCursos, arrSumaPonderada,
                            arrNumCreditos, cant_alumnos, cred_curso, input);
    }
}





// Módulo que solicita al usuario dos códigos de facultad distintos y los almacena dinámicamente
void solicitar_dos_codigos_de_facultad_al_usuario(char *&cod_facu_usuario_1, char *&cod_facu_usuario_2) {
    
    // Buffers temporales para almacenar los códigos ingresados por el usuario
    char buffer_temporal_de_cod_facu_1[15], buffer_temporal_de_cod_facu_2[15];
    
    // Solicitud al usuario para que ingrese dos códigos separados por espacio
    cout << "Ingrese dos códigos de facultad diferentes y separados por";
    cout << " espacios en blanco(por ejemplo: EEGGCC  FARTE): ";
    
    // Leer ambos códigos desde la entrada estándar
    cin >> buffer_temporal_de_cod_facu_1 >> buffer_temporal_de_cod_facu_2;
    
    // Asignar memoria dinámica y copiar los valores del buffer a las cadenas exactas
    asignar_memoria_y_copiar_en_cadena_exacta(cod_facu_usuario_1, buffer_temporal_de_cod_facu_1);
    asignar_memoria_y_copiar_en_cadena_exacta(cod_facu_usuario_2, buffer_temporal_de_cod_facu_2);
}

