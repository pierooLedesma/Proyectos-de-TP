

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 23 de junio del 2025, 10:32 AM
 */

#include "Funciones.hpp"
#include "Fecha.hpp"


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
void aperturar_archivo_escriura(const char *nombre_archivo, ofstream &output) {
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
    input.get(); // Lectura de la coma.
    return dato;
}



// Módulo que lee un dato de tipo "char".
char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get(); // Leer el cambio de línea o una coma.
    return dato;
}





// Módulo que asigna memoria exacta a una cadena de caracteres.
char *asignar_cadena(const char *buffer) {
    char *cadena_dinamica;
    cadena_dinamica = new char[strlen(buffer) + 1];
    strcpy(cadena_dinamica, buffer);
    return cadena_dinamica;
}





// Módulo que lee una cadena y lo retorna con memoria exacta.
// Se puede leer la cadena con el "getline()" o con el operador de lectura.
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_operador_lectura) {
    char buffer[300], *cadena;
    if(leer_con_operador_lectura) {
        input >> buffer;
    } else {
        input.getline(buffer, 300, delimitador);
    }
    cadena = asignar_cadena(buffer);
    return cadena;
}





// Módulo que lee una fecha de la forma DD/MM/AAAA.
struct Fecha leer_fecha(ifstream &input) {
    struct Fecha fecha;
    fecha.dd = leer_int(input);
    input.get(); // Lectura del slash '/'
    fecha.mm = leer_int(input);
    input.get(); // Lectura del slash '/'
    fecha.aa = leer_int(input);
    fecha.fecha = fecha.dd * 10000 + fecha.mm * 100 + fecha.dd;
    return fecha;
}




// Módulo que imprime una fecha de la forma DD/MM/AAAA.
void imprimir_fecha(struct Fecha fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha.dd << '/';
    output << setw(2) << fecha.mm << '/' << setfill(' ');
    output << fecha.aa;
}




// Módulo que elabora las líneas del reporte solicitado.
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output) {
    for(int i=0; i<cant_caracteres; i++)  output.put(caracter);
    output << endl;
}





// Módulo que imprime el título y el encabezado de las empresas.
void imprimir_titulo_y_encabezado_de_empresas(ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_EMPRESAS_1) / 2);
    output << "MINISTERIO DE TRANSPORTES" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_EMPRESAS_2) / 2);
    output << "LISTADO DE INFRACCIONES POR EMPRESA" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(47) << "EMPRESA";
    output << setw(109) << "FECHA INF.";
    output << setw(15) << "FECHA PAGO";
    output << setw(43) << "CANTIDAD";
    output << endl;
    output << left << setw(8) << "No.";
    output << setw(11) << "DNI";
    output << setw(46) << "NOMBRE";
    output << setw(30) << "DISTRITO";
    output << setw(50) << "PLACAS";
    output << setw(15) << "MAS ANTIGUA";
    output << setw(16) << "MAS RECIENTE";
    output << setw(15) << "TOTAL PAGADO";
    output << setw(15) << "TOTAL DEUDA";
    output << right << "DE FALTAS" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}





// Módulo que imprime las placas de una empresa.
void imprimir_placas(char **arrPlacas, int numPlacas, ofstream &output) {
    for(int indice = 0; indice < numPlacas; indice++){
        output << arrPlacas[indice];
        if(indice + 1  !=  numPlacas) output << '/';
    }
}





// Módulo que imprime toda la información de una empresa.
void imprimir_datos_de_una_empresa(int n_empresa, struct EmpresasRegistradas &una_empresa, ofstream &output) {
    output << setw(2) << n_empresa << ')' << setw(11) << una_empresa.dni;
    output << setw(5) << ' ' << left << setw(46) << una_empresa.nombre;
    output << setw(30) << una_empresa.distrito << right;
    imprimir_placas(una_empresa.placas, una_empresa.numPlacas, output);
    output << setw(51 - una_empresa.numPlacas * 9) << ' ';
    imprimir_fecha(una_empresa.fechaDeInfraccion, output);
    output << setw(6) << ' ';
    imprimir_fecha(una_empresa.fechaDePago, output);
    output << setw(15) << una_empresa.totalPagado;
    output << setw(14) << una_empresa.totalAdeudado;
    output << setw(11) << una_empresa.cantidadDeFaltas << endl;
}







