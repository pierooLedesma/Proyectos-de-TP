

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 17 de mayo de 2025, 06:36 PM
 */


#include "Funciones.h"



/* ========================================================================================== */
/* =============================  Funciones principales  ==================================== */
/* ================= (Funciones que controlan el flujo principal del programa) ============== */
/* ========================================================================================== */



// Módulo que lee el archivo "PlatosOfrecidos.txt" y almacena los
// datos leídos (excepto una cadena de caracteres) en arreglos.
void leer_platos_ofrecidos(const char *nombre_archivo,int *arr_codigo_plato,
                           double *arr_precio_plato,int *arr_cantidades_plato,
                           double *arr_descuento_plato,double *arr_montos_recaudados,
                           int &cant_platos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int codigo_plato;
    cant_platos = 0;
    while(true){
        codigo_plato = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "PlatosOfrecidos.txt"
        arr_codigo_plato[cant_platos] = codigo_plato;
        ignorar_hasta_delimitador('}',input);
        arr_precio_plato[cant_platos] = leer_dato_tipo_double(input);
        
        arr_cantidades_plato[3*cant_platos] = leer_dato_tipo_int(input); // Se almacena la cantidad de 
                                                                         // platos preparados (o también
                                                                         // denominado elaborados).
        if(input.get() != '\n'){
            // Sí hay descuento para este plato.
            arr_descuento_plato[cant_platos] = leer_dato_tipo_double(input);
            input.get(); // Lectura de este siguiente caracter:  %
        }
        else arr_descuento_plato[cant_platos] = 0.0; // No hay descuento para este plato
        
        // Cálculo del monto esperado de un plato
        arr_montos_recaudados[3*cant_platos] = arr_cantidades_plato[3*cant_platos] *
                                               arr_precio_plato[cant_platos];
        cant_platos++;
    }
}



// Módulo que lee el archivo "Clientes.txt" y almacena los
// el DNI del cliente y el porcentaje al cliente en arreglos.
void leer_clientes(const char *nombre_archivo,int *arr_dni_cliente,
                   double *arr_descuento_cliente,int &cant_clientes){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int dni_cliente,codigo_distrito;
    char tipo_vehiculo,hay_descuento_al_cliente;
    cant_clientes = 0;
    while(true){
        dni_cliente = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "Clientes.txt"
        arr_dni_cliente[cant_clientes] = dni_cliente;
        ignorar_hasta_delimitador(']',input);
        codigo_distrito = leer_dato_tipo_int(input);
        ignorar_hasta_delimitador(' ',input);
        tipo_vehiculo = leer_dato_tipo_char(input);
        hay_descuento_al_cliente = leer_dato_tipo_char(input);
        
        if(hay_descuento_al_cliente == 'S'){
            // Sí hay descuento para el cliente
            arr_descuento_cliente[cant_clientes] = leer_dato_tipo_double(input);
            input.get(); // Lectura de este siguiente caracter:  %
        }
        else arr_descuento_cliente[cant_clientes] = 0.0; // No hay descuento para el cliente
        
        cant_clientes++;
    }
}




// Módulo que emite un reporte de prueba para verificar la correcta asignación almacenada en los arreglos.
void emitir_reporte_prueba(const char *nombre_archivo,int *arr_codigo_plato,
                           double *arr_precio_plato,int *arr_cantidades_plato,double *arr_descuento_plato,
                           double *arr_montos_recaudados,int cant_platos,int *arr_dni_cliente,
                           double *arr_descuento_cliente,int cant_clientes){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulo(1,output);
    elaborar_encabezado(true,output);
    for(int indice=0; indice < cant_platos; indice++){
        imprimir_un_juego_de_datos_de_platos(arr_codigo_plato[indice],arr_precio_plato[indice],
                arr_cantidades_plato[3*indice],arr_cantidades_plato[3*indice + 1],
                arr_cantidades_plato[3*indice + 2],arr_descuento_plato[indice],arr_montos_recaudados[3*indice],
                arr_montos_recaudados[3*indice + 1],arr_montos_recaudados[3*indice + 2],output);
    }
    elaborar_lineas('=',TAM_REPORTE,output);
    output << endl << endl << endl << endl;
    imprimir_titulo(2,output);
    elaborar_encabezado(false,output);
    imprimir_clientes(arr_dni_cliente,arr_descuento_cliente,cant_clientes,output);
}




