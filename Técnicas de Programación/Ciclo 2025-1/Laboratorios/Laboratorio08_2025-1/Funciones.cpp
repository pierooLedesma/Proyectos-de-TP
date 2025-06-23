

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 20 de junio del 2025, 02:26 PM
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
    input.get(); // Lectura de la coma
    return dato;
}






// Módulo que lee un dato de tipo "char"
char leer_dato_char(ifstream &input) {
    char dato;
    input >> dato;
    return dato;
}





// Módulo que asigna una cadena con memoria exacta.
char* asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}






// Módulo que lee una cadena de caracteres y lo almacena con memoria exacta.
// Se puede leer la cadena de caracteres mediante el operador de lectura o con "getline()".
char* leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura) {
    char buffer[300], *cadena;
    if(leer_con_el_operador_de_lectura) {
        input >> buffer;
    } else {
        input.getline(buffer, 300, delimitador);
    }
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}






// Módulo que lee una fecha de la forma DD/MM/AAAA y
// lo retorna como un valor entero.
int leer_fecha(ifstream &input) {
    int dia, mes, anio;
    char slash;
    
    dia = leer_dato_int(input);
    slash = leer_dato_char(input);
    mes = leer_dato_int(input);
    slash = leer_dato_char(input);
    anio = leer_dato_int(input);
    
    return anio*10000 + mes*100 + dia;
}







// Módulo que retorna una estructura de tipo "fecha".
struct Fecha retornar_estructura_fecha(int fecha_dada_como_entero) {
    struct Fecha fecha;
    fecha.fecha = fecha_dada_como_entero;
    fecha.dd = fecha_dada_como_entero % 100;
    fecha.mm = fecha_dada_como_entero / 100 % 100;
    fecha.aa = fecha_dada_como_entero / 10000;
    return fecha;
}







// Módulo que imprime una fecha de la forma DD/MM/AAAA
void imprimir_fecha(struct Fecha fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha.dd << '/';
    output << setw(2) << fecha.mm << '/' << setfill(' ');
    output << fecha.aa;
}






// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output){
    for(int i=0; i<cantidad_caracteres; i++) output.put(caracter);
    output << endl;
}







// Módulo que imprime el título y el encabezado de infracciones en el reporte.
void imprimir_titulo_y_encabezado_de_infracciones(ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_INFRACCIONES) / 2);
    output << "TABLA DE INFRACCIONES" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "CODIGO";
    output << setw(TAM_REPORTE / N_COLUMNAS - 7) << "MULTA";
    output << setw(TAM_REPORTE / N_COLUMNAS) << "DESCRIPCION" << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}







// Módulo que imrpime los datos de un infracción en el reporte solicitado.
void imprimr_datos_de_una_infraccion(char *codigo_infraccion, double multa_infraccion,
                                     char *descripcion_infraccion, ofstream &output) {
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << codigo_infraccion;
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << multa_infraccion;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 3) << ' ';
    output << descripcion_infraccion << endl;
}







