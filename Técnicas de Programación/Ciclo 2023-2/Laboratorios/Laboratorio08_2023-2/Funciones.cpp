

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 16 de junio del 2025, 10:51 AM
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




// Módulo que lee un dato de tipo "double"
double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo "char"
char leer_dato_char(ifstream &input) {
    char dato;
    input >> dato;
    return dato;
}




// Módulo que lee un semestre de tipo "AAAA-C" y
// lo retorna como un valor entero.
int leer_semestre(ifstream &input) {
    int anio, ciclo;
    char guion;
    
    anio = leer_dato_int(input);
    guion = leer_dato_char(input);
    ciclo = leer_dato_int(input);
    
    return anio*10 + ciclo;
}





// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output) {
    for(int i=0; i<cantidad_caracteres; i++)  output.put(caracter);
    output << endl;
}






// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(int semestre, ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "DETALLES DE PAGOS REALIZADO POR CICLO" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2  - 5);
    output << "CICLO: " << semestre / 10 << '-' << semestre % 10;
    output << endl;
}







// Módulo que imprime el encabezado del reporte solicitado
void imprimir_encabezado(ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 2) << "No.";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) + 7) << "CURSO";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 1) << "CREDITOS";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 5) << "ALUMNOS MAT.";
    output << right << "MONTO PAGADO" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}








// Módulo que imprime los datos de un curso.
void imprimir_datos_de_un_curso(int n_curso, int cod_curso,
                                char *nombre_curso, double numeroDeCreditos,
                                int cantidadDeAlumnosMatriculados,
                                double montoPagadoDeAlumnosMatriculados, ofstream &output) {
    output << setfill('0') << setw(2) << n_curso << setfill(' ') << ')';
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 4) << cod_curso << " - ";
    output << left << setw(TAM_REPORTE / (N_COLUMNAS - 3) + 5) << nombre_curso;
    output << right << setw(TAM_REPORTE / (N_COLUMNAS + 7) - 6) << numeroDeCreditos;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 7) + 4) << cantidadDeAlumnosMatriculados;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 1)) << montoPagadoDeAlumnosMatriculados;
    output << endl;
}








// Módulo que imprime todos los elementos del arreglo de estructura de tipo "Curso".
void imprimir_todos_los_cursos(struct Curso *arrCursos, int cant_cursos,
                               double &monto_total_pagado, ofstream &output) {
    for(int indice = 0; indice < cant_cursos; indice++) {
        imprimir_datos_de_un_curso(indice + 1, arrCursos[indice].codigo,
                         arrCursos[indice].nombre, arrCursos[indice].numeroDeCreditos,
                         arrCursos[indice].cantidadDeAlumnosMatriculados,
                         arrCursos[indice].montoPagadoDeAlumnosMatriculados,
                         output);
        monto_total_pagado += arrCursos[indice].montoPagadoDeAlumnosMatriculados;
    }
}









// Módulo que imprime el resumen del reporte solicitado (este es el monto
// total pagado de los alumnos rspecto al ciclo ingresado por el usuario).
void imprimir_monto_total_pagado(double monto_total_pagado, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "MONTO TOTAL PAGADO:";
    output << setw(3 * (TAM_REPORTE / (N_COLUMNAS - 1)) + 8);
    output << monto_total_pagado;
    output << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}








// Módulo que emite el reporte solicitado mediante el semestre ingresado por el usuario.
void emitir_reporte(const char *nombre_archivo, struct Curso *arrCursos,
                    int cant_cursos, int semestre_ingresado) {
    double monto_total_pagado = 0.0;
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(semestre_ingresado, output);
    imprimir_encabezado(output);
    imprimir_todos_los_cursos(arrCursos, cant_cursos, monto_total_pagado, output);
    imprimir_monto_total_pagado(monto_total_pagado, output);
}








//  Módulo que intercambia datos de tipo "struct Curso".
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2) {
    struct Curso aux;
    aux = curso_1;
    curso_1 = curso_2;
    curso_2 = aux;
}







// Módulo que ordena el arreglo de estructura de tipo "Curso" de forma
// ascendente por la cantidad de alumnos matriculados y, en caso de igualdad,
// de forma descendente por el nombre del curso.
void ordenar_arreglo_cursos(struct Curso *arrCursos, int cant_cursos) {
    for(int i=0; i<cant_cursos - 1; i++) {
        for(int k=i+1; k<cant_cursos; k++) {
            if(arrCursos[i].cantidadDeAlumnosMatriculados > arrCursos[k].cantidadDeAlumnosMatriculados
                    or arrCursos[i].cantidadDeAlumnosMatriculados == arrCursos[k].cantidadDeAlumnosMatriculados
                        and strcmp(arrCursos[i].nombre, arrCursos[k].nombre) < 0) {
                intercambiar_struct_curso(arrCursos[i], arrCursos[k]);
            }
        }
    }
}