// Módulo que lee el archivo "RepartosARealizar.txt". Mediante este archivo se actualizan
// los datos de los arreglos de montos y cantidades totales de cada plato.
void leer_repartos_a_realizar(const char *nombre_archivo,int *arr_codigo_plato,
                      double *arr_precio_plato,int *arr_cantidades_plato,double *arr_descuento_plato,
                      double *arr_montos_recaudados,int cant_platos,int *arr_dni_cliente,
                      double *arr_descuento_cliente,int cant_clientes){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int num_pedido,dni_leido,pos_cliente;
    double descuento_cliente;
    while(true){
        // Lectura fija del archivo "RepartosARealizar.txt"
        num_pedido = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "RepartosARealizar.txt"
        dni_leido = leer_dato_tipo_int(input);
        pos_cliente = buscar_posicion(dni_leido,arr_dni_cliente,cant_clientes);
        descuento_cliente = (pos_cliente != NO_ENCONTRADO ? arr_descuento_cliente[pos_cliente]: 0.0);
        
        // Lectura variable del archivo "RepartosARealizar.txt"
        procesar_lista_de_platos(arr_codigo_plato,arr_precio_plato,arr_cantidades_plato,
                                 arr_descuento_plato,arr_montos_recaudados,cant_platos,
                                 descuento_cliente,input);
    }
}




// Módulo que procesa la lista de platos de un reparto. Es la lectura variable del archivo "RepartosARealizar.txt".
void procesar_lista_de_platos(int *arr_codigo_plato,double *arr_precio_plato,int *arr_cantidades_plato,
                              double *arr_descuento_plato,double *arr_montos_recaudados,
                              int cant_platos,double descuento_cliente,ifstream &input){
    int cantidad_pedida,codigo_plato_leido,pos_plato,cant_atendida;
    while(true){
        cantidad_pedida = leer_dato_tipo_int(input);
        codigo_plato_leido = leer_dato_tipo_int(input);
        pos_plato = buscar_posicion(codigo_plato_leido,arr_codigo_plato,cant_platos);
        if(pos_plato != NO_ENCONTRADO){
            actualizar_cantidad_de_platos_atendidos_y_no_atendidos(cant_atendida,cantidad_pedida,
                                arr_cantidades_plato[3*pos_plato],arr_cantidades_plato[3*pos_plato +1],
                                arr_cantidades_plato[3*pos_plato +2]);
            actualizar_monto_bruto_y_monto_recibido(arr_montos_recaudados[3*pos_plato + 1],
                    arr_montos_recaudados[3*pos_plato + 2], cant_atendida,arr_precio_plato[pos_plato],
                    arr_descuento_plato[pos_plato],descuento_cliente);
        }
        if(input.get() == '\n') break;
    }
}




// Módulo que ordena los arreglos mediante la forma descendente
// por la cantidad de platos elaborados (o también llamado preparados).
void ordenar_arreglos(int *arr_codigo_plato,double *arr_precio_plato,int *arr_cantidades_plato,
                      double *arr_descuento_plato,double *arr_montos_recaudados,
                      int cant_platos){
    for(int i = 0; i < cant_platos - 1; i++){
        for(int k = i + 1; k < cant_platos; k++){
            if(arr_cantidades_plato[3*i] < arr_cantidades_plato[3*k]){
                intercambiar_int(arr_codigo_plato[i],arr_codigo_plato[k]);
                intercambiar_double(arr_precio_plato[i],arr_precio_plato[k]);
                intercambiar_int(arr_cantidades_plato[3*i],arr_cantidades_plato[3*k]);
                intercambiar_int(arr_cantidades_plato[3*i + 1],arr_cantidades_plato[3*k + 1]);
                intercambiar_int(arr_cantidades_plato[3*i + 2],arr_cantidades_plato[3*k + 2]);
                intercambiar_double(arr_descuento_plato[i],arr_descuento_plato[k]);
                intercambiar_double(arr_montos_recaudados[3*i],arr_montos_recaudados[3*k]);
                intercambiar_double(arr_montos_recaudados[3*i + 1],arr_montos_recaudados[3*k + 1]);
                intercambiar_double(arr_montos_recaudados[3*i + 1],arr_montos_recaudados[3*k + 2]);
            }
        }
    }
}




