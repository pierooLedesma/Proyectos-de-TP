

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 24 de abril de 2025, 10:48 AM
 */

#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo,ifstream &input){
    input.open(nombre_archivo,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/





// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Módulo que elabora los encabezados del reporte
void elaborar_encabezados(int opcion,ofstream &output){
    switch (opcion){
        case 1:
            elaborar_lineas('=',TAM_REPORTE,output);
            output << setw((TAM_REPORTE + TAM_TITULO_1)/2) << "EMPRESA DE SALUD S. A." << endl;
            output << setw((TAM_REPORTE + TAM_TITULO_2)/2) << "REGISTRO DE CITAS MEDICAS" << endl;
            break;
        case 2:
            elaborar_lineas('-',TAM_REPORTE,output);
            output << left << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "Fecha";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 4) << "Paciente";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 5) << "Inicio";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 8) << "Fin";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << "Duracion";
            output << setw(TAM_REPORTE / (N_COLUMNAS - 2)  + 4) << "% de descuento por Seguro";
            output << "Pago por cita" << right << endl;
            elaborar_lineas('-',TAM_REPORTE,output);
            break;
        case 3:
            output << setw(TAM_REPORTE / N_COLUMNAS  + 5) << "No.";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 7) << "Codigo";
            output << setw(TAM_REPORTE / N_COLUMNAS) << "Descripcion";
            output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 5) << "Cantidad";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 3) << "Precio";
            output << setw(TAM_REPORTE / N_COLUMNAS  - 4) << "Pago" << endl;
            break;
        default:
            elaborar_lineas('=',TAM_REPORTE,output);
            output << "MEDICO QUE APORTO MAS INGRESOS INGRESOS AL INSTITUTO:" << endl;
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Módulo que procesa el reporte solicitado
void procesar_reporte(const char *nombre_archivo_medicos,
                      const char *nombre_archivo_citas,
                      const char *nombre_archivo_medicinas,
                      const char *nombre_archivo_reporte){
    ifstream input_medicos,input_citas,input_medicinas;
    ofstream output;
    int cod_medico_aporto_mas;
    double total_ingresado_por_el_medico = 0.0;
    aperturar_archivo_lectura(nombre_archivo_medicos,input_medicos);
    aperturar_archivo_lectura(nombre_archivo_citas,input_citas);
    aperturar_archivo_lectura(nombre_archivo_medicinas,input_medicinas);
    aperturar_archivo_escritura(nombre_archivo_reporte,output);
    output << fixed << setprecision(2);
    elaborar_encabezados(1,output);
    procesar_medicos(input_medicos,input_citas,input_medicinas,output,
                     cod_medico_aporto_mas,total_ingresado_por_el_medico);
    imprimir_resumen(cod_medico_aporto_mas,total_ingresado_por_el_medico,
                     input_medicos,output);
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/







// Módulo que imprime el resumen mediante el uso del archivo "Medicos.txt"
// para pode imprimir los datos del médico que aportó más ingresos al instituto.
void imprimir_resumen(int cod_medico_aporto_mas,double total_ingresado_por_el_medico,
                      ifstream &input,ofstream &output){
    int codigo_medico;
    double tarifa;
    input.clear(); // Libera el buffer del archivo "Medicos.txt" y limpiar banderas levantadas
    input.seekg(0,ios::beg); //Desplazamiento al inicio del archivo "Medicos.txt"
    while(true){
        input >> codigo_medico;
        // No coloco un " input.eof() break; " , porque cuando se procesó a los médicos en el
        // módulo "procesar_reporte", pues se encontró al médico que aportó más al instituto y el
        // médico existe porque fue leído anteriormente en "Medicos.txt" (o sea, en este archivo que se
        // está leyendo nuevamente). Cuando termine de leer al médico que más aportó, se sale del bucle.
        if(codigo_medico == cod_medico_aporto_mas){
            elaborar_encabezados(4,output);
            leer_and_imprimir_datos_medico(codigo_medico,input,output);
            leer_e_imprimir_tarifa_del_medico(tarifa,input,output);
            output << "Total ingresado por el medico:";
            output << setw(TAM_REPORTE / (N_COLUMNAS + 5)) << total_ingresado_por_el_medico << endl;
            elaborar_lineas('=',TAM_REPORTE,output);
            break;
        } else {
            while(input.get() != '\n'); // Descartar médico
        }
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/









// Módulo que procesa el archivo "Medicos.txt"
void procesar_medicos(ifstream &input_medicos,ifstream &input_citas,ifstream &input_medicinas,ofstream &output,
                      int &cod_medico_aporto_mas,double &total_ingresado_por_el_medico){
    int codigo_medico;
    double tarifa,monto_total_generado_por_el_medico;
    while(true){
        input_medicos >> codigo_medico;
        if(input_medicos.eof()) break;// Salir del bucle si es fin del archivo "Medicos.txt"
        elaborar_lineas('=',TAM_REPORTE,output);
        leer_and_imprimir_datos_medico(codigo_medico,input_medicos,output);
        leer_e_imprimir_tarifa_del_medico(tarifa,input_medicos,output);
        procesar_citas_medicas(tarifa,codigo_medico,monto_total_generado_por_el_medico,input_citas,input_medicinas,output);
        if(monto_total_generado_por_el_medico > total_ingresado_por_el_medico){
            total_ingresado_por_el_medico = monto_total_generado_por_el_medico;
            cod_medico_aporto_mas = codigo_medico;
        }
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/









// Módulo que procesa las citas médicas de los pacientes. Además, se actualiza el monto total generado por
// el médico, puesto que solo servirán las citas que duraron menos de 2 horas, 31 minutos y 25 segundos
// y del médico que se atendió al paciente leído de la cita del archivo "CitasMedicas.txt" (se procesará este archivo).
void procesar_citas_medicas(double tarifa,int codigo_medico,double &monto_total_generado_por_el_medico,
                            ifstream &input_citas,ifstream &input_medicinas,ofstream &output){
    int fecha,dni_paciente,tiempo_inicial,tiempo_final,cod_medico_que_atendio;
    double porcentaje_descuento_cliente,pago_por_cita,pago_total_por_medicinas,pago_total;
    input_citas.clear(); // Liberar el buffer del archivo "CitasMedicas.txt" y limpiar las banderas levantas.
    input_citas.seekg(0,ios::beg); // Desplazamiento al inicio del archivo "CitasMedicas.txt"
    output << "PACIENTES ATENDIDOS" << endl;
    while(true){
        fecha = leer_fecha(input_citas);
        if(input_citas.eof()) break; // Salir del bucle si es fin del archivo "CitasMedicas.txt"
        leer_cita_medica_hasta_codigo_medico(dni_paciente,porcentaje_descuento_cliente,tiempo_inicial,
                                             tiempo_final,cod_medico_que_atendio,pago_por_cita,tarifa,input_citas);
        if(cod_medico_que_atendio == codigo_medico and (tiempo_final - tiempo_inicial) < (2*3600+31*60+25)){
            pago_total_por_medicinas = 0.0;
            imprimir_datos_paciente(fecha,dni_paciente,tiempo_inicial,tiempo_final,
                                    porcentaje_descuento_cliente,pago_por_cita,output);
            if(input_citas.get() != '\n'){  // Preguntar si llegó al fin de línea; en caso sí, pues no le recetaron medicinas.
                // Sí le recetaron medicina al paciente.
                procesar_lista_de_medicinas(pago_total_por_medicinas,input_citas,input_medicinas,output);
            } else {
                output << setw(2* (TAM_REPORTE / (N_COLUMNAS-2) ) + 4) << "No se recetaron medicinas al paciente." << endl;
            }
            pago_total = pago_por_cita + pago_total_por_medicinas;
            imprimir_resumen_de_una_cita(pago_total_por_medicinas,pago_total,output);
            monto_total_generado_por_el_medico += pago_total;
        } else {
            while(input_citas.get() != '\n'); // Descartar cita
        }
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/









// Módulo que lee, de una cita médica del archivo "CitasMedicas.txt", desde el DNI
// del paciente hasta el código del médico que atendió a ese paciente
void leer_cita_medica_hasta_codigo_medico(int &dni_paciente,double &porcentaje_descuento_cliente,
        int &tiempo_inicial,int &tiempo_final,int &cod_medico_que_atendio,double &pago_por_cita,
        double tarifa,ifstream &input_citas){
    input_citas >> dni_paciente >> porcentaje_descuento_cliente;
    tiempo_inicial = leer_tiempo(input_citas);
    tiempo_final = leer_tiempo(input_citas);
    input_citas >> cod_medico_que_atendio;
    pago_por_cita = ( tarifa*( (100-porcentaje_descuento_cliente) / 100) ) * ( (double)(tiempo_final - tiempo_inicial)/(3600) );
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/








// Módulo que lee e imprime los datos del médico
void leer_and_imprimir_datos_medico(int codigo_medico,ifstream &input_medicos,ofstream &output){
    output << left << setw(TAM_REPORTE/N_COLUMNAS) << "Codigo del medico:";
    output << right << codigo_medico << endl;
    output << "Nombre del medico:" << setw(2) << ' ';
    imprimir_cadena_caracteres(false,true,'/',input_medicos,output);
    output << left << setw(TAM_REPORTE/N_COLUMNAS);
    output << "Especialidad:" << right;
    imprimir_cadena_caracteres(false,false,' ',input_medicos,output);
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/







// Módulo que lee e imprime la tarifa del médico
void leer_e_imprimir_tarifa_del_medico(double &tarifa,ifstream &input,ofstream &output){
    input >> tarifa;
    output << left << setw(TAM_REPORTE/N_COLUMNAS) << "Tarifa:";
    output << right << tarifa << endl;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/









// Módulo que lee los datos del paciente
void imprimir_datos_paciente(int fecha,int dni_paciente,int tiempo_inicial,int tiempo_final,
                             double porcentaje_descuento_cliente,double pago_por_cita,ofstream &output){
    elaborar_encabezados(2,output);
    imprimir_fecha(fecha,output);
    
    output << setw(4) << ' ' << left << setw(TAM_REPORTE / N_COLUMNAS  - 5) << dni_paciente << right;
    
    imprimir_tiempo(tiempo_inicial,output);
    
    output << setw(6) << ' ';
    imprimir_tiempo(tiempo_final,output);
    
    output << setw(6) << ' ';
    imprimir_tiempo(tiempo_final - tiempo_inicial,output);
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 8)  + 6) << ' ';
    output << setw(6) << porcentaje_descuento_cliente << '%';
    
    output << setw(TAM_REPORTE / N_COLUMNAS  + 5) << pago_por_cita << endl;
    output << "Medicinas recetadas:"  << endl;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/








// Módulo que procesa la lista de medicinas que se le recetó al paciente
void procesar_lista_de_medicinas(double &pago_total_por_medicinas,ifstream &input_citas,
                                 ifstream &input_medicinas,ofstream &output){
    int codigo_medicina,cantidad,cant_medicinas=0;
    elaborar_encabezados(3,output);
    while(true){
        input_citas >> codigo_medicina >> cantidad;
        imprimir_medicina(codigo_medicina,cantidad,cant_medicinas,pago_total_por_medicinas,input_medicinas,output);
        if(input_citas.get() == '\n') break;
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Modulo que imprime la medicina mediante el archivo "Medicinas.txt"
void imprimir_medicina(int codigo_medicina,int cantidad,int &cant_medicinas,
                       double &pago_total_por_medicinas,ifstream &input,ofstream &output){
    int cod_medicina_leida;
    double precio;
    input.clear(); // Liberar el buffer del archivo "Medicinas.txt" y libera las banderas levantas
    input.seekg(0,ios::beg); // Desplazamiento al inicio del archivo "Medicinas.txt"
    while(true){
        input >> cod_medicina_leida;
        if(input.eof()) break; // Salir del bucle si es el fin del archivo "Medicinas.txt"
        if(cod_medicina_leida == codigo_medicina){
            cant_medicinas++;
            output << setw(TAM_REPORTE/N_COLUMNAS +2) << ' ' << setfill('0') << setw(2) << cant_medicinas << setfill(' ');
            output << setw(9) << ' ' << left << setw(TAM_REPORTE/N_COLUMNAS - 6) << cod_medicina_leida << right;
            imprimir_cadena_caracteres(true,false,' ',input,output);
            input >> precio;
            output << setw(2) << cantidad << setw(TAM_REPORTE/N_COLUMNAS  - 5) << ' ' << setw(5) << precio;
            output << setw(TAM_REPORTE/N_COLUMNAS - 3) << precio*cantidad << endl;
            pago_total_por_medicinas += precio*cantidad;
            break;
        } else {
            while(input.get() != '\n'); // Descartar medicina
        }
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/







// Módulo que imprime el resumen de una cita
void imprimir_resumen_de_una_cita(double pago_total_por_medicinas,
                                  double monto_total_generado_por_el_medico,ofstream &output){
    output << "Pago total por medicinas: " << setw(7) << pago_total_por_medicinas << endl;
    output << left << setw(TAM_REPORTE / (N_COLUMNAS - 2) - 2);
    output << "Pago total:" << right << setw(7) << monto_total_generado_por_el_medico << endl;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/







// Módulo que imprime una cadena de caracteres
void imprimir_cadena_caracteres(bool es_medicina,bool es_nombre_medico,
                                char delimitador,ifstream &input,ofstream &output){
    int n_caracteres = 0;
    input >> ws; // Lectura de espacios en blanco
    if(es_nombre_medico) input.get(); // Leer el slash
    while(true){
        char c = input.get(); // Lectura de un caracter
        if(c == delimitador)break;
        if(c == '_') c = ' ';
        output.put(c); // Impresión de un caracter
        n_caracteres++;
    }
    if(es_medicina){
        // Si se lee e imprimie una medicina, se imprimen espacios en blanco
        int tam = TAM_REPORTE / (N_COLUMNAS-4);
        for(int i=0;i< tam - n_caracteres;i++) output.put(' ');
    } else {
        output << endl;
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/





// Módulo que lee fecha en DD/MM/AAAA y lo imprime en un valor entero
int leer_fecha(ifstream &input){
    int dia,mes,anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/





// Módulo que imprime una fecha DD/MM/AAAA
void imprimir_fecha(int fecha,ofstream &output){
    output << setfill('0') << setw(2) << fecha%100 << '/';
    output << setw(2) << fecha/100%100 << '/';
    output << fecha/10000 << setfill(' ');
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Módulo que lee el tiempo en HH:MM:SS y lo retorna en segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Módulo que imprime el tiempo en HH:MM:SS
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo/3600 << ':';
    output << setw(2) << tiempo/60%60 << ':';
    output << setw(2) << tiempo%60 << setfill(' ');
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/






// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracter,ofstream &output){
    for(int i=0;i<cant_caracter;i++) output.put(caracter);
    output << endl;
}

