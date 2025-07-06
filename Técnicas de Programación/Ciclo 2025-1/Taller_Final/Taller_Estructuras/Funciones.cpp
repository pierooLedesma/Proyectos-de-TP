

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 2 de julio del 2025, 10:27 AM
 */


#include "Funciones.hpp"


// Módulo que apertura un archivo de lectura sin usar el constructor.
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que apertura un archivo de escritura sin usar el constructor.
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato de tipo "int".
int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "double".
double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "char".
char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get(); // Lectura de la coma o del cambio de línea.
    return dato;
}


// Módulo que asigna memoria exacta a una cadena de caracteres.
char *asignar_cadena(const char *buffer) {
    char *cadena_a_asignar;
    cadena_a_asignar = new char[strlen(buffer) + 1];
    strcpy(cadena_a_asignar, buffer);
    return cadena_a_asignar;
}


// Módulo que lee una cadena de caracteres con memoria exacta.
char *leer_cadena(ifstream &input, char delimitador) {
    char buffer[70], *cadena;
    input.getline(buffer, 70, delimitador);
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}




// Módulo que elabora las líneas del reporte solicitado.
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output) {
    for(int i=0; i<cantCaracteres; i++) output.put(caracter);
    output << endl;
}






// Módulo que concatena un número entero al final de una cadena de caracteres.
void concatenar_numero(char *cadena, int numero) {
    int cantDigitos, digito, longitud_cadena;
    char entero_digito_en_caracter;
    
    // Calcular la longitud actual de la cadena (para saber desde dónde empezar a agregar más caracteres).
    longitud_cadena = strlen(cadena);
    
    // Calcular la cantidad de dígitos del número (por ejemplo: 123 -> 3 dígitos)
    cantDigitos = log10(numero) + 1;
    
    // Bucle que recorre cada dígito del número de izquierda a derecha.
    while(cantDigitos > 0) {
        
        // Obtener el dígito más significativo (ejemplo: si el número es 123, entonces se obtiene 1).
        digito = numero / (int) pow(10, cantDigitos - 1);
        
        // Convertir el dígito entero a caracter (ejemplo: 1 -> '1').
        entero_digito_en_caracter = '0' + digito;
        
        // Añadir el caracter correspondiente al final de la cadena.
        cadena[longitud_cadena] = entero_digito_en_caracter;
        
        // Eliminar el dígito ya procesado del número (ejemplo: 123 -> 23).
        numero = numero % (int) pow(10, cantDigitos - 1);
        
        cantDigitos--;  // Disminuir la cantidad de dígitos restantes.
        longitud_cadena++; // Actualizar el índice para agregar el siguiente caracter en la cadena.
    }
    cadena[longitud_cadena] = '\0'; // Colocar el caracter nulo al final para cerrar la cadena correctamente.
}






// Módulo que concatena a una cadena el semestre ingresado por el usuario.
void concatenar_semestre(char *cadena, int anho_usuario, int ciclo_usuario) {
    concatenar_numero(cadena, anho_usuario);
    strcat(cadena, "-");
    concatenar_numero(cadena, ciclo_usuario);
}





// Módulo que escoge el nombre del archivo de reporte (el reporte solicitado o el reporte preliminar de alumnos).
void escoger_nombre_del_archivo(int anho_usuario, int ciclo_usuario, bool es_reporte_final, char *nombre_archivo) {
    if(es_reporte_final) {
        strcpy(nombre_archivo, "ReporteAlumnos_");
        concatenar_semestre(nombre_archivo, anho_usuario, ciclo_usuario);
        strcat(nombre_archivo, ".txt");
    } else {
        strcpy(nombre_archivo, "ReporteInicialAlumnos.txt");
    }
}





// Módulo que imprime el título del reporte (el de alumnos preliminar o del solicitado).
void imprimir_titulo(bool es_reporte_final, int anho_usuario, int ciclo_usuario, ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA TP" << endl;
    if(es_reporte_final) {
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "DETALLE DE PAGO REALIZADO POR CICLO" << endl;
        char titulo_del_ciclo[14] = "CICLO: ";
        concatenar_semestre(titulo_del_ciclo, anho_usuario, ciclo_usuario);
        output << setw((TAM_REPORTE + strlen(titulo_del_ciclo)) / 2) << titulo_del_ciclo << endl;
    } else {
        output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
        output << "DETALLE PRELIMINAR DE ALUMNOS" << endl;
    }
}






