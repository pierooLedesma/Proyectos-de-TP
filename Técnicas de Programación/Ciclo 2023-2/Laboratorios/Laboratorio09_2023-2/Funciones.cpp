

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de junio del 2025, 01:28 PM
 */


#include "Funciones.h"


// Módulo que lee un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que lee un archivo de escritura sin usar el constructor
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
    input.get(); // Lectura de la coma
    return dato;
}



// Módulo que asigna una cadena con memoria exacta
char* asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}



// Módulo que lee una cadena de caracteres y lo almacena con memoria exacta.
char* leer_cadena(ifstream &input, char delimitador) {
    char buffer[100], *cadena;
    input.getline(buffer, 100, delimitador);
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}




// Módulo que lee un semestre de la forma AAAA-C y
// lo retorna como un valor entero
int leer_semestre(ifstream &input) {
    int anio, ciclo;
    
    anio = leer_dato_int(input);
    input.get(); // Lectura del guion
    ciclo = leer_dato_int(input);
    
    return anio*10 + ciclo;
}






// Módulo que elabora las líneas del reporte solicitado
void elaborar_lineas(char caracter, int cantidad_de_caracteres, ofstream &output) {
    for(int i=0; i<cantidad_de_caracteres; i++)  output.put(caracter);
    output << endl;
}






// Módulo que imprime el título del reporte solicitado.
void imprimir_titulo(int semestre_ingresado, ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "INSTITUCION EDUCATIVA_TP" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "DETALLE DE PAGO REALIZADO POR CICLO" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_3) / 2  - 3);
    output << "CICLO: " << semestre_ingresado / 10 << '-' << semestre_ingresado %10 << endl;
}







// Módulo que imprime los encabezados del reporte solicitado.
void imprimir_encabezado(bool es_de_curso, ofstream &output) {
    if(es_de_curso) {
        elaborar_lineas('=', TAM_REPORTE, output);
        output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5)) << "No.";
        output << setw(5 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 8) << "CURSO" << right;
        output << "CREDITOS" << endl;
        elaborar_lineas('-', TAM_REPORTE, output);
    } else {
        output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 6) << "ALUMNOS MATRICULADOS" << endl;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1) << "No.";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 3) << "ALUMNO";
        output << setw(4 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 3) << "ESCALA";
        output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 5)) - 1) << "PAGO POR CREDITO";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 6) << "TOTAL A PAGAR" << endl;
    }
}





// Módulo que imprime los datos de un curso.
void imprimir_datos_de_un_curso(int n_curso, int codigo, char *nombre_curso,
                                                           double numeroDeCreditos, ofstream &output) {
    output << setfill('0') << setw(2) << n_curso << ')' << setfill(' ');
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1) << codigo << " - ";
    output << left << setw(5 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 5) << nombre_curso;
    output << right << numeroDeCreditos << endl;
}







// Módulo que imprime todos los datos almacenados en el arreglo de estructuras de tipo "Alumno".
void imprimir_alumnos(struct Alumno *arrAlumnos, int cantAlumnos, double numCreditos, ofstream &output) {
    for(int indice = 0; indice < cantAlumnos; indice++) {
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 4) << ' ';
        output << setfill('0') << setw(2) << indice + 1 << ')' << setfill(' ');
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1) << arrAlumnos[indice].codigo;
        output << setw((TAM_REPORTE / (N_COLUMNAS + 5)) / 2  -  3) << ' ';
        output << left << setw(4 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 2) << arrAlumnos[indice].nombre;
        output << right << arrAlumnos[indice].escala;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 6) << arrAlumnos[indice].pagoPorCredito;
        output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 5)) - 2);
        output << arrAlumnos[indice].pagoPorCredito * numCreditos << endl;
    }
}








