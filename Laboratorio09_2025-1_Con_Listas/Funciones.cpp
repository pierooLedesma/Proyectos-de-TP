

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 28 de junio del 2025, 01:37 PM
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
    input.get(); // Lectura de la coma
    return dato;
}


// Módulo que lee un dato de tipo "char".
char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get(); // Lectura de la coma o del cambio de línea.
    return dato;
}



// Módulo que guarda una cadena de caracteres con memoria exacta.
char *asignar_cadena(const char *buffer) {
    char *cadena_a_asignar;
    cadena_a_asignar = new char[strlen(buffer) + 1];
    strcpy(cadena_a_asignar, buffer);
    return cadena_a_asignar;
}




// Módulo que lee una cadena de caracteres y lo almacena con memoria exacta.
// Se puede leer la cadena de caracteres con el "getline()" o con el operador de lectura ">>".
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura) {
    char buffer[300], *cadena;
    
    if(leer_con_el_operador_de_lectura) input >> buffer;  // Leer la cadena con el operador de lectura.
    else  input.getline(buffer, 300, delimitador);  // Leer con la función "getline()".
    
    cadena = asignar_cadena(buffer);
    
    return cadena;
}




// Módulo que lee una fecha de tipo DD/MM/AAAA.
struct Fecha leer_fecha(ifstream &input) {
    struct Fecha una_fecha;
    una_fecha.dd = leer_int(input);
    input.get();  // Lectura del slash '/'
    una_fecha.mm = leer_int(input);
    input.get();  // Lectura del slash '/'
    una_fecha.aa = leer_int(input);
    una_fecha.fecha = una_fecha.aa*10000 + una_fecha.mm*100 + una_fecha.dd;
    return una_fecha;
}




// Módulo que imprime una fecha con una estructura de tipo "Fecha".
void imprimir_fecha(struct Fecha una_fecha, ofstream &output) {
    output << setfill('0') << setw(2) << una_fecha.dd << '/';
    output << setw(2) << una_fecha.mm << '/';
    output << setfill(' ') << una_fecha.aa;
}




// Módulo que elabora las líneas del reporte solicitado;
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output) {
    for(int i=0; i<cantCaracteres; i++)   output.put(caracter);
    output << endl;
}





// Módulo que imprime el título del reporte solicitado.
void imprimir_titulo(ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "MINISTERIO DE TRANSPORTES" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "LISTADO DE INFRACCIONES POR EMPRESA" << endl;
}





// Módulo que imprime los datos de una empresa (DNI, nombre del representante legal, el distrito, las placas registradas).
void imprimir_datos_de_la_empresa(int dni, char *nombre, char *distrito, char **arrPlacas, int numPlacas,
                                  int n_empresa_registrada,ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setfill('0') << setw(2) << n_empresa_registrada + 1<< ')';
    output << setfill(' ') << setw((TAM_REPORTE / (N_COLUMNAS + 6)) / 5 + 3) << "DNI: ";
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 5) << dni;
    output << "NOMBRE: " << setw(TAM_REPORTE / (N_COLUMNAS - 1) - 4) << nombre;
    output << "DISTRITO: " << setw(TAM_REPORTE / (N_COLUMNAS - 1)) << distrito;
    output << right << "PLACAS: ";
    
    // Impresión de las empresas registradas de la empresa.
    for(int indice = 0; indice < numPlacas; indice++) {
        output << arrPlacas[indice];
        if(indice + 1 != numPlacas)  output << '/';
    }
    
    output << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}








// Módulo que imprime el encabezado de las infracciones cometidas de cada empresa en el reporte
void imprimir_encabezado_infracciones(bool booleano_escogido, ofstream &output) {
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 3) << "FECHA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 5) << "PLACA";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 2) << "CODIGO DE INFRACCION";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 2) << "DESCRIPCION";
    output << setw((TAM_REPORTE / (N_COLUMNAS + 3)) * 5  + 7) << "MULTA";
    if(booleano_escogido)  output << setw(TAM_REPORTE / (N_COLUMNAS + 8)) << "FECHA DE PAGO";
    output << endl;
    elaborar_lineas('-', TAM_REPORTE, output);
}




