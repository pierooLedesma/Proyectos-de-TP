

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de abril de 2025, 08:51 PM
 */

#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/






// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/






// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "EMPRESA DE REPARTOS A DOMICILIO TP S.  A." << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "ENTREGAS QUE DEBEN REALIZAR LOS REPARTIDORES" << endl;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que imprime los encabezdos del reporte (de repartidores y de platos solicitados)
void imprimir_encabezados(bool esRepartidor,ofstream &output){
    if(esRepartidor){
        // Imprimir encabezado de los repartidores
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 6) - 3);
        output << "NOMBRE";
        output << setw(TAM_REPORTE / (TAM_COLUMNAS - 1) - 3);
        output << "DNI";
        output << setw(TAM_REPORTE / TAM_COLUMNAS - 5);
        output << "VEHICULO";
        output << setw(TAM_REPORTE / TAM_COLUMNAS);
        output << "DISTRITO A ATENDER" << endl;
    } else {
        // Imprimir encabezado de los platos solicitados
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 1) + 2);
        output << "PLATOS SOLICITADOS:" << endl;
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 4) + 2);
        output << "CODIGO";
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 6) + 1);
        output << "CANTIDAD";
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 6) + 1);
        output << "PRECIO";
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 3) + 1);
        output << "SUBTOTAL" << endl;
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/






// Módulo que imprime las líneas del reporte solicitado
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/








// Módulo que lee e imprime una cadena de caracteres
void leer_and_imprimir_cadena_de_caracteres(bool es_vehiculo,bool imprimir_cambio_de_linea,
        bool pasar_todo_a_mayuscula,char delimitador,ifstream &input,ofstream &output){
    int n_caracteres = 0;
    bool mayuscula;
    input >> ws; // Lectura de espacios en blanco
    while(true){
        char c = input.get(); // Lectura de un caracter
        if(c == delimitador) break;
        if(c == '/'    or    c == '-') c = ' '; // Se cambia el caracter leído a un espacio en blanco
        else if(pasar_todo_a_mayuscula)  c = (c >= 'a'  and  c <= 'z'  ?  c - 'a' + 'A' : c);
        output.put(c); // Impresión del caracter
        n_caracteres++;
    }
    if(not imprimir_cambio_de_linea){
        int longitud_total;
        if(es_vehiculo) longitud_total = TAM_REPORTE / (TAM_COLUMNAS + 2) - 1;
        else  longitud_total = TAM_REPORTE / (TAM_COLUMNAS - 1);
        for(int i=0; i < longitud_total - n_caracteres; i++) output.put(' ');
    } else  output << endl;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/








// Módulo que lee e imprime los datos de un repartidor del archivo "Repartidores.txt"
void leer_and_imprimir_datos_del_repartidor(int dni,char &vehiculo,int &cod_distrito,
        int n_repartidores,ifstream &input_repartidores,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setfill('0') << setw(2) << n_repartidores << setfill(' ') << " REPARTIDOR:" << endl;
    imprimir_encabezados(true,output);
    
    output << setw(3) << ' ';
    leer_and_imprimir_cadena_de_caracteres(false,false,true,' ',input_repartidores,output);
    
    output << left << setw(TAM_REPORTE / (TAM_COLUMNAS + 2)) << dni << right;
    
    input_repartidores >> ws;
    input_repartidores >> vehiculo;
    output.put(vehiculo);
    leer_and_imprimir_cadena_de_caracteres(true,false,true,' ',input_repartidores,output);
    
    input_repartidores >> cod_distrito;
    output << left << setw(TAM_REPORTE / (TAM_COLUMNAS + 7) - 3) << cod_distrito << right;
    leer_and_imprimir_cadena_de_caracteres(false,true,false,'\n',input_repartidores,output);
    
    elaborar_lineas('-',TAM_REPORTE,output);
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que imprime un pedido del cliente
void imprimir_un_pedido_del_cliente(int n_platos_pedidos,int cod_plato_leido,int cantidad_pedida,
                                    double precio_del_plato,double subtotal,ofstream &output){
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 10) - 1) << ' ';
    output << setfill('0') << setw(2) << n_platos_pedidos << setfill(' ');
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 10) - 1) << cod_plato_leido;
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 6) - 1) << cantidad_pedida;
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 3) - 1) << precio_del_plato;
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 3)) << subtotal << endl;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que busca en el arreglo de "códigos de platos" el código de un plato leído
// y, en caso que se encuentre, retornará el índice del arreglo de los  "códigos de platos".
int buscar_precio_del_plato(int cod_plato_leido,int *arr_cod_plato,int cant_platos){
    for(int indice = 0; indice < cant_platos; indice++){
        if(cod_plato_leido == arr_cod_plato[indice]) return indice;
    }
    return NO_ENCONTRADO; // No se encontró en el arreglo de "códigos de platos"
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que procesa la lista de platos de un cliente del archivo "RepartosARealizar.txt"
void procesar_lista_de_platos_pedidos_por_el_cliente(double &total_a_pagar,
                        ifstream &input_repartos,ofstream &output,int *arr_cod_plato,
                        double *arr_precio_plato,int cant_platos){
    int cantidad_pedida,cod_plato_leido,posicion_plato,n_platos_pedidos = 0;
    double subtotal;
    imprimir_encabezados(false,output);
    while(true){
        input_repartos >> cantidad_pedida >> cod_plato_leido;
        posicion_plato = buscar_precio_del_plato(cod_plato_leido,arr_cod_plato,cant_platos);
        if(posicion_plato != NO_ENCONTRADO){
            n_platos_pedidos++;
            subtotal = cantidad_pedida * arr_precio_plato[posicion_plato];
            imprimir_un_pedido_del_cliente(n_platos_pedidos,cod_plato_leido,cantidad_pedida,
                                           arr_precio_plato[posicion_plato],subtotal,output);
            total_a_pagar += subtotal;
        }
        if(input_repartos.get() == '\n') break;
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/








// Módulo que calcula el pago al repartidor (10% al "total a pagar" si el vehículo es en 
// motocicleta y 5% al "total a pagar" si el vehículo es en bicicleta).
double calcular_pago_al_repartidor(char vehiculo,double total_a_pagar){
    double pago_al_repartidor;
    if(vehiculo == 'M') pago_al_repartidor = total_a_pagar * ((double)10 / 100);
    else pago_al_repartidor = total_a_pagar * ((double)5 / 100);
    return pago_al_repartidor;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/









// Módulo que imprime los montos totales de un cliente ( "total a pagar", "pago al repartidor"
// y el "total recaudado" que es la suma de "total a pagar" con "pago al repartidor" ).
void impresion_de_totales_de_un_cliente(double total_a_pagar,double pago_al_repartidor,
                                                                         ofstream &output){
    elaborar_lineas('-',TAM_REPORTE / 2  + 5,output);
    
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 2) + 1) << "TOTAL A PAGAR:";
    output << setw(TAM_REPORTE / (TAM_COLUMNAS - 1) - 1) << total_a_pagar << endl;
    
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 1) + 2) << "PAGO AL REPARTIDOR:";
    output << setw(TAM_REPORTE / (TAM_COLUMNAS - 1) - 6) << pago_al_repartidor << endl;
    
    elaborar_lineas('-',TAM_REPORTE / 2  + 5,output);
    
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 2) + 3) << "TOTAL RECAUDADO:";
    output << setw(TAM_REPORTE / (TAM_COLUMNAS - 1) - 3);
    output << total_a_pagar + pago_al_repartidor << endl;
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/









