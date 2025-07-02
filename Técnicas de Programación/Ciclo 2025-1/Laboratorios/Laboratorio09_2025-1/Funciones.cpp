

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de junio del 2025, 01:12 PM
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
int leer_int(ifstream &input, bool leer_caracter) {
    int dato;
    input >> dato;
    if(leer_caracter) input.get();
    return dato;
}



// Módulo que lee un dato de tipo "double".
double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get(); // Leer la coma.
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
    char *cadena_dinamica;
    cadena_dinamica = new char[strlen(buffer) + 1];
    strcpy(cadena_dinamica, buffer);
    return cadena_dinamica;
}




// Módulo que lee una cadena de caracteres y lo guarda con memoria exacta.
// Se puede leer con el "getline()" o con el operador de lectura (cuando se lee un archivo "TXT").
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_operador_lectura) {
    char buffer[300], *cadena;
    if(leer_con_operador_lectura) {
        input >> buffer;
    } else {
        input.getline(buffer, 300, delimitador);
    }
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}




// Módulo que lee una fecha de tipo DD/MM/AAAA y lo retorna
// como una estructura de tipo "Fecha".
struct Fecha leer_fecha(ifstream &input) {
    struct Fecha fecha;
    fecha.dd = leer_int(input, true);
    fecha.mm = leer_int(input, true);
    fecha.aa = leer_int(input, false);
    fecha.fecha = fecha.aa * 10000 + fecha.mm * 100 + fecha.dd;
    return fecha;
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






// Módulo que emite el reporte solicitado.
void emitir_reporte(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulo(output);
    for(int indice = 0; indice < cantEmpresas; indice++) {
        imprimir_datos_de_la_empresa(arrEmpresasRegistradas[indice].dni, arrEmpresasRegistradas[indice].nombre,
                                     arrEmpresasRegistradas[indice].distrito, arrEmpresasRegistradas[indice].placas,
                                     arrEmpresasRegistradas[indice].numPlacas, indice, output);
        imprimir_infracciones_cometidas(arrEmpresasRegistradas[indice].infraccion, arrEmpresasRegistradas[indice].cantidadDeInfracciones,
                                        arrEmpresasRegistradas[indice].totalPagado, arrEmpresasRegistradas[indice].totalAdeudado, output);
    }
    elaborar_lineas('=', TAM_REPORTE, output);
}






// Módulo que intercambia los datos de tipo "struct EmpresasRegistradas".
int intercambiar_struct_Empresa(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2) {
    struct EmpresasRegistradas aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}





// Módulo que ordena el arreglo de estructuras de forma ascendente por el distrito.
void ordenar_por_distrito(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    for(int i=0; i<cantEmpresas-1;i++) {
        for(int k=i+1; k<cantEmpresas; k++) {
            if(strcmp(arrEmpresasRegistradas[i].distrito, arrEmpresasRegistradas[k].distrito) > 0) {
                intercambiar_struct_Empresa(arrEmpresasRegistradas[i], arrEmpresasRegistradas[k]);
            }
        }
    }
}





// Módulo que intercambia los datos de tipo "struct InfraccionCometida".
void intercambiar_struct_inf_cometida(struct InfraccionCometida &dato_1, struct InfraccionCometida &dato_2) {
    struct InfraccionCometida aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}






// Módulo que ordena un arreglo de infracciones de tal manera que primero queden primero las infracciones cometidas
// que tienen fecha de pago diferente de cero (los pagados) y al último los de fecha de pago igual a cero (los adeudados).
// En otros términos, se ordena de forma descendente el arreglo de infracciones cometidas por la fecha de pago.
void ordenar_inf_cometida(struct InfraccionCometida *infraccion, int cantidadDeInfracciones) {
    for(int i=0; i<cantidadDeInfracciones-1;i++){
        for(int k=i+1; k<cantidadDeInfracciones; k++) {
            if(infraccion[i].fechaDePago.fecha < infraccion[k].fechaDePago.fecha){
                intercambiar_struct_inf_cometida(infraccion[i], infraccion[k]);
            }
        }
    }
}







// Módulo que ordena el arreglo de empresas registradas. Así mismo, se ordenan las infracciones cometidas de
// cada empresa de tal manera que primero estén las infracciones pagadas y luego las adeudadas.
void ordenar_arreglos(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    ordenar_por_distrito(arrEmpresasRegistradas, cantEmpresas);
    for(int i=0; i<cantEmpresas; i++) {
        ordenar_inf_cometida(arrEmpresasRegistradas[i].infraccion, arrEmpresasRegistradas[i].cantidadDeInfracciones);
    }
}





// Módulo que actualiza el total pagado y el total adeudado de una empresa.
void sumar_montos_pagados_y_adeudados(double &totalPagado, double &totalAdeudado,
                                      struct InfraccionCometida *infraccion, int cantidadDeInfracciones) {
    for(int indice = 0; indice < cantidadDeInfracciones; indice++) {
        if(infraccion[indice].multaPagada) totalPagado += infraccion[indice].multa;
        else  totalAdeudado += infraccion[indice].multa;
    }
}






// Módulo que calcula los montos totales pagados y adeudados de cada empresa del arreglo de estructuras "EmpresasRegistradas".
void calcular_montos_totales_pagados_y_adeudados(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    for(int i=0; i<cantEmpresas; i++) {
        sumar_montos_pagados_y_adeudados(arrEmpresasRegistradas[i].totalPagado,
                                         arrEmpresasRegistradas[i].totalAdeudado,arrEmpresasRegistradas[i].infraccion,
                                         arrEmpresasRegistradas[i].cantidadDeInfracciones);
    }
}






// Módulo que lee una infracción cometida del archivo "InfraccionesCometidas.csv".
void leer_una_infraccion_cometida(struct Fecha &fechaInfraccion, char *&placa_leida, char *&cod_inf_leida,
                                  struct Fecha &fechaDePago, ifstream &input) {
    char caracter_de_pago;
    fechaInfraccion = leer_fecha(input);
    if(input.eof()) return;
    input.get(); // Lectura de la coma
    placa_leida = leer_cadena(input, ',', false);
    cod_inf_leida = leer_cadena(input, ',', false);
    caracter_de_pago = leer_char(input);
    if(caracter_de_pago == 'P') {
        fechaDePago = leer_fecha(input);
        input.get(); // Lectura del cambio de línea
    } else {
        fechaDePago.aa = fechaDePago.mm = fechaDePago.dd = fechaDePago.fecha = 0;
    }
}







// Módulo que verifica si existe la placa en el arreglo de placas de una empresa.
bool existe_placa(char *placa_buscada, char **arrPlacas, int numPlacas) {
    for(int indice = 0; indice < numPlacas; indice++) {
        if(strcmp(arrPlacas[indice], placa_buscada) == 0){
            return true;
        }
    }
    return false;
}





// Módulo que busca una placa mediante el arreglo de estructuras de tipo "EmpresasRegistradas".
int buscar_placa(char *placa_buscada, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    for(int indice = 0; indice < cantEmpresas; indice++) {
        if(existe_placa(placa_buscada, arrEmpresasRegistradas[indice].placas, arrEmpresasRegistradas[indice].numPlacas)) {
            return indice;
        }
    }
    return NO_ENCONTRADO;
}





// Módulo que busca un código de infracción de la tabla de infracciones mediante un arreglo de estructuras de "TablaDeInfracciones",
int buscar_tabla_infraccion(char *cod_inf_leida, struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInf) {
    for(int indice = 0; indice < cantTablaInf; indice++) {
        if(strcmp(arrTablaDeInfracciones[indice].codigo, cod_inf_leida) == 0) {
            return indice;
        }
    }
    return NO_ENCONTRADO;
}





// Módulo que completa los campos de una infracción de una empresa registrada.
void completar_campos_infracciones(struct InfraccionCometida *arrInfraccionesCometidas, int &cantInfracciones,
                                   struct Fecha fechaInfraccion, char *cod_inf_leida, struct Fecha fechaDePago,
                                   struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInf, char *placa_leida) {
    int indice_tabla_inf;
    arrInfraccionesCometidas[cantInfracciones].placa = asignar_cadena(placa_leida);
    arrInfraccionesCometidas[cantInfracciones].fechaDeInfraccion = fechaInfraccion;
    arrInfraccionesCometidas[cantInfracciones].fechaDePago = fechaDePago;
    arrInfraccionesCometidas[cantInfracciones].multaPagada = (fechaDePago.fecha > 0 ? true : false);
    arrInfraccionesCometidas[cantInfracciones].codigoDeLaInfraccion = asignar_cadena(cod_inf_leida);
    
    indice_tabla_inf = buscar_tabla_infraccion(cod_inf_leida, arrTablaDeInfracciones, cantTablaInf);
    if(indice_tabla_inf != NO_ENCONTRADO) {
        arrInfraccionesCometidas[cantInfracciones].multa = arrTablaDeInfracciones[indice_tabla_inf].multa;
        arrInfraccionesCometidas[cantInfracciones].descripcion = asignar_cadena(arrTablaDeInfracciones[indice_tabla_inf].descripcion);
    } else {
        arrInfraccionesCometidas[cantInfracciones].multa = 0.0;
        arrInfraccionesCometidas[cantInfracciones].descripcion = asignar_cadena("NO EXISTE INFRACCION");
    }
    
    cantInfracciones++;
}








// Módulo que procesa el archivo "InfraccionesCometidas.csv" y con el arreglo de "tabla de infracciones" se
// completan los campos restantes del arreglo de estructuras de tipo "EmpresasRegistradas".
void procesar_infracciones_cometidas(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones,
                                     int cantTablaInf, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    struct Fecha fechaInfraccion, fechaDePago;
    char *placa_leida, *cod_inf_leida;
    int indice_empresa;
    while(true) {
        leer_una_infraccion_cometida(fechaInfraccion, placa_leida, cod_inf_leida, fechaDePago, input);
        if(input.eof()) break; // Validar fin del archivo "InfraccionesCometidas.csv".
        indice_empresa = buscar_placa(placa_leida, arrEmpresasRegistradas, cantEmpresas);
        if(indice_empresa != NO_ENCONTRADO) {
            completar_campos_infracciones(arrEmpresasRegistradas[indice_empresa].infraccion,
                                          arrEmpresasRegistradas[indice_empresa].cantidadDeInfracciones, fechaInfraccion,
                                          cod_inf_leida, fechaDePago, arrTablaDeInfracciones, cantTablaInf, placa_leida);
        }
    }
}






// Módulo que busca un DNI mediante el arreglo de estructuras de tipo "EmpresasRegistradas".
int buscar_dni(int dni_buscado, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    for(int indice = 0; indice < cantEmpresas; indice++) {
        if(arrEmpresasRegistradas[indice].dni == dni_buscado) {
            return indice; // Se encontró el DNI, entonces se retorna el índice.
        }
    }
    return NO_ENCONTRADO;
}





// Módulo que procesa el archivo "PlcasRegistradas.txt" y almacena las placas
// para cada empresa en el arreglo de estructuras de tipo "EmpresasRegistradas".
void procesar_placas_registradas(const char *nombre_archivo,
                                 struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    while(true) {
        int dni_leido, indice_empresa;
        char *placa;
        
        dni_leido = leer_int(input, false);
        if(input.eof()) break; // Validar fin del archivo "PlcasRegistradas.txt".
        placa = leer_cadena(input, '\n', true);
        
        indice_empresa = buscar_dni(dni_leido, arrEmpresasRegistradas, cantEmpresas);
        if(indice_empresa != NO_ENCONTRADO) {
            int cant_placas = arrEmpresasRegistradas[indice_empresa].numPlacas;
            arrEmpresasRegistradas[indice_empresa].placas[cant_placas] = asignar_cadena(placa);
            arrEmpresasRegistradas[indice_empresa].numPlacas++;
        }
    }
}







// Módulo que pasa todas las letras de una cadena de caracteres a mayúsculas.
void todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice]>='a'  and  cadena[indice]<='z') {
            cadena[indice] -= 32;
        }
    }
}






