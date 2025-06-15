

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de junio del 2025, 12:55 PM
 */


#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
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



// Módulo que asigna memoria y copia una cadena estática (buffer)
// a una cadena dinámica (esta cadena es la que se retorna).
char* asignar_cadena(const char* buffer) {
    char* cadena_asignada;
    cadena_asignada = new char[strlen(buffer) + 1];
    strcpy(cadena_asignada, buffer);
    return cadena_asignada;
}



// Módulo que lee una cadena de caracteres y almacena esta cadena con memoria exacta.
char* leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura) {
    char buffer[200], *cadena;
    if (leer_con_el_operador_de_lectura) {
        input >> buffer;
    } else {
        input.getline(buffer, 100, delimitador);
    }
    if (input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}




// Módulo que elabora las líneas del reporte.
void elaborar_lineas(char caracter, int cantidad_caracteres, ofstream &output) {
    for (int i = 0; i < cantidad_caracteres; i++) output.put(caracter);
    output << endl;
}





// Módulo que imprime los títulos de los reportes de prueba como el título del reporte solicitado.
void imprimir_titulo(int opcion, ofstream &output) {
    switch (opcion) {
        case 1:
            elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
            output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA_1) / 2);
            output << "VERIFICAR DATOS DE PLATOS OFRECIDOS" << endl;
            break;
        case 2:
            elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
            output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA_2) / 2);
            output << "VERIFICAR DATOS DE LOS DISTRITOS" << endl;
            break;
        case 3:
            elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
            output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA_3) / 2);
            output << "VERIFICAR DATOS DE LOS CLIENTES" << endl;
            break;
        default:
            output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
            output << "EMPRESA DE REPARTOS A DOMICILIO TP S.  A." << endl;
            output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
            output << "RELACION DE PEDIDOS POR CLIENTE" << endl;
            elaborar_lineas('=', TAM_REPORTE, output);
    }
}






// Módulo que imprime los encabezados del reporte solicitado.
void imprimir_encabezados_del_reporte_solicitado(bool es_encabezado_cliente, ofstream &output) {
    if (es_encabezado_cliente) {
        output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 2) << "DNI";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 4) + 5) << "NOMBRE";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 4) + 2) << "DISTRITO";
        output << right << "PAGO TOTAL";
        output << endl;
    } else {
        output << setw(TAM_REPORTE / (N_COLUMNAS - 4) - 4) << "PEDIDOS REALIZADOS:" << endl;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 1) << "No.";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 4) << "PEDIDO";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 1) << "CODIGO";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 1) << "DESCRIPCION";
        output << setw(2 * (TAM_REPORTE / (N_COLUMNAS - 1)) + 7) << "PRECIO";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) - 5) << "CANTIDAD";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) - 4) << "SUBTOTAL";
        output << endl;
    }
}





// Módulo que imprime el DNI, nombre, datos del distrito y el monto total de la lista de pedidos de un cliente
void imprimir_datos_de_un_cliente(const struct Cliente &unCliente, int cantClientes, ofstream &output) {
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 2) << unCliente.dni;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4) + 5) << unCliente.nombre;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 2) << unCliente.distrito.codigo;
    output << setw(2 * (TAM_REPORTE / (N_COLUMNAS + 2)) + 2) << unCliente.distrito.nombre;
    output << right << setw(7) << unCliente.montoTotal;
    output << endl;
}





// Módulo que imprime la lista de pedidos de un cliente
void imprimir_lista_de_pedidos(struct PlatoPedido *listaDePedidos, int cantidadDePedidos, ofstream &output) {
    for(int indice = 0; indice < cantidadDePedidos; indice++) {
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 2) << ' ';
        output << setfill('0') << setw(2) << indice + 1 << ')' << setfill(' ');
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 4) << listaDePedidos[indice].codigoPedido;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 1) << listaDePedidos[indice].codigoPlato;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 2) << ' ';
        output << left << setw(3 * (TAM_REPORTE / (N_COLUMNAS - 1)) - 8) << listaDePedidos[indice].descripcion;
        output << right << setw(6) << listaDePedidos[indice].precio;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 2) << listaDePedidos[indice].cantidad;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 4) << listaDePedidos[indice].subtotal << endl;
    }
}






// Módulo que imprime los toda la información almacenada del arreglo de
// clientes para la elaboración del reporte solicitado
void imprimir_clientes(struct Cliente *arrClientes, int cantClientes, ofstream &output) {
    for (int indice = 0; indice < cantClientes; indice++) {
        output << "CLIENTE No. " << setfill('0') << setw(3) << indice + 1 << setfill(' ') << endl;
        imprimir_encabezados_del_reporte_solicitado(true, output);
        imprimir_datos_de_un_cliente(arrClientes[indice], cantClientes, output);
        elaborar_lineas('-', TAM_REPORTE, output);
        imprimir_encabezados_del_reporte_solicitado(false, output);
        imprimir_lista_de_pedidos(arrClientes[indice].pedidos, arrClientes[indice].cantidadDePedidos, output);
        elaborar_lineas('=', TAM_REPORTE, output);
    }
}






// Módulo que emite el reporte solicitado
void emitir_reporte(const char *nombre_archivo, struct Cliente *arrClientes, int cantClientes) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(4, output);
    imprimir_clientes(arrClientes, cantClientes, output);
}




// Módulo que intercambia los datos de tipo estructura "PlatoPedido"
void intercambiarStructPlatoPedido(struct PlatoPedido &platoPedido_1, struct PlatoPedido &platoPedido_2) {
    struct PlatoPedido auxiliar;
    auxiliar = platoPedido_1;
    platoPedido_1 = platoPedido_2;
    platoPedido_2 = auxiliar;
}




// Módulo que ordena la lista de pedidos de forma ascendente por el código del
// pedido y descendentemente por el código del plato
void ordenar_una_lista_de_pedidos_de_un_cliente(struct PlatoPedido *arrPlatosPedidos, int cantidadDePedidos) {
    for (int i = 0; i < cantidadDePedidos - 1; i++) {
        for (int k = i + 1; k < cantidadDePedidos; k++) {
            if (arrPlatosPedidos[i].codigoPedido > arrPlatosPedidos[k].codigoPedido or
                    arrPlatosPedidos[i].codigoPedido == arrPlatosPedidos[k].codigoPedido and
                            strcmp(arrPlatosPedidos[i].codigoPlato, arrPlatosPedidos[k].codigoPlato) < 0) {
                intercambiarStructPlatoPedido(arrPlatosPedidos[i], arrPlatosPedidos[k]);
            }
        }
    }
}




// Módulo que ordena los pedidos de cada cliente
void ordenar_pedidos_de_los_clientes(struct Cliente *arrClientes, int cantClientes) {
    for (int indice = 0; indice < cantClientes; indice++) {
        ordenar_una_lista_de_pedidos_de_un_cliente(arrClientes[indice].pedidos,
                                                   arrClientes[indice].cantidadDePedidos);
    }
}




// Módulo que intercambia los datos del tipo estructura "Cliente
void intercambiarStructCliente(struct Cliente &cliente_1, struct Cliente &cliente_2) {
    struct Cliente auxiliar;
    auxiliar = cliente_1;
    cliente_1 = cliente_2;
    cliente_2 = auxiliar;
}




// Módulo que ordena los el arreglo de estructura de tipo "Cliente" de forma
// ascendente por el nombre del cliente.
void ordenar_clientes(struct Cliente *arrClientes, int cantClientes) {
    for (int i = 0; i < cantClientes - 1; i++) {
        for (int k = i + 1; k < cantClientes; k++) {
            if (strcmp(arrClientes[i].nombre, arrClientes[k].nombre) > 0) {
                intercambiarStructCliente(arrClientes[i], arrClientes[k]);
            }
        }
    }
}