// Módulo que procesa el archivo "RepartosARealizar.txt". Imprime la información del reparto
// si el código del distrito leído con el código del distrito del cliente y el vehículo del repartidor
// con el vehículo que desea el cliente que se lleve el pedido coiniciden.
void procesar_repartos(char vehiculo,int cod_distrito,ifstream &input_repartos,
                       ofstream &output,int *arr_cod_plato,double *arr_precio_plato,
                       int cant_platos,int &n_clientes,
                       double &total_recaudado_por_todos_los_pedidos,
                       double &total_a_pagar_a_los_repartidores){
    int cod_distrito_cliente;
    char vehiculo_que_desea_el_cliente;
    input_repartos.clear(); // Libera el buffer del archivo "RepartosARealizar.txt" y limpia las banderas levantadas
    input_repartos.seekg(0,ios::beg); // Devuelve el puntero al inicio del archivo "RepartosARealizar.txt"
    while(true){
        input_repartos >> cod_distrito_cliente;
        if(input_repartos.eof()) break; // Validar fin del archivo "RepartosARealizar.txt"
        input_repartos >> vehiculo_que_desea_el_cliente;
        if(cod_distrito == cod_distrito_cliente   and   vehiculo == vehiculo_que_desea_el_cliente){
            double total_a_pagar = 0.0, pago_al_repartidor;
            n_clientes++;
            if(n_clientes != 1) elaborar_lineas('=',TAM_REPORTE / 2  + 5,output);
            output << setw(3) << ' ' << setfill('0') << setw(2) << n_clientes << setfill(' ') << setw(2) << ' '; 
            leer_and_imprimir_cadena_de_caracteres(false,true,false,']',input_repartos,output);
            procesar_lista_de_platos_pedidos_por_el_cliente(total_a_pagar,input_repartos,output,
                                                            arr_cod_plato,arr_precio_plato,cant_platos);
            pago_al_repartidor = calcular_pago_al_repartidor(vehiculo,total_a_pagar);
            impresion_de_totales_de_un_cliente(total_a_pagar,pago_al_repartidor,output);
            total_a_pagar_a_los_repartidores += pago_al_repartidor;
            total_recaudado_por_todos_los_pedidos += total_a_pagar + pago_al_repartidor;
        } else {
            while(input_repartos.get() != '\n'); // Descartar reparto realizado
        }
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/









// Módulo que procesa el archivo "Repartidores.txt". Imprime la información de cada repartidor.
void procesar_repartidores(double &total_recaudado_por_todos_los_pedidos,
                           double &total_a_pagar_a_los_repartidores,
                           ifstream &input_repartidores,ifstream &input_repartos,
                           ofstream &output,int *arr_cod_plato,double *arr_precio_plato,
                           int cant_platos){
    int dni,cod_distrito,n_repartidores = 0;
    char vehiculo;
    while(true){
        input_repartidores >> dni;
        if(input_repartidores.eof()) break; // Validar fin de archivo "Repartidores.txt"
        n_repartidores++;
        leer_and_imprimir_datos_del_repartidor(dni,vehiculo,cod_distrito,n_repartidores,
                                               input_repartidores,output);
        int n_clientes = 0;
        output << setw(TAM_REPORTE / (TAM_COLUMNAS + 2) + 1);
        output << "CLIENTES A ATENDER" << endl;
        procesar_repartos(vehiculo,cod_distrito,input_repartos,output,arr_cod_plato,
                          arr_precio_plato,cant_platos,n_clientes,
                          total_recaudado_por_todos_los_pedidos,total_a_pagar_a_los_repartidores);
    }
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/








// Módulo que imprime el resumen del reporte solicitado
void imprimir_resumen_del_reporte(double total_recaudado_por_todos_los_pedidos,
                            double total_a_pagar_a_los_repartidores,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    
    output << "TOTAL RECAUDADO POR LOS PEDIDOS SOLICITADOS:";
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 3) - 1);
    output << total_recaudado_por_todos_los_pedidos << endl;
    
    output << "TOTAL A PAGAR A LOS REPARTIDORES:";
    output << setw(TAM_REPORTE / (TAM_COLUMNAS + 1) + 3);
    output << total_a_pagar_a_los_repartidores << endl;
    
    elaborar_lineas('=',TAM_REPORTE,output);
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que procesa el reporte solicitado, apertura los archivos de lectura y de escritura
// e imprime toda la información correspondiente.
void procesar_reporte(const char *nombre_archivo_repartidores,
                      const char *nombre_archivo_repartos,
                      const char *nombre_archivo_reporte,
                      int *arr_cod_plato,double *arr_precio_plato,int cant_platos){
    ifstream input_repartidores,input_repartos;
    ofstream output;
    double total_recaudado_por_todos_los_pedidos = 0.0,
                total_a_pagar_a_los_repartidores = 0.0;
    aperturar_archivo_lectura(nombre_archivo_repartidores,input_repartidores);
    aperturar_archivo_lectura(nombre_archivo_repartos,input_repartos);
    aperturar_archivo_escritura(nombre_archivo_reporte,output);
    imprimir_titulo(output);
    output << fixed << setprecision(2);
    procesar_repartidores(total_recaudado_por_todos_los_pedidos,
                          total_a_pagar_a_los_repartidores,
                          input_repartidores,input_repartos,output,
                          arr_cod_plato,arr_precio_plato,cant_platos);
    imprimir_resumen_del_reporte(total_recaudado_por_todos_los_pedidos,
                                 total_a_pagar_a_los_repartidores,output);
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/







// Módulo que ignora una cadena de caracteres
void ignorar_cadena_caracteres(int longitud_cadena,char delimitador,ifstream &input){
    input >> ws;
    input.ignore(longitud_cadena,delimitador);
}
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
/**********************************************************************************************************************************/






// Módulo que procesa el archivo "PlatosOfrecidos.txt". Llena en arreglos los valores numéricos.
void procesar_platos_ofrecidos(const char *nombre_archivo_platos,int *arr_cod_plato,
                               double *arr_precio_plato,int &cant_platos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo_platos,input);
    cant_platos = 0;
    while(true){
        input >> arr_cod_plato[cant_platos];
        if(input.eof()) break; // Validar el fin del archivo "PlatosOfrecidos.txt"
        ignorar_cadena_caracteres(45,' ',input);
        input >> arr_precio_plato[cant_platos];
        ignorar_cadena_caracteres(10,'\n',input);
        cant_platos++;
    }
}