// Módulo que imprime los datos que existen en el arreglo de estructuras de tipo "Curso":
void imprimir_cursos(struct Curso *arrCursos, int cantCursos, 
                     double &monto_total_por_ingresos_de_matricula, ofstream &output) {
    for(int indice = 0; indice < cantCursos; indice++) {
        imprimir_encabezado(true, output);
        imprimir_datos_de_un_curso(indice+1, arrCursos[indice].codigo, arrCursos[indice].nombre,
                                   arrCursos[indice].numeroDeCreditos, output);
        imprimir_encabezado(false, output);
        imprimir_alumnos(arrCursos[indice].listaDeAlumnosMatriculados, arrCursos[indice].cantAlumnosMatriculados,
                         arrCursos[indice].numeroDeCreditos, output);
        output << "TOTAL DE INGRESOS POR MATRICULA: " << arrCursos[indice].totalDeIngresos << endl;
        monto_total_por_ingresos_de_matricula += arrCursos[indice].totalDeIngresos;
    }
}







// Módulo que imprime el total de ingresos de matrícula.
void imprimir_total_ingresos(double monto_total_por_ingresos_de_matricula, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "MONTO TOTAL POR INGRESOS DE MATRICULA:";
    output << setw(TAM_REPORTE / N_COLUMNAS) << monto_total_por_ingresos_de_matricula;
    output << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}







// Módulo que emite el reporte solicitado mediante el semestre ingresado por el usuario.
void emitir_reporte(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos, int semestre_ingresado) {
    double monto_total_por_ingresos_de_matricula = 0.0;
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(semestre_ingresado, output);
    imprimir_cursos(arrCursos, cantCursos, monto_total_por_ingresos_de_matricula, output);
    imprimir_total_ingresos(monto_total_por_ingresos_de_matricula, output);
}








// Intercambia dos estructuras de tipo "Curso" usando una variable auxiliar.
void intercambiar_struct_curso(struct Curso &curso_1, struct Curso &curso_2) {
    struct Curso aux;
    aux = curso_1;
    curso_1 = curso_2;
    curso_2 = aux;
}








// Ordena el arreglo de cursos de forma ascendente por el código del curso.
void ordenar_cursos(struct Curso *arrCursos, int cantCursos) {
    for(int i = 0;   i < cantCursos - 1;   i++) {
        for(int k = i + 1;   k < cantCursos;   k++) {
            
            // Si el curso en la posición "i" tiene un código mayor que el de "k", entonces se intercambian.
            if(arrCursos[i].codigo > arrCursos[k].codigo) {
                intercambiar_struct_curso(arrCursos[i], arrCursos[k]);
            }
        }
    }
}







// Intercambia dos estructuras de tipo "Alumno" usando una variable auxiliar
void intercambiar_struct_alumno(struct Alumno &alumno_1, struct Alumno &alumno_2) {
    struct Alumno aux;
    aux = alumno_1;
    alumno_1 = alumno_2;
    alumno_2 = aux;
}







// Ordena un arreglo de alumnos de forma ascendente por el código del alumno.
void ordenar_alumnos_de_un_curso(struct Alumno *arrAlumnos, int cantAlumnos) {
    for(int a = 0;   a < cantAlumnos - 1;   a++) {
        for(int b = a + 1;   b < cantAlumnos;   b++) {
            
            // Si el alumno en la posición  "a"  tiene el código mayor que el de  "b", entonces se intercambian.
            if(arrAlumnos[a].codigo < arrAlumnos[b].codigo) {
                intercambiar_struct_alumno(arrAlumnos[a], arrAlumnos[b]);
            }
        }
    }
}








// Ordena las listas de alumnos de cada curso dentro del arreglo de cursos.
void ordenar_listas_de_alumnos(struct Curso *arrCursos, int cantCursos) {
    for(int indice_curso = 0; indice_curso < cantCursos; indice_curso++) {
        ordenar_alumnos_de_un_curso(arrCursos[indice_curso].listaDeAlumnosMatriculados,
                                    arrCursos[indice_curso].cantAlumnosMatriculados);
    }
}







// Ordena, primero, el arreglo de cursos y, luego, las listas de alumnos dentro de cada curso
void ordenar_arreglo_de_cursos_y_listas_de_alumnos(struct Curso *arrCursos, int cantCursos) {
    ordenar_cursos(arrCursos, cantCursos);             // Ordena los cursos por código de curso.
    ordenar_listas_de_alumnos(arrCursos, cantCursos);  // Ordena los alumnos en cada curso por código de alumno.
}









