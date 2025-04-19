

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 18 de abril de 2025, 08:15 PM
 */

#include "Funciones.h"


// Módulo que procesa las infracciones. Módulo inicial
void procesar_infracciones(){
    int fecha_1,fecha_2;
    leer_las_dos_fechas_iniciales_e_imprimirlas(fecha_1,fecha_2);
    procesar_archivo_infracciones(fecha_1,fecha_2);
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que lee e imprime las dos fechas iniciales
void leer_las_dos_fechas_iniciales_e_imprimirlas(int &fecha_1,int &fecha_2){
    fecha_1 = leer_fecha();
    fecha_2 = leer_fecha();
    cout << setw((TAM_REPORTE + TAM_TITULO)/2  - 4) << "MINISTERIO DE TRANSPORTE" << endl;
    cout << setw((TAM_REPORTE + TAM_TITULO)/2) << "MULTAS IMPUESTAS A LAS COMPANIAS" << endl;
    cout << setw((TAM_REPORTE + TAM_TITULO)/2  - 17) << "RANGO DE FECHAS A CONSIDERAR";
    cout << left << setw(2) << ':' << setw(5) << "DEL" << right;
    imprimir_fecha(fecha_1);
    cout << " AL ";
    imprimir_fecha(fecha_2);
    cout << endl;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que procesar el archivo "Infracciones de transito.txt"
void procesar_archivo_infracciones(int fecha_1,int fecha_2){
    int dni,n_compania=1,dni_menor_pago,dni_mayor_pago;
    double total_recaudado_por_infracciones = 0.0,compania_menor_pago=1e9,compania_mayor_pago=0.0;
    cout << fixed << setprecision(2);
    while(true){
        // Lectura fija
        cin >> dni;
        if(cin.eof()) break; // Salir del bucle si se lee el fin del archivo TXT
        leer_nombre_e_imprimir_dni_nombre(dni,n_compania);
        n_compania++;
        
        // Lectura variable
        procesar_descripcion_infracciones(fecha_1,fecha_2,total_recaudado_por_infracciones,
                compania_menor_pago,dni_menor_pago,compania_mayor_pago,dni_mayor_pago,dni);
    }
    imprimir_total_recaudado(total_recaudado_por_infracciones);
    imprimir_resumen(dni_mayor_pago,compania_mayor_pago,dni_menor_pago,compania_menor_pago);
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que lee el nombre del DNI del representante legal e imprime su DNI y su nombre
void leer_nombre_e_imprimir_dni_nombre(int dni,int n_compania){
    int cant_caracteres=0;
    elaborar_lineas('=',TAM_REPORTE);
    cout << "COMPANIA No." << setw(3) << n_compania << endl;
    cout << "REPRESENTANTE LEGAL: ";
    
    // Proceso de la lectura e impresión del nombre
    cin >> ws; // Leer espacios en blanco
    while(true){
        char c = cin.get();  // Lectura de un caracter
        if(c == ' ') break;  // Se sale del bucle si se lee un espacio en blanco
        if(c == '/'  or  c == '-')  c = ' ';
        c = (c>='a' and c<='z' ? c-'a'+'A' : c); // Si está en minúscula, pasará a mayúscula y sino, solo me entrega el mismo caracter leído
        cout.put(c);  // Impresión de un caracter
        cant_caracteres++;
    }
    // Impresión de espacios en blanco
    int tam = TAM_REPORTE/2;
    for(int i=0; i < tam - cant_caracteres; i++) cout.put(' ');
    
    // Impresión del DNI
    cout << "DNI:" << setw(8) << dni << endl;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que procesa la descripción de infracciones (proceso de la lectura variable)
void procesar_descripcion_infracciones(int fecha_1,int fecha_2,double &total_recaudado_por_infracciones,
        double &compania_menor_pago,int &dni_menor_pago,double &compania_mayor_pago,
        int &dni_mayor_pago,int dni){
    double total_multas=0.0,total_fecha=0.0,total_hora=0.0,total_tipo=0.0,total_total_a_pagar=0.0;
    imprimir_encabezado_descripcion_infracciones();
    while(true){
        leer_e_imprimir_descripcion_infracciones(fecha_1,fecha_2,total_multas,total_fecha,total_hora,total_tipo,
                total_total_a_pagar);
        if(cin.get() == '\n') break; // Si se lee el cambio de línea, se sale del bucle (lectura variable)
    }
    imprimir_montos_totales(total_multas,total_fecha,total_hora,total_tipo,total_total_a_pagar);
    total_recaudado_por_infracciones += total_total_a_pagar;
    if(total_total_a_pagar < compania_menor_pago){
        dni_menor_pago = dni;
        compania_menor_pago = total_total_a_pagar;
    }
    if(total_total_a_pagar > compania_mayor_pago){
        dni_mayor_pago = dni;
        compania_mayor_pago = total_total_a_pagar;
    }
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/

              



// Módulo que imprime el encabezado de las descripciones de las infracciones
void imprimir_encabezado_descripcion_infracciones(){
    elaborar_lineas('-',TAM_REPORTE);
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "VECHICULOS INFRACCIONADOS:" << endl;
    cout << setw(TAM_REPORTE/2  + 30) << "INCREMENTOS" << endl;
    cout << setw(3) << ' ' << left << setw(TAM_REPORTE / N_COLUMNAS - 3) << "TIPO";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 3) << "PLACA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 1) << "FECHA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 3) << "HORA";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 1) << "GRAVEDAD";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "MULTA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "POR TIPO";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "POR FECHA";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "POR HORA";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "TOTAL A PAGAR" << right << endl;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que lee e imprime una descripción de infracciones
void leer_e_imprimir_descripcion_infracciones(int fecha_1,int fecha_2,double &total_multas,
        double &total_fecha,double &total_hora,double &total_tipo,double &total_total_a_pagar){
    char gravedad,tipo_vehiculo;
    int fecha,tiempo;
    double multa,total_a_pagar,incremento_tipo,incremento_fecha,incremento_hora;
    
    leer_imprimir_placa(tipo_vehiculo);
    fecha = leer_fecha();
    cout << setw(TAM_REPORTE / N_COLUMNAS - 12) << ' ';
    imprimir_fecha(fecha);
    tiempo = leer_tiempo();
    cout << setw(TAM_REPORTE / N_COLUMNAS  - 11) << ' ';
    imprimir_tiempo(tiempo);
    imprimir_gravedad(gravedad);
    multa = imprimir_multa(gravedad);
    incremento_tipo = imprimir_incremento_tipo(tipo_vehiculo,multa);
    incremento_fecha = imprimir_incremento_fecha(fecha,fecha_1,fecha_2,multa);
    incremento_hora = imprimir_incremento_hora(tiempo,multa);
    total_a_pagar = multa + incremento_tipo + incremento_fecha + incremento_hora;
    cout << setw(TAM_REPORTE / N_COLUMNAS + 2) << total_a_pagar << endl;
    
    total_multas += multa;
    total_fecha += incremento_tipo;
    total_hora += incremento_fecha;
    total_tipo += incremento_hora;
    total_total_a_pagar += total_a_pagar;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que lee e imprime la placa del vehículo como también el tipo del vehículo
void leer_imprimir_placa(char &tipo_vehiculo){
    // P599-629
    int num_1_placa,num_2_placa;
    char guion;
    cin >> tipo_vehiculo >> num_1_placa >> guion >> num_2_placa;
    imprimir_tipo_vehiculo(tipo_vehiculo);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 20) << tipo_vehiculo << num_1_placa << num_2_placa;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime el tipo de vehículo
void imprimir_tipo_vehiculo(char tipo_vehiculo){
    cout << left << setw(3) << '-' << setw(TAM_REPORTE / N_COLUMNAS  - 3);
    if(tipo_vehiculo == 'C') cout << "GRANDE";
    else if (tipo_vehiculo == 'M') cout << "MEDIANO";
    else cout << "PEQUENO";  // tipo_vechiculo = 'P'
    cout << right;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime la gravedad
void imprimir_gravedad(char &gravedad){
    cin >> gravedad;
    cout << setw(10) << ' ' << left << setw(TAM_REPORTE / N_COLUMNAS - 2);
    if(gravedad == 'L') cout << "LEVE";
    else if (gravedad == 'M') cout << "MUY GRAVE";
    else cout << "GRAVE";
    cout << right;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que retorna e imprime la multa correspondiente a la gravedad dada
double imprimir_multa(char gravedad){
    double multa;
    if(gravedad == 'L') multa = 158.33;  // LEVE
    else if (gravedad == 'M') multa = 3920.25;  // MUY GRAVE
    else multa = 516.75;  // GRAVE
    cout << setw(8) << multa;
    return multa;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que imprime el incremento por tipo y retorna este incremento
double imprimir_incremento_tipo(char tipo_vehiculo,double multa){
    double incremento;
    if(tipo_vehiculo == 'C')  incremento = multa*(15.3/100);  // GRANDE
    else if (tipo_vehiculo == 'M')  incremento = multa*(11.7/100);  // MEDIANO
    else  incremento = multa*(2.7/100);  // tipo_vechiculo = 'P' = PEQUEÑO
    cout << setw(TAM_REPORTE / N_COLUMNAS) << incremento;
    return incremento;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/





// Módulo que imprime el incremento por fecha y retorna este incremento
double imprimir_incremento_fecha(int fecha,int fecha_1,int fecha_2,double multa){
    double incremento;
    if(fecha < fecha_1) incremento = multa*(10.75/100);
    else if(fecha <= fecha_2) incremento = multa*(7.25/100); // fecha_1 < fecha  y  fecha <= fecha_2
    else incremento = 0.0; // fecha > fecha_2
    cout << setw(TAM_REPORTE / N_COLUMNAS - 4) << incremento;
    return incremento;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime el incremento por hora y retorna este incremento
double imprimir_incremento_hora(int tiempo,double multa){
    double incremento;
    if(tiempo >= 4*3600 + 30*60  and tiempo<= 11*3600 + 25*60)  incremento = multa*(8.5/100); 
    else if(tiempo <= 20*3600 + 40*60) incremento = multa*(5.8/100);
    else if (tiempo < 4*3600 + 30*60) incremento = multa*(3.7/100);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << incremento;
    return incremento;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime los montos totales de los incrementos, como de las multas y el total del total a pagar
void imprimir_montos_totales(double total_multas,double total_fecha,double total_hora,
        double total_tipo,double total_total_a_pagar){
    elaborar_lineas('-',TAM_REPORTE);
    cout << "PAGO TOTAL :";
    cout << setw(TAM_REPORTE / 2  - 12) << total_multas;
    cout << setw(TAM_REPORTE / N_COLUMNAS) << total_fecha;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 4) << total_hora;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << total_tipo;
    cout << setw(TAM_REPORTE / N_COLUMNAS + 2) << total_total_a_pagar << endl;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/






// Módulo que lee la fecha(DD:MM:AAAA) y me lo retorna en un número entero
int leer_fecha(){
    int dia,mes,anio;
    char slash;
    cin >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime la fecha en DD/MM/AAAA
void imprimir_fecha(int fecha){
    cout << setfill('0') << setw(2) << fecha%100 << '/';
    cout << setw(2) << fecha/100%100 << '/';
    cout << fecha/10000 << setfill(' ');
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo el tiempo en HH:MM:SS y lo retornaré en segundos
int leer_tiempo(){
    int hora,minuto,segundo;
    char dos_puntos;
    cin >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime el tiempo en HH:MM:SS
void imprimir_tiempo(int tiempo){
    cout << setfill('0') << setw(2) << tiempo/3600 << ':';
    cout << setw(2) << tiempo/60%60 << ':';
    cout << setw(2) << tiempo%60 << setfill(' ');
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que imprime el total recaudado por infracciones
void imprimir_total_recaudado(double total_recaudado_por_infracciones){
    elaborar_lineas('=',TAM_REPORTE);
    cout << "TOTAL RECAUDADO POR INFRACCIONES:";
    cout << setw(12) << total_recaudado_por_infracciones <<endl; 
    elaborar_lineas('=',TAM_REPORTE);
    cout << endl;
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/



// Módulo que imprime la compañía que tuvo mayor y menor pago por infracciones
void imprimir_resumen(int dni_mayor_pago,double compania_mayor_pago,
        int dni_menor_pago,double compania_menor_pago){
    elaborar_lineas('/',TAM_REPORTE/4  + 2);
    cout << "//COMPANIA CON MAYOR PAGO POR INFRACCIONES:" << setw(4) << "//" << endl;
    cout << "//DNI:" << setw(TAM_REPORTE/9  - 1) << dni_mayor_pago;
    cout << setw(TAM_REPORTE/N_COLUMNAS  + 4) << "//" << endl;
    cout << "//TOTAL PAGADO:" << setw(TAM_REPORTE/N_COLUMNAS  - 8) << compania_mayor_pago;
    cout << setw(TAM_REPORTE/N_COLUMNAS  + 4) << "//" << endl;
    
    elaborar_lineas('/',TAM_REPORTE/4  + 2);
    cout << "//COMPANIA CON MENOR PAGO POR INFRACCIONES:" << setw(4) << "//" << endl;
    cout << "//DNI:" << setw(TAM_REPORTE/9  - 1) << dni_menor_pago;
    cout << setw(TAM_REPORTE/N_COLUMNAS  + 4) << "//" << endl;
    cout << "//TOTAL PAGADO:" << setw(TAM_REPORTE/N_COLUMNAS  - 8) << compania_menor_pago;
    cout << setw(TAM_REPORTE/N_COLUMNAS  + 4) << "//" << endl;
    elaborar_lineas('/',TAM_REPORTE/4  + 2);
}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres){
    for(int i=0; i<cant_caracteres; i++) cout.put(caracter);
    cout << endl;
}