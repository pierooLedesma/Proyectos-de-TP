

/*
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de mayo de 2025, 01:24 PM
 */

#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input){
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output){
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que lee un dato de tipo "int"
int leer_dato_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo "double"
double leer_dato_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo "char"
char leer_dato_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output){
    for(int i = 0;  i < cant_caracteres;  i++)  output.put(caracter);
    output << endl;
}





// Módulo que busca un dato en un arreglo ordenado ascendentemente. Retorna "true" si lo encuentra y
// también devuelve el índice en el que se encuentra el dato buscado. Si no lo encuentra, retorna
// "false"  e  indica el índice dónde debería insertarse.
bool busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos, int &indice){
    int limite_inferior = 0, limite_superior = cant_datos - 1, punto_medio;
    while(true){
        if(limite_inferior > limite_superior) {
            // si ya no hay elementos por revisar, el dato no está.
            // Se devuelve el índice donde debe insertarse.
            indice = limite_inferior;
            return false;
        }
        
        punto_medio = (limite_superior + limite_inferior) / 2;  // Calcular el punto medio del intervalo actual.
        
        if(arreglo[punto_medio] == dato_buscado) {
            // Si se encuentra ese dato a buscar en el arreglo, entonces se retorna "true" y el índice.
            indice = punto_medio;
            return true;
        }
        
        if(arreglo[punto_medio] < dato_buscado){
            limite_inferior = punto_medio + 1;
        } else {
            limite_superior = punto_medio - 1;
        }
    }
}





// Módulo que busca el nombre de facultad mediante un código de facultad ingresado
bool buscar_nombre_facultad(ifstream &input_facultades, char *nombre_facultad, int cod_facultad){
    char facultad_leida[MAX_CARACTERES_FACULTAD];
    int cod_facultad_leido;
    while(true){
        input_facultades >> facultad_leida;
        if(input_facultades.eof()) break;
        cod_facultad_leido = leer_dato_int(input_facultades);
        if(cod_facultad_leido == cod_facultad){
            for(int indice = 0; facultad_leida[indice]; indice++)
                facultad_leida[indice] = (facultad_leida[indice] == '_' ?  ' ' : facultad_leida[indice]);
            copiar_cadena(nombre_facultad, facultad_leida);
            return true;
        }
    }
    return false;
}






// Módulo que imprime el título del reporte solicitado con el nombre
// de la facultad que el usuario ingresó
void imprimir_titulo(char *nombre_facultad, ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "PROMEDIO PONDERADO DE LOS ALUMNOS MATRICULADOS" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
    output << "CICLO: 2024-1" << endl;
    output << setw((TAM_REPORTE + longitud_cadena(nombre_facultad)) / 2);
    output << nombre_facultad << endl;
}




// Módulo que imprime el encabezado de los alumnos para el reporte solicitado
void imprimir_encabezado(ofstream &output){
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5));
    output << "Alumno";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2)  + 7);
    output << "No. de Cursos";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1)  - 1);
    output << "Suma Ponderada";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1));
    output << "No. de Creditos";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1));
    output << "Prom. Ponderado";
    output << endl;
    elaborar_lineas('-', TAM_REPORTE, output);
}



// Módulo que busca un caracter desde el final de una cadena de caracteres
int buscar_caracter(const char *cadena, char caracter) {
    int long_cadena = longitud_cadena(cadena);
    
    for(int indice = long_cadena - 1; indice > 0; indice--){
        if(cadena[indice] == caracter)  return indice;
    }
    
    return NO_ENCONTRADO;
}



// Módulo que convierte letras mayúsculas en minúsculas si están en medio de una palabra (no al inicio).
void camelizar(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++){
        if(cadena[indice] == '/'  or cadena[indice] == '-')  cadena[indice] = ' ';
        if(indice > 0  and   cadena[indice - 1] != ' '   and  (cadena[indice] >= 'A'  and cadena[indice] <= 'Z')){
            cadena[indice] += 'a' - 'A';
        }
    }
}