// Módulo que imprime la información personal de un alumno matriculado.
void imprimir_un_alumno_matriculado(int codAlumno, char *nombre, char escala, double valorCred, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "ALUMNO: " << codAlumno << " - " << left << setw(TAM_REPORTE / (N_COLUMNAS - 1) - 7);
    output << nombre << right << "ESCALA: " << escala << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 3);
    output << "Valor Credito: " << valorCred << endl;
    elaborar_lineas('-', TAM_REPORTE, output);
}







// Módulo que imprime los cursos matriculados de un alumno.
void imprimir_cursos_matriculados_de_un_alumno(struct Curso *arrCursos, int cantidadCursos,
                                               double valorCred, ofstream &output) {
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 2) << "CURSO MATRICULADO";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 2) << "CREDITOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1) - 5) << "MONTO PAGADO" << endl;
    for(int indice = 0; indice < cantidadCursos; indice++) {
        output << setfill('0') << setw(2) << indice + 1 << ')' << setfill(' ') << setw(2) << ' ';
        output << arrCursos[indice].codCurso << " - " << left << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 5);
        output << arrCursos[indice].nombre << right << arrCursos[indice].creditos;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 3) << valorCred * arrCursos[indice].creditos << endl;
    }
}






// Módulo que imprime los totales (total de créditos y de monto pagado) de un alumno matriculado.
void imprimir_totales_de_un_alumno(double totalCreditos, double totalPago, ofstream &output) {
    elaborar_lineas('-', TAM_REPORTE, output);
    output << "TOTAL CREDITOS: " << totalCreditos;
    output << setw(TAM_REPORTE / N_COLUMNAS) << "TOTAL MONTO PAGADO: " << totalPago << endl;
}






// Módulo que imprime los datos de los alumnos matriculados en el reporte.
void imprimir_alumnos_matriculados(struct Alumno *arrAlumnos, int cantAlumnos, int &cantidad_alumnos_matriculados,
                                   double &total_monto_pagado, bool es_reporte_final, ofstream &output) {
    for(int indice = 0; indice < cantAlumnos; indice++) {
        if(not es_reporte_final  or  arrAlumnos[indice].cantidadCursos > 0) {
            imprimir_un_alumno_matriculado(arrAlumnos[indice].codAlumno, arrAlumnos[indice].nombre,
                                           arrAlumnos[indice].escAlumno.escala, arrAlumnos[indice].escAlumno.valorCred, output);
            imprimir_cursos_matriculados_de_un_alumno(arrAlumnos[indice].cursos, arrAlumnos[indice].cantidadCursos,
                                                      arrAlumnos[indice].escAlumno.valorCred, output);
            imprimir_totales_de_un_alumno(arrAlumnos[indice].totalCreditos, arrAlumnos[indice].totalPago, output);
            cantidad_alumnos_matriculados++;
            total_monto_pagado += arrAlumnos[indice].totalPago;
        }
    }
}






// Módulo que imprime el resumen del reporte (cantidad de alumnos matriculados y el total del monto pagado).
void imprimir_resumen_del_reporte(int cantidad_alumnos_matriculados, double total_monto_pagado, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "RESUMEN:" << endl;
    output << "CANTIDAD TOTAL  DE ALUMNOS: " << cantidad_alumnos_matriculados;
    output << setw(TAM_REPORTE / N_COLUMNAS) << "MONTO TOTAL PAGADO: ";
    output << total_monto_pagado << endl;
}







// Módulo que emite el reporte preliminar de alumnos o el reporte solicitado por el semestre ingresado por el usuario.
void emitir_reporte(int anho_usuario, int ciclo_usuario, struct Alumno *arrAlumnos, int cantAlumnos, bool es_reporte_final) {
    char nombre_archivo[26];
    ofstream output;
    escoger_nombre_del_archivo(anho_usuario, ciclo_usuario, es_reporte_final, nombre_archivo);
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(es_reporte_final, anho_usuario, ciclo_usuario, output);
    int cantidad_alumnos_matriculados = 0;
    double total_monto_pagado = 0.0;
    imprimir_alumnos_matriculados(arrAlumnos, cantAlumnos, cantidad_alumnos_matriculados,
                                  total_monto_pagado, es_reporte_final, output);
    imprimir_resumen_del_reporte(cantidad_alumnos_matriculados, total_monto_pagado, output);
}







// Módulo que intercambia los datos de estructuras de tipo "Alumno".
void intercambiar_struct_alumno(struct Alumno &alumno_1, struct Alumno &alumno_2) {
    struct Alumno auxiliar;
    auxiliar = alumno_1;
    alumno_1 = alumno_2;
    alumno_2 = auxiliar;
}