// Módulo que calcula y completa el campo "totalDeIngresos"  para cada curso del arreglo "arrCursos".
// El ingreso total de un curso se obtiene multiplicando el número de créditos del curso
// por el pago por crédito de cada alumno matriculado, y acumulando estos valores.
void completar_el_ingreso_total_por_curso(struct Curso *arrCursos, int cantCursos) {
    
    // Recorre cada curso en el arreglo.
    for(int indice_curso = 0; indice_curso < cantCursos; indice_curso++) {
        int cantAlumnos = arrCursos[indice_curso].cantAlumnosMatriculados;
        
        // Recorrer todos los alumnos matriculados en el curso actual.
        for(int indice_alumno = 0; indice_alumno < cantAlumnos; indice_alumno++) {
            
            // Sumar al total de ingresos el resultado de multiplicar el número de créditos
            // del curso por el pago por crédito del alumno.
            arrCursos[indice_curso].totalDeIngresos += arrCursos[indice_curso].numeroDeCreditos *
                                                       arrCursos[indice_curso].listaDeAlumnosMatriculados[indice_alumno].pagoPorCredito;
        }
    }
}







// Módulo que lee los datos de un alumno del archivo "Alumnos.csv"
void leer_un_alumno(int &codigo_alumno_leido, char *&nombre_alumno,
                    char &escala_alumno, ifstream &input) {
    codigo_alumno_leido = leer_dato_int(input);
    if(input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma
    nombre_alumno = leer_cadena(input, ',');
    escala_alumno = leer_dato_char(input);
}







// Módulo que busca una escala en el arreglo "arrEscalas". Compara tanto el carácter de escala como el semestre.
int buscar_escala(char escala_alumno, int semestre_ingresado, struct Escala *arrEscalas, int cantEscalas) {
    for(int indice = 0; indice < cantEscalas; indice++) {
        if(arrEscalas[indice].escala == escala_alumno  and  arrEscalas[indice].semestre == semestre_ingresado){
            return indice;
        }
    }
    return NO_ENCONTRADO;
}








// Módulo que completa los campos restantes de un alumno: copia el nombre en un nuevo espacio de memoria,
// asigna la escala y determina el pago por crédito según la escala.
void completar_campos_restantes_del_alumno(struct Alumno &un_alumno, char *nombre_alumno,
                                           char escala_alumno, struct Escala *arrEscalas, int cantEscalas,
                                           int semestre_ingresado) {
    int indice_escala;
    un_alumno.nombre = asignar_cadena(nombre_alumno);  // Copiar el nombre en un nuevo espacio de memoria.
    un_alumno.escala = escala_alumno;                                 // Asignar la escala.
    
    // Buscar el índice de la escala para determinar el pago por crédito.
    indice_escala = buscar_escala(escala_alumno, semestre_ingresado, arrEscalas, cantEscalas);
    
    if(indice_escala != NO_ENCONTRADO) {
        un_alumno.pagoPorCredito = arrEscalas[indice_escala].costoPorCredito;
    } else {
        un_alumno.pagoPorCredito = 0.0; // No se encuentró, entonces se deja el pago por crédito en cero.
    }
}










// Módulo que recorre el arreglo de alumnos matriculados en un curso y si encuentra uno cuyo código
// coincide con el leído del archivo, entonces se completa sus campos restantes.
void recorrer_el_arreglo_alumnos_matriculados(struct Alumno *arrAlumnos, int cantAlumnos,
                                              int codigo_alumno_leido, char escala_alumno, int semestre_ingresado,
                                              struct Escala *arrEscalas, int cantEscalas, char *nombre_alumno) {
    for(int indice_alumno = 0; indice_alumno < cantAlumnos; indice_alumno++) {
        if(arrAlumnos[indice_alumno].codigo == codigo_alumno_leido) {
            completar_campos_restantes_del_alumno(arrAlumnos[indice_alumno], nombre_alumno,
                                                  escala_alumno, arrEscalas, cantEscalas, semestre_ingresado);
        }
    }
}









// Módulo que recorre todos los cursos y, en cada uno, actualiza los datos del alumno si está matriculado allí.
void insertar_alumno_en_cada_curso(int codigo_alumno_leido, char *nombre_alumno, char escala_alumno,
                                   struct Curso *arrCursos, int cantCursos, struct Escala *arrEscalas,
                                   int cantEscalas, int semestre_ingresado) {
    for(int indice_curso = 0; indice_curso < cantCursos; indice_curso++) {
        recorrer_el_arreglo_alumnos_matriculados(arrCursos[indice_curso].listaDeAlumnosMatriculados,
                                                 arrCursos[indice_curso].cantAlumnosMatriculados, codigo_alumno_leido,
                                                 escala_alumno, semestre_ingresado, arrEscalas, cantEscalas, nombre_alumno);
    }
}








// Módulo que procesa el archivo "Alumnos.csv". Por cada alumno leído, se busca en todos
// los cursos en los que esté matriculado y se completan sus datos..
void completar_el_pago_por_credito_de_cada_alumno(const char *nombre_archivo, struct Curso *arrCursos,
                          int cantCursos, struct Escala *arrEscalas, int cantEscalas, int semestre_ingresado) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int codigo_alumno_leido;
    char escala_alumno, *nombre_alumno;
    while(true){
        leer_un_alumno(codigo_alumno_leido, nombre_alumno, escala_alumno, input);
        if(input.eof()) break; // Validar fin del archivo "Alumnos.csv"
        insertar_alumno_en_cada_curso(codigo_alumno_leido, nombre_alumno, escala_alumno,
                                      arrCursos, cantCursos, arrEscalas, cantEscalas, semestre_ingresado);
    }
}








