

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de mayo de 2025, 08:21 PM
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



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



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


// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i = 0;  i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}



// Módulo que lee e imprime una cadena de caracteres
void leer_e_imprimir_cadena_caracteres(bool todo_a_mayusculas,int tamano_total_cadena,
                                       ifstream &input,ofstream &output){
    int n_caracteres;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        char c = input.get();
        if(c == ' ') break;
        if(c == '_')   c = ' ';
        if(todo_a_mayusculas) c = (c >= 'a'  and  c <= 'z'   ?  c - 'a' + 'A' : c);
        output.put(c);
        n_caracteres++;
    }
    for(int i=0; i < tamano_total_cadena - n_caracteres; i++) output.put(' ');
}




// Módulo que solicita un semestre (anio-ciclo) al usuario
void solicitar_semestre_al_usuario(int &ciclo,int &anio){
    char guion;
    cout << "Ingrese un semestre (por ejemplo: 2022-1): ";
    cin >> anio >> guion >> ciclo;
}




// Módulo que elabora el reporte solicitado
void elaborar_reporte(const char *nombre_archivo_alumnos,const char *nombre_archivo_matricula,
                      const char *nombre_archivo_escalas,const char *nombre_archivo_cursos,
                      const char *nombre_archivo_reporte,int ciclo_usuario,int anio_usuario){
    ifstream input_alumnos,input_matricula,input_escalas,input_cursos;
    ofstream output;
    int cant_alumnos = 0;
    double monto_total_pagado = 0.0;
    aperturar_archivo_lectura(nombre_archivo_alumnos,input_alumnos);
    aperturar_archivo_lectura(nombre_archivo_matricula,input_matricula);
    aperturar_archivo_lectura(nombre_archivo_escalas,input_escalas);
    aperturar_archivo_lectura(nombre_archivo_cursos,input_cursos);
    aperturar_archivo_escritura(nombre_archivo_reporte,output);
    imprimir_titulo(anio_usuario,ciclo_usuario,output);
    output << fixed << setprecision(2);
    procesar_alumnos(input_alumnos,input_matricula,input_escalas,input_cursos,
                     cant_alumnos,monto_total_pagado,output,ciclo_usuario,anio_usuario);
    imprimir_resumen(cant_alumnos,monto_total_pagado,output);
}



// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(int anio_usuario,int ciclo_usuario,ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "DETALLE DE PAGOS REALIZADO POR CICLO" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2  - 3);
    output << "CICLO: ";
    imprimir_anio_y_ciclo(anio_usuario,ciclo_usuario,output);
    output << endl;
}




// Módulo que procesa el archivo "Alumnos.txt". Lee e imprime los datos de un alumno.
void procesar_alumnos(ifstream &input_alumnos,ifstream&input_matricula,ifstream &input_escalas,
                      ifstream &input_cursos,int &cant_alumnos,double &monto_total_pagado,
                      ofstream &output,int ciclo_usuario,int anio_usuario){
    int codigo_alumno;
    char escala_alumno;
    while(true){
        codigo_alumno = leer_tipo_dato_int(input_alumnos);
        if(input_alumnos.eof()) break;  // Validar fin del archivo "Alumnos.txt"
        continuar_lectura_de_un_alumno_e_imprimir_sus_datos(codigo_alumno,escala_alumno,
                                                            input_alumnos,output);
        int cant_cursos = 0;
        double valor_credito_escala,total_creditos = 0.0, total_monto_pagado = 0.0;
        valor_credito_escala = buscar_valor_credito_escala(anio_usuario,ciclo_usuario,
                                                           escala_alumno,input_escalas);
        procesar_matricula(input_matricula,input_cursos,cant_cursos,
                           total_creditos,total_monto_pagado,output,ciclo_usuario,
                           anio_usuario,codigo_alumno,valor_credito_escala);
        imprimir_resumen_de_un_alumno(total_creditos,total_monto_pagado,output);
        cant_alumnos += (cant_cursos > 0 ? 1:0);
        monto_total_pagado += total_monto_pagado;
    }
}





// Módulo que continúa con la lectura de datos de un alumno del archivo "Alumnos.txt" y los imprime
void continuar_lectura_de_un_alumno_e_imprimir_sus_datos(int codigo_alumno,
                        char &escala_alumno,ifstream &input_alumnos,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    
    output << "ALUMNO: " << codigo_alumno;
    output << " - ";
    leer_e_imprimir_cadena_caracteres(true,2 * (TAM_REPORTE / 3  + 2),input_alumnos,output);
    
    escala_alumno = leer_tipo_dato_char(input_alumnos);
    output << "ESCALA: " << escala_alumno;
    output << endl;
}





// Módulo que busca el valor de crédito de la respectiva escala de un alumno de un semestre (año y ciclo)
double buscar_valor_credito_escala(int anio_usuario,int ciclo_usuario,
                                   char escala_alumno,ifstream &input_escalas){
    input_escalas.clear(); // Liberar el buffer del archivo "Escalas.txt" y limpia banderas levantadas.
    input_escalas.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "Escalas.txt"
    int anio,ciclo;
    char escala;
    double valor_credito_escala;
    while(true){
        leer_anio_y_ciclo(anio,ciclo,input_escalas);
        if(input_escalas.eof()) break; // Validar fin del archivo "Escalas.txt"
        escala  = leer_tipo_dato_char(input_escalas);
        valor_credito_escala = leer_tipo_dato_double(input_escalas);
        if(anio == anio_usuario   and
                          ciclo == ciclo_usuario   and
                                          escala == escala_alumno){
            return valor_credito_escala;
        }
    }
    
    // En caso no se haya encontrado el valor de crédito
    // de la respectiva escala del alumno en el derterminado
    // semestre (año y ciclo) ingresado por el usuario, pues se retornará el valor cero.
    return 0.0;
}






// Módulo que procesa el archivo "Matricula.txt". Se busca el semestre (año y ciclo) que el usuario ingresó
// y el código de un alumno para imprimir la lisa de cursos que llevó el alumno en dicho semestre.
void procesar_matricula(ifstream &input_matricula,ifstream &input_cursos,
                        int &cant_cursos,double &total_creditos,double &total_monto_pagado,
                        ofstream &output,int ciclo_usuario,int anio_usuario,
                        int codigo_alumno,double valor_credito_escala){
    input_matricula.clear(); // Liberar el buffer del archivo "Matricula.txt" y limpia banderas levantadas.
    input_matricula.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "Matricula.txt"
    int anio,ciclo,cod_alumno_leido;
    elaborar_encabezado_cursos(output);
    while(true){
        leer_anio_y_ciclo(anio,ciclo,input_matricula);
        if(input_matricula.eof()) break; // Validar fin del archivo "Matricula.txt"
        cod_alumno_leido = leer_tipo_dato_int(input_matricula);
        if(anio == anio_usuario  and  ciclo == ciclo_usuario  and  cod_alumno_leido == codigo_alumno){
            leer_lista_de_cursos(cant_cursos,total_creditos,total_monto_pagado,valor_credito_escala,
                                 input_matricula,input_cursos,output);
            break;
        }
        else   ignorar_hasta_delimitador('\n',input_matricula);
    }
    if(cant_cursos == 0){
        output << setw(TAM_REPORTE / 2  - 10);
        output << "EL ALUMNO NO SE HA MATRICULADO EN ESTE CICLO" << endl;
    }
}





// Módulo que imprime el encabezado de la lista de cursos de un alumno
void elaborar_encabezado_cursos(ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 1);
    output << "CURSO MATRICULADO";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1) - 4);
    output << "CREDITOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2);
    output << "MONTO PAGADO";
    output << endl;
}





// Módulo que lee la lista de cursos de un alumno del archivo "Matricula.txt"
void leer_lista_de_cursos(int &cant_cursos,double &total_creditos,double &total_monto_pagado,
                          double valor_credito_escala,ifstream &input_matricula,
                          ifstream &input_cursos,ofstream &output){
    int cod_curso,n_cursos = 0;
    double numero_creditos_curso,monto_pagado;
    while(true){
        cod_curso = leer_tipo_dato_int(input_matricula);
        buscar_and_imprimir_curso(n_cursos,cod_curso,numero_creditos_curso,
                                  monto_pagado,valor_credito_escala,cant_cursos,
                                  input_cursos,output);
        total_creditos += numero_creditos_curso;
        total_monto_pagado += monto_pagado;
        if(input_matricula.get() == '\n') break;
    }
}





// Módulo que busca en el archivo "Cursos.txt" un curso de la lista de cursos que lleva un alumno
void buscar_and_imprimir_curso(int &n_cursos,int cod_curso,double &numero_creditos_curso,
                               double &monto_pagado,double valor_credito_escala,
                               int &cant_cursos,ifstream &input_cursos,ofstream &output){
    input_cursos.clear(); // Liberar el buffer del archivo "Cursos.txt" y limpia banderas levantadas.
    input_cursos.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "Cursos.txt"
    int cod_curso_leido;
    numero_creditos_curso = 0.0;
    monto_pagado = 0.0;
    while(true){
        cod_curso_leido = leer_tipo_dato_int(input_cursos);
        if(input_cursos.eof()) break; // Validar fin del archivo "Cursos.txt"
        if(cod_curso_leido == cod_curso){
            // Se encontró el curso.
            n_cursos++;
            imprimir_curso(n_cursos,cod_curso,numero_creditos_curso,monto_pagado,
                           valor_credito_escala,input_cursos,output);
            cant_cursos++;
            break;
        }
        else ignorar_hasta_delimitador('\n',input_cursos);
    }
}




// Módulo que imprime la información de un curso que lleva un alumno
void imprimir_curso(int n_cursos,int cod_curso,double &numero_creditos_curso,
                    double &monto_pagado,double valor_credito_escala,
                    ifstream &input_cursos,ofstream &output){
    output << ' ' << setfill('0') << setw(2) << n_cursos << setfill(' ') << ')';
    output << setw(N_COLUMNAS + 5) << cod_curso << " - ";
    leer_e_imprimir_cadena_caracteres(false,TAM_REPORTE / 2,input_cursos,output);
    numero_creditos_curso = leer_tipo_dato_double(input_cursos);
    output << numero_creditos_curso;
    monto_pagado = numero_creditos_curso * valor_credito_escala;
    output << setw(TAM_REPORTE / 6  - 3) << monto_pagado << endl;
}





// Módulo que imprime el resumen de un alumno (el total de créditos y el total monto pagado).
void imprimir_resumen_de_un_alumno(double total_creditos,double total_monto_pagado,
                                   ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "TOTAL CREDITOS: " << setw(5) << total_creditos;
    output << setw(TAM_REPORTE / 5);
    output << "TOTAL MONTO PAGADO:";
    output << setw(TAM_REPORTE / 10);
    output << total_monto_pagado;
    output << endl;
}





// Módulo que imprime el resumen del reporte solicitado
// (la cantidad total de alumnos y el monto total pagado).
void imprimir_resumen(int cant_alumnos,double monto_total_pagado,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "RESUMEN:" << endl;
    output << left << setw(TAM_REPORTE / 4  - 1);
    output << "CANTIDAD TOTAL DE ALUMNOS:" << cant_alumnos << right;
    output << setw(TAM_REPORTE / 4  + 3);
    output << "MONTO TOTAL PAGADO:";
    output << setw(TAM_REPORTE / 5  - 10) << monto_total_pagado;
    output << endl;
}