// Módulo que busca la escala del alumno en el arreglo de estructura tipo "Escala".
int buscar_escala(char escala_alumno, struct Escala *arrEscalas, int cant_escalas) {
    // Recorre el arreglo de escalas.
    for(int indice = 0; indice < cant_escalas; indice++) {
        if(arrEscalas[indice].escala == escala_alumno) {
            // Se encuentró una escala que coincide con la del alumno.
            return indice; // Retornar el índice de la escala encontrada.
        }
    }
    return NO_ENCONTRADO; // No se encontró la esacala
}









// Módulo que busca el costo por crédito de una escala mediante la búsqueda
// del índice a encontrar en el arreglo de alumnos y de escalas.
int buscar_costo_por_credito(int codigo_alumno_leido, struct Alumno *arrAlumnos,
                             int cant_alumnos, struct Escala *arrEscalas,
                             int cant_escalas) {
    
    // Iterar sobre todos los alumnos para buscar el alumno con el código leído.
    for(int indice_alumno = 0; indice_alumno < cant_alumnos; indice_alumno++) {
        if(arrAlumnos[indice_alumno].codigo == codigo_alumno_leido) {
            
            // Se encontró al alumno, entonces se obtiene su escala de pago.
            int escala_alumno = arrAlumnos[indice_alumno].escalaDePago;
            
            
            
            // Buscar el índice de la escala del alumno correspondiente en el arreglo de escalas.
            int indice_escala = buscar_escala(escala_alumno, arrEscalas, cant_escalas);
            
            if(indice_escala != NO_ENCONTRADO) return indice_escala; // Si se encontró la escala, retornar el índice.
            else  break; // No se encontró la escala, entonces salir del bucle (no es necesario seguir buscando alumnos).
        }
    }
    return NO_ENCONTRADO; // No se encontró al alumno o su escala.
}









// Módulo que asigna el costo por crédito de una escala mediante el arreglo
// de alumnos mediante su escala de pago y el arreglo de escalas para saber
// el costo por crédito de esa escala.
double asignar_costo_por_credito(int codigo_alumno_leido, struct Alumno *arrAlumnos,
                                 int cant_alumnos, struct Escala *arrEscalas,
                                 int cant_escalas) {
    int indice_escala;
    
    // Busca el índice de la escala correspondiente al alumno
    indice_escala = buscar_costo_por_credito(codigo_alumno_leido, arrAlumnos,
                                             cant_alumnos, arrEscalas, cant_escalas);
    if(indice_escala != NO_ENCONTRADO) {
        // Se encontró una escala válida, entonces retornar el costo por crédito correspondiente
        return arrEscalas[indice_escala].costoPorCredito;
    } else {
        // No se encontró, entonces se retorna 0.0 como valor por defecto
        return 0.0;
    }
}







// Módulo que busca un curso mediante el arreglo de cursos.
int buscar_curso(int codigo_curso_buscado, struct Curso *arrCursos, int cant_cursos) {
    
    // Recorrer el arreglo de cursos.
    for(int indice = 0; indice < cant_cursos; indice++) {
        
        // Comparar el código del curso actual con el código buscado.
        if(arrCursos[indice].codigo == codigo_curso_buscado) {
            return indice; // Se encuentró el curso, entonces retornar su índice.
        };
    }
    return NO_ENCONTRADO; // No se encontró el curso en el arreglo de cursos.
}









// Módulo que procesa una lista de cursos del archivo "Matricula.csv" y
// actualiza la información de la cantidad de alumnos matriculados y del
// monto pagado de los alumnos matriculados de cada curso que se lee.
void procesar_lista_de_cursos(struct Curso *arrCursos, int cant_cursos,
                             double costo_por_credito, ifstream &input) {
    int codigo_curso_leido, indice_curso;
    while(true) {
        codigo_curso_leido = leer_dato_int(input);
        
        // Buscar el índice del curso en el arreglo de cursos.
        indice_curso = buscar_curso(codigo_curso_leido, arrCursos, cant_cursos);
        
        if(indice_curso != NO_ENCONTRADO) {
            // El curso fue encontrado, entonces actualizar su información:
            
            // Aumentar la cantidad de alumnos matriculados.
            arrCursos[indice_curso].cantidadDeAlumnosMatriculados++;
            
            // Acumular monto total pagado por los alumnos en dicho curso.
            arrCursos[indice_curso].montoPagadoDeAlumnosMatriculados += 
                                costo_por_credito*arrCursos[indice_curso].numeroDeCreditos;
        }
        
        // Verificar si se ha llegado al fin de línea (fin de la lista de cursos).
        if(input.get() == '\n') break;
    }
}