// Módulo que imprime una infracción cometida de una empresa.
void imprimir_una_infraccion_cometida(int n_inf, struct Fecha fechaDeInfraccion, char *placa,
                                      char *codigoDeLaInfraccion, char *descripcion, double multa,
                                      struct Fecha fechaDePago, ofstream &output) {
    output << setw((TAM_REPORTE / (N_COLUMNAS + 6)) / 5) << n_inf + 1 << ')';
    output << setw((TAM_REPORTE / (N_COLUMNAS + 6)) / 5 - 2) << ' ';
    imprimir_fecha(fechaDeInfraccion, output);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 6) << placa;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 3) << codigoDeLaInfraccion;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 4) << ' ';
    output << left << setw((TAM_REPORTE / (N_COLUMNAS + 3)) * 5  + 12) << descripcion << right;
    output << setw((TAM_REPORTE / (N_COLUMNAS + 6)) / 5 + 3) << multa;
    if(fechaDePago.fecha > 0) {
        output << setw((TAM_REPORTE / (N_COLUMNAS + 6)) / 5 + 1) << ' ';
        imprimir_fecha(fechaDePago, output);
    }
    output << endl;
}






// Módulo que imprime el arreglo de infracciones cometidas de una empresa.
void imprimir_arreglo_infracciones(int &indice_infraccion, struct InfraccionCometida *infracciones,
                                   int cantidadDeInfracciones, bool booleano_escogido, ofstream &output) {
    imprimir_encabezado_infracciones(booleano_escogido, output);
    int n_inf = 0;
    for(indice_infraccion; indice_infraccion < cantidadDeInfracciones and
                            infracciones[indice_infraccion].multaPagada == booleano_escogido; indice_infraccion++, n_inf++) {
        imprimir_una_infraccion_cometida(n_inf, infracciones[indice_infraccion].fechaDeInfraccion,
                            infracciones[indice_infraccion].placa, infracciones[indice_infraccion].codigoDeLaInfraccion,
                            infracciones[indice_infraccion].descripcion, infracciones[indice_infraccion].multa,
                            infracciones[indice_infraccion].fechaDePago, output);
    }
    elaborar_lineas('-', TAM_REPORTE, output);
}







// Módulo que imprime las infracciones cometidas que han sido pagadas como adeudadas de una empresa.
void imprimir_infracciones_cometidas(struct InfraccionCometida *infracciones, int cantidadDeInfracciones,
                                     double totalPagado, double totalAdeudado, ofstream &output) {
    int indice_infraccion = 0;
    if(totalPagado > 0  or  totalAdeudado > 0) {
        if(totalPagado > 0) {
            output << setw(TAM_REPORTE / (N_COLUMNAS + 8)) << "MULTAS PAGADAS:" << endl;
            imprimir_arreglo_infracciones(indice_infraccion, infracciones, cantidadDeInfracciones, true, output);
            output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 1) << "TOTAL PAGADO: " << totalPagado << endl;
        } else {
            output << "NINGUNA INFRACCION COMETIDA HA SIDO PAGADA." << endl;
        }
        
        elaborar_lineas('=', TAM_REPORTE, output);
        
        if(totalAdeudado > 0) {
            output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 2) << "MULTAS ADEUDADAS:" << endl;
            imprimir_arreglo_infracciones(indice_infraccion, infracciones, cantidadDeInfracciones, false, output);
            output << setw(TAM_REPORTE / (N_COLUMNAS + 8) + 1) << "TOTAL ADEUDADO: " << totalAdeudado << endl;
        } else {
            output << "NO HAY INFRACCIONES COMETIDAS ADEUDADAS." << endl;
        }
    }  else {
        output << "LA EMPRESA NO HA COMETIDO NINGUNA INFRACCION." << endl;
    }
}