// Módulo que emite el reporte solicitado
void emitir_reporte(const char *nombre_archivo,int *arr_codigo_plato,
                    double *arr_precio_plato,int *arr_cantidades_plato,
                    double *arr_descuento_plato,double *arr_montos_recaudados,
                    int cant_platos){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_titulo(3,output);
    elaborar_encabezado(true,output);
    double total_del_monto_esperado = 0.0,total_del_monto_bruto = 0.0,
                total_del_monto_recibido = 0.0;
    for(int indice=0; indice < cant_platos; indice++){
        imprimir_un_juego_de_datos_de_platos(arr_codigo_plato[indice],arr_precio_plato[indice],
                arr_cantidades_plato[3*indice],arr_cantidades_plato[3*indice + 1],
                arr_cantidades_plato[3*indice + 2],arr_descuento_plato[indice],arr_montos_recaudados[3*indice],
                arr_montos_recaudados[3*indice + 1],arr_montos_recaudados[3*indice + 2],output);
        
        // Actualización de totales:
        total_del_monto_esperado += arr_montos_recaudados[3*indice];
        total_del_monto_bruto += arr_montos_recaudados[3*indice + 1];
        total_del_monto_recibido += arr_montos_recaudados[3*indice + 2];
    }
    imprimir_resumen_de_totales(total_del_monto_esperado,total_del_monto_bruto,
                                total_del_monto_recibido,output);
}




// Módulo que elimina los datos de los arreglos que no pudieron
// atender la demanda (elimino los datos que tienen "no atendidos" igual a cero).
void eliminar_datos_en_los_arreglos(int *arr_codigo_plato,double *arr_precio_plato,
                                    int *arr_cantidades_plato,double *arr_descuento_plato,
                                    double *arr_montos_recaudados,int &cant_platos){
    int indice=0;
    while(indice < cant_platos){
        if(arr_cantidades_plato[3*indice + 2]  == 0){
            // Se eliminaran datos del arreglo del índice escogido.
            eliminar_datos(indice,arr_codigo_plato,arr_precio_plato,
                           arr_cantidades_plato,arr_descuento_plato,
                           arr_montos_recaudados,cant_platos);
            // No se incrementa el índice porque hay nuevos datos en ese índice.
        } else {
            // Aumentar el índice si no se ha eliminado los datos en los arreglos.
            indice++;
        }
    }
}



// Módulo que elimina los datos que se desea eliminar en los arreglos
void eliminar_datos(int posicion_a_eliminar,int *arr_codigo_plato,double *arr_precio_plato,
                    int *arr_cantidades_plato,double *arr_descuento_plato,
                    double *arr_montos_recaudados,int &cant_platos){
    for(int indice = posicion_a_eliminar; indice < cant_platos - 1; indice++){
        // Código del plato:
        arr_codigo_plato[indice] = arr_codigo_plato[indice + 1];
        // Precio del plato:
        arr_precio_plato[indice] = arr_precio_plato[indice + 1];
        
        // Cantidad de platos preparados:
        arr_cantidades_plato[3*indice] = arr_cantidades_plato[3*(indice+1)];
        
        // Cantidad de platos atendidos:
        arr_cantidades_plato[3*indice + 1] = arr_cantidades_plato[3*(indice+1) + 1];
        
        // Cantidad de platos no atendidos:
        arr_cantidades_plato[3*indice + 2] = arr_cantidades_plato[3*(indice+1) + 2];
        
        // Descuento del plato:
        arr_descuento_plato[indice] = arr_descuento_plato[indice + 1];
        
        // Monto recaudado de lo esperado:
        arr_montos_recaudados[3*indice] = arr_montos_recaudados[3*(indice+1)];
        
        // Monto reacaudado de lo bruto:
        arr_montos_recaudados[3*indice + 1] = arr_montos_recaudados[3*(indice+1) + 1];
        
        // Monto recaudado de lo recibido:
        arr_montos_recaudados[3*indice + 2] = arr_montos_recaudados[3*(indice+1) + 2];
    }
    cant_platos--;
}


