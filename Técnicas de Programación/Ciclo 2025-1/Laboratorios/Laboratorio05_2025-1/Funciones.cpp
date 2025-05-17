

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 14 de mayo de 2025, 05:32 PM
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



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que elabora las líneas del reporte solicitado
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++)  output.put(caracter);
    output << endl;
}



// Módulo que imprime los títulos de las empresas y de las infracciones
void imprimir_titulos(bool es_empresa,ofstream &output){
    if(es_empresa){
        output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
        output << "MINISTERIO DE TRANSPORTE" << endl;
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "MULTAS IMPUESTAS A LAS COMPANIAS" << endl;
    } else {
        output << endl;
        output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
        output << "MULTAS IMPUESTAS POR INFRACCION" << endl;
    }
}




// Módulo que imprime el encabezado de las empresas y de las infracciones
void imprimir_encabezados(bool es_empresa,ofstream &output){
    if(es_empresa){
        elaborar_lineas('-',TAM_REPORTE,output);
        output << "MULTAS APLICADAS SEGUN LA GRAVEDAD:" << endl;
        output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 4)) << "LEVES";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1)) << "GRAVES";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 2) << "MUY GRAVES";
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 1) << "TOTALES" << endl;
        output << setw(4) << ' ';
        for(int i=1; i < N_COLUMNAS - 1; i++){
            output << "CANTIDAD";
            output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 4) << "TOTAL DE MULTAS";
            output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 4) - 9) << ' ';
        }
        output << "EN CANTIDAD";
        output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 4) - 4) << "EN MULTAS" << endl;
    } else {
        elaborar_lineas('=',TAM_REPORTE,output);
        output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 5) << "CODIGO";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 1) << "GRAVEDAD";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 4) << "MULTA";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2) << "CANTIDAD";
        output << setw(TAM_REPORTE / (N_COLUMNAS + 3)) << "MONTO TOTAL" << endl;
    }
}




// Módulo que imprime las cantidad y el total de las multas de una empresa
void imprimir_cantidades_y_multas_de_una_empresa(int cant_faltas_leves,
                double total_multas_leves,int cant_faltas_graves,double total_multas_graves,
                int cant_faltas_muy_graves,double total_multas_muy_graves,int cant_faltas_totales,
                double total_multas,ofstream &output){
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 6) - 5);
    output << cant_faltas_leves;
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 5);
    output << total_multas_leves;
    
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 6);
    output << cant_faltas_graves;
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 5);
    output << total_multas_graves;
    
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 6);
    output << cant_faltas_muy_graves;
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 5);
    output << total_multas_muy_graves;
    
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 4);
    output << cant_faltas_totales;
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 1) + 2) - 6);
    output << total_multas;
    output << endl;
}



// Módulo que imprime los datos de de una infracción
void imprimir_datos_de_una_infraccion(int cod_infraccion,char gravedad,
                double valor_multa,int cant_impuesta_por_infraccion,
                double monto_total_por_infraccion,ofstream &output){
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 4) << cod_infraccion;
    output << setw(N_COLUMNAS + 2) << ' ';
    imprimir_gravedad(gravedad,output);
    output << setw(7) << valor_multa;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 5) << cant_impuesta_por_infraccion;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 2) << monto_total_por_infraccion;
    output << endl;
}




// Módulo que imprime la gravedad de una infracción
void imprimir_gravedad(char gravedad,ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 4) - 1);
    
    if(gravedad == 'L') output << "LEVE";
    else if(gravedad == 'G') output << "GRAVE";
    else  output << "MUY GRAVE";  // gravedad == 'M'
    
    output << right;
}




// Módulo que imprime el resumen de infracciones (la cantidad total impuestas
// por las infracciones y el total del monto total de las infracciones).
void imprimir_resumen_de_totales_de_infracciones(int total_de_cantidad,
                                                 double total_de_monto_total,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 5) << "TOTAL";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 1) + 4) << total_de_cantidad;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 2) - 1) << total_de_monto_total << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}