// Módulo que reorganiza una cadena con formato tipo "APELLIDO/NOMBRE" a "Nombre Apellido"
void modificar_nombre_completo(char *cadena_original) {
    char copia_de_cadena_original[MAX_CARACTERES_CADENA];
    int indice = buscar_caracter(cadena_original, '/');
    if(indice != NO_ENCONTRADO){
        copiar_cadena(copia_de_cadena_original, &cadena_original[indice + 1]);
        concatenar(copia_de_cadena_original, " ");
        cadena_original[indice] = '\0';
        concatenar(copia_de_cadena_original, cadena_original);
        camelizar(copia_de_cadena_original);
        copiar_cadena(cadena_original, copia_de_cadena_original);
    }
}





// Módulo que imprime un juego de datos de un alumno
void imprimir_juego_de_datos_de_un_alumno(int codigoAlumno, char *nombre_completo_alumno,
                                          int numCursos,double sumaPonderada, double numCreditos,
                                          double promedioPonderado, ofstream &output) {
    output << codigoAlumno << " - ";
    modificar_nombre_completo(nombre_completo_alumno);
    output << nombre_completo_alumno;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2)  -  longitud_cadena(nombre_completo_alumno)) << ' ';
    output << setw(2) << numCursos;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) + 1) << sumaPonderada;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 1) << numCreditos;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 1) << promedioPonderado;
    output << endl;
}







// Módulo que imprime todos los datos de los alumnos de una facultad
void imprimir_alumnos(int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                      double *arrNumCreditos, int cant_alumnos, int cod_facultad_usuario,
                      ifstream &input_alumnos, ofstream &output) {
    int cod_alumno_leido, cod_facultad_leido, indice_alumno;
    char nombre_completo_alumno[MAX_CARACTERES_CADENA];
    while(true){
        cod_alumno_leido = leer_dato_int(input_alumnos);
        if(input_alumnos.eof()) break; // Validar fin del archivo "Alumnos.txt"
        input_alumnos >> nombre_completo_alumno;
        cod_facultad_leido = leer_dato_int(input_alumnos);
        if(busqueda_binaria(cod_alumno_leido, arrCodigoAlumnos, cant_alumnos, indice_alumno)  and
                     cod_facultad_leido == cod_facultad_usuario){
            imprimir_juego_de_datos_de_un_alumno(arrCodigoAlumnos[indice_alumno],
                              nombre_completo_alumno, arrNumCursos[indice_alumno],
                              arrSumaPonderada[indice_alumno], arrNumCreditos[indice_alumno],
                              arrSumaPonderada[indice_alumno] / arrNumCreditos[indice_alumno], output);
        }
    }
}





// Módulo que elabora el reporte solicitado del usuario de una facultad elegida
void emitir_reporte_solicitado(const char *nombre_archivo_alumnos,
                const char *nombre_archivo_reporte, int *arrCodigoAlumnos,
                int *arrNumCursos, double *arrSumaPonderada, double *arrNumCreditos,
                int cant_alumnos,int cod_facultad_usuario, char *nombre_facultad) {
    ifstream input_alumnos;
    ofstream output;
    aperturar_archivo_lectura(nombre_archivo_alumnos, input_alumnos);
    aperturar_archivo_escritura(nombre_archivo_reporte, output);
    imprimir_titulo(nombre_facultad, output);
    imprimir_encabezado(output);
    output << fixed << setprecision(2);
    imprimir_alumnos(arrCodigoAlumnos, arrNumCursos, arrSumaPonderada, arrNumCreditos,
                     cant_alumnos, cod_facultad_usuario, input_alumnos, output);
    elaborar_lineas('=', TAM_REPORTE, output);
}





// Módulo que procesa la elaboración del reporte solicitado mediante el código de facultad ingresado por el usuario
void procesar_la_elaboracion_del_reporte(const char *nombre_archivo_facultades,
                            const char *nombre_archivo_alumnos, const char *nombre_archivo_reporte,
                            int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
                            double *arrNumCreditos, int cant_alumnos, int cod_facultad_usuario) {
    ifstream input_facultades, input_alumnos;
    ofstream output;
    aperturar_archivo_lectura(nombre_archivo_facultades, input_facultades);
    char nombre_facultad[MAX_CARACTERES_FACULTAD];
    bool existe_facultad;
    existe_facultad = buscar_nombre_facultad(input_facultades, nombre_facultad, cod_facultad_usuario);
    if(existe_facultad){
        emitir_reporte_solicitado(nombre_archivo_alumnos, nombre_archivo_reporte,
                                arrCodigoAlumnos, arrNumCursos, arrSumaPonderada, arrNumCreditos,
                                cant_alumnos, cod_facultad_usuario, nombre_facultad);
    } else {
        cout << "EL CÓDIGO DE FACULTAD INGRESADO NO EXISTE" << endl;
    }
}