// Módulo que imprime el reporte solicitado mediante la lista simplemente enlazada de empresas registardas.
void emitir_reporte(const char *nombre_archivo, struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    
    imprimir_titulo(output);
    
    int n_empresa_registrada = 0;
    struct NodoEmpresasRegistradas *ptrAuxiliar = listaEmpresasRegistradas;
    while(ptrAuxiliar) {
        imprimir_datos_de_la_empresa(ptrAuxiliar->dato.dni, ptrAuxiliar->dato.nombre, ptrAuxiliar->dato.distrito,
                                     ptrAuxiliar->dato.placas, ptrAuxiliar->dato.numPlacas, n_empresa_registrada, output);
        imprimir_infracciones_cometidas(ptrAuxiliar->dato.infracciones, ptrAuxiliar->dato.cantidadDeInfracciones,
                                        ptrAuxiliar->dato.totalPagado, ptrAuxiliar->dato.totalAdeudado, output);
        n_empresa_registrada++;
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
    elaborar_lineas('=', TAM_REPORTE, output);
}




// Módulo que intercambia los datos de tipo estructura "InfraccionCometida".
void intercambiar_struct_infraccion_cometida(struct InfraccionCometida &infraccion_1,
                                             struct InfraccionCometida &infraccion_2) {
    struct InfraccionCometida auxiliar;
    auxiliar = infraccion_1;
    infraccion_1 = infraccion_2;
    infraccion_2 = auxiliar;
}





// Se ordena las infracciones de forma descendente por el campo fecha de la estructura "Fecha" de tal
// forma que primero aparezcan los pagados y al último los adeudados.
void ordenar_infracciones(struct InfraccionCometida *infracciones, int cantidadDeInfracciones) {
    for(int i = 0;  i < cantidadDeInfracciones - 1;  i++) {
        for(int k = i + 1;  k < cantidadDeInfracciones;  k++) {
            if(infracciones[i].fechaDePago.fecha < infracciones[k].fechaDePago.fecha) {
                intercambiar_struct_infraccion_cometida(infracciones[i], infracciones[k]);
            }
        }
    }
}





// Módulo que ordena las infracciones de cada empresa de la lista simplemente enlazada de empresas registradas..
void ordenar_infracciones_para_cada_empresa(struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    struct NodoEmpresasRegistradas *ptrAuxiliar = listaEmpresasRegistradas;
    while(ptrAuxiliar) {
        ordenar_infracciones(ptrAuxiliar->dato.infracciones, ptrAuxiliar->dato.cantidadDeInfracciones);
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
}





// Módulo que actualiza el total pagado y el total adeudado de una empresa.
void actualizar_totalPagado_y_totalAdeudado_de_una_empresa(struct InfraccionCometida *infracciones,
                                    int cantidadDeInfracciones, double &totalPagado, double &totalAdeudado) {
    for(int indice = 0; indice < cantidadDeInfracciones; indice++) {
        if(infracciones[indice].fechaDePago.fecha > 0)  totalPagado += infracciones[indice].multa;
        else  totalAdeudado += infracciones[indice].multa;
    }
}





// Módulo que calcula los totales pagados y adeudados de las empresas registradas en la lista simplemente enlazada.
void calcular_totales_pagados_y_adeudados(struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    struct NodoEmpresasRegistradas *ptrAuxiliar = listaEmpresasRegistradas;
    while(ptrAuxiliar) {
        actualizar_totalPagado_y_totalAdeudado_de_una_empresa(ptrAuxiliar->dato.infracciones,
                       ptrAuxiliar->dato.cantidadDeInfracciones, ptrAuxiliar->dato.totalPagado, ptrAuxiliar->dato.totalAdeudado);
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
}






// Módulo que lee una infracción cometida del archivo "InfraccionesCometidas.csv".
void leer_una_infraccion_cometida(struct Fecha &fechaDeInfraccion, char *&placa_leida, char *&codInfraccion_leida,
                                  struct Fecha &fechaDePago, ifstream &input) {
    char caracter_de_pago;
    fechaDeInfraccion = leer_fecha(input);
    if(input.eof()) return;
    input.get();  // Lectura de la coma.
    placa_leida = leer_cadena(input, ',', false);
    codInfraccion_leida = leer_cadena(input, ',', false);
    caracter_de_pago = leer_char(input);
    if(caracter_de_pago == 'P') {
        fechaDePago = leer_fecha(input);
    } else {
        fechaDePago.dd = fechaDePago.mm = fechaDePago.aa = fechaDePago.fecha = 0;
    }
}




// Módulo que verifica si existe la placa buscada en el arreglo de placas.
bool existe_placa(char *placa_buscada, char **arrPlacas, int numPlacas) {
    for(int indice = 0; indice < numPlacas; indice++) {
        if(strcmp(arrPlacas[indice], placa_buscada) == 0) return true;
    }
    return false;
}



// Módulo que busca una placa mediante la lista simplemente enlazada de empresas registradas.
struct NodoEmpresasRegistradas *buscar_placa(char *placa_buscada, struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    struct NodoEmpresasRegistradas *ptrAuxiliar = listaEmpresasRegistradas;
    while(ptrAuxiliar) {
        if(existe_placa(placa_buscada, ptrAuxiliar->dato.placas, ptrAuxiliar->dato.numPlacas)) return ptrAuxiliar;
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
    return nullptr;
}





// Módulo que busca un código de infracción en la lista simplemente enlazada de tabla de infracciones.
struct NodoTablaDeInfracciones *buscarTablaInfraccion(char *codInfraccion_leida, struct NodoTablaDeInfracciones *listaTablaDeInfraciones) {
    struct NodoTablaDeInfracciones *ptrAuxiliar = listaTablaDeInfraciones;
    while(ptrAuxiliar) {
        if(strcmp(ptrAuxiliar->dato.codigo, codInfraccion_leida) == 0) return ptrAuxiliar;
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
    return nullptr;
}






// Módulo que completa los campos de una infracción cometida de una empresa.
void completar_campos_de_infraccion_cometida(struct Fecha fechaDeInfraccion, struct Fecha fechaDePago,
                                    char *codInfraccion_leida, struct NodoTablaDeInfracciones *listaTablaDeInfraciones,
                                    struct InfraccionCometida *arrInfracciones, int &cantidadDeInfracciones, char *placa_leida) {
    arrInfracciones[cantidadDeInfracciones].fechaDeInfraccion = fechaDeInfraccion;
    arrInfracciones[cantidadDeInfracciones].placa = asignar_cadena(placa_leida);
    
    arrInfracciones[cantidadDeInfracciones].codigoDeLaInfraccion = asignar_cadena(codInfraccion_leida);
    struct NodoTablaDeInfracciones *ptrAuxiliarTablaInfraccion = buscarTablaInfraccion(codInfraccion_leida, listaTablaDeInfraciones);
    if(ptrAuxiliarTablaInfraccion != nullptr) {
        arrInfracciones[cantidadDeInfracciones].multa = ptrAuxiliarTablaInfraccion->dato.multa;
        arrInfracciones[cantidadDeInfracciones].descripcion = asignar_cadena(ptrAuxiliarTablaInfraccion->dato.descripcion);
    } else {
        arrInfracciones[cantidadDeInfracciones].descripcion = asignar_cadena("NO SE ENCONTRO LA INFRACCION");
    }
    
    if(fechaDePago.fecha > 0) arrInfracciones[cantidadDeInfracciones].multaPagada = true;
    arrInfracciones[cantidadDeInfracciones].fechaDePago = fechaDePago;
    cantidadDeInfracciones++;
}






// Módulo que procesa el archivo "InfraccionesCometidas.csv" y completa las infracciones cometidas de cada
// empresa de la lista simplemente enlazada de empresas registradas.
void procesarInfraccionesCometidas(const char *nombre_archivo, struct NodoTablaDeInfracciones *listaTablaDeInfraciones,
                                   struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    struct Fecha fechaDeInfraccion, fechaDePago;
    while(true) {
        char *placa_leida, *codInfraccion_leida;
        leer_una_infraccion_cometida(fechaDeInfraccion, placa_leida, codInfraccion_leida, fechaDePago, input);
        if(input.eof()) break; // Validar fin del archivo "InfraccionesCometidas.csv"
        struct NodoEmpresasRegistradas *ptrEmpresa = buscar_placa(placa_leida, listaEmpresasRegistradas);
        if(ptrEmpresa != nullptr) {
            completar_campos_de_infraccion_cometida(fechaDeInfraccion, fechaDePago, codInfraccion_leida,
                                                    listaTablaDeInfraciones, ptrEmpresa->dato.infracciones,
                                                    ptrEmpresa->dato.cantidadDeInfracciones, placa_leida);
        }
    }
}






// Módulo que busca una empresa registrada en una lista simplemente enlazada usando el DNI como criterio de búsqueda.
struct NodoEmpresasRegistradas *buscar_empresa_registrada(int dni_leido, struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    
    // Crear un puntero auxiliar para recorrer la lista sin modificar el puntero original de la lista de empresas registradas.
    struct NodoEmpresasRegistradas *ptrAuxiliar = listaEmpresasRegistradas;
    
    // Recorrer la lista de empresas registradas mientras el puntero no sea nulo.
    while(ptrAuxiliar) {
        
        // Si el DNI del nodo actual coincide con el buscado, se retorna el puntero al nodo.
        if(ptrAuxiliar->dato.dni == dni_leido) return ptrAuxiliar;
        
        // Avanzar al siguiente nodo de la lista de empresas registradas.
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
    
    // Si no se encontró ningún nodo con el DNI buscado, se retorna "nullptr".
    return nullptr;
}








// Módulo que procesa el archivo "PlacasRegistradas.txt" y las asigna a la empresa correspondiente
// en la lista simplemente enlazada de empresas registradas.
void procesarPlacasRegistradas(const char *nombre_archivo, struct NodoEmpresasRegistradas *listaEmpresasRegistradas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni_leido;
    while(true) {
        dni_leido = leer_int(input);
        if(input.eof()) break;  // Validar el fin del archivo "PlacasRegistradas.txt"
        
        char *placa; // Puntero para almacenar la cadena leída (la placa).
        placa = leer_cadena(input, '\n', true);
        
        // Puntero auxiliar para encontrar la empresa correspondiente al DNI leído.
        struct NodoEmpresasRegistradas *ptrEmpresa = buscar_empresa_registrada(dni_leido, listaEmpresasRegistradas);
        
        if(ptrEmpresa != nullptr) {
            // Se encontró la empresa en la lista simplemente enlazada de empresas registradas.
            int indice_empresa = ptrEmpresa->dato.numPlacas;  // Obtener el índice actual donde se debe agregar la nueva placa.
            ptrEmpresa->dato.placas[indice_empresa] = asignar_cadena(placa);  // Asignar la nueva placa al arreglo de placas de la empresa
            ptrEmpresa->dato.numPlacas++;  // Incrementar el contador de placas registradas para esa empresa.
        }
    }
}







// Módulo que pasa a mayúscula toda las letras que hay en una cadena de caracteres.
void todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'  and cadena[indice] <= 'z') {
//            cadena[indice] -= ('a' - 'A');
            cadena[indice] -= 32;  // 32 es la diferencia de los códigos ASCCI entre 'a' y 'A'.
        }
    }
}






// Módulo que lee una empresa del archivo "EmpresasRegistradas.csv".
void leer_una_empresa(int &dni, char *&nombre, char *&distrito, ifstream &input) {
    dni = leer_int(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    input.get(); // Lectura de la coma.
    nombre = leer_cadena(input, ',', false);
    todo_a_mayusculas(nombre);
    distrito = leer_cadena(input, '\n', false);
    todo_a_mayusculas(distrito);
}






// Módulo que completa los datos en los campos de la estructura "EmpresasRegistradas".
void asignar_datos_empresa(int dni, char *nombre, char *distrito, struct EmpresasRegistradas &empresa) {
    // Almacenar los datos leídos (dni, nombre, distrito) en la estructura "EmpresasRegistradas".
    empresa.dni = dni;
    empresa.nombre = asignar_cadena(nombre);
    empresa.distrito = asignar_cadena(distrito);
    
    // Inicializar los campos restantes de la estructura "EmpresasRegistradas".
    empresa.infracciones = new struct InfraccionCometida[MAX_CANT_INFRACCIONES_COMETIDAS]{};
    empresa.numPlacas = empresa.cantidadDeInfracciones = 0;
    empresa.totalPagado = empresa.totalAdeudado = 0.0;
}







// Módulo que inserta un nuevo nodo a la lista simplemente enlazada de empresas registradas de forma ascendente por el distrito.
void insertar_ordenado_lista_empresas(int dni, char *nombre, char *distrito, struct NodoEmpresasRegistradas *&listaEmpresasRegistradas) {
    struct NodoEmpresasRegistradas *nuevo_nodo, *anterior, *ptrAuxiliar;
    
    nuevo_nodo = new struct NodoEmpresasRegistradas;
    asignar_datos_empresa(dni, nombre, distrito, nuevo_nodo->dato);
    
    ptrAuxiliar = listaEmpresasRegistradas;
    anterior = nullptr;
    
    // Buscar la posición de inserción en orden ascendente por el distrito.
    while(ptrAuxiliar) {
        if(strcmp(ptrAuxiliar->dato.distrito, distrito) > 0) break;
        anterior = ptrAuxiliar;
        ptrAuxiliar = ptrAuxiliar->siguiente;
    }
    
    nuevo_nodo->siguiente = ptrAuxiliar;
    
    if(anterior != nullptr) anterior->siguiente = nuevo_nodo;
    else listaEmpresasRegistradas = nuevo_nodo; // Insertar el nuevo nodo al inicio de la lista.
}







// Módulo que procesa el archivo "EmpresasRegistradas.csv" y almacena los datos en la lista simplemente enlazada llamada "listaEmpresasRegistradas".
void procesarEmpresasRegistradas(const char *nombre_archivo, struct NodoEmpresasRegistradas *&listaEmpresasRegistradas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    listaEmpresasRegistradas = nullptr;  // Inicializar la lista en "nullptr". Lista vacía.
    while(true) {
        int dni;
        char *nombre, *distrito;
        leer_una_empresa(dni, nombre, distrito, input);
        if(input.eof()) break; // Validar el fin del archivo "EmpresasRegistradas.csv".
        insertar_ordenado_lista_empresas(dni, nombre, distrito, listaEmpresasRegistradas);
    }
}





// Módulo que lee una línea del archivo "TablaDeInfracciones.csv".
void leer_una_linea_de_tabla_de_infracciones(char *&codInfraccion, double &multa, char *&descripcion, ifstream &input) {
    codInfraccion = leer_cadena(input, ',', false);
    if(codInfraccion == nullptr) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    multa = leer_double(input);
    descripcion = leer_cadena(input, '\n', false);
    todo_a_mayusculas(descripcion);
}





// Módulo que inserta un nuevo nodo al final de la lista simplemente enlazada de tabla de infracciones.
void insertar_nuevo_nodo_tabla_de_infracciones(char *codInfraccion, double multa, char *descripcion,
                                               struct NodoTablaDeInfracciones *&listaTablaDeInfraciones) {
    struct NodoTablaDeInfracciones *nuevo_nodo;
    nuevo_nodo = new struct NodoTablaDeInfracciones;
    nuevo_nodo->dato.codigo = asignar_cadena(codInfraccion);
    nuevo_nodo->dato.multa = multa;
    nuevo_nodo->dato.descripcion = asignar_cadena(descripcion);
    nuevo_nodo->siguiente = nullptr;
    
    if(listaTablaDeInfraciones == nullptr) {
        // Es un nuevo nodo a la lista de tabla de infracciones.
        listaTablaDeInfraciones = nuevo_nodo;
    } else {
        // Recorrer la lista hasta el final con un puntero auxiliar (recorrido).
        struct NodoTablaDeInfracciones *recorrido;
        recorrido = listaTablaDeInfraciones;
        while(recorrido->siguiente) recorrido = recorrido->siguiente;
        
        // Insertar el nuevo nodo al final de la lista de infracciones.
        recorrido->siguiente = nuevo_nodo;
    }
}






// Módulo que procesa el archivo "TablaDeInfracciones.csv" y almacena los datos en la lista simplemente enlazada llamada "listaTablaDeInfraciones".
void procesarTablaDeInfracciones(const char *nombre_archivo, struct NodoTablaDeInfracciones *&listaTablaDeInfraciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    
    listaTablaDeInfraciones = nullptr;  // Inicializar la lista en "nullptr". Lista vacía.
    
    while(true) {
        char *codInfraccion, *descripcion;
        double multa;
        leer_una_linea_de_tabla_de_infracciones(codInfraccion, multa, descripcion, input);
        if(input.eof()) break; // Validar el fin del archivo "TablaDeInfracciones.csv".
        insertar_nuevo_nodo_tabla_de_infracciones(codInfraccion, multa, descripcion, listaTablaDeInfraciones);
    }
}


