

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de junio del 2025, 10:45 AM
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


// Módulo que lee una fecha del tipo DD/MM/AAAA y lo
// retorna como un valor entero
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


// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output) {
    for(int i=0; i<cant_caracteres; i++) output.put(caracter);
    output << endl;
}


// Módulo que imprime una fecha de la forma DD/MM/AAAA
void imprimir_fecha(int fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha % 100 << '/';
    output << setw(2) << fecha / 100 % 100 << '/';
    output << fecha / 10000 << setfill(' ');
}



// Módulo que imprime el título del reporte de prueba
// y el título del reporte solicitado
void imprimir_titulo(bool es_de_prueba, ofstream &output) {
    if(es_de_prueba) {
        output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
        output << "VERIFICACION DE DATOS DE INFRACCION" << endl;
    } else {
        output << setw((TAM_REPORTE_SOLICITADO + TAM_TITULO_1) / 2);
        output << "MINISTERIO DE TRANSPORTES" << endl;
        output << setw((TAM_REPORTE_SOLICITADO + TAM_TITULO_2) / 2);
        output << "LISTADO DE INFRACCIONES" << endl;
        elaborar_lineas('=', TAM_REPORTE_SOLICITADO, output);
    }
}



// Módulo que realiza una búsqueda binaria en un arreglo ordenado ascendentemente.
// Si encuentra el dato, retorna "true" y devuelve el índice donde se encuentra.
// Si no lo encuentra, retorna "false" y devuelve en "indice_buscado" el índice donde se debe insertar el nuevo dato.
bool busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos, int &indice_buscado) {
    int lim_inferior = 0, lim_superior = cant_datos - 1, punto_medio;
    while(true) {
        if(lim_inferior > lim_superior) {
            // Los límites se cruzan, el dato no está en el arreglo.
            
            // Se devuelve el índice donde se debe insertar el nuevo dato para mantener el orden.
            indice_buscado = lim_inferior;
            // Retornar  "false"  ya que no se encontró el dato.
            return false;
        }
        
        punto_medio = (lim_inferior + lim_superior) / 2;   // Calcula el punto medio entre los límites actuales.
        
        // Si se encuentra el dato en el punto medio.
        if(arreglo[punto_medio] == dato_buscado) {
            indice_buscado = punto_medio;  // Se guarda la posición donde se encontró el dato.
            return true;  // Retorna true indicando que el dato fue hallado.
        }
        
        if(arreglo[punto_medio] < dato_buscado) {
            // El dato buscado es mayor, se descarta la mitad inferior.
            lim_inferior = punto_medio + 1;
        } else {
            // El dato buscado es menor, se descarta la mitad superior
            lim_superior = punto_medio - 1;
        }
    }
}




// Módulo que imprime el encabezado del reporte solicitado
void imprimir_encabezado_del_reporte_solicitado(ofstream &output) {
    output << setw(4 * (TAM_REPORTE_SOLICITADO / (N_COLUMNAS - 1)) + 2);
    output << "MULTA MAS";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2) + 2);
    output << "ULTIMA MULTA";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2));
    output << "TOTAL EN";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2) - 2);
    output << "MULTAS";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2) - 1);
    output << "MULTAS" << endl;
    
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 4) - 5);
    output << "No.";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 4) - 5);
    output << "DNI";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2) - 1);
    output << "PLACAS";
    output << setw(3 * (TAM_REPORTE_SOLICITADO / (N_COLUMNAS - 1)) - 4);
    output << "ANTIGUA";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2));
    output << "PAGADA";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2) + 2);
    output << "MULTAS";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2));
    output << "PAGADAS";
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 2));
    output << "PENDIENTES" << endl;
}





// Módulo que cuenta cuántas placas hay en la lista.
// Las placas están separadas por el carácter '/'.
// Ejemplo: "M466-711/P325-365"  ->  2 placas
int contar_placas(const char *listaDePlacas) {
    
    // Si la cadena está vacía, no hay ninguna placa
    if(listaDePlacas[0] == '\0') return 0;
    
    int cant_placas = 1; // Se asume al menos una placa, porque la
                         // cadena de lista de placas no está vacía
    
    // Recorre la cadena para contar los separadores ('/'), de este modo se cuenta
    // la cantidad de placas que hay en la lista de placas
    for(int indice=0; listaDePlacas[indice]; indice++) {
        if(listaDePlacas[indice] == '/') cant_placas++;
    }
    
    return cant_placas;
}




// Copia los caracteres de una placa específica desde la lista de placas, usando índices.
// "indice_inicial"  e  "indice_final"  definen el rango (sin incluir el final).
void copiar_placa_de_la_lista_de_placas(const char *listaDePlacas, int indice_inicial, int indice_final, char *placa) {
    int indice_placa = 0, indice_lista_placas = indice_inicial;
    indice_placa = 0;    // Índice para construir la placa
    indice_lista_placas = indice_inicial;    // Índice de recorrido de la lista
    
    // Copia caracter por caracter desde la lista original al arreglo placa
    while(indice_lista_placas <= indice_final) {
        placa[indice_placa] = listaDePlacas[indice_lista_placas];
        indice_placa++;
        indice_lista_placas++;
    }
    
    // Cierra la cadena resultante con el carácter nulo
    placa[indice_placa] = '\0';
}





// Módulo que extrae la placa número "n" desde la cadena "listaDePlacas".
// Asume que cada placa ocupa exactamente "MAX_CARACTERES_PLACA" espacios (formato fijo).
void obtenerPlaca(const char *listaDePlacas, int n, char *placa) {
    int cant_placas;
    
    // Contar cuántas placas hay en la lista de placas
    cant_placas = contar_placas(listaDePlacas);
    
    // Verificar que la posición solicitada de placa "n" (la enésima placa) sea válida
    if ( n >= 1  and  n <= cant_placas ) {
        copiar_placa_de_la_lista_de_placas(listaDePlacas, (n-1)*MAX_CARACTERES_PLACA,
                                           n*MAX_CARACTERES_PLACA - 2, placa);
    }
}





// Módulo que agrega una nueva placa a la lista de placas si esta aún no ha sido registrada.
// Las placas están separadas por un delimitador (en este caso "/") dentro de una sola cadena.
void agregarPlaca(char *listaDePlacas, const char *placa) {
    int cant_placas;
    bool existe_placa = false;
    char placa_extraida[MAX_CARACTERES_PLACA];
    
    // Cuenta cuántas placas hay actualmente en la lista
    cant_placas = contar_placas(listaDePlacas);
    
    
    // Recorre todas las placas existentes en la lista de placas
    for(int n_placa = 1; n_placa <= cant_placas; n_placa++) {
        // Extrae la placa número  "n_placa"  desde la lista de placas y la guarda en "placa_extraida"
        obtenerPlaca(listaDePlacas, n_placa, placa_extraida);
        
        // Compara la nueva placa con la placa extraída
        if( comparar_cadenas(placa, placa_extraida) == 0) {
            // Si son iguales, ya existe en la lista de placas
            existe_placa = true;
            break;
        }
    }
    
    
    // Si la placa no estaba registrada, se concatena a la lista con el delimitador "/"
    if(not existe_placa) {
        concatenar_cadena(listaDePlacas, "/");
        concatenar_cadena(listaDePlacas, placa);
    }
}







// Módulo que obtiene todas las placas asociadas a un DNI desde el archivo "PlacasRegistradas.txt".
// Las placas se almacenan en una cadena separadas por un slash '/'.
void obtener_lista_de_placas(int dni, char *listaDePlacas, ifstream &input) {
    input.clear();
    input.seekg(0, ios::beg);
    int dni_leido;
    char placa[MAX_CARACTERES_PLACA];
    bool primera_placa = true;
    
    // Bucle para leer todo el archivo "PlacasRegistradas.txt" línea por línea
    while(true) {
        dni_leido = leer_dato_int(input);
        if(input.eof()) break; // Validar el fin del archivo "PlacasRegistradas.txt"
        input >> placa;
        if(dni_leido == dni) {
            // El DNI leído coincide con el DNI que se envió como argumento a este módulo
            if (not primera_placa) {
                // Si ya hay una placa previa registrada, se agrega esta nueva a la cadena
                agregarPlaca(listaDePlacas, placa);
            } else {
                // Si es la primera placa encontrada, se copia directamente
                copiar_cadena(listaDePlacas, placa);
                primera_placa = false;
            }
        }
    }
}






// Módulo que imprime los datos de un representante legal en una línea del reporte.
// Incluye su número de orden, DNI, lista de placas asociadas, fechas de infracciones,
// y totales de multas.
void imprimir_un_juego_de_datos_de_un_representante_legal(int n_representante, int dni,
                        int fecha_masMultaAntigua, int fecha_ultimaPendiente, double totalMultas,
                        double totalPagadas, double totalPendientes, ifstream &input, ofstream &output) {
    char listaDePlacas[MAX_CARACTERES_DE_LISTA_PLACAS];
    output << setw(2) << ' ' << setw(2) << n_representante << ')' << setw(2) << ' ';
    
    // Imprimir el DNI alineado a la izquierda, con ancho proporcional al ancho total del reporte
    output << left << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 4) + 1) << dni;
    
    // Obtiener la lista de placas relacionadas al DNI y las guarda en listaDePlacas; posterior a ello, imprime la lista
    obtener_lista_de_placas(dni, listaDePlacas, input);
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS - 5) + 8) << listaDePlacas << right;
    
    // Imprimir la fecha de la multa más antigua
    imprimir_fecha(fecha_masMultaAntigua, output);
    output << setw(4) << ' ';
    
    if(fecha_ultimaPendiente == 0) {
        // Si no hay multa pendiente, muestra un mensaje
        output << "NO HAY REGISTRO";
    } else {
        // Si hay una multa pendiente, imprime la fecha correspondiente
        imprimir_fecha(fecha_ultimaPendiente, output);
        output << setw(5) << ' ';
    }
    
    // Imprime los totales de multas, pagadas y pendientes con alineación apropiada
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 6)) << totalMultas;
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 6) + 3) << totalPagadas;
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 6) + 3) << totalPendientes;
    output << endl;
}







// Módulo que imprime un listado de infracciones de varios representantes legales,
// acumulando además los totales generales de multas.
void imprimir_listado_de_infracciones(double &total_de_total_multas, double &total_de_multas_pagadas,
                    double &total_de_multas_pendientes, int *arrDni, int *arrMasMultaAntigua,
                    int *arrUltimaPendiente, double *arrTotalMultas, double *arrTotalPagadas,
                    double *arrTotalPendientes, int cant_representantes, ofstream &output, ifstream &input) {
    elaborar_lineas('=', TAM_REPORTE_SOLICITADO, output);
    
    // Recorrer todos los representantes legales
    for(int indice = 0; indice < cant_representantes; indice++) {
        // Imprimir los datos detallados de un representante legal
        imprimir_un_juego_de_datos_de_un_representante_legal(indice + 1, arrDni[indice],
                                arrMasMultaAntigua[indice], arrUltimaPendiente[indice], arrTotalMultas[indice],
                                arrTotalPagadas[indice], arrTotalPendientes[indice], input, output);
        
        // Acumular los totales generales con los valores del representante actual
        total_de_total_multas += arrTotalMultas[indice];
        total_de_multas_pagadas += arrTotalPagadas[indice];
        total_de_multas_pendientes += arrTotalPendientes[indice];
    }
}




// Módulo que imprime los totales generales de multas al final del reporte.
// Incluye el total global, total de multas pagadas y total de multas pendientes.
void imprimir_totales_del_listado_de_infracciones(double total_de_total_multas,
                double total_de_multas_pagadas, double total_de_multas_pendientes, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE_SOLICITADO, output);
    output << setw(2) << ' ' << "TOTALES:";
    output << setw( 3 * (TAM_REPORTE_SOLICITADO / (N_COLUMNAS - 4)) - 3);
    output << total_de_total_multas;
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 6) + 3);
    output << total_de_multas_pagadas;
    output << setw(TAM_REPORTE_SOLICITADO / (N_COLUMNAS + 6) + 3);
    output << total_de_multas_pendientes;
    output << endl;
    elaborar_lineas('=', TAM_REPORTE_SOLICITADO, output);
}




// Módulo que genera el reporte llamado "ReporteDeMultas.txt". Mediante el archivo "PlacasRegistradas.txt"
// se realiza un lista de placas por cada representante legal.
void emitir_reporte(const char *nombre_archivo_reporte, int *arrDni, int *arrMasMultaAntigua,
                    int *arrUltimaPendiente, double *arrTotalMultas, double *arrTotalPagadas,
                    double *arrTotalPendientes, int cant_representantes,
                    const char *nombre_archivo_placas_registradas) {
    double total_de_total_multas = 0.0, total_de_multas_pagadas = 0.0, total_de_multas_pendientes = 0.0;
    ifstream input;
    ofstream output;
    
    // Apertura de los archivos
    aperturar_archivo_lectura(nombre_archivo_placas_registradas, input);
    aperturar_archivo_escritura(nombre_archivo_reporte, output);
    
    // Formato numérico fijo con 2 decimales para los montos
    output << fixed << setprecision(2);
    
    // Imprimir título del reporte solicitado
    imprimir_titulo(false, output);
    
    // Imprimir el encabezado de columnas del reporte solicitado
    imprimir_encabezado_del_reporte_solicitado(output);
    
    // Imprimir el listado de infracciones por representante legal acumulando también los totales generales.
    imprimir_listado_de_infracciones(total_de_total_multas, total_de_multas_pagadas,
                total_de_multas_pendientes, arrDni, arrMasMultaAntigua, arrUltimaPendiente, 
                arrTotalMultas, arrTotalPagadas, arrTotalPendientes, cant_representantes, output, input);
    
    // Imprimir el resumen de totales generales al final del reporte
    imprimir_totales_del_listado_de_infracciones(total_de_total_multas, total_de_multas_pagadas,
                                                 total_de_multas_pendientes, output);
}





// Módulo que lee una infracción cometida si es que se pudo leer toda la información de una infracción cometida
bool leer_una_infraccion_cometida(ifstream &input, int &fecha_infraccion, char *placa, int &dni,
                                  int &cod_infraccion, int &fecha_pago) {
    fecha_infraccion = leer_fecha(input);
    if(input.eof()) return false; // Retorna "false" porque se llegó al fin del archivo "InfraccionesCometidas.txt"
    input >> placa;
    dni = leer_dato_int(input);
    cod_infraccion = leer_dato_int(input);
    
    if(input.get() != '\n') {
        // Se ha pagado la infracción
        char se_ha_pagado = leer_dato_char(input);
        fecha_pago = leer_fecha(input);
    } else {
        // No se ha pagado la infracción
        fecha_pago = 0;
    }
    
    return true; // Retorna "true" porque se pudo leer una infracción cometida
}




// Módulo que desplaza los valores de los arreglos paralelos una posición hacia la derecha
// a partir del índice donde se insertará un nuevo representante legal.Esto se hace para mantener
// el arreglo ordenado después de una búsqueda binaria.
void desplazar_valores_en_los_arreglos(int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                                double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                                int &cant_representantes, int ind_buscado) {
    for(int indice = cant_representantes; indice > ind_buscado; --indice) {
        arrDni[indice] = arrDni[indice - 1];
        arrMasMultaAntigua[indice] = arrMasMultaAntigua[indice - 1];
        arrUltimaPendiente[indice] = arrUltimaPendiente[indice - 1];
        arrTotalMultas[indice] = arrTotalMultas[indice - 1];
        arrTotalPagadas[indice] = arrTotalPagadas[indice - 1];
        arrTotalPendientes[indice] = arrTotalPendientes[indice - 1];
    }
}





// Módulo que inserta un nuevo representante legal en los arreglos o acumula su información si ya existe.
// Se utiliza la búsqueda binaria para verificar si el DNI ya está presente en el arreglo ordenado.
void insertar_o_acumular_representante_legal(int fecha_infraccion, int dni, int cod_infraccion,
                            int fecha_pago, int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                            double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                            int &cant_representantes, double valor_multa) {
    int ind_buscado;
    if ( busqueda_binaria(dni, arrDni, cant_representantes, ind_buscado) ) {
        // Se actualiza la fecha de la multa más antigua si corresponde
        if(arrMasMultaAntigua[ind_buscado] > fecha_infraccion) arrMasMultaAntigua[ind_buscado] = fecha_infraccion;
        
        // Se actualiza la fecha de la última multa pendiente (si es posterior)
        if(arrUltimaPendiente[ind_buscado] < fecha_pago) arrUltimaPendiente[ind_buscado] = fecha_pago;
        
        // Se acumulan los valores de multa
        arrTotalMultas[ind_buscado] += valor_multa;
        arrTotalPagadas[ind_buscado] += (fecha_pago > 0 ? valor_multa : 0.0);
        arrTotalPendientes[ind_buscado] += valor_multa - (fecha_pago > 0 ? valor_multa : 0.0);
    } else {
        // Es un nuevo DNI de representante legal, entonces se inserta en la posición correcta en los arreglos
        desplazar_valores_en_los_arreglos(arrDni, arrMasMultaAntigua, arrUltimaPendiente, arrTotalMultas,
                                          arrTotalPagadas, arrTotalPendientes, cant_representantes, ind_buscado);
        
        // Se registra la información del nuevo representante legal
        arrDni[ind_buscado] = dni;
        arrMasMultaAntigua[ind_buscado] = fecha_infraccion;
        arrUltimaPendiente[ind_buscado] = fecha_pago;
        arrTotalMultas[ind_buscado] = valor_multa;
        arrTotalPagadas[ind_buscado] = (fecha_pago > 0 ? valor_multa : 0.0);
        arrTotalPendientes[ind_buscado] = valor_multa - (fecha_pago > 0 ? valor_multa : 0.0);
        cant_representantes++;
    }
}





// Módulo que lee las infracciones cometidas desde el archivo "InfraccionesCometidas.txt".
// Registra y acumula información por representante legal, y guarda la relación
// DNI con placa en el archivo "PlacasRegistradas.txt".
void leer_infracciones_cometidas(const char *nombre_archivo_infracciones_cometidas,
                                 int *arrCodInfraccion, double *arrMultasInfraccion, int cant_infracciones,
                                 int *arrDni, int *arrMasMultaAntigua, int *arrUltimaPendiente,
                                 double *arrTotalMultas, double *arrTotalPagadas, double *arrTotalPendientes,
                                 int &cant_representantes, const char *nombre_archivo_placas_registradas) {
    ifstream input;
    ofstream output;
    aperturar_archivo_lectura(nombre_archivo_infracciones_cometidas, input);
    aperturar_archivo_escritura(nombre_archivo_placas_registradas, output);
    int fecha_infraccion, dni, cod_infraccion, fecha_pago, indice_infraccion;
    double valor_multa;
    char placa[MAX_CARACTERES_PLACA];
    cant_representantes = 0; // Inicializar el contador de representantes
    while(true) {
        // Leer una infracción cometida, si retorna "false" es porque llegó al final del archivo "InfraccionesCometidas.txt"
        if ( not  leer_una_infraccion_cometida(input, fecha_infraccion, placa, dni, cod_infraccion, fecha_pago) ) break;
        
        // Buscar el código de infracción para obtener el valor de la multa
        if( busqueda_binaria(cod_infraccion, arrCodInfraccion, cant_infracciones, indice_infraccion) ) {
            valor_multa = arrMultasInfraccion[indice_infraccion];
        }
        else valor_multa = 0.0; // Si el código de infracción no existe, la multa es cero
        
        // Registrar o acumular los datos del representante legal de la infracción
        insertar_o_acumular_representante_legal(fecha_infraccion, dni, cod_infraccion, fecha_pago, arrDni,
                                                arrMasMultaAntigua, arrUltimaPendiente, arrTotalMultas, arrTotalPagadas,
                                                arrTotalPendientes, cant_representantes, valor_multa);
        
        // Escribir el DNI y placa en el archivo "PlacasRegistradas.txt"
        output << dni << setw(4) << ' ' << placa << endl;
    }
}





// Módulo que elabora el encabezado del reporte de prueba
void imprimir_encabezado_de_reporte_de_prueba(ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 7);
    output << "COD.INFRACCION";
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) + 4);
    output << "VALOR DE LA MULTA";
    output << endl;
    elaborar_lineas('-', TAM_REPORTE_PRUEBA, output);
}





// Módulo que genera un reporte de prueba llamado "PruebaTablaInf.txt" con los códigos de infracción
// y sus respectivas multas. Este reporte sirve para verificar si los valores han sido correctamente
// asignados a los arreglos "arrCodInfraccion" y "arrMultasInfraccion" luego de la lectura de datos.
void verificar_datos_de_infracciones(const char *nombre_archivo, int *arrCodInfraccion,
                                     double *arrMultasInfraccion, int &cant_infracciones) {
    ofstream output;
    
    // Aperturar el archivo de salida donde se guardará el reporte de prueba
    aperturar_archivo_escritura(nombre_archivo, output);
    
    // Configurar el formato de salida para mostrar decimales con dos cifras
    output << fixed << setprecision(2);
    
    // Imprimir el título del reporte de prueba
    imprimir_titulo(true, output);
    
    // // Imprimir los encabezados de las columnas del reporte de prueba
    imprimir_encabezado_de_reporte_de_prueba(output);
    
    // Recorrer todos los códigos de infracción y sus valores de multa
    for(int indice = 0; indice < cant_infracciones; indice++) {
        // Imprimir el código de infracción con formato y alineación
        output << setw(TAM_REPORTE_PRUEBA / ((N_COLUMNAS - 6) + 3) + 2);
        output << arrCodInfraccion[indice];
        
        // Imprimir el valor de la multa correspondiente al código anterior
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) + 5);
        output << arrMultasInfraccion[indice] << endl;
    }
    
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
}






// Módulo que inserta un nuevo código de infracción y su multa correspondiente 
// en los arreglos respectivos, manteniéndolos ordenados de forma ascendente por código de infracción.
void insertar_ascendentemente_por_codigo_de_infraccion(int cod_infraccion, double valor_multa,
                                int *arrCodInfraccion, double *arrMultasInfraccion, int &cant_infracciones) {
    int indice;
    
    // Recorrer el arreglo de atrás hacia adelante buscando la posición correcta
    // donde insertar el nuevo código, desplazando hacia la derecha los elementos mayores.
    for(indice = cant_infracciones - 1; indice >= 0  and  arrCodInfraccion[indice] > cod_infraccion; indice--) {
        arrCodInfraccion[indice + 1] = arrCodInfraccion[indice];
        arrMultasInfraccion[indice + 1] = arrMultasInfraccion[indice];
    }
    
    // Insertar el nuevo código y su valor de multa en la posición encontrada.
    arrCodInfraccion[indice + 1] = cod_infraccion;
    arrMultasInfraccion[indice + 1] = valor_multa;
    
    // Incrementar la cantidad total de infracciones registradas.
    cant_infracciones++;
}





// Módulo que lee el archivo "TablaDeInfracciones.txt" y almacena los códigos 
// de infracción y los valores de multa en arreglos ordenados ascendentemente.
void leer_tabla_de_infracciones(const char *nombre_archivo, int *arrCodInfraccion,
                                double *arrMultasInfraccion, int &cant_infracciones) {
    ifstream input;
    
    aperturar_archivo_lectura(nombre_archivo, input);
    int cod_infraccion;
    double valor_multa;
    cant_infracciones = 0;
    while(true){
        cod_infraccion = leer_dato_int(input);  // Leer el código de infracción
        if(input.eof()) break;   // Validar fin de archivo "TablaDeInfracciones.txt"
        valor_multa = leer_dato_double(input);  // Leer el valor de la multa
        
        // Ignorar el resto de la línea (la descripción de la infracción)
        while(input.get() != '\n');
        
        // Insertar el código y el valor de multa en su posición correspondiente
        insertar_ascendentemente_por_codigo_de_infraccion(cod_infraccion,
                      valor_multa, arrCodInfraccion, arrMultasInfraccion,
                      cant_infracciones);
    }
}