// Módulo que imprime la sección de infracciones en el reporte solicitado.
void imprimir_infracciones(const struct TablaDeInfracciones *arrTablaDeInfracciones,
                           int cantTablaInfracciones, ofstream &output) {
    imprimir_titulo_y_encabezado_de_infracciones(output);
    for(int indice = 0; indice < cantTablaInfracciones; indice++) {
        imprimr_datos_de_una_infraccion(arrTablaDeInfracciones[indice].codigo,
                                        arrTablaDeInfracciones[indice].multa,
                                        arrTablaDeInfracciones[indice].descripcion, output);
    }
    elaborar_lineas('=', TAM_REPORTE, output);
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






// Módulo que imprime los datos de todas las empresas del arreglo "arrEmpresasRegistradas".
void imprimir_empresas_registradas(struct EmpresasRegistradas *arrEmpresasRegistradas,
                                   int cantEmpresasRegistradas,ofstream &output) {
    double total_total_pagado = 0, total_total_adeudado = 0;
    int total_cantidad_de_faltas = 0;
    imprimir_titulo_y_encabezado_de_empresas(output);
    for(int indice = 0; indice < cantEmpresasRegistradas; indice++) {
        imprimir_datos_de_una_empresa(indice + 1, arrEmpresasRegistradas[indice], output);
        total_total_pagado += arrEmpresasRegistradas[indice].totalPagado;
        total_total_adeudado += arrEmpresasRegistradas[indice].totalAdeudado;
        total_cantidad_de_faltas += arrEmpresasRegistradas[indice].cantidadDeFaltas;
    }

    // Impresión de los totales (total pagado, total adeudado y total de cantidad de faltas) de todas las empresas..
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw(171) << "TOTALES:" << setw(15) << total_total_pagado;
    output << setw(14) << total_total_adeudado;
    output << setw(11) << total_cantidad_de_faltas << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}






// Módulo que imprime el reporte solicitado.
void emitir_reporte(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                    int cantEmpresasRegistradas, const struct TablaDeInfracciones *arrTablaDeInfracciones,
                    int cantTablaInfracciones) {
    double tota_total_pagado = 0, total_total_adeudado = 0;
    int total_cantidad_de_faltas = 0;
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_empresas_registradas(arrEmpresasRegistradas, cantEmpresasRegistradas, output);
    imprimir_infracciones(arrTablaDeInfracciones, cantTablaInfracciones, output);
}






// Módulo que intercambia los datos de estructura de tipo "TablaDeInfracciones".
void intercambiar_struct_infracciones(struct TablaDeInfracciones &dato_1, struct TablaDeInfracciones &dato_2) {
    struct TablaDeInfracciones auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}





// Módulo que ordena el arreglo de estructuras de tipo "TablaDeInfracciones"
// de forma descendente por el código de la infracción.
void ordenar_infracciones(struct TablaDeInfracciones *arrTablaDeInfracciones, int cantTablaInfracciones) {
    for(int a = 0;  a < cantTablaInfracciones - 1;  a++) {
        for(int b = a + 1;  b < cantTablaInfracciones;  b++) {
            if(strcmp(arrTablaDeInfracciones[a].codigo, arrTablaDeInfracciones[b].codigo) < 0) {
                intercambiar_struct_infracciones(arrTablaDeInfracciones[a], arrTablaDeInfracciones[b]);
            }
        }
    }
}





// Módulo que intercambia los datos de estructura de tipo "EmpresasRegistradas".
void intercambiar_empresas(struct EmpresasRegistradas &dato_1, struct EmpresasRegistradas &dato_2) {
    struct EmpresasRegistradas aux;
    aux = dato_1;
    dato_1 = dato_2;
    dato_2 = aux;
}






// Módulo que ordena el arreglo de estructuras de tipo "EmpresasRegistradas" de
// forma ascendente por el distrito y en caso de igualdad por la fecha de infracción.
void ordenar_empresas(struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas) {
    for(int i = 0; i < cantEmpresasRegistradas - 1; i++) {
        for(int k = i + 1;  k < cantEmpresasRegistradas; k++){
            if(strcmp(arrEmpresasRegistradas[i].distrito, arrEmpresasRegistradas[k].distrito) > 0  or 
               strcmp(arrEmpresasRegistradas[i].distrito, arrEmpresasRegistradas[k].distrito) == 0  and
               arrEmpresasRegistradas[i].fechaDeInfraccion.fecha < arrEmpresasRegistradas[k].fechaDeInfraccion.fecha) {
                intercambiar_empresas(arrEmpresasRegistradas[i], arrEmpresasRegistradas[k]);
            }
        }
    }
}







// Módulo que lee una infracción cometida del archivo "InfraccionesCometidas.csv".
void leer_una_infraccion_cometida(int &fecha_infraccion, char *&placa_leida,
                                  char *&cod_infraccion_leida, int &fecha_pagada, ifstream &input){
    char caracter_de_pago;
    fecha_infraccion = leer_fecha(input);
    if(input.eof()) return;
    input.get(); // Lectura de la coma
    placa_leida = leer_cadena(input, ',', false);
    cod_infraccion_leida = leer_cadena(input, ',', false);
    caracter_de_pago = leer_dato_char(input);
    if(caracter_de_pago == 'P') {
        input.get(); // Lectura de la coma
        fecha_pagada = leer_fecha(input);
    } else {
        fecha_pagada = 0;
    }
}








// Módulo que busca una infracción mediante un arreglo de estructuras de tipo "TablaDeInfracciones".
int buscar_infraccion(char *cod_infraccion_leida, struct TablaDeInfracciones *arrTablaDeInfracciones,
                      int cantTablaInfracciones) {
    for(int indice = 0;  indice < cantTablaInfracciones;  indice++){
        if(strcmp(arrTablaDeInfracciones[indice].codigo, cod_infraccion_leida) == 0){
            return indice;
        }
    }
    return NO_ENCONTRADO;
}







// Módulo que asigna un valor de multa mediante el arreglo de estructuras de tipo "TablaDeInfracciones".
double asignar_valor_multa(char *cod_infraccion_leida, struct TablaDeInfracciones *arrTablaDeInfracciones,
                           int cantTablaInfracciones) {
    int indice_infraccion;
    indice_infraccion = buscar_infraccion(cod_infraccion_leida, arrTablaDeInfracciones, cantTablaInfracciones);
    if(indice_infraccion != NO_ENCONTRADO){
        return arrTablaDeInfracciones[indice_infraccion].multa;
    } else {
        // No se encontró en el arreglo, entonces se le asigna el valor de cero.
        return 0.0;
    }
}






// Módulo que verifica si existe la placa leída mediante el arreglo de placas de una empresa.
bool existe_placa(char *placa_leida, char **arrPlacas, int numPlacas) {
    for(int i=0; i<numPlacas; i++){
        if(strcmp(placa_leida, arrPlacas[i]) == 0) return true; // Sí existe en el arreglo, entonces retorna "true".
    }
    return false;  // No existe la placa en el arreglo, entonces retorna "false".
}







// Módulo que busca una placa mediante el arreglo de estructuras de tipo "EmpresasRegistradas".
int buscar_placa_de_una_empresa(char *placa_leida, struct EmpresasRegistradas *arrEmpresasRegistradas,
                                int cantEmpresasRegistradas) {
    for(int indice = 0; indice < cantEmpresasRegistradas; indice++){
        if(existe_placa(placa_leida, arrEmpresasRegistradas[indice].placas, arrEmpresasRegistradas[indice].numPlacas)) {
            return indice; // Sí existe la placa en el arreglo, entocnes devuelve el índice.
        }
    }
    return NO_ENCONTRADO;
}







// Módulo que actualiza los campos restantes de la estructura "EmpresasRegistradas" de una empresa.
void actualizar_los_campos_restantes_de_una_empresa(struct Fecha &fechaDeInfraccion,
                            int fecha_infraccion,int fecha_pagada, struct Fecha &fechaDePago,
                            int &cantidadDeFaltas, double &totalPagado, double &totalAdeudado, double valor_multa) {
    if(fechaDeInfraccion.fecha > fecha_infraccion){
        // La fecha de infracción leída es la más antigua actualmente.
        fechaDeInfraccion = retornar_estructura_fecha(fecha_infraccion);
    }
    
    if(fechaDePago.fecha < fecha_pagada) {
        // La fecha pagada leída es la más reciente.
        fechaDePago = retornar_estructura_fecha(fecha_pagada);
    }
    
    totalPagado += (fecha_pagada > 0 ? valor_multa : 0.0);
    totalAdeudado += (fecha_pagada == 0 ? valor_multa : 0.0);
    cantidadDeFaltas++;
}








// Módulo que lee el archivo "InfraccionesCometidas.csv". Se actualizan los campos restantes de una estructura
// de tipo "EmpresasRegistradas" de cada empresa en el arreglo de empresas y también mediante la ayuda del
// arreglo de estructuras de tipo "TablaDeInfracciones" para asignar el valor de multa de una infracción cometida.
void leer_infracciones_cometidas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                                 int cantEmpresasRegistradas,struct TablaDeInfracciones *arrTablaDeInfracciones,
                                 int cantTablaInfracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int fecha_infraccion, fecha_pagada, indicePlacaDeUnaEmpresa;
    char *placa_leida, *cod_infraccion_leida;
    double valor_multa;
    while(true) {
        leer_una_infraccion_cometida(fecha_infraccion, placa_leida, cod_infraccion_leida, fecha_pagada, input);
        if(input.eof()) break; // Validar el fin del archivo "InfraccionesCometidas.csv"
        valor_multa = asignar_valor_multa(cod_infraccion_leida, arrTablaDeInfracciones, cantTablaInfracciones);
        indicePlacaDeUnaEmpresa = buscar_placa_de_una_empresa(placa_leida, arrEmpresasRegistradas, cantEmpresasRegistradas);
        if(indicePlacaDeUnaEmpresa != NO_ENCONTRADO) {
            actualizar_los_campos_restantes_de_una_empresa(arrEmpresasRegistradas[indicePlacaDeUnaEmpresa].fechaDeInfraccion,
                        fecha_infraccion, fecha_pagada, arrEmpresasRegistradas[indicePlacaDeUnaEmpresa].fechaDePago,
                        arrEmpresasRegistradas[indicePlacaDeUnaEmpresa].cantidadDeFaltas,
                        arrEmpresasRegistradas[indicePlacaDeUnaEmpresa].totalPagado,
                        arrEmpresasRegistradas[indicePlacaDeUnaEmpresa].totalAdeudado, valor_multa);
        }
    }
}