// Módulo que ignora todo lo que se lee de un archivo hasta un delimitador
void ignorar_hasta_delimitador(char delimitador,ifstream &input){
    input >> ws; // Lectura de espacios en blanco
    while(input.get() != delimitador);
}


// Módulo que lee un dato de tipo "int"
int leer_dato_tipo_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "double"
double leer_dato_tipo_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "char"
char leer_dato_tipo_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}



// Módulo que lee una placa de la forma: P559-672
void leer_placa(char &tipo_vehiculo,int &num_placa_1,
                int &num_placa_2,ifstream &input){
    tipo_vehiculo = leer_dato_tipo_char(input);
    num_placa_1 = leer_dato_tipo_int(input);
    input.get(); // Lectura del guion
    num_placa_2 = leer_dato_tipo_int(input);
}



// Módulo que lee una fecha de la forma: DD/MM/AAAA
void leer_fecha(ifstream &input){
    int dia, mes, anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
}





// Módulo que busca la posición del representante legal (empresa) a partir de una placa específica.
int buscar_posicion_dni_representante(char tipo_vehiculo_leido,
        int num_placa_1_leido,int num_placa_2_leido,int *arr_dni_placa,
        char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,
        int cant_vehiculos,int *arr_dni_representante,int cant_empresas){
    
    // Buscar la placa en los arreglos de vehículos.
    for(int i = 0; i < cant_vehiculos; i++){
        if( tipo_vehiculo_leido == arr_tipo_vehiculo[i] and
                num_placa_1_leido == arr_num_placa_1[i] and
                num_placa_2_leido == arr_num_placa_2[i] ){
            
            // Si la placa leída y una placa registrada en la posición 'i' de los arreglos
            // de vehículos coinciden, entonces se obtiene el DNI del propietario de esa placa.
            int dni_placa = arr_dni_placa[i];
            
            // Buscar el índice del DNI encontrado anteriormente en el arreglo de
            // DNI's de representantes legales ("arr_dni_representante").
            for(int j=0; j < cant_empresas; j++){
                if( dni_placa == arr_dni_representante[j] ){
                    return j; // Se encontró la empresa que corresponde a la placa.
                }
            }
            return NO_ENCONTRADO; // No se encontró el DNI en el arreglo de representantes legales.
        }
    }
    return NO_ENCONTRADO; // No se encontró la placa en los arreglos de vehículos.
}




// Módulo que busca la posición de una infracción específica en los arreglos de infracciones.
int buscar_posicion_infracciones(char gravedad_leida,int cod_infraccion_leida,
                            char *arr_gravedad,int *arr_cod_infraccion,int cant_infracciones){
    // Se recorre el arreglo de infracciones.
    for(int indice = 0; indice < cant_infracciones; indice ++){
        if(gravedad_leida == arr_gravedad[indice] and
                cod_infraccion_leida == arr_cod_infraccion[indice]){
            return indice; // Se retorna la posición en los arreglos de la infracción buscada.
        }
    }
    return NO_ENCONTRADO; // No se encontró la infracción buscada en los arreglos.
}


// Módulo que intercambia datos de tipo  " int "
void intercambiar_int(int &dato_1,int &dato_2){
    int auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}



// Módulo que intercambia datos de tipo  " double "
void intercambiar_double(double &dato_1,double &dato_2){
    double auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}



// Módulo que intercambia datos de tipo  " char "
void intercambiar_char(char &dato_1,char &dato_2){
    char auxiliar;
    auxiliar = dato_1;
    dato_1 = dato_2;
    dato_2 = auxiliar;
}





// Módulo que imprime las multas impuestas por las empresas
void imprimir_empresas(int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas,ofstream &output){
    imprimir_titulos(true,output);
    for(int indice = 0; indice < cant_empresas; indice++){
        elaborar_lineas('=',TAM_REPORTE,output);
        output << "COMPANIA No." << setw(3) << indice + 1 << setw(3) << ' ';
        output << "DNI DEL REPRESENTANTE LEGAL: " << arr_dni_representante[indice] << endl;
        imprimir_encabezados(true,output);
        imprimir_cantidades_y_multas_de_una_empresa(arr_cant_faltas_por_empresa[4*indice],
                arr_total_multas_por_empresa[4*indice],arr_cant_faltas_por_empresa[4*indice + 1],
                arr_total_multas_por_empresa[4*indice + 1],arr_cant_faltas_por_empresa[4*indice + 2],
                arr_total_multas_por_empresa[4*indice + 2],arr_cant_faltas_por_empresa[4*indice + 3],
                arr_total_multas_por_empresa[4*indice + 3],output);
    }
}