/* ==================================================================================== */








/* ============================================================================================= */
/* ==========================  Funciones de reportería  ======================================== */
/* =============== (Funciones que ayudan en la elaboración de un reporte) ====================== */
/* ============================================================================================= */


// Módulo que imprime los títulos del reporte de prueba y del reporte solicitado
void imprimir_titulo(int opcion,ofstream &output){
    switch (opcion){
        case 1:
            output << setw((TAM_REPORTE + TAM_TITULO_PRUEBA_1) / 2);
            output << "DATOS DE PLATOS EN SUS RESPECTIVOS ARREGLOS" << endl;
            break;
        case 2:
            output << setw((TAM_REPORTE + TAM_TITULO_PRUEBA_2) / 2);
            output << "DATOS DE CLIENTES EN SUS RESPECTIVOS ARREGLOS" << endl;
            break;
        default:
            output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
            output << "EMPRESA DE REPARTOS A DOMICILIO TP S. A." << endl;
            output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
            output << "RELACION DE LOS PLATOS VENDIDOS" << endl;
    }
}




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}



// Módulo que elabora los encabezados
void elaborar_encabezado(bool es_para_platos,ofstream &output){
    if(es_para_platos){
        elaborar_lineas('=',TAM_REPORTE,output);
        output << setw(TAM_REPORTE / (N_COLUMNAS - 6) + 7) << "CANTIDAD DE PLATOS";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 7) - 1) << "MONTOS RECAUDADOS";
        output << endl;
        output << "CODIGO";
        output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "PRECIO";
        output << setw(TAM_REPORTE / N_COLUMNAS + 3) << "PREPARADOS";
        output << setw(TAM_REPORTE / N_COLUMNAS - 1) << "ATENDIDOS";
        output << setw(TAM_REPORTE / N_COLUMNAS + 2) << "NO ATENDIDOS";
        output << setw(TAM_REPORTE / N_COLUMNAS + 2) << "DESCUENTO";
        output << setw(TAM_REPORTE / N_COLUMNAS + 2) << "ESPERADO";
        output << setw(TAM_REPORTE / N_COLUMNAS) << "BRUTO";
        output << setw(TAM_REPORTE / N_COLUMNAS + 1) << "RECIBIDO" << endl;
        elaborar_lineas('-',TAM_REPORTE,output);
    } else {
        output << setw(TAM_TITULO_PRUEBA_2 - (N_COLUMNAS + 5)) << ' ';
        elaborar_lineas('=',TAM_TITULO_PRUEBA_2 + 10,output);
        output << setw(TAM_REPORTE / (N_COLUMNAS - 6) + 7) << "DNI";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 4) + 6) << "DESCUENTO AL CLIENTE";
        output << endl;
        output << setw(TAM_TITULO_PRUEBA_2 - (N_COLUMNAS + 5))  << ' ';
        elaborar_lineas('-',TAM_TITULO_PRUEBA_2 + 10,output);
    }
}




// Módulo que imprime los datos de clientes (DNI y el descuento) almacenado en arreglos
void imprimir_clientes(int *arr_dni_cliente,double *arr_descuento_cliente,
                       int cant_clientes,ofstream &output){
    for(int indice =0; indice < cant_clientes; indice++){
        output << setw(TAM_REPORTE / (N_COLUMNAS - 6) + 9) << arr_dni_cliente[indice];
        output << setw(TAM_REPORTE / (N_COLUMNAS + 1) + 8);
        output << arr_descuento_cliente[indice] << '%' << endl;
    }
    output << setw(TAM_TITULO_PRUEBA_2 - (N_COLUMNAS + 5))  << ' ';
    elaborar_lineas('=',TAM_TITULO_PRUEBA_2 + 10,output);
}