// Módulo que lee el archivo "Matricula.csv" y que completa la información faltante
// de los campos de curso para cada elemento del arreglo de estructura de tipo "Curso".
void leer_matricula(const char *nombre_archivo, struct Curso *arrCursos,
                    int cant_cursos, struct Alumno *arrAlumnos, int cant_alumnos,
                    struct Escala *arrEscalas, int cant_escalas, int semestre_ingresado) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int semestre_leido, codigo_alumno_leido;
    while(true) {
        semestre_leido = leer_semestre(input);
        if(input.eof()) break; // Validar fin del archivo "Matricula.csv"
        input.get(); // Lectura de la coma
        codigo_alumno_leido = leer_dato_int(input);
        input.get(); // Lectura de la coma
        
        if(semestre_leido == semestre_ingresado) {
            // El semestre leído SÍ coincide con el semestre ingresado por el usuario.
            
            // Calcular el costo por crédito para este alumno.
            double costo_por_credito = asignar_costo_por_credito(codigo_alumno_leido,
                                                     arrAlumnos, cant_alumnos, arrEscalas,
                                                     cant_escalas);
            
            // Procesar la lista de cursos de este alumno.
            procesar_lista_de_cursos(arrCursos, cant_cursos, costo_por_credito, input);
        } else {
            // El semestre leído NO coincide con el semestre ingresado por el usuario.
            while(input.get() != '\n'); // Descartar lista de cursos
        }
    }
}









// Módulo que lee la información de un escala del archivo "Escala.csv" y
// lo almacena en un dato de estructura de tipo "Escala".
void leer_una_escala(struct Escala &una_escala, ifstream &input) {
    int semestre;
    semestre = leer_semestre(input);
    if(input.eof()) return;
    input.get(); // Lectura de la coma
    una_escala.semestre = semestre;
    una_escala.escala = leer_dato_char(input);
    input.get(); // Lectura de la coma
    una_escala.costoPorCredito = leer_dato_double(input);
}









// Módulo que lee el archivo "Escalas.csv" y almacena la información
// que se lee en un arreglo de estrcutura de tipo "Escala".
void leer_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cant_escalas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cant_escalas = 0;
    while(true) {
        leer_una_escala(arrEscalas[cant_escalas], input);
        if(input.eof()) break; // Validar fin del archivo "Escalas.csv"
        cant_escalas++;
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






// Módulo que lee la información de un curso del archivo "Cursos.csv" y
// lo almacena en un dato de estructura de tipo "Curso".
void leer_un_curso(struct Curso &un_curso, ifstream &input) {
    int codigo_del_curso;
    codigo_del_curso = leer_dato_int(input);
    if(input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma
    un_curso.codigo = codigo_del_curso;
    input.getline(un_curso.nombre, MAX_CARACTERES_NOMBRE_CURSO, ',');
    pasar_todo_a_mayusculas(un_curso.nombre);
    un_curso.numeroDeCreditos = leer_dato_double(input);
    
    // Inicializar los campos restantes del curso
    un_curso.cantidadDeAlumnosMatriculados = 0;
    un_curso.montoPagadoDeAlumnosMatriculados = 0.0;
}









// Módulo que lee el archivo "Cursos.csv" y almacena la información
// que se lee en un arreglo de estrcutura de tipo "Curso".
void leer_cursos(const char *nombre_archivo, struct Curso *arrCursos, int &cant_cursos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cant_cursos = 0;
    while(true) {
        leer_un_curso(arrCursos[cant_cursos], input);
        if(input.eof()) break; // Validar fin del archivo "Alumnos.csv"
        cant_cursos++;
    }
}










// Módulo que lee la información de un alumno del archivo "Alumnos.csv" y
// lo almacena en un dato de estructura de tipo "Alumno".
void leer_un_alumno(struct Alumno &un_alumno, ifstream &input) {
    int codigo_del_alumno;
    codigo_del_alumno = leer_dato_int(input);
    if(input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma
    un_alumno.codigo = codigo_del_alumno;
    input.getline(un_alumno.nombre, MAX_CARACTERES_NOMBRE_ALUMNO, ',');
    un_alumno.escalaDePago = leer_dato_char(input);
}









// Módulo que lee el archivo "Alumnos.csv" y almacena la información
// que se lee en un arreglo de estrcutura de tipo "Alumno".
void leer_alumnos(const char *nombre_archivo, struct Alumno *arrAlumnos, int &cant_alumnos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cant_alumnos = 0;
    while(true) {
        leer_un_alumno(arrAlumnos[cant_alumnos], input);
        if(input.eof()) break; // Validar fin del archivo "Alumnos.csv"
        cant_alumnos++;
    }
}







// Módulo que solicita un semestre al usuario y lo retorna como un valor entero.
int solicitar_semestre() {
    int anio, ciclo;
    char guion;
    cout << "Ingrese un semestre (por ejemplo: 2022-1): ";
    cin >> anio >> guion >> ciclo;
    return anio*10 + ciclo;
}