// Módulo que lee una empresa registrada del archivo "EmpresasRegistradas.csv" e
// inicializa los campos restantes de la estrcutura de tipo "EmpresasRegistradas".
void leer_una_empresa_registrada(struct EmpresasRegistradas &una_empresa, ifstream &input) {
    int dni;
    dni = leer_int(input, false);
    if(input.eof()) return; // Si no hay más datos a leer en el archivo, entonces salir de este módulo.
    input.get(); // Lectura de la coma
    una_empresa.dni = dni;
    una_empresa.nombre = leer_cadena(input, ',', false);
    todo_a_mayusculas(una_empresa.nombre);
    una_empresa.distrito = leer_cadena(input, '\n', false);
    todo_a_mayusculas(una_empresa.distrito);
    
    // Inicializar campos restantes de la estructura de tipo "EmpresasRegistradas".
    una_empresa.infraccion = new struct InfraccionCometida[MAX_CANT_INFRACCIONES_COMETIDAS]{};
    una_empresa.numPlacas = una_empresa.cantidadDeInfracciones = 0;
    una_empresa.totalPagado = una_empresa.totalAdeudado = 0.0;
}







// Módulo que procesa el archivo "EmpresasRegistradas.csv" y almacena los datos
// que se leen en un arreglo de estructuras de tipo "EmpresasRegistradas".
void procesar_empresas_registradas(const char *nombre_archivo,
                                   struct EmpresasRegistradas *arrEmpresasRegistradas, int &cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    
    
    // Inicializar el contador de tabla de infracciones.
    cantEmpresas = 0;
    
    while(true) {
        leer_una_empresa_registrada(arrEmpresasRegistradas[cantEmpresas], input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.csv"
        cantEmpresas++;
    }
}






// Módulo que lee una infracción de la tabla de infracciones.
void leer_una_infraccion_de_la_tabla_de_infracciones(struct TablaDeInfracciones &infraccion, ifstream &input) {
    char *cod_infraccion;
    cod_infraccion = leer_cadena(input, ',', false);
    if(cod_infraccion == nullptr) return; // No hay más datos a leer en el archivo. Salir del módulo.
    infraccion.codigo = asignar_cadena(cod_infraccion);
    infraccion.multa = leer_double(input);
    infraccion.descripcion = leer_cadena(input, '\n', false);
    todo_a_mayusculas(infraccion.descripcion);
}









// Módulo que procesa el archivo "TablaDeInfracciones.csv" y almacena los datos
// que se leen en un arreglo de estructuras de tipo "TablaDeInfracciones".
void procesar_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones, int &cantTablaInf) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    
    // Inicializar el contador de tabla de infracciones.
    cantTablaInf = 0;
    
    
    // Lectura de datos del archivo "TablaDeInfracciones.csv".
    while(true) {
        leer_una_infraccion_de_la_tabla_de_infracciones(arrTablaDeInfracciones[cantTablaInf], input);
        if(input.eof()) break; // Validar fin del archivo "TablaDeInfracciones.csv".
        cantTablaInf++;
    }
}