// Módulo que imprime las multas impuestas por infracción
void imprimir_infracciones(int *arr_cod_infraccion,char *arr_gravedad,
            double *arr_valor_multa,int *arr_cant_impuesta_por_infraccion,
            double *arr_monto_total_por_infraccion,int cant_infracciones,ofstream &output){
    int total_de_cantidad = 0;
    double total_de_monto_total = 0.0;
    imprimir_titulos(false,output);
    imprimir_encabezados(false,output);
    for(int indice = 0; indice < cant_infracciones; indice++){
        imprimir_datos_de_una_infraccion(arr_cod_infraccion[indice],arr_gravedad[indice],
                                arr_valor_multa[indice],arr_cant_impuesta_por_infraccion[indice],
                                arr_monto_total_por_infraccion[indice],output);
        total_de_cantidad += arr_cant_impuesta_por_infraccion[indice];
        total_de_monto_total += arr_monto_total_por_infraccion[indice];
    }
    imprimir_resumen_de_totales_de_infracciones(total_de_cantidad,
                                                total_de_monto_total,output);
}



// Módulo que imprime el reporte solicitado
void emitir_reporte(const char *nombre_archivo,int *arr_cod_infraccion,
            char *arr_gravedad,double *arr_valor_multa,
            int *arr_cant_impuesta_por_infraccion,double *arr_monto_total_por_infraccion,
            int cant_infracciones,int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_empresas(arr_dni_representante,arr_cant_faltas_por_empresa,
                      arr_total_multas_por_empresa,cant_empresas,output);
    elaborar_lineas('/',TAM_REPORTE,output);
    imprimir_infracciones(arr_cod_infraccion,arr_gravedad,arr_valor_multa,
            arr_cant_impuesta_por_infraccion,arr_monto_total_por_infraccion,
            cant_infracciones,output);
}




// Módulo que ordena los arreglos de forma ascendente por el DNI del representante legal
void ordenar_empresas(int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas){
    for(int i=0; i < cant_empresas - 1; i++){
        for(int k=i+1; k < cant_empresas; k++){
            if(arr_dni_representante[i] > arr_dni_representante[k]){
                intercambiar_int(arr_dni_representante[i],arr_dni_representante[k]);
                intercambiar_int(arr_cant_faltas_por_empresa[4*i],
                                 arr_cant_faltas_por_empresa[4*k]);
                intercambiar_int(arr_cant_faltas_por_empresa[4*i + 1],
                                 arr_cant_faltas_por_empresa[4*k + 1]);
                intercambiar_int(arr_cant_faltas_por_empresa[4*i + 2],
                                 arr_cant_faltas_por_empresa[4*k + 2]);
                intercambiar_int(arr_cant_faltas_por_empresa[4*i + 3],
                                 arr_cant_faltas_por_empresa[4*k + 3]);
                intercambiar_double(arr_total_multas_por_empresa[4*i],
                                    arr_total_multas_por_empresa[4*k]);
                intercambiar_double(arr_total_multas_por_empresa[4*i + 1],
                                    arr_total_multas_por_empresa[4*k + 1]);
                intercambiar_double(arr_total_multas_por_empresa[4*i + 2],
                                    arr_total_multas_por_empresa[4*k + 2]);
                intercambiar_double(arr_total_multas_por_empresa[4*i + 3],
                                    arr_total_multas_por_empresa[4*k + 3]);
            }
        }
    }
}




// Módulo que ordena las infracciones por el código de infracción (la parte numérica)
void ordenar_infracciones(int *arr_cod_infraccion,char *arr_gravedad,
            double *arr_valor_multa,int *arr_cant_impuesta_por_infraccion,
            double *arr_monto_total_por_infraccion,int cant_infracciones){
    for(int i=0; i < cant_infracciones - 1; i++){
        for(int k=i+1; k < cant_infracciones; k++){
            if(arr_cod_infraccion[i] > arr_cod_infraccion[k]){
                intercambiar_int(arr_cod_infraccion[i],arr_cod_infraccion[k]);
                intercambiar_char(arr_gravedad[i],arr_gravedad[k]);
                intercambiar_double(arr_valor_multa[i],arr_valor_multa[k]);
                intercambiar_int(arr_cant_impuesta_por_infraccion[i],
                                 arr_cant_impuesta_por_infraccion[k]);
                intercambiar_double(arr_monto_total_por_infraccion[i],
                                    arr_monto_total_por_infraccion[k]);
            }
        }
    }
}




// Módulo que ordena los arreglos.
void ordenar_datos(int *arr_cod_infraccion,char *arr_gravedad,double *arr_valor_multa,
            int *arr_cant_impuesta_por_infraccion,double *arr_monto_total_por_infraccion,
            int cant_infracciones,int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas){
    ordenar_empresas(arr_dni_representante,arr_cant_faltas_por_empresa,
                     arr_total_multas_por_empresa,cant_empresas);
    ordenar_infracciones(arr_cod_infraccion,arr_gravedad,arr_valor_multa,
            arr_cant_impuesta_por_infraccion,arr_monto_total_por_infraccion,
            cant_infracciones);
}






// Módulo que actualiza las cantidades y montos de una empresa y de una infracción
void actualizar_cantidades_y_montos(char gravedad,double valor_multa,
             int &cant_impuesta_por_infraccion,double &arr_monto_total_por_infraccion,
             int &cant_faltas_leves_por_empresa,int &cant_faltas_graves_por_empresa,
             int &cant_faltas_muy_graves_por_empresa,int &cant_faltas_totales_por_empresa,
             double &total_multas_leves_por_empresa,double &total_multas_graves_por_empresa,
             double &total_multas_muy_graves_por_empresa,double &total_multas_totales_por_empresa){
    
    /************** Actualización de cantidad y monto de una infracción. ********************/
    cant_impuesta_por_infraccion++;
    arr_monto_total_por_infraccion += valor_multa;
    
    
    /************** Actualización de cantidades y montos de una empresa. ****************/
    cant_faltas_leves_por_empresa += (gravedad == 'L'  ?   1 : 0);
    total_multas_leves_por_empresa += (gravedad == 'L'  ?   valor_multa : 0);
    
    cant_faltas_graves_por_empresa += (gravedad == 'G'  ?   1 : 0);
    total_multas_graves_por_empresa += (gravedad == 'G'  ?   valor_multa : 0);
    
    cant_faltas_muy_graves_por_empresa += (gravedad == 'M'  ?   1 : 0);
    total_multas_muy_graves_por_empresa += (gravedad == 'M'  ?   valor_multa : 0);
    
    cant_faltas_totales_por_empresa++;
    total_multas_totales_por_empresa += valor_multa;
}





// Módulo que lee el archivo "InfraccionesCometidas.txt". Mediante este archivo
// se actualizan las cantidad y montos de los respectivos arreglos.
void leer_infracciones_cometidas(const char *nombre_archivo,int *arr_cod_infraccion,
            char *arr_gravedad,double *arr_valor_multa,int *arr_cant_impuesta_por_infraccion,
            double *arr_monto_total_por_infraccion,int cant_infracciones,
            int *arr_dni_representante,int *arr_cant_faltas_por_empresa,
            double *arr_total_multas_por_empresa,int cant_empresas,int *arr_dni_placa,
            char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,int cant_vehiculos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    char tipo_vehiculo_leido,gravedad_leida;
    int num_placa_1_leido,num_placa_2_leido,cod_infraccion_leida,pos_dni_representante,pos_infraccion;
    while(true){
        leer_fecha(input);
        if(input.eof()) break; // Validar fin del archivo "InfraccionesCometidas.txt"
        leer_placa(tipo_vehiculo_leido,num_placa_1_leido,num_placa_2_leido,input);
        gravedad_leida = leer_dato_tipo_char(input);
        cod_infraccion_leida = leer_dato_tipo_int(input);
        pos_dni_representante = buscar_posicion_dni_representante(tipo_vehiculo_leido,num_placa_1_leido,
                                      num_placa_2_leido,arr_dni_placa,arr_tipo_vehiculo,arr_num_placa_1,
                                      arr_num_placa_2,cant_vehiculos,arr_dni_representante,cant_empresas);
        pos_infraccion = buscar_posicion_infracciones(gravedad_leida,cod_infraccion_leida,arr_gravedad,
                                                      arr_cod_infraccion,cant_infracciones);
        if(pos_dni_representante != NO_ENCONTRADO    and    pos_infraccion != NO_ENCONTRADO){
            actualizar_cantidades_y_montos(arr_gravedad[pos_infraccion],arr_valor_multa[pos_infraccion],
                    arr_cant_impuesta_por_infraccion[pos_infraccion],arr_monto_total_por_infraccion[pos_infraccion],
                    arr_cant_faltas_por_empresa[4*pos_dni_representante],
                    arr_cant_faltas_por_empresa[4*pos_dni_representante +1],
                    arr_cant_faltas_por_empresa[4*pos_dni_representante +2],
                    arr_cant_faltas_por_empresa[4*pos_dni_representante +3],
                    arr_total_multas_por_empresa[4*pos_dni_representante],
                    arr_total_multas_por_empresa[4*pos_dni_representante +1],
                    arr_total_multas_por_empresa[4*pos_dni_representante +2],
                    arr_total_multas_por_empresa[4*pos_dni_representante +3]);
        }
    }
}




// Módulo que procesa el archivo "PlacasRegistradas.txt" y almacena
// la información de los vehículos mediante su placa y el DNI del dueño del vehículo.
void leer_placas_registradas(const char *nombre_archivo,int *arr_dni_placa,
        char *arr_tipo_vehiculo,int *arr_num_placa_1,int *arr_num_placa_2,int &cant_vehiculos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int dni_placa;
    cant_vehiculos = 0;
    while(true){
        dni_placa = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "PlacasRegistradas.txt"
        arr_dni_placa[cant_vehiculos] = dni_placa;
        leer_placa(arr_tipo_vehiculo[cant_vehiculos],arr_num_placa_1[cant_vehiculos],
                   arr_num_placa_2[cant_vehiculos],input);
        cant_vehiculos++;
    }
}




// Módulo que procesa el archivo "EmpresasRegistradas.txt" y almacena
// la información de los DNI's del representante legal en un arreglo.
void leer_empresas_registradas(const char *nombre_archivo,
                               int *arr_dni_representante,int &cant_empresas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int dni;
    cant_empresas = 0;
    while(true){
        dni = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "EmpresasRegistradas.txt"
        arr_dni_representante[cant_empresas] = dni;
        ignorar_hasta_delimitador(' ',input);
        ignorar_hasta_delimitador('\n',input);
        cant_empresas++;
    }
}




// Módulo que procesa el archivo "TablaDeInfracciones.txt" y almacena la
// información de los códigos de infracción y los valores de la multa en arreglos.
void leer_tabla_infracciones(const char *nombre_archivo,int *arr_cod_infraccion,
                             char *arr_gravedad,double *arr_valor_multa,int &cant_infracciones){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    char gravedad;
    cant_infracciones = 0;
    while(true){
        gravedad = input.get();
        if(input.eof()) break; // Validar fin del archivo "TablaDeInfracciones.txt"
        arr_gravedad[cant_infracciones] = gravedad;
        arr_cod_infraccion[cant_infracciones] = leer_dato_tipo_int(input);
        arr_valor_multa[cant_infracciones] = leer_dato_tipo_double(input);
        ignorar_hasta_delimitador('\n',input);
        cant_infracciones++;
    }
}