// Módulo que ordena ascendentemente por la escala y, en caso de igualdad, de
// forma descendente por el total de créditos matriculados el arreglo de alumnos.
void ordenar_alumnos(struct Alumno *arrAlumnos, int cantAlumnos) {
    for(int i=0; i<cantAlumnos-1; i++) {
        for(int k=i+1; k<cantAlumnos; k++) {
            if(arrAlumnos[i].escAlumno.escala > arrAlumnos[k].escAlumno.escala   or
                   arrAlumnos[i].escAlumno.escala == arrAlumnos[k].escAlumno.escala  and
                        arrAlumnos[i].totalCreditos < arrAlumnos[k].totalCreditos) {
                intercambiar_struct_alumno(arrAlumnos[i],arrAlumnos[k]);
            }
        }
    }
}






// Módulo que intercambia los datos de estructuras de tipo "Curso".
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2) {
    struct Curso auxiliar;
    auxiliar = curso_1;
    curso_1 = curso_2;
    curso_2 = auxiliar;
}






// Módulo que ordena el arreglo de cursos de forma ascendente por el nombre del curso.
void ordenar_cursos(struct Curso *arrCursos, int cantCursos) {
    for(int i=0; i<cantCursos-1; i++) {
        for(int k=i+1; k<cantCursos; k++) {
            if(strcmp(arrCursos[i].nombre, arrCursos[k].nombre) > 0) {
                intercambiar_struct_curso(arrCursos[i], arrCursos[k]);
            }
        }
    }
}







// Módulo que ordenael arreglo de alumnos de forma ascendente por la escala y por
// el total de créditos desendentemente. Luego, para cada alumno se ordena el arreglo
// de cursos por el nombre del curso de forma ascendente.
void ordenar_arreglo_alumnos(struct Alumno *arrAlumnos, int cantAlumnos) {
    ordenar_alumnos(arrAlumnos, cantAlumnos);
    for(int indice = 0; indice < cantAlumnos; indice++) {
        ordenar_cursos(arrAlumnos[indice].cursos, arrAlumnos[indice].cantidadCursos);
    }
}






// Módulo que solicita un año y ciclo al usuario. Se asume que el usuario ingresa los datos correctamente.
void solicitar_anho_y_ciclo_al_usuario(int &anho_usuario, int &ciclo_usuario) {
    cout << "Ingrese un año: ";
    cin >> anho_usuario;
    cout << "Ingrese un ciclo: ";
    cin >> ciclo_usuario;
}






// Módulo que busca un código del alumno mediante el arreglo de estructuras de tipo "Alumnos".
int buscar_alumno(int codAlumno_leido, struct Alumno *arrAlumnos, int cantAlumnos) {
    for(int indice = 0; indice < cantAlumnos; indice++) {
        if(arrAlumnos[indice].codAlumno == codAlumno_leido) return indice;
    }
    return NO_ENCONTRADO;
}






// Módulo que busca una escala de un año y ciclo determinado mediante el arreglo de estructuras de tipo "Escala".
int buscar_escala(int anho_leido, int ciclo_leido, char escalaAlumno, struct Escala *arrEscalas, int cantEscalas) {
    for(int indice = 0; indice < cantEscalas; indice++) {
        if(anho_leido == arrEscalas[indice].anho  and  ciclo_leido == arrEscalas[indice].ciclo
                        and escalaAlumno == arrEscalas[indice].escala) {
            return indice;
        }
    }
    return NO_ENCONTRADO;
}







// Módulo que completa el campo de "escala" de un alumno.
void completar_campo_escala_del_alumno(struct Escala &escala_de_un_alumno, int anho_leido, int ciclo_leido,
                                       struct Escala *arrEscalas, int cantEscalas) {
    int indice_escala;
    
    escala_de_un_alumno.anho = anho_leido;
    escala_de_un_alumno.ciclo = ciclo_leido;
    
    indice_escala = buscar_escala(anho_leido, ciclo_leido, escala_de_un_alumno.escala, arrEscalas, cantEscalas);
    
    if(indice_escala != NO_ENCONTRADO) {
        // SÍ se encontró la escala del alumno en el arreglo de escalas. Por lo tanto,
        // se le asigna el valor del crédito correspondiente al alumno del año y ciclo ingresado por el usuario.
        escala_de_un_alumno.valorCred = arrEscalas[indice_escala].valorCred;
    }
}






// Módulo que busca un curso mediante el arreglo de estructuras de tipo "Curso".
int buscar_curso(int codCurso_leido, struct Curso *arrCursos, int cantCursos) {
    for(int indice = 0; indice < cantCursos; indice++) {
        if(codCurso_leido ==  arrCursos[indice].codCurso) return indice;
    }
    return NO_ENCONTRADO;
}