// Módulo que imprime sección de empresas registradas en el reporte solicitado.
void imprimir_empresas(struct EmpresasRegistradas *arrEmpresas, int cantEmpresas, ofstream &output) {
    double total_total_pagado = 0, total_total_adeudado = 0;
    int total_cantidad_de_faltas = 0;
    imprimir_titulo_y_encabezado_de_empresas(output);
    for(int indice = 0; indice < cantEmpresas; indice++) {
        imprimir_datos_de_una_empresa(indice + 1, arrEmpresas[indice], output);
        total_total_pagado += arrEmpresas[indice].totalPagado;
        total_total_adeudado += arrEmpresas[indice].totalAdeudado;
        total_cantidad_de_faltas += arrEmpresas[indice].cantidadDeFaltas;
    }

    // Impresión de los totales (total pagado, total adeudado y total de cantidad de faltas) de todas las empresas..
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(171) << "TOTALES:" << setw(15) << total_total_pagado;
    output << setw(14) << total_total_adeudado;
    output << setw(11) << total_cantidad_de_faltas << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}






// Módulo que imprime el título y el encabezado de infracciones.
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output) {
    // Impresión del título de infracciones.
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw((TAM_REPORTE + TAM_TITULO_INFRACCIONES) / 2);
    output << "TABLA DE INFRACCIONES" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
    
    // Impresión del encabezado de infracciones.
    output << setw(16) << "CODIGO";
    output << setw(13) << "MULTA";
    output << setw(20) << "DESCRIPCION" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}






// Módulo que imprime la sección de infracciones en el reporte solicitado.
void imprimir_infracciones(struct TablaDeInfracciones *arrInfracciones, int cantInfracciones, ofstream &output) {
    imprimir_titulo_y_encabezado_de_infracciones(output);
    for(int indice = 0; indice < cantInfracciones; indice++) {
        output << setw(15) << arrInfracciones[indice].codigo;
        output << setw(15) << arrInfracciones[indice].multa;
        output << setw(8) << ' ';
        output << arrInfracciones[indice].descripcion;
        output << endl;
    }
    elaborar_lineas('=', TAM_REPORTE, output);
}






// Módulo que emite el reporte solicitado.
void emitir_reporte(const char *nombre_archivo, struct TablaDeInfracciones *arrInfracciones,
                    int cantInfracciones, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    ofstream output;
    aperturar_archivo_escriura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_empresas(arrEmpresas, cantEmpresas, output);
    imprimir_infracciones(arrInfracciones, cantInfracciones, output);
}








// Módulo que intercambia datos de estructura de tipo "TablaDeInfracciones".
void intercambiar_struct_infracciones(struct TablaDeInfracciones &dato_1, struct TablaDeInfracciones &dato_2) {
    struct TablaDeInfracciones aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}






// Módulo que ordena de forma descendente por el código de infracción el arreglo de infracciones.
void ordenar_infracciones(struct TablaDeInfracciones *arrInfracciones, int cantInfracciones) {
    for(int i=0; i<cantInfracciones-1; i++) {
        for(int j=i+1; j<cantInfracciones; j++) {
            if(strcmp(arrInfracciones[i].codigo, arrInfracciones[j].codigo) < 0) {
                intercambiar_struct_infracciones(arrInfracciones[i],arrInfracciones[j]);
            }
        }
    }
}





// Módulo que intercambia datos de estructura de tipo "EmpresasRegistradas".
void intercambiar_struct_empresas(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2) {
    struct EmpresasRegistradas aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}






// Módulo que ordena de forma ascendente por el distrito y, en caso de igualdad,
// de forma descendente por el códgio de infracción para el arreglo de empresas.
void ordenar_empresas(struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    for(int i=0; i<cantEmpresas-1; i++) {
        for(int j=i+1; j<cantEmpresas; j++) {
            if(strcmp(arrEmpresas[i].distrito, arrEmpresas[j].distrito) > 0  or
                      strcmp(arrEmpresas[i].distrito, arrEmpresas[j].distrito) == 0 and
                             arrEmpresas[i].fechaDeInfraccion.fecha < arrEmpresas[j].fechaDeInfraccion.fecha) {
                intercambiar_struct_empresas(arrEmpresas[i], arrEmpresas[j]);
            }
        }
    }
}







// Módulo que lee los datos de una infracción cometida del archivo "InfraccionesCometidas.csv".
void leer_una_infraccion_cometida(struct Fecha &fechaInfraccion, char *&placa_leida,
                                  char *&cod_infraccion_leida, struct Fecha &fechaDePago, ifstream &input) {
    char caracter_de_pago;
    fechaInfraccion = leer_fecha(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    input.get(); // Lectura de la coma.
    placa_leida = leer_cadena(input, ',', false);
    cod_infraccion_leida = leer_cadena(input, ',', false);
    caracter_de_pago = leer_char(input);
    if(caracter_de_pago == 'P') {
        fechaDePago = leer_fecha(input);
    } else {
        fechaDePago.fecha = fechaDePago.dd = fechaDePago.mm = fechaDePago.aa = 0;
    }
}








// Módulo que verifica si existe la placa buscada en el arreglo de placas.
bool existe_placa(char *placa_buscada, char **arrPlacas, int num_placas) {
    for(int indice = 0; indice < num_placas; indice++) {
        if(strcmp(arrPlacas[indice], placa_buscada) == 0) {
            return true;
        }
    }
    return false;
}










// Módulo que busca una placa mediante el arreglo de estructuras de tipo "EmpresasRegistradas".
int buscar_placa(char *placa_buscada, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    for(int indice = 0; indice < cantEmpresas; indice++) {
        if(existe_placa(placa_buscada, arrEmpresas[indice].placas, arrEmpresas[indice].numPlacas)) {
            // La placa existe en esa empresa.
            return indice; // Retornar el índice.
        }
    }
    return NO_ENCONTRADO;
}










// Módulo que busca una infracción mediante el arreglo de estructuyras de tipo "TablaDeInfracciones".
int buscar_infraccion(char *cod_infraccion_leida, struct TablaDeInfracciones *arrInfracciones, int cantInfracciones) {
    for(int indice = 0; indice < cantInfracciones; indice++) {
        if(strcmp(arrInfracciones[indice].codigo, cod_infraccion_leida) == 0) {
            return indice;
        }
    }
    return NO_ENCONTRADO;
}








// Módulo que asigna la multa correspondiente de un código de infracción leído mediante el arreglo de estructuras de infracciones.
double asignar_multa(char *cod_infraccion_leida, struct TablaDeInfracciones *arrInfracciones, int cantInfracciones) {
    int indice_infraccion;
    indice_infraccion = buscar_infraccion(cod_infraccion_leida, arrInfracciones, cantInfracciones);
    if(indice_infraccion != NO_ENCONTRADO) {
        return arrInfracciones[indice_infraccion].multa;
    } else {
        return 0.0;
    }
}







// Módulo que actualiza los datos de una empresa.
void actualizar_datos_de_una_empresa(struct EmpresasRegistradas &una_empresa, struct Fecha fechaInfraccion,
                                     struct Fecha fechaDePago, double multa) {
    if(una_empresa.fechaDeInfraccion.fecha > fechaInfraccion.fecha) {
        // Actualizar la fecha de infracción más antigua.
        una_empresa.fechaDeInfraccion = fechaInfraccion;
    }
    
    if(una_empresa.fechaDePago.fecha < fechaDePago.fecha) {
        // Actualizar la fecha de pago más reciente.
        una_empresa.fechaDePago = fechaDePago;
    }
    
    una_empresa.totalDeMultas += multa;
    una_empresa.totalPagado += (fechaDePago.fecha > 0 ? multa : 0.0);
    una_empresa.totalAdeudado += (fechaDePago.fecha == 0 ? multa : 0.0);
    una_empresa.cantidadDeFaltas++;
}









// Módulo que procesa el archivo "InfraccionesCometidas.csv" y que junto con el arreglo de infracciones se
// actualizan los datos del arreglo de empresas registradas.
void procesar_infracciones_cometidas(const char *nombre_archivo, struct TablaDeInfracciones *arrInfracciones,
                                     int cantInfracciones, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    struct Fecha fechaInfraccion, fechaDePago;
    char *placa_leida, *cod_infraccion_leida;
    double multa;
    int indice_empresa;
    while(true) {
        leer_una_infraccion_cometida(fechaInfraccion, placa_leida, cod_infraccion_leida, fechaDePago, input);
        if(input.eof()) break; // Valdiar fin del archivo "InfraccionesCometidas.csv".
        indice_empresa = buscar_placa(placa_leida, arrEmpresas, cantEmpresas);
        if(indice_empresa != NO_ENCONTRADO) {
            multa = asignar_multa(cod_infraccion_leida, arrInfracciones, cantInfracciones);
            actualizar_datos_de_una_empresa(arrEmpresas[indice_empresa], fechaInfraccion, fechaDePago, multa);
        }
    }
}










// Módulo que busca un DNI mediante el arreglo de estrcuturas de tipo "EmpresasRegistradas".
int buscar_dni(int dni_buscado, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    for(int indice = 0; indice < cantEmpresas; indice++) {
        if(arrEmpresas[indice].dni == dni_buscado) {
            return indice;
        }
    }
    return NO_ENCONTRADO;
}









// Módulo que procesa el archivo "PlacasRegistradas.txt" y almacena las placa a las distintas empresas
// que existen en el arreglo de estructuras de tipo "EmpresasRegistradas".
void procesar_placas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresas, int cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni_leido, indice_empresa;
    char *placa;
    while(true) {
        dni_leido = leer_int(input);
        if(input.eof()) break; // Validar fin del archivo "PlacasRegistradas.txt".
        placa = leer_cadena(input, '\n', true);
        
        indice_empresa = buscar_dni(dni_leido, arrEmpresas, cantEmpresas);
        
        if(indice_empresa != NO_ENCONTRADO) {
            // El DNI leído sí existe en el arreglo de estrcuturas de tipo "EmpresasRegistradas".
            // Se procede a insertar la placa en el arreglo de placas para esa empresa.
            int indice_placa = arrEmpresas[indice_empresa].numPlacas;
            arrEmpresas[indice_empresa].placas[indice_placa] = asignar_cadena(placa);
            arrEmpresas[indice_empresa].numPlacas++;
        }
    }
}









// Módulo que pasa las letras de una cadena de caracteres a mayúsculas.
void todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'  and  cadena[indice] <= 'z') {
//            cadena[indice] -= 'a' - 'A';
            cadena[indice] -= 32; // 32 es la diferencia del código ASCCI entre 'a' y 'A'.
        }
    }
}







// Módulo que incializa valores de una fecha.
void inicializar_struct_fecha(struct Fecha &fecha, bool es_de_pago) {
    if(es_de_pago) {
        fecha.fecha = fecha.dd = fecha.mm = fecha.aa = 0;
    } else {
        fecha.fecha = 99999999;
        fecha.dd = 99;
        fecha.mm = 99;
        fecha.aa = 99;
    }
}








// Módulo que lee una empresa registrada del archivo "EmpresasRegistradas.csv".
void leer_una_empresa_registrada(struct EmpresasRegistradas &una_empresa, ifstream &input) {
    int dni;
    dni = leer_int(input);
    if(input.eof()) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    una_empresa.dni = dni;
    input.get(); // Lectura de la coma.
    una_empresa.nombre = leer_cadena(input, ',', false);
    todo_a_mayusculas(una_empresa.nombre);
    una_empresa.distrito = leer_cadena(input, '\n', false);
    todo_a_mayusculas(una_empresa.distrito);
    
    // Inicializar los campos restantes de la estructura "EmpresasRegistradas".
    inicializar_struct_fecha(una_empresa.fechaDeInfraccion, false);
    inicializar_struct_fecha(una_empresa.fechaDePago, true);
    una_empresa.totalDeMultas = una_empresa.totalPagado = una_empresa.totalAdeudado = 0.0;
    una_empresa.numPlacas = una_empresa.cantidadDeFaltas = 0;
}










// Módulo que procesa el archivo "EmpresasRegistradas.csv" y almacena la información
// que se lee en un arreglo de estructuras de tipo "EmpresasRegistradas".
void procesar_empresas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *&arrEmpresas, int &cantEmpresas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    arrEmpresas = new struct EmpresasRegistradas[MAX_CANT_EMPRESAS]; // Asignar memoria al arreglo.
    cantEmpresas = 0; // Inicializar el contador del arreglo de empresas.
    while(true) {
        leer_una_empresa_registrada(arrEmpresas[cantEmpresas], input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.csv".
        cantEmpresas++;
    }
}








// Módulo que lee una infracción del archivo "TablaDeInfracciones.csv".
void leer_una_infraccion_de_la_tabla_de_infracciones(struct TablaDeInfracciones &una_infraccion, ifstream &input) {
    char *codigo_infraccion;
    codigo_infraccion = leer_cadena(input, ',', false);
    if(codigo_infraccion == nullptr) return; // No hay más datos a leer en el archivo. Salir de este módulo.
    una_infraccion.codigo = asignar_cadena(codigo_infraccion);
    una_infraccion.multa = leer_double(input);
    una_infraccion.descripcion = leer_cadena(input, '\n', false);
    todo_a_mayusculas(una_infraccion.descripcion);
}












// Módulo que procesa el archivo "TablaDeInfracciones.csv" y almacena la información
// que se lee en un arreglo de estructuras de tipo "TablaDeInfracciones".
void procesar_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *&arrInfracciones, int &cantInfracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    arrInfracciones = new struct TablaDeInfracciones[MAX_CANT_INFRACCIONES]; // Asignar memoria al arreglo.
    cantInfracciones = 0; // Inicializar el contador del arreglo de infracciones.
    
    while(true) {
        leer_una_infraccion_de_la_tabla_de_infracciones(arrInfracciones[cantInfracciones], input);
        if(input.eof()) break; // Validar fin del archivo "TablaDeInfracciones.csv".
        cantInfracciones++;
    }
}