// Módulo que inserta un nuevo alumno en el arreglo o, si ya existe, acumula la
// información sobre sus notas, cursos y créditos.
void insertar_o_acumular(int cod_alumno, int nota_alumno, int *arrCodigoAlumnos, int *arrNumCursos,
                         double *arrSumaPonderada, double *arrNumCreditos, int &cant_alumnos,
                         double creditos_curso) {
    int indice_alumno;
    if ( busqueda_binaria(cod_alumno, arrCodigoAlumnos, cant_alumnos, indice_alumno) ) {
        // El alumno ya existe en los arreglos, entonces se actualizan acumuladores
        arrNumCursos[indice_alumno]++;
        arrSumaPonderada[indice_alumno] += nota_alumno * creditos_curso;
        arrNumCreditos[indice_alumno] += creditos_curso;
    } else {
        // Se recorre el arreglo desde el final hasta la posición donde se debe insertar.
        for(int indice = cant_alumnos; indice > indice_alumno; --indice){
            arrCodigoAlumnos[indice] = arrCodigoAlumnos[indice - 1];
            arrNumCursos[indice] = arrNumCursos[indice - 1];
            arrSumaPonderada[indice] = arrSumaPonderada[indice - 1];
            arrNumCreditos[indice] = arrNumCreditos[indice - 1];
        }
        // Inserta el nuevo código de alumno en la posición correcta
        arrCodigoAlumnos[indice_alumno] = cod_alumno;
    
        // Inicializa el número de cursos a 1, ya que es la primera aparición del alumno
        arrNumCursos[indice_alumno] = 1;
    
        // Calcula y guarda la suma ponderada: nota * créditos del curso
        arrSumaPonderada[indice_alumno] = nota_alumno * creditos_curso;
    
        // Guarda los créditos del curso para el nuevo alumno
        arrNumCreditos[indice_alumno] = creditos_curso;
    
        // Aumentar la cantidad total de alumnos
        cant_alumnos++;
    }
}




// Módulo que procesa una lista de notas de un curso del archivo "Calificaciones.txt".
void procesar_lista_de_notas(double creditos_curso, int *arrCodigoAlumnos,
                 int *arrNumCursos, double *arrSumaPonderada,
                 double *arrNumCreditos, int &cant_alumnos, ifstream &input){
    int cod_alumno, nota_alumno, pos_alumno;
    while(true){
        cod_alumno = leer_dato_int(input);
        nota_alumno = leer_dato_int(input);
        insertar_o_acumular(cod_alumno, nota_alumno, arrCodigoAlumnos, arrNumCursos,
                            arrSumaPonderada, arrNumCreditos, cant_alumnos, creditos_curso);
        if(input.get() == '\n') break;
    }
}





// Módulo que lee el archivo "Calificaciones.txt". Ingresa los datos de los alumnos por cada curso
// y se realiza ello de forma ascendente por el código del alumno en los arreglos.
void leer_calificaciones(const char *nombre_archivo, int *arrCodigoAlumnos, int *arrNumCursos,
                         double *arrSumaPonderada, double *arrNumCreditos, int &cant_alumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    double creditos_curso;
    char cod_curso[MAX_CARACTERES_CURSO];
    cant_alumnos = 0;
    while(true){
        /********* Lectura fija del archivo "Calificaciones.txt" *************/
        input >> cod_curso;
        if(input.eof()) break; // Validar fin del archivo "Calificaciones.txt"
        creditos_curso = leer_dato_double(input);
        
        /********* Lectura variable del archivo "Calificaciones.txt" **********/
        procesar_lista_de_notas(creditos_curso, arrCodigoAlumnos ,arrNumCursos,
                        arrSumaPonderada, arrNumCreditos, cant_alumnos, input);
    }
}




// Módulo que ingresa el código de una facultad
int solicitar_codigo_de_una_facultad_al_usuario(){
    int cod_facultad;
    cout << "Ingrese el codigo de una facultad: ";
    cin >> cod_facultad;
    return cod_facultad;
}