// Módulo que lee un listado de cursos de un alumno del archivo "Matricula.txt" y
// actualiza los campos de total pagado y total de créditos del alumno como también
// almacena los cursos matriculados en en el arreglo de cursos del alumno.
void leer_cursos_matriculados_de_un_alumno(struct Curso *arrCursosAlumno, int &cantidadCursosAlumno,
                            double &totalCreditos, double &totalPago, double valorCredAlumno,
                            struct Curso *arrCursos,int cantCursos, ifstream &input) {
    int codCurso_leido, indice_curso;
    while(true) {
        codCurso_leido = leer_int(input);
        indice_curso = buscar_curso(codCurso_leido, arrCursos, cantCursos);
        if(indice_curso != NO_ENCONTRADO) {
            // El código de curso leído SÍ existe en el arreglo de estructuras de tipo "Alumno".
            // Por lo tanto, actualizar el total de créditos, el total de pago e ingresar un nuevo
            // curso al alumno.
            arrCursosAlumno[cantidadCursosAlumno].codCurso = arrCursos[indice_curso].codCurso;
            arrCursosAlumno[cantidadCursosAlumno].nombre = asignar_cadena(arrCursos[indice_curso].nombre);
            arrCursosAlumno[cantidadCursosAlumno].creditos = arrCursos[indice_curso].creditos;
            cantidadCursosAlumno++;
            totalCreditos += arrCursos[indice_curso].creditos;
            totalPago += arrCursos[indice_curso].creditos * valorCredAlumno;
        }
        if(input.get() == '\n') break;
    }
}







// Módulo que procesa el archivo "Matricula.txt". Actualiza todos los campos del arreglo de
// estructuras de tipo "Alumno" para cada alumno almacenado en el arreglo.
void procesar_matricula(const char *nombre_archivo, int &anho_usuario, int &ciclo_usuario, struct Curso *arrCursos,
                        int cantCursos, struct Escala *arrEscalas, int cantEscalas, struct Alumno *arrAlumnos,
                        int cantAlumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    solicitar_anho_y_ciclo_al_usuario(anho_usuario, ciclo_usuario);
    int anho_leido, ciclo_leido, codAlumno_leido, indice_alumno;
    while(true) {
        anho_leido = leer_int(input);
        if(input.eof()) break; // Verificar fin del archivo "Matricula.txt".
        input.get(); // Lectura del guion '-'.
        ciclo_leido = leer_int(input);
        if(anho_leido == anho_usuario  and  ciclo_leido == ciclo_usuario) {
            // El año y ciclo leído coinciden con el año y ciclo ingresado por el usuario.
            codAlumno_leido = leer_int(input);
            indice_alumno = buscar_alumno(codAlumno_leido, arrAlumnos, cantAlumnos);
            if(indice_alumno != NO_ENCONTRADO) {
                // El código de alumno leído SÍ existe en el arreglo de estructuras de tipo "Alumno".
                completar_campo_escala_del_alumno(arrAlumnos[indice_alumno].escAlumno, anho_leido, ciclo_leido, arrEscalas, cantEscalas);
                leer_cursos_matriculados_de_un_alumno(arrAlumnos[indice_alumno].cursos, arrAlumnos[indice_alumno].cantidadCursos,
                                arrAlumnos[indice_alumno].totalCreditos, arrAlumnos[indice_alumno].totalPago,
                                arrAlumnos[indice_alumno].escAlumno.valorCred, arrCursos, cantCursos, input);
            } else {
                while(input.get() != '\n'); // Descartar línea.
            }
        } else {
            while(input.get() != '\n'); // Descartar línea.
        }
    }
}







// Módulo que pasa las letras de una cadena de caracteres a mayúsculas.
void todo_a_mayuscula(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'  and  cadena[indice] <= 'z') {
//            cadena[indice] -= ('a' - 'A');
            cadena[indice] -= 32;
        }
    }
}






