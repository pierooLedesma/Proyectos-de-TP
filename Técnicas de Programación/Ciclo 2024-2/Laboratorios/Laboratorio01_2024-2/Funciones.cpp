

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de abril de 2025, 12:21 PM
 */


#include "Funciones.h"


// Módulo que lee y procesa el archivo "EmpresaDeEnvios.txt". Se procesan estos datos y se imprime el reporte
void leer_y_procesar_envios(){
    int fecha,dni,dni_menor,dni_mayor;
    double menor_distancia = 1e9, mayor_distancia = 0;
    cout << fixed << setprecision(2);
    fecha = leer_fecha();
    imprimir_titulo_and_subtitulo("EMPRESA DE REPARTOS A DOMICILO TP S. A.",
            "FECHA DE LOS REPARTOS",fecha);
    while(true){
        cin >> dni;
        if(cin.eof()) break;
        leer_nombre_and_dni(dni);
        procesar_datos_entrega(dni,menor_distancia,dni_menor,mayor_distancia,dni_mayor);
    }
    imprimir_resumen(menor_distancia,dni_menor,mayor_distancia,dni_mayor);
}




// Módulo que lee la fecha lo retorna como un valor entero
int leer_fecha(){
    int dia,mes,anio;
    char slash;
    cin >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que imprime el título y el subtítulo del reporte
void imprimir_titulo_and_subtitulo(const char *titulo,const char *subtitulo,int fecha){
    cout << setw((TAM_REPORTE + CANT_CARAC_TITULO)/2) << titulo << endl;
    cout << setw((TAM_REPORTE - CANT_CARAC_SUBTITULO)/2  + 15) << subtitulo;
    cout << left << setw(2) << ':' << right << setfill('0') << setw(2) << fecha%100 << '/';
    cout << setw(2) << fecha/100%100 << '/' << fecha/10000 << setfill(' ') << endl;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que lee e imprimir caracter por caracter el nombre, también se imprime el dni
void leer_nombre_and_dni(int dni){
    char caracter;
    int cant_caracteres = 0;
    
    elaborar_lineas('=',TAM_REPORTE);
    cout << "Repartidor :" << endl;
    cout << "Nombre: ";
    cin >> ws; // Leer los esapcios en blanco
    
    // Proceso de leer e imprimir caracter por caracter
    while(true){
        caracter = cin.get(); // Lectura de un caracter
        if(caracter == ' ') break; // Salgo del bucle si se lee un espacio en blanco
        if(caracter == '/'  or  caracter == '-') caracter = ' ';
        cout.put(caracter); // Impresión del caracter
        cant_caracteres++;
    }
    
    // Impresión de espacios en blanco
    for(int i=0; i < TAM_NOMBRE - cant_caracteres; i++) cout.put(' ');
    cout << "DNI: " << dni << endl; // Imprimir el DNI del repartidor
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/





// Módulo que procesa el juego de datos de las entregas, actualiza distancias e imprime algunas partes del reporte
void procesar_datos_entrega(int dni,double &menor_distancia,int &dni_menor,double &mayor_distancia,
        int &dni_mayor){
    int tiempo_uno,tiempo_dos,cant_tramos=1;
    double velocidad,direccion,distancia,distancia_acumulada = 0.0,abscisa_1=0.0,ordenada_1=0.0,
            abscisa_2,ordenada_2,pago,pago_total = 0.0;
    imprimir_encabezado_tramos();
    tiempo_uno = leer_tiempo();
    while(true){
        leer_and_actualizar_los_datos_de_entrega_por_repartidor(velocidad,tiempo_dos,
                direccion,distancia,abscisa_2,ordenada_2,pago,pago_total,tiempo_uno);
        imprimir_datos_de_entrega(cant_tramos,tiempo_uno,tiempo_dos,velocidad,distancia,abscisa_1,
                ordenada_1,abscisa_2,ordenada_2,distancia_acumulada,pago,false);
        actualizar_datos_de_los_tramos(cant_tramos,tiempo_uno,tiempo_dos,abscisa_1,abscisa_2,
                ordenada_1,ordenada_2);
        if(cin.get() == '\n') break; // Salgo del bucle si se lee el cambio de línea
    }
    calcular_datos_faltantes_de_retorno(tiempo_uno,tiempo_dos,distancia,velocidad,abscisa_1,ordenada_1,
            abscisa_2,ordenada_2);
    imprimir_datos_de_entrega(cant_tramos,tiempo_uno,tiempo_dos,velocidad,distancia,abscisa_1,
                ordenada_1,abscisa_2,ordenada_2,distancia_acumulada,0.0,true);
    imprimir_pago_total_al_repartidor(pago_total);
    actualizar_distancias(dni,distancia_acumulada,menor_distancia,dni_menor,mayor_distancia,dni_mayor);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



// Imprimir encabezado de los tramos
void imprimir_encabezado_tramos(){
    elaborar_lineas('-',TAM_REPORTE);
    cout << "DATOS DE LA RUTA:" << endl;
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "HORA INI";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 8) << "HORA FIN";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 8) << "VELOCIDAD";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 8) << "DISTANCIA";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 5) << "PUNTO DE PARTIDA (X,Y)";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 5) << "PUNTO DE LLEGADA (X,Y)";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 3) << "DISTANCIA ACUMULADA";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "PAGO POR ENVIO" << endl;
}