// Módulo que busca un curso en el arreglo "arrCursos" dado su código de curso.
int buscar_curso(int codigo_curso, struct Curso *arrCursos, int cantCursos) {
    
    for(int indice = 0; indice < cantCursos; indice++) {
    
        // Comparar el código del curso actual con el código buscado.
        if(arrCursos[indice].codigo == codigo_curso) {
            return indice;  // Se encuentró el curso, entonces se retorna el índice del curso.
        }
    }
    return NO_ENCONTRADO;  // No se encontró el curso.
}







// Módulo que busca a un alumno en un arreglo de estructuras de tipo "Alumno"
bool buscar_alumno(int codigo_alumno, int cantAlumnos, struct Alumno *arrAlumnos) {
    for(int indice = 0; indice < cantAlumnos; indice++) {
        if(arrAlumnos[indice].codigo == codigo_alumno) return true;
    }
    return false;
}








// Módulo que procesa una lista de cursos del archivo "Matricula.csv".
void procesar_lista_de_cursos(int codigo_alumno, struct Curso *arrCursos, int cantCursos, ifstream &input) {
    int codigo_curso, indice_curso, ind_alumnos_matriculados;
    while(true) {
        // Lee un código de curso.
        codigo_curso = leer_dato_int(input);
        
        // Buscar el curso en el arreglo de cursos.
        indice_curso = buscar_curso(codigo_curso, arrCursos, cantCursos);
        
        if(indice_curso != NO_ENCONTRADO) {
            
            // Buscar si existe el alumno en el arreglo de estructuras de tipo "Alumno"  llamado  "listaDeAlumnosMatriculados".
            bool existe_alumno = buscar_alumno(codigo_alumno, arrCursos[indice_curso].cantAlumnosMatriculados,
                                               arrCursos[indice_curso].listaDeAlumnosMatriculados);
            
            if(not existe_alumno) {
                // Es un nuevo alumno en el arreglo "listaDeAlumnosMatriculados".
                int cantAlumnos = arrCursos[indice_curso].cantAlumnosMatriculados;
                arrCursos[indice_curso].listaDeAlumnosMatriculados[cantAlumnos].codigo = codigo_alumno;
                arrCursos[indice_curso].cantAlumnosMatriculados++;
            }
        }
        
        // Verificar si se ha llegado al fin de la línea (fin de la lista de cursos para este alumno).
        if(input.get() == '\n') break;
    }
}