// Módulo que busca una empresa mediante el DNI leído en un arreglo de
// estructuras de tipo "EmpresasRegistradas"
int buscar_empresa(int dni_leido, struct EmpresasRegistradas *arrEmpresasRegistradas, int cantEmpresasRegistradas) {
    for(int indice = 0;  indice < cantEmpresasRegistradas; indice++){
        if(arrEmpresasRegistradas[indice].dni == dni_leido) return indice;
    }
    return NO_ENCONTRADO;
}







// Módulo que lee el archivo "PlacasRegistradas.txt" y almacena las placas
// en un arreglo de placas para cada empresa registrada del arreglo de
// estructuras de tipo "EmpresasRegistradas".
void leer_placas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                             int cantEmpresasRegistradas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int dni_leido, ind_empresa;
    char *placa;
    while(true) {
        dni_leido = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "PlacasRegistradas.txt"
        placa = leer_cadena(input, '\n', true);
        ind_empresa = buscar_empresa(dni_leido, arrEmpresasRegistradas, cantEmpresasRegistradas);
        if(ind_empresa != NO_ENCONTRADO) {
            int cant_placas = arrEmpresasRegistradas[ind_empresa].numPlacas;
            arrEmpresasRegistradas[ind_empresa].placas[cant_placas] = asignar_cadena(placa);
            arrEmpresasRegistradas[ind_empresa].numPlacas++;
        }
    }
}







// Módulo que pasa todas las letras de la cadena a mayúsculas.
void todo_a_mayuscula(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'  and  cadena[indice] <= 'z') {
//            cadena[indice] -= ('a' - 'A');
            cadena[indice] -= 32;
        }
    }
}







// Módulo que lee una empresa registrada del archivo "EmpresasRegistradas.csv".
// Asímismo, inicializa con valores por defecto los campos restantes.
void leer_una_empresa_registrada(struct EmpresasRegistradas &unaEmpresa, ifstream &input) {
    int dni;
    dni = leer_dato_int(input);
    if(input.eof()) return;// Se llegó al fin del archivo. Salir de este módulo.
    input.get(); // Lectura de la coma
    unaEmpresa.dni = dni;
    unaEmpresa.nombre = leer_cadena(input, ',', false);
    todo_a_mayuscula(unaEmpresa.nombre);
    unaEmpresa.distrito = leer_cadena(input, '\n', false);
    todo_a_mayuscula(unaEmpresa.distrito);
    
    // Inicializar los campos restantes con valores por defecto.
    unaEmpresa.numPlacas = 0;
    unaEmpresa.fechaDeInfraccion = retornar_estructura_fecha(99999999);
    unaEmpresa.fechaDePago = retornar_estructura_fecha(0);
    unaEmpresa.totalPagado = 0.0;
    unaEmpresa.totalAdeudado = 0.0;
    unaEmpresa.cantidadDeFaltas = 0;
}








// Módulo que lee el archivo "EmpresasRegistradas.csv" y lo almacena en un
// arreglo de estructuras de tipo "EmpresasRegistradas".
void leer_empresas_registradas(const char *nombre_archivo, struct EmpresasRegistradas *arrEmpresasRegistradas,
                               int &cantEmpresasRegistradas) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantEmpresasRegistradas = 0;
    while(true) {
        leer_una_empresa_registrada(arrEmpresasRegistradas[cantEmpresasRegistradas], input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.csv"
        cantEmpresasRegistradas++;
    }
}







// Módulo que lee una infraccion del archivo "TablaDeInfracciones.csv".
void leer_una_infraccion(struct TablaDeInfracciones &unaInfraccion, ifstream &input) {
    char* cod_infraccion;
    cod_infraccion = leer_cadena(input, ',', false);
    if(cod_infraccion == nullptr) return; // Se llegó al fin del archivo. Salir de este módulo.
    unaInfraccion.codigo = cod_infraccion;
    unaInfraccion.multa = leer_dato_double(input);
    unaInfraccion.descripcion = leer_cadena(input, '\n', false);
    todo_a_mayuscula(unaInfraccion.descripcion);
}








// Módulo que lee el archivo "TablaDeInfracciones.csv" y lo almacena en un
// arreglo de estructuras de tipo "TablaDeInfracciones".
void leer_tabla_de_infracciones(const char *nombre_archivo, struct TablaDeInfracciones *arrTablaDeInfracciones,
                                int &cantTablaInfracciones) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantTablaInfracciones = 0;
    while(true) {
        leer_una_infraccion(arrTablaDeInfracciones[cantTablaInfracciones], input);
        if(input.eof()) break; // Validar fin del archivo "TablaDeInfracciones.csv"
        cantTablaInfracciones++;
    }
}