// Módulo que lee una el juego de datos de las entregas que hizo el repartidor
void leer_and_actualizar_los_datos_de_entrega_por_repartidor(double &velocidad,int &tiempo_dos,
        double &direccion,double &distancia,double &abscisa_2,double &ordenada_2,
        double &pago,double &pago_total,int tiempo_uno){
    cin >> velocidad; // La velocidad leída está en kilometros por hora (k/h)
    tiempo_dos = leer_tiempo(); // El tiempo está en segundos
    direccion = leer_direccion(); // La dirección está en grados sexagesimales
    distancia = calcular_distancia(tiempo_dos - tiempo_uno,velocidad); // La distancia en kilómetros
    calcular_puntos(distancia,direccion,abscisa_2,ordenada_2);
    pago = calcular_pago_por_tramo(distancia); 
    pago_total += pago; // Se actualiza el pago total al repartidor
}






// Módulo que lee el tiempo y lo retorna en segundos
int leer_tiempo(){
    int hora,minuto,segundo;
    char dos_puntos;
    cin >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que lee el tiempo y lo retorna en grados sexagesimales
double leer_direccion(){
    int grado,minuto,segundo;
    char caracter;
    cin >> grado >> caracter >> minuto >> caracter >> segundo >> caracter;
    return grado + (double)minuto/60 + (double)segundo/3600;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que calcula la distancia en kilómetros
double calcular_distancia(int tiempo_en_segundos,double velocidad){
    return velocidad*((double)tiempo_en_segundos/3600);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que calcula los puntos (abscisa ; ordenada)
void calcular_puntos(double distancia,double direccion,double &abscisa,double &ordenada){
    double angulo_en_radianes = pasar_sexagesimal_a_radianes(direccion);
    abscisa = distancia * cos(angulo_en_radianes);
    ordenada = distancia * sin(angulo_en_radianes);
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



// Módulo que pasa de grados sexagesimales a radianes
double pasar_sexagesimal_a_radianes(double angulo_en_sexagesimales){
    return angulo_en_sexagesimales*M_PI/180;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



// Módulo que calcula el pago al repartidor por la distancia recorrida en un tramo
double calcular_pago_por_tramo(double distancia){
    if(distancia < 10.5) return 8.50;
    else if(distancia < 20.5) return 17.50;
    else if(distancia < 35.5) return 29.85;
    else return 45.69;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que imprime los datos de entrega de un tramo
void imprimir_datos_de_entrega(int cant_tramos,int &tiempo_uno,int tiempo_dos,double velocidad,
        double distancia,double abscisa_1,double ordenada_1,double abscisa_2,double ordenada_2,
        double &distancia_acumulada,double pago,bool es_el_retorno){
    if(not es_el_retorno) cout << "Tramo " << cant_tramos << left << setw(5) << ':' << right;
    else cout << left << setw(12) << "Retorno:" << right;
    
    imprimir_hora(tiempo_uno);
    cout << setw(4) << ' ';
    imprimir_hora(tiempo_dos);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 10) << velocidad;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 8) << distancia;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 13) << ' ';
    imprimir_puntos(abscisa_1,ordenada_1);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 10) << ' ';
    imprimir_puntos(abscisa_2,ordenada_2);
    
    distancia_acumulada += distancia; // Se actualiza la distancia acumulada en kilómetros
    cout << setw(TAM_REPORTE / N_COLUMNAS) << distancia_acumulada;
    
    if(pago > 0.0) cout << setw(TAM_REPORTE / N_COLUMNAS + 2) << pago << endl;
    else cout << endl;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que imprime la hora en el reporte
void imprimir_hora(int tiempo){
    if(tiempo / 3600 == 24  and  (tiempo / 60 % 60 > 0  or  tiempo % 60 > 0)) cout << "00" << ':';
    else cout << setfill('0') << setw(2) << tiempo / 3600 << ':';
    
    cout << setw(2) << tiempo / 60 % 60 << ':';
    cout << setw(2) << tiempo % 60 << setfill(' ');
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



// Módulo que imprime los puntos en el reporte
void imprimir_puntos(double abscisa,double ordenada){
    cout << setw(6) << abscisa << "  - " << setw(6) << ordenada;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que actualiza los datos de los tramos que faltan
void actualizar_datos_de_los_tramos(int &cant_tramos,int &tiempo_uno,int tiempo_dos,double &abscisa_1,
        double abscisa_2,double &ordenada_1,double ordenada_2){
    cant_tramos++;
    tiempo_uno = tiempo_dos;
    abscisa_1 = abscisa_2;
    ordenada_1 = ordenada_2;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que imprime el pago total
void imprimir_pago_total_al_repartidor(double pago_total){
    elaborar_lineas('-',TAM_REPORTE);
    cout << left << setw(27) << "PAGO TOTAL AL REPARTIDOR:" << right << pago_total << endl;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



// Módulo que calcula los datos faltanes para imprimir el retorno
void calcular_datos_faltantes_de_retorno(int tiempo_uno,int &tiempo_dos,double &distancia,
        double velocidad,double abscisa_1,double ordenada_1,double &abscisa_2,double &ordenada_2){
    abscisa_2 = 0.0;
    ordenada_2 = 0.0;
    distancia = sqrt(pow(abscisa_1- abscisa_2,2) + pow(ordenada_1- ordenada_2,2));
    tiempo_dos = (distancia / velocidad) * 3600 + tiempo_uno;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que actualiza las distancias de menor y mayor recorrido
void actualizar_distancias(int dni,double distancia_acumulada,double &menor_distancia,int &dni_menor,
        double &mayor_distancia,int &dni_mayor){
    if(menor_distancia > distancia_acumulada){
        menor_distancia = distancia_acumulada;
        dni_menor = dni;
    }
    if(mayor_distancia < distancia_acumulada){
        mayor_distancia = distancia_acumulada;
        dni_mayor = dni;
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que imprime el resumen de la mayor y menor distancia recorrida
void imprimir_resumen(double menor_distancia,int dni_menor,double mayor_distancia,int dni_mayor){
    elaborar_lineas('/',TAM_REPORTE);
    cout << "REPARTIDOR CON MAYOR RECORRIDO:" << endl;
    cout << "DNI:" << setw(15) << dni_mayor << endl;
    cout << "Distancia:" << setw(7) << mayor_distancia << setw(4) << "km." << endl;
    cout << "REPARTIDOR CON MENOR RECORRIDO:" << endl;
    cout << "DNI:" << setw(15) << dni_menor << endl;
    cout << "Distancia:" << setw(7) << menor_distancia << setw(4) << "km." << endl;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres){
    for(int i=0; i<cant_caracteres; i++) cout.put(caracter);
    cout << endl;
}