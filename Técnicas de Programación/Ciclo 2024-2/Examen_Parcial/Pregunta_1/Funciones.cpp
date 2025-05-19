

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de mayo de 2025, 06:28 PM
 */

#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::out);
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


// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}


// Módulo que lee y retorna un dato de tipo "int"
int leer_dato_tipo_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee y retorna un dato de tipo "double"
double leer_dato_tipo_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}



// Módulo que lee y retorna un dato de tipo "double"
char leer_dato_tipo_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}


// Módulo que lee el porcentaje
double leer_porcentaje(ifstream &input){
    double porcentaje;
    char signo_porcentaje;
    porcentaje = leer_dato_tipo_double(input);
    signo_porcentaje = leer_dato_tipo_char(input);
    return porcentaje;
}


// Módulo que imprime el tipo del vehículo
void imprimir_vehiculo(char vehiculo,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 1);
    
    if(vehiculo == 'M') output << "Motocicleta";
    else  output << "Bicicleta";
    
    output << right;
}



// Módulo que imprime una cadena de caracteres
void imprimir_cadena(char delimitador,int tam_total_de_cadena_con_espacios,
                     ifstream &input,ofstream &output){
    int n_caracteres = 0;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        char c = input.get();
        if(c == delimitador) break;
        if(c == '_') c = ' ';
        output.put(c);
        n_caracteres++;
    }
    
    // Impresión de espacios en blanco
    for(int i=0; i < tam_total_de_cadena_con_espacios - n_caracteres; i++) output.put(' ');
}




// Módulo que ignora todo hasta el delimitador
void ignorar_hasta_delimitador(char delimitador,ifstream &input){
    input >> ws;
    while(input.get() != delimitador);
}




// Módulo que realiza el procesamiento de la elaboración del reporte mediante la
// lectura de archivos e impresión de lo requerido en el reporte solicitado.
void procesar_reporte(const char *nombre_archivo_clientes,
                      const char *nombre_archivo_repartos,
                      const char *nombre_archivo_platos,
                      const char *nombre_archivo_repartidores,
                      const char *nombre_archivo_reporte){
    ifstream input_clientes,input_repartos,input_platos,input_repartidores;
    ofstream output;
    double total_recaudado_por_los_pedidos_solicitados = 0.0,
           total_a_pagar_a_los_repartidores = 0.0;
    aperturar_archivo_lectura(nombre_archivo_clientes,input_clientes);
    aperturar_archivo_lectura(nombre_archivo_repartos,input_repartos);
    aperturar_archivo_lectura(nombre_archivo_platos,input_platos);
    aperturar_archivo_lectura(nombre_archivo_repartidores,input_repartidores);
    aperturar_archivo_escritura(nombre_archivo_reporte,output);
    imprimir_titulo(output);
    output << fixed << setprecision(2);
    procesar_clientes(input_clientes,input_repartos,input_platos,input_repartidores,
                      total_recaudado_por_los_pedidos_solicitados,
                      total_a_pagar_a_los_repartidores,output);
    imprimir_resumen_del_reporte(total_recaudado_por_los_pedidos_solicitados,
                                 total_a_pagar_a_los_repartidores,output);
}




// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "EMPRESA DE REPARTOS A DOMICILIO TP S. A." << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "CLIENTES POR ATENDER" << endl;
}




// Módulo que lee el archivo "Clientes.txt" y realiza el procesamiento de cada cliente de este archivo
void procesar_clientes(ifstream &input_clientes,ifstream &input_repartos,
                       ifstream &input_platos,ifstream &input_repartidores,
                       double &total_recaudado_por_los_pedidos_solicitados,
                       double &total_a_pagar_a_los_repartidores,ofstream &output){
    int dni_cliente,cod_distrito;
    char vehiculo_desea_el_cliente;
    double descuento_cliente;
    while(true){
        dni_cliente = leer_dato_tipo_int(input_clientes);
        if(input_clientes.eof()) break; // Validar fin del archivo "Clientes.txt"
        continuar_lectura_de_un_cliente_e_imprimirlo(dni_cliente,cod_distrito,
                            vehiculo_desea_el_cliente,descuento_cliente,input_clientes,output);
        double monto_total_pagado_por_el_cliente = 0.0,pago_total_al_repartidor = 0.0;
        procesar_repartos(dni_cliente,descuento_cliente,monto_total_pagado_por_el_cliente,
                          input_repartos,pago_total_al_repartidor,input_platos,output,
                          vehiculo_desea_el_cliente);
        imprimir_resumen_de_un_cliente(monto_total_pagado_por_el_cliente,
                                       pago_total_al_repartidor,input_repartidores,output,
                                       vehiculo_desea_el_cliente,cod_distrito);
        total_recaudado_por_los_pedidos_solicitados += monto_total_pagado_por_el_cliente;
        total_a_pagar_a_los_repartidores += pago_total_al_repartidor;
    }
}




// Módulo que continua con la lectura de un cliente
// del archivo "Clientes.txt" e imprime estos datos que se leen.
void continuar_lectura_de_un_cliente_e_imprimirlo(int dni_cliente,int &cod_distrito,
                                        char &vehiculo_desea_el_cliente,double &descuento_cliente,
                                        ifstream &input_clientes,ofstream &output){
    char hay_descuento;
    
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "CLIENTE: " << dni_cliente << "  -  ";
    imprimir_cadena(']',TAM_REPORTE / (N_COLUMNAS - 1),input_clientes,output);
    
    cod_distrito = leer_dato_tipo_int(input_clientes);
    output << "DISTRITO: ";
    imprimir_cadena(' ',TAM_REPORTE / (N_COLUMNAS + 1) + 4,input_clientes,output);
    
    output << "TIPO DE VEHICULO: ";
    vehiculo_desea_el_cliente = leer_dato_tipo_char(input_clientes);
    imprimir_vehiculo(vehiculo_desea_el_cliente,output);
    
    
    hay_descuento = leer_dato_tipo_char(input_clientes);
    if(hay_descuento == 'S'){
        descuento_cliente = leer_porcentaje(input_clientes);
    }
    else  descuento_cliente = 0.0;
    
    output << "DESCUENTO: ";
    output << descuento_cliente << '%' << endl;
}




// Módulo que procesa el archivo "RepartosARealizar.txt". Mediante este archivo
// se lee los pedidos que ha pedido el cliente y se imprime lo que ha pedido el cliente.
void procesar_repartos(int dni_cliente,double porcentaje_descuento_cliente,
                       double &monto_total_pagado_por_el_cliente,
                       ifstream &input_repartos,double &pago_total_al_repartidor,
                       ifstream &input_platos,ofstream &output,char vehiculo_desea_el_cliente){
    input_repartos.clear(); // Liberar el buffer del archivo "RepartosARealizar.txt" y limpia banderas levantadas.
    input_repartos.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "RepartosARealizar.txt"
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "REPARTOS:" << endl;
    int cod_pedido,dni_cliente_leido,n_pedido = 0;
    while(true){
        cod_pedido = leer_dato_tipo_int(input_repartos);
        if(input_repartos.eof()) break; // Validar fin del archivo "RepartosARealizar.txt"
        dni_cliente_leido = leer_dato_tipo_int(input_repartos);
        if(dni_cliente_leido == dni_cliente){
            double total_pedido_sin_descuentos = 0.0,descuento_total_por_platos = 0.0,
                   descuento_cliente,pago_al_repartidor;
            imprimir_encabezado_de_un_pedido(n_pedido+1,cod_pedido,output);
            leer_lista_de_platos(total_pedido_sin_descuentos,descuento_total_por_platos,
                                 descuento_cliente,pago_al_repartidor,input_repartos,input_platos,
                                 output,porcentaje_descuento_cliente,vehiculo_desea_el_cliente);
            imprimir_resumen_de_un_pedido(total_pedido_sin_descuentos,
                                          descuento_total_por_platos,descuento_cliente,
                                          pago_al_repartidor,output);
            monto_total_pagado_por_el_cliente += total_pedido_sin_descuentos +
                                                 descuento_total_por_platos +
                                                 descuento_cliente;
            pago_total_al_repartidor += pago_al_repartidor;
            n_pedido++;
        }
        else   ignorar_hasta_delimitador('\n',input_repartos);
    }
}