// Módulo que imprime un juego de datos de un plato
void imprimir_un_juego_de_datos_de_platos(int cod_plato,double precio_plato,
                                          int cant_platos_preparados,int cant_platos_atendidos,
                                          int cant_platos_no_atendidos,double descuento_plato,
                                          double monto_total_esperado,double monto_total_bruto,
                                          double monto_total_recibido,ofstream &output){
    output << cod_plato << setw(TAM_REPORTE / N_COLUMNAS - 3);
    output << precio_plato << setw(TAM_REPORTE / N_COLUMNAS - 1);
    output << cant_platos_preparados << setw(TAM_REPORTE / N_COLUMNAS - 1);
    output << cant_platos_atendidos << setw(TAM_REPORTE / N_COLUMNAS + 1);
    output << cant_platos_no_atendidos << setw(TAM_REPORTE / N_COLUMNAS + 4);
    output << descuento_plato << '%' << setw(TAM_REPORTE / N_COLUMNAS + 3);
    output << monto_total_esperado << setw(TAM_REPORTE / N_COLUMNAS + 2);
    output << monto_total_bruto << setw(TAM_REPORTE / N_COLUMNAS);
    output << monto_total_recibido << endl;
}





// Módulo que imprime el resumen de totales de los platos del reporte solicitado
void imprimir_resumen_de_totales(double total_del_monto_esperado,
                  double total_del_monto_bruto,double total_del_monto_recibido,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS - 7) + 12) << "TOTALES:";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) - 2) << total_del_monto_esperado;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) - 2) << total_del_monto_bruto;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) - 4) << total_del_monto_recibido;
    output << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}

/* ==================================================================================== */









/* =========================================================================================== */
/* ===========================  Funciones de auxiliares  ===================================== */
/* ================== (Funciones pequeñas que leen o actualizan datos) ======================= */
/* =========================================================================================== */


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


// Módulo que ignora hasta el delimitador
void ignorar_hasta_delimitador(char delimitador,ifstream &input){
    input >> ws; // Lectura de espacios en blanco
    while(input.get() != delimitador);
}



// Módulo que busca la posición de un arreglo
int buscar_posicion(int dato,int *arreglo,int cant_datos){
    for(int indice = 0; indice < cant_datos; indice++){
        if(arreglo[indice] == dato){
            return indice;
        }
    }
    return NO_ENCONTRADO;
}



// Módulo que actualiza el total de cantidad de platos atendidos y de no atendidos de un plato.
void actualizar_cantidad_de_platos_atendidos_y_no_atendidos(int &cant_atendida,
                        int cantidad_pedida,int cant_platos_preparados,
                        int &total_cant_platos_atendidos,int &total_cant_platos_no_atendidos){
    // Inicialización de la cantidad de platos atendidos.
    cant_atendida = 0;
    
    // Cálculo de la cantidad de platos atendidos.
    while(cant_atendida <= cantidad_pedida){
        cant_atendida++;
        if(cant_platos_preparados < cant_atendida + total_cant_platos_atendidos) break;
    }
    cant_atendida--;
    
    // Acumular la cantidad de platos atendidos de un plato.
    total_cant_platos_atendidos += cant_atendida;
    
    // Acumular la cantidad de platos no atendidos del total de un plato.
    total_cant_platos_no_atendidos += (cantidad_pedida - cant_atendida);
}




// Módulo que actualiza el total de monto bruto y el total del monto recibido de un plato
void actualizar_monto_bruto_y_monto_recibido(double &total_monto_bruto,
                    double &total_monto_recibido,int cant_atendida,double precio_plato,
                    double descuento_plato,double descuento_cliente){
    double monto_bruto,monto_con_descuento_plato,monto_con_descuento_cliente;
    monto_bruto = cant_atendida * precio_plato;
    total_monto_bruto += monto_bruto;
    total_monto_recibido += monto_bruto * (1  -  descuento_plato / 100  -  descuento_cliente / 100);
}



// Módulo que intercambia datos de tipo "int"
void intercambiar_int(int &dato_1,int &dato_2){
    int auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}



// Módulo que intercambia datos de tipo "double"
void intercambiar_double(double &dato_1,double &dato_2){
    double auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}



/* ==================================================================================== */








/* ========================================================================================= */
/* ============================  Funciones de soporte  ===================================== */
/* ============== (Funciones que aperturan archivos de lectura como de escritura) ========== */
/* ========================================================================================= */


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
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

/* ==================================================================================== */