// Módulo que lee la información de un un pedido del archivo "PedidosRealizados.txt"
void leer_un_pedido(int &codigoDelPedido, int &dni_leido, char* &cod_plato_leido,
        int &cantidadPedida, ifstream &input) {
    codigoDelPedido = leer_dato_int(input);
    if (input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    dni_leido = leer_dato_int(input);
    input.get(); // Lectura de la coma
    cod_plato_leido = leer_cadena(input, ' ', true);
    cantidadPedida = leer_dato_int(input);
}




// Módulo que busca un plato en el arreglo de estructura de tipo "Plato".
int buscar_plato(char* cod_plato_leido, struct Plato *arrPlatos, int cantPlatos) {
    for (int indice = 0; indice < cantPlatos; indice++) {
        if (strcmp(arrPlatos[indice].codigo, cod_plato_leido) == 0) return indice;
    }
    return NO_ENCONTRADO;
}




// Módulo que busca un cliente en el arreglo de estructura de tipo "Cliente".
int buscar_cliente(int dni_leido, struct Cliente *arrClientes, int cantClientes) {
    for (int indice = 0; indice < cantClientes; indice++) {
        if (arrClientes[indice].dni == dni_leido) return indice;
    }
    return NO_ENCONTRADO;
}




// Módulo que agrega un plato pedido.
void agregar_un_plato_pedido_al_cliente(const struct Plato &unPlato, struct PlatoPedido &unPlatoPedido,
                                        int codigoDelPedido, int cantidadPedida) {
    unPlatoPedido.codigoPedido = codigoDelPedido;
    unPlatoPedido.codigoPlato = asignar_cadena(unPlato.codigo);
    unPlatoPedido.descripcion = asignar_cadena(unPlato.descripcion);
    unPlatoPedido.cantidad = cantidadPedida;
    unPlatoPedido.precio = unPlato.precio;
    unPlatoPedido.subtotal = cantidadPedida * unPlato.precio;
}




// Módulo que busa el distrito mediante el arreglo de estructura de tipo "Distrito"
int buscar_distrito(char *codigo_distrito_buscado, struct Distrito *arrDistritos, int cantDistritos) {
    for (int indice = 0; indice < cantDistritos; indice++) {
        if (strcmp(arrDistritos[indice].codigo, codigo_distrito_buscado) == 0) return indice;
    }
    return NO_ENCONTRADO;
}




// Módulo que inserta los campos faltantes de distrito del cliente
void insertar_nombre_del_distrito_del_cliente(struct Distrito *arrDistritos, int cantDistritos,
                                              struct Distrito &distritoDelCliente) {
    int indice_distrito;
    indice_distrito = buscar_distrito(distritoDelCliente.codigo, arrDistritos, cantDistritos);
    if (indice_distrito != NO_ENCONTRADO) {
        distritoDelCliente.nombre = asignar_cadena(arrDistritos[indice_distrito].nombre);
        distritoDelCliente.ubicacion = asignar_cadena(arrDistritos[indice_distrito].ubicacion);
    } else {
        distritoDelCliente.nombre = asignar_cadena("No hay distrito encontrado");
        distritoDelCliente.ubicacion = asignar_cadena("No hay ubicacion encontrado");
    }
}




// Módulo que completa los campos de los distritos de cada cliente en el arreglo de estructura
// de tipo "Cliente" mediante el arreglo de estructura de tipo "Distrito".
void completar_los_campos_de_distrito_a_los_clientes(struct Distrito *arrDistritos, int cantDistritos,
                                                     struct Cliente *arrClientes, int cantClientes) {
    for(int indice_cliente = 0; indice_cliente < cantClientes; indice_cliente++) {
        insertar_nombre_del_distrito_del_cliente(arrDistritos, cantDistritos, arrClientes[indice_cliente].distrito);
    }
}





// Módulo que lee el archivo "PedidosRealizados.txt". Se completa los pedidos que ha realizado cada cliente.
// Asímismo, se completan los campos faltantes de cada dato del arreglo de estructura "Cliente".
void leer_pedidos_realizados(const char *nombre_archivo, struct Plato *arrPlatos, int cantPlatos,
                             struct Distrito *arrDistritos, int cantDistritos, struct Cliente *arrClientes,
                             int cantClientes) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int codigoDelPedido, dni_leido, cantidadPedida, indice_cliente, indice_plato;
    char *cod_plato_leido;
    while (true) {
        leer_un_pedido(codigoDelPedido, dni_leido, cod_plato_leido, cantidadPedida, input);
        if(input.eof()) break; // Validar fin del archivo "PedidosRealizados.txt"
        indice_plato = buscar_plato(cod_plato_leido, arrPlatos, cantPlatos);
        indice_cliente = buscar_cliente(dni_leido, arrClientes, cantClientes);
        if(indice_plato != NO_ENCONTRADO   and   indice_cliente != NO_ENCONTRADO) {
            int indice_cliente_de_arreglo_pedidos = arrClientes[indice_cliente].cantidadDePedidos;
            agregar_un_plato_pedido_al_cliente(arrPlatos[indice_plato],
                                               arrClientes[indice_cliente].pedidos[indice_cliente_de_arreglo_pedidos],
                                               codigoDelPedido, cantidadPedida);
            arrClientes[indice_cliente].montoTotal += cantidadPedida * arrPlatos[indice_plato].precio;
            arrClientes[indice_cliente].cantidadDePedidos++;
        }
    }
    completar_los_campos_de_distrito_a_los_clientes(arrDistritos, cantDistritos, arrClientes, cantClientes);
}





// Módulo que imprime los encabezados de los reportes de prueba
void imprimir_encabezado_reporte_de_prueba(int opcion, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
    switch (opcion) {
        case 1:
            output << left << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 7) - 2) << "No.";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 7) + 4) << "CODIGO";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 7) << "NOMBRE DEL PLATO";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 4) - 7) << "CATEGORIA";
            output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS + 1) << "PRECIO";
            output << right << "CANTIDAD" << endl;
            break;
        case 2:
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 4) + 1) << "No.";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4) + 5) << "CODIGO";
            output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4))) << "NOMBRE DEL DISTRITO";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 6) + 8) << "UBICACION" << endl;
            break;
        default:
            output << setw(2 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4)) + 4) << "No.";
            output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4) - 4) << "DNI";
            output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4))) << "NOMBRE DEL CLIENTE";
            output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4)) + 9) << "COD. DEL DISTRITO";
            output << endl;
    }
    elaborar_lineas('-', TAM_REPORTE_PRUEBA, output);
}







// Módulo que emite el reporte de prueba de platos. Se verifica la información
// almacenada en el arreglo de tipo estructura "Plato". 
void emitir_reporte_de_prueba_de_platos(const char *nombre_archivo, struct Plato *arrPlatos, int cantPlatos) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    imprimir_titulo(1, output);
    imprimir_encabezado_reporte_de_prueba(1, output);
    output << fixed << setprecision(2);
    for(int indice = 0; indice < cantPlatos; indice++) {
        output << setfill('0') << setw(3) << indice + 1 << setfill(' ') << ')' << setw(2) << ' ';
        output << left << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2) - 8) << arrPlatos[indice].codigo;
        output << setw(3 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2)) - 7) << arrPlatos[indice].descripcion;
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2) + 3) << arrPlatos[indice].categoria;
        output << right << setw(6) << arrPlatos[indice].precio;
        output << setw(TAM_REPORTE / (N_COLUMNAS - 2) - 9) << arrPlatos[indice].cantidad;
        output << endl;
    }
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
}






// Módulo que emite el reporte de prueba de distritos. Se verifica la información
// almacenada en el arreglo de tipo estructura "Distrito". 
void emitir_reporte_de_prueba_de_distritos(const char *nombre_archivo, struct Distrito *arrDistritos, int cantDistritos) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    imprimir_titulo(2, output);
    imprimir_encabezado_reporte_de_prueba(2, output);
    output << fixed << setprecision(2);
    for(int indice = 0; indice < cantDistritos; indice++) {
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 4) - 2) << ' ' << setfill('0') << setw(3);
        output << indice + 1 << setfill(' ') << ')' << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4) - 2) << ' ';
        output << left << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS + 2) << arrDistritos[indice].codigo;
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2) + 8) << arrDistritos[indice].nombre;
        output << right << arrDistritos[indice].ubicacion << endl;
    }
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
}






// Módulo que emite el reporte de prueba de clientes. Se verifica la información
// almacenada en el arreglo de tipo estructura "Cliente". 
void emitir_reporte_de_prueba_de_clientes(const char *nombre_archivo, struct Cliente *arrClientes, int cantClientes) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    imprimir_titulo(3, output);
    imprimir_encabezado_reporte_de_prueba(3, output);
    output << fixed << setprecision(2);
    for(int indice = 0; indice < cantClientes; indice++) {
        output << setw(2 * (TAM_REPORTE_PRUEBA / (N_COLUMNAS + 4)) + 1) << ' ';
        output << setfill('0') << setw(3) << indice + 1 << setfill(' ') << ')' << setw(2) << ' ';
        output << left << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS) << arrClientes[indice].dni;
        output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS + 30) << arrClientes[indice].nombre;
        output << right << arrClientes[indice].distrito.codigo;
        output << endl;
    }
    elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
}





// Módulo que verifica los datos de los arreglos de platos, distritos y clientes.
void verificar_datos_en_los_arreglos(struct Plato *arrPlatos, int cantPlatos, struct Distrito *arrDistritos,
                                     int cantDistritos, struct Cliente *arrClientes, int cantClientes) {
    emitir_reporte_de_prueba_de_platos("ReporteDePruebaDePlatos.txt", arrPlatos, cantPlatos);
    emitir_reporte_de_prueba_de_distritos("ReporteDePruebaDeDistritos.txt", arrDistritos, cantDistritos);
    emitir_reporte_de_prueba_de_clientes("ReporteDePruebaDeClientes.txt", arrClientes, cantClientes);
}





// Módulo que lee los datos de un cliente del archivo "Clientes.csv" y almacena esta
// información de un índice del arreglo de tipo estructura "Cliente" (pasado por referencia).
// En caso se llegue al fin del archivo, se sale de este módulo.
void leer_un_cliente(struct Cliente &cliente, ifstream &input) {
    int dni;
    dni = leer_dato_int(input);
    if (input.eof()) return; // Se llegó al fin del archivo. Salir de este módulo.
    cliente.dni = dni;
    input.get(); // Lectura de la coma
    cliente.nombre = leer_cadena(input, ',', false);
    cliente.distrito.codigo = leer_cadena(input, '\n', false);
    
    cliente.cantidadDePedidos = 0;
    cliente.montoTotal = 0.0;
}





// Módulo que lee el archivo "Clientes.csv" y almacena la información que
// se lee en ese archivo en un arreglo de estructuras de tipo "Cliente".
void leer_clientes(const char *nombre_archivo, struct Cliente *arrClientes, int &cantClientes) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantClientes = 0;
    while (true) {
        leer_un_cliente(arrClientes[cantClientes], input);
        if (input.eof()) break; // Validar fin del archivo "Clientes.csv"
        cantClientes++;
    }
}





// Módulo que lee la información de un distrito de Lima del archivo "DistritosDeLima.csv" y almacena esta
// información de un índice del arreglo de tipo estructura "Distrito" (pasado por referencia). En caso se
// llegue al fin del archivo, se sale de este módulo.
void leer_un_distrito(struct Distrito &distritoDeLima, ifstream &input) {
    char *codigoDelDistrito;
    codigoDelDistrito = leer_cadena(input, ',', false);
    if (codigoDelDistrito == nullptr) return; // Se llegó al fin del archivo. Salir de este módulo.
    distritoDeLima.codigo = codigoDelDistrito;
    distritoDeLima.nombre = leer_cadena(input, ',', false);
    distritoDeLima.ubicacion = leer_cadena(input, '\n', false);
}





// Módulo que lee el archivo "DistritosDeLima.csv" y almacena la información que
// se lee en ese archivo en un arreglo de estructuras de tipo "Distrito".
void leer_distritos(const char *nombre_archivo, struct Distrito *arrDistritos, int &cantDistritos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantDistritos = 0;
    while (true) {
        leer_un_distrito(arrDistritos[cantDistritos], input);
        if (input.eof()) break; // Validar fin del archivo "DistritosDeLima.csv"
        cantDistritos++;
    }
}





// Módulo que lee la información de un plato ofrecido del archivo "PlatosOfrecidos.csv" y almacena esta
// información de un índice del arreglo de tipo estructura "Plato" (pasado por referencia). En caso se
// llegue al fin del archivo, se sale de este módulo.
void leer_un_plato_ofrecido(struct Plato &plato_ofrecido, ifstream &input) {
    char *codigoPlato;
    codigoPlato = leer_cadena(input, ',', false);
    if (codigoPlato == nullptr) return; // Se llegó al fin del archivo. Salir de este módulo.
    plato_ofrecido.codigo = codigoPlato;
    plato_ofrecido.descripcion = leer_cadena(input, ',', false);
    plato_ofrecido.precio = leer_dato_double(input);
    plato_ofrecido.categoria = leer_cadena(input, '\n', false);
    plato_ofrecido.cantidad = 0;
}






// Módulo que lee el archivo "PlatosOfrecidos.csv" y almacena la información que
// se lee en ese archivo en un arreglo de estructuras de tipo "Plato".
void leer_platos_ofrecidos(const char *nombre_archivo, struct Plato *arrPlatos, int &cantPlatos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantPlatos = 0;
    while (true) {
        leer_un_plato_ofrecido(arrPlatos[cantPlatos], input);
        if (input.eof()) break; // Validar fin del archivo "PlatosOfrecidos.csv"
        cantPlatos++;
    }
}