// Módulo que imprime el encabezado de un pedido
void imprimir_encabezado_de_un_pedido(int n_pedido,int cod_pedido,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setfill('0') << setw(2) << n_pedido << setfill(' ') << ')';
    output << setw(N_COLUMNAS + 6) << "PEDIDO: " << cod_pedido << endl;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) + 2) << "PLATO";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) + 1) << "CANTIDAD";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 4) << "PRECIO";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6)) << "SUBTOTAL";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) + 3) << "DESCUENTO";
    output << endl;
}




// Módulo que lee una lista de plato de un cliente del archivo "RepartosARealizar.txt"
void leer_lista_de_platos(double &total_pedido_sin_descuentos,
                  double &descuento_total_por_platos,double &descuento_cliente,
                  double &pago_al_repartidor,ifstream &input_repartos,
                  ifstream &input_platos,ofstream &output,
                  double porcentaje_descuento_cliente,char vehiculo_desea_el_cliente){
    int cant_pedida,cod_plato,n_platos = 1;
    while(true){
        cant_pedida = leer_dato_tipo_int(input_repartos);
        cod_plato = leer_dato_tipo_int(input_repartos);
        procesar_plato(total_pedido_sin_descuentos,
                       descuento_total_por_platos,n_platos,
                       cant_pedida,cod_plato,input_platos,output);
        if(input_repartos.get() == '\n') break;
    }
    descuento_cliente = total_pedido_sin_descuentos *
                        (porcentaje_descuento_cliente / 100);
    
    pago_al_repartidor = (vehiculo_desea_el_cliente == 'M' ? 
                          total_pedido_sin_descuentos*0.10 : total_pedido_sin_descuentos*0.5);
}




// Módulo que busca un plato y procesa con la impresión de la información de ese plato
void procesar_plato(double &total_pedido_sin_descuentos,
                    double &descuento_total_por_platos,int &n_platos,int cant_pedida,
                    int cod_plato,ifstream &input_platos,ofstream &output){
    input_platos.clear(); // Liberar el buffer del archivo "PlatosOfrecidos.txt" y limpia banderas levantadas.
    input_platos.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "PlatosOfrecidos.txt"
    int cod_plato_leido;
    double subtotal,el_monto_con_descuento_plato;
    while(true){
        cod_plato_leido = leer_dato_tipo_int(input_platos);
        if(input_platos.eof()) break; // Validar fin del archivo "PlatosOfrecidos.txt"
        if(cod_plato_leido == cod_plato){
            continuar_lectura_de_un_plato_e_imprimirlo(n_platos,cod_plato,cant_pedida,
                                      subtotal,el_monto_con_descuento_plato,input_platos,output);
            n_platos++;
            total_pedido_sin_descuentos += subtotal;
            descuento_total_por_platos += el_monto_con_descuento_plato;
        }
        else  ignorar_hasta_delimitador('\n',input_platos);
    }
}




// Módulo que continua con la lectura de un plato e imprime los datos de ese plato
void continuar_lectura_de_un_plato_e_imprimirlo(int n_platos,int cod_plato,
                           int cant_pedida,double &subtotal,double &el_monto_con_descuento_plato,
                           ifstream &input_platos,ofstream &output){
    double precio,porcentaje_plato;
    int cant_platos_elaborados;
    output << setw(N_COLUMNAS + 1) << ' ' ;
    output << n_platos << ')';
    output << setw(N_COLUMNAS + 1) << cod_plato << '-';
    imprimir_cadena('}',TAM_REPORTE / (N_COLUMNAS - 2),input_platos,output);
    output << setw(2) << cant_pedida;
    precio = leer_dato_tipo_double(input_platos);
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4)) << precio;
    subtotal = precio * cant_pedida;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 1) << subtotal;
    cant_platos_elaborados = leer_dato_tipo_int(input_platos);
    if(input_platos.get() != '\n'){
        porcentaje_plato = leer_porcentaje(input_platos);
    }
    else   porcentaje_plato = 0.0;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8)) << porcentaje_plato << '%' << " - ";
    el_monto_con_descuento_plato = subtotal * (porcentaje_plato / 100);
    output << setw(6) << el_monto_con_descuento_plato;
    output << endl;
}