// Módulo que lee un alumno del archivo "Alumnos.csv" y asigna memoria para el campo de "cursos".
void leer_un_alumno(struct Alumno &un_alumno, ifstream &input) {
    int codigo_del_alumno;
    codigo_del_alumno = leer_int(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    input.get(); // Lectura de la coma.
    un_alumno.codAlumno = codigo_del_alumno;
    un_alumno.nombre = leer_cadena(input, ',');
    todo_a_mayuscula(un_alumno.nombre);
    un_alumno.escAlumno.escala = leer_char(input);
    
    // Reservar memoria y asignar los campos de la estructura "Curso" con valores por defecto.
    un_alumno.cursos = new struct Curso[MAX_CURSOS_POR_ALUMNO]{};
}








// Módulo que procesa el archivo "Alumnos.csv" y almacena la información leída
// en un arreglo de estructuras de tipo "Alumno".
void procesar_alumnos(const char *nombre_archivo, struct Alumno *arrAlumnos, int &cantAlumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantAlumnos = 0;
    while(true) {
        leer_un_alumno(arrAlumnos[cantAlumnos], input);
        if(input.eof()) break; // Verificar fin del archivo "Alumnos.csv".
        cantAlumnos++;
    }
}







// Módulo que imprime el título y el encabezado del reporte de prueba de escalas.
void imprimir_titulo_y_encabezado_del_reporte_prueba_escalas(ofstream &output) {
    elaborar_lineas('=', 46, output);
    output << setw(34) << "VERIFICACION DE ESCALAS" << endl;
    elaborar_lineas('=', 46, output);
    output << left << setw(5) << "No." << setw(12) << "SEMESTRE";
    output << setw(11) << "ESCALA" << right << "VALOR DEL CREDITO" << endl;
    elaborar_lineas('-', 46, output);
}









// Módulo que emite un reporte de prueba del arreglo de escalas para verificar la correcta asignación de las escalas.
void verificar_asignacion_de_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int cantEscalas) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    
    imprimir_titulo_y_encabezado_del_reporte_prueba_escalas(output);
    
    for(int indice = 0; indice < cantEscalas; indice++) {
        output << setw(2) << indice + 1 << ')' << setw(7) << arrEscalas[indice].anho << '-';
        output << arrEscalas[indice].ciclo << setw(8) << arrEscalas[indice].escala;
        output << setw(18) << arrEscalas[indice].valorCred << endl;
    }
    elaborar_lineas('=', 46, output);
}








// Módulo que lee una escala del archivo "Escala.csv".
void leer_una_escala(struct Escala &una_escala, ifstream &input) {
    int anio;
    anio = leer_int(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    input.get();  // Lectura del guion '-'.
    una_escala.anho = anio;
    una_escala.ciclo = leer_int(input);
    input.get();  // Lectura de la coma.
    una_escala.escala = leer_char(input);
    una_escala.valorCred = leer_double(input);
}








// Módulo que procesa el archivo "Escalas.csv" y almacena la información leída
// en un arreglo de estructuras de tipo "Escala".
void procesarEscalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cantEscalas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantEscalas = 0;
    while(true) {
        leer_una_escala(arrEscalas[cantEscalas], input);
        if(input.eof()) break; // Verificar fin del archivo "Escalas.csv".
        cantEscalas++;
    }
}







// Módulo que imprime el título y el encabezado del reporte de prueba de cursos.
void imprimir_titulo_y_encabezado_del_reporte_prueba_curso(ofstream &output) {
    elaborar_lineas('=', 75, output);
    output << setw(48) << "VERIFICACION DE CURSOS" << endl;
    elaborar_lineas('=', 75, output);
    output << left << setw(5) << "No." << setw(9) << "CODIGO";
    output << setw(52) << "NOMBRE DEL CURSO" << right << "CREDITOS" << endl;
    elaborar_lineas('-', 75, output);
}








// Módulo que emite un reporte de prueba del arreglo de cursos para verificar la correcta asignación de los cursos.
void verificar_asignacion_de_cursos(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    
    imprimir_titulo_y_encabezado_del_reporte_prueba_curso(output);
    
    for(int indice = 0; indice < cantCursos; indice++) {
        output << setw(2) << indice + 1 << ')' << setw(8) << arrCursos[indice].codCurso;
        output << setw(3) << ' ' << left << setw(54) << arrCursos[indice].nombre;
        output << right << arrCursos[indice].creditos << endl;
    }
    elaborar_lineas('=', 75, output);
}








// Módulo que lee un curso del archivo "Cursos.csv".
void leer_un_curso(struct Curso &un_curso, ifstream &input) {
    int codigo_del_curso;
    codigo_del_curso = leer_int(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    input.get(); // Leer una coma.
    un_curso.codCurso = codigo_del_curso;
    un_curso.nombre = leer_cadena(input, ',');
    un_curso.creditos = leer_double(input);
}








// Módulo que procesa el archivo "Cursos.csv" y almacena la información leída
// en un arreglo de estructuras de tipo "Curso".
void procesarCursos(const char *nombre_archivo, struct Curso *arrCursos, int &cantCursos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantCursos = 0;
    while(true) {
        leer_un_curso(arrCursos[cantCursos], input);
        if(input.eof()) break; // Validar fin del archivo "Cursos.csv".
        cantCursos++;
    }
}