// Módulo que lee el archivo "Matricula.csv". Se almacenan los códigos de alumnos
// para cada curso en el arreglo de estructuras de tipo "Curso" en el semestre ingresado por el usuario..
void leer_matricula(const char *nombre_archivo, struct Curso *arrCursos, int cantCursos, int semestre_ingresado) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int semestre_leido, codigo_alumno;
    while(true) {
        semestre_leido = leer_semestre(input);
        if(input.eof()) break; // Validar fin del archivo "Matricula.csv"
        input.get(); // Lectura de la coma
        codigo_alumno = leer_dato_int(input);
        input.get(); // Lectura de la coma
        if(semestre_leido == semestre_ingresado) {
            procesar_lista_de_cursos(codigo_alumno, arrCursos, cantCursos, input);
        } else {
            while(input.get() != '\n'); // Descartar lista de cursos
        }
    }
}









// Módulo que pasa todas las letras de una cadena de caracteres a mayúsculas.
void pasar_todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'   and   cadena[indice] <= 'z') {
            // cadena[indice] = cadena[indice] - ('a' - 'A')
            cadena[indice] -= 32;  // 32 es igual al codigo ASCCI de la diferencia de ('a' - 'A')
        }
    }
}







// Módulo que lee una escala del archivo "Cursos.csv" y lo almacena en un dato de estructura de tipo
// "Curso". Asímismo, inicializa los campos restantes con valores por defecto.
void leer_un_curso(struct Curso &un_curso, ifstream &input) {
    int codigo_curso;
    codigo_curso = leer_dato_int(input);
    if(input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma.
    un_curso.codigo = codigo_curso;
    un_curso.nombre = leer_cadena(input, ',');
    pasar_todo_a_mayusculas(un_curso.nombre);
    un_curso.numeroDeCreditos = leer_dato_double(input);
    
    // Inicializar campos restantes del dato de estructura "Curso" con valores por defecto.
    un_curso.listaDeAlumnosMatriculados = new struct Alumno[MAX_CANT_ALUMNOS];
    un_curso.cantAlumnosMatriculados = 0; // Inicializar en cero la cantidad de alumnos matriculados.
    un_curso.totalDeIngresos = 0.0; // Inicializar en cero el total de ingresos.
}








// Módulo que lee el archivo "Cursos.csv" y almacena la información que se lee en
// un arreglo de estructura de tipo "Curso".
void leer_cursos(const char *nombre_archivo, struct Curso *arrCursos, int &cantCursos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantCursos = 0;
    while(true) {
        leer_un_curso(arrCursos[cantCursos], input);
        if(input.eof()) break; // Validar fin del archivo "Cursos.csv"
        cantCursos++;
    }
}







// Módulo que lee una escala del archivo "Escalas.csv" y lo almacena en un
// dato de estructura de tipo "Escala".
void leer_una_escala(struct Escala &una_escala, ifstream &input) {
    int semestre;
    semestre = leer_semestre(input);
    if(input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma.
    una_escala.semestre = semestre;
    una_escala.escala = leer_dato_char(input);
    una_escala.costoPorCredito = leer_dato_double(input);
}







// Módulo que lee el archivo "Escalas.csv" y almacena la información que se lee en
// un arreglo de estructura de tipo "Escala".
void leer_escalas(const char *nombre_archivo, struct Escala *arrEscalas, int &cantEscalas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantEscalas = 0;
    while(true) {
        leer_una_escala(arrEscalas[cantEscalas], input);
        if(input.eof()) break; // Verificar fin del archivo "Escalas.csv"
        cantEscalas++;
    }
}





// Módulo que solicita un semestre al usuario y lo retorna como un valor entero.
int solicitar_semestre() {
    int anio, ciclo;
    char guion;
    cout << "Ingrese un semestre (por ejemplo: 2023-1): ";
    cin >> anio >> guion >> ciclo;
    return anio*10 + ciclo;
}