// Módulo que imprime el resumen de un pedido (impresión del total pedido sin descuento,
// descuento total por platos, descuento del cliente, total pagado por el cliente y
// el pago al repartidor).
void imprimir_resumen_de_un_pedido(double total_pedido_sin_descuentos,
                                   double descuento_total_por_platos,double descuento_cliente,
                                   double pago_al_repartidor,ofstream &output){
    double total_pagado_por_el_cliente = total_pedido_sin_descuentos -
                                         descuento_total_por_platos -
                                         descuento_cliente;
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(N_COLUMNAS + 1) << ' ' << "TOTAL PEDIDO SIN DESCUENTOS:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 5) << total_pedido_sin_descuentos;
    output << endl;
    output << setw(N_COLUMNAS + 1) << ' ' << "DESCUENTO TOTAL POR PLATOS:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 4) << descuento_total_por_platos;
    output << endl;
    output << setw(N_COLUMNAS + 1) << ' ' << "DESCUENTO DEL CLIENTE:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 1) << descuento_cliente;
    output << endl;
    output << setw(N_COLUMNAS + 1) << ' ' << "TOTAL PAGADO POR EL CLIENTE:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8) - 3) << total_pagado_por_el_cliente;
    output << endl;
    output << setw(N_COLUMNAS + 1) << ' ' << "PAGO AL REPARTIDOR:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 4) + 1) << pago_al_repartidor;
    output << endl;
}








// Módulo que imprime el monto total pagado por el cliente y el repartidor que cumple
// con las características (distrito y vehículo) que desea el cliente que se llevado su(s) pedido(s).
void imprimir_resumen_de_un_cliente(double monto_total_pagado_por_el_cliente,
                           double pago_total_al_repartidor,ifstream &input_repartidores,ofstream &output,
                           char vehiculo_desea_el_cliente,int cod_distrito){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "MONTO TOTAL PAGADO POR EL CLIENTE:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 8);
    output << monto_total_pagado_por_el_cliente;
    output << endl;
    imprimir_repartidor(pago_total_al_repartidor,vehiculo_desea_el_cliente,
                        cod_distrito,input_repartidores,output);
}





// Módulo que busca e imprime el repartidor según el distrito y vehículo que desee el cliente.
void imprimir_repartidor(double pago_total_al_repartidor,char vehiculo_desea_el_cliente,
                         int cod_distrito_cliente,ifstream &input_repartidores,ofstream &output){
    input_repartidores.clear(); // Liberar el buffer del archivo "Repartidores.txt" y limpia banderas levantadas.
    input_repartidores.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "Repartidores.txt"
    int dni_repartidor,cod_distrito_repartidor;
    char vehiculo_repartidor;
    while(true){
        dni_repartidor = leer_dato_tipo_int(input_repartidores);
        if(input_repartidores.eof()) break; // Validar fin del archivo "Repartidores.txt"
        vehiculo_repartidor = leer_dato_tipo_char(input_repartidores);
        ignorar_hasta_delimitador(' ',input_repartidores);
        cod_distrito_repartidor = leer_dato_tipo_int(input_repartidores);
        
        if(cod_distrito_repartidor == cod_distrito_cliente   and
                        vehiculo_repartidor == vehiculo_desea_el_cliente){
            output << "REPARTIDOR: " << dni_repartidor << "  -  ";
            imprimir_cadena('\n',TAM_REPORTE / (N_COLUMNAS - 1),input_repartidores,output);
            output << "PAGO TOTAL:" << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 5);
            output << pago_total_al_repartidor << endl;
        }
        else ignorar_hasta_delimitador('\n',input_repartidores);
    }
}





// Módulo que imprime el resumen del reporte.imprime el total recaudado
// por los pedidos solicitados y el total a pagar a los repartidores.
void imprimir_resumen_del_reporte(double total_recaudado_por_los_pedidos_solicitados,
                                  double total_a_pagar_a_los_repartidores,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "TOTAL RECAUDADO POR LOS PEDIDOS SOLICITADOS:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8));
    output << total_recaudado_por_los_pedidos_solicitados << endl;
    output << "TOTAL A PAGAR A LOS REPARTIDORES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS + 6) + 9);
    output << total_a_pagar_a_los_repartidores << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}