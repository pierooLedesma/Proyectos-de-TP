

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 19 de abril de 2025, 06:44 PM
 */


#include "Funciones.h"




// Módulo que apertura un archivo de lectura sin aplicar el constructor
void aperturar_archivo_lectura(const char *arch_nombre,ifstream &input){
    input.open(arch_nombre,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << arch_nombre << " no se pudo abrir." << endl;
        exit(1);
    }
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que apertura un archivo de escritura sin aplicar el constructor
void aperturar_archivo_escritura(const char *arch_nombre,ofstream &output){
    output.open(arch_nombre,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << arch_nombre << " no se pudo abrir." << endl;
        exit(1);
    }
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que apertura los archivos e inicia con el proceso de lectura del archivo "CitasMedicas.txt"
void procesar_reporte(const char *arch_nombre_citas,const char *arch_nombre_medicos,
        const char *arch_nombre_reporte){
    ifstream input_citas,input_medicos;
    ofstream output;
    int dni_paciente_mas_gasto_ha_realizado;
    double monto_paciente_mas_gasto_ha_realizado = 0.0;
    aperturar_archivo_lectura(arch_nombre_citas,input_citas);
    aperturar_archivo_lectura(arch_nombre_medicos,input_medicos);
    aperturar_archivo_escritura(arch_nombre_reporte,output);
    output << fixed << setprecision(2);
    imprimir_titulo_y_encabezados(output);
    procesar_citas(input_citas,input_medicos,output,monto_paciente_mas_gasto_ha_realizado,
            dni_paciente_mas_gasto_ha_realizado);
    imprimir_paciente_que_mas_gasto(dni_paciente_mas_gasto_ha_realizado,
            monto_paciente_mas_gasto_ha_realizado,output);
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que imprime el título y los encabezados del reporte solicitado
void imprimir_titulo_y_encabezados(ofstream &output){
    output << setw((TAM_REPORTE + TAM_TITULO)/2  - 4) << "EMPRESA DE SALUD S. A." << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw((TAM_REPORTE + TAM_TITULO)/2  - 2) << "REGISTRO DE CITAS MEDICAS" << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
    output << left << setw(TAM_REPORTE / N_COLUMNAS  - 4) << "Fecha";
    output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "Paciente";
    output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "Inicio";
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "Fin";
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "Duracion";
    output << setw(TAM_REPORTE / N_COLUMNAS - 1) << "% por Seguro";
    output << setw(TAM_REPORTE / N_COLUMNAS + 25) << "Medico";
    output << setw(TAM_REPORTE / N_COLUMNAS + 1) << "Especialidad";
    output << "Pago (cita+medicinas)" << right << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que procesa el archivo "CitasMedicas.txt". Lee línea por línea, realiza lecturas e impresiones
void procesar_citas(ifstream &input_citas,ifstream &input_medicos,ofstream &output,
        double &monto_paciente_mas_gasto_ha_realizado,int &dni_paciente_mas_gasto_ha_realizado){
    int fecha,dni_paciente,tiempo_inicial,tiempo_final,cod_medico_citas;
    double porcentaje_descuento_paciente,monto_pagado_por_los_medicamentos,total_ingresos=0.0,pago;
    while(true){
        fecha = leer_fecha(input_citas);
        if(input_citas.eof()) break;
        leer_datos_paciente(dni_paciente,porcentaje_descuento_paciente,tiempo_inicial,tiempo_final,
                cod_medico_citas,monto_pagado_por_los_medicamentos,input_citas,output);
        imprimir_datos_paciente(fecha,dni_paciente,tiempo_inicial,tiempo_final,porcentaje_descuento_paciente,output);
        procesar_medico(porcentaje_descuento_paciente,cod_medico_citas,
                monto_pagado_por_los_medicamentos,input_medicos,output,tiempo_final,tiempo_inicial,
                pago);
        total_ingresos += pago; // Actualización del total de ingresos
        if(pago > monto_paciente_mas_gasto_ha_realizado){
            dni_paciente_mas_gasto_ha_realizado = dni_paciente;
            monto_paciente_mas_gasto_ha_realizado = pago;
        }
    }
    imprimir_total_ingresos(total_ingresos,output);
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/








// Módulo que lee los datos del paciente en la cita realizada del archivo "CitasMedicas.txt". Lee los
// datos que hay después del DNI.
void leer_datos_paciente(int &dni_paciente,double &porcentaje_descuento_paciente,int &tiempo_inicial,
        int &tiempo_final,int &cod_medico_citas,double &monto_pagado_por_los_medicamentos,
        ifstream &input_citas,ofstream &output){
    char hay_medicamentos;
    input_citas >> dni_paciente >> porcentaje_descuento_paciente;
    tiempo_inicial = leer_tiempo(input_citas);
    tiempo_final = leer_tiempo(input_citas);
    input_citas >> cod_medico_citas >> hay_medicamentos;
    if(hay_medicamentos == 'S') input_citas >> monto_pagado_por_los_medicamentos;
    else monto_pagado_por_los_medicamentos = 0.0;
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que imprime los datos del paciente (la línea leída del archivo "CitasMedicas.txt")
void imprimir_datos_paciente(int fecha,int dni_paciente,int tiempo_inicial,int tiempo_final,
        double porcentaje_descuento_paciente,ofstream &output){
    imprimir_fecha(fecha,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 6) << dni_paciente;
    output << setw(TAM_REPORTE / N_COLUMNAS  - 13) << ' ';
    imprimir_tiempo(tiempo_inicial,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 13) << ' ';
    imprimir_tiempo(tiempo_final,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 11) << ' ';
    imprimir_tiempo(tiempo_final - tiempo_inicial,output);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 5) << porcentaje_descuento_paciente << '%';
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/







// Módulo que lee el archivo "Medicos.txt". Imprime el médico que tenga el mismo código que el
// código de médico leído en el archivo "CitasMedicas.txt" (cod_medico_citas).
void procesar_medico(double porcentaje_descuento_paciente,int cod_medico_citas,
        double monto_pagado_por_los_medicamentos,ifstream &input_medicos,ofstream &output,
        int tiempo_final,int tiempo_inicial,double &pago){
    int codigo;
    input_medicos.clear(); // Liberar el buffer del archivo "Medicos.txt" y limpia las banderas levantas
    input_medicos.seekg(0,ios::beg); // Desplazamiento al inicio del archivo "Medicos.txt"
    while(true){
        input_medicos >> codigo;
        if(input_medicos.eof()) break; // Sale del bucle si se lee el fin del archivo "Medicos.txt"
        if(codigo != cod_medico_citas){
            // El código del médico leído (codigo) del archivo "Medicos.txt" es diferente al 
            // código del médico leído (cod_medico_citas) en el archivo "CitasMedicas.txt".
            while(input_medicos.get() != '\n'); // Descartar línea
            continue; // Regresa a la primera líndea de este bucle
        }
        leer_nombre_y_especialidad_e_imprimir_datos_del_medico(pago,tiempo_inicial,tiempo_final,
                porcentaje_descuento_paciente,monto_pagado_por_los_medicamentos,input_medicos,output);
        break; // Se sale del bucle, porque ya se imprimió los datos del médico
    }
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/







// Módulo que lee el nombre y especialidad del médico e imprime los datos del médico como el pago del cliente
void leer_nombre_y_especialidad_e_imprimir_datos_del_medico(double &pago,int tiempo_inicial,
        int tiempo_final,double porcentaje_descuento_paciente,double monto_pagado_por_los_medicamentos,
        ifstream &input_medicos,ofstream &output){
    double tarifa;
    output << setw(TAM_REPORTE / N_COLUMNAS  - 10) << ' ';
    leer_e_imprimir_cadena_caracteres(input_medicos,output,false,TAM_REPORTE / 4  + 2);
    leer_e_imprimir_cadena_caracteres(input_medicos,output,true,TAM_REPORTE / 6  - 2);
    input_medicos >> tarifa;
    pago = tarifa*((double)(tiempo_final - tiempo_inicial)/3600)*(1 - (porcentaje_descuento_paciente/100)) +
                monto_pagado_por_los_medicamentos*(1 - (porcentaje_descuento_paciente / 2) / 100);
    output << setw(TAM_REPORTE / N_COLUMNAS  - 10) << pago << endl;
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que lee e imprime una cadena de caracteres y también espacios en blanco luego de imprimir la cadena
void leer_e_imprimir_cadena_caracteres(ifstream &input,ofstream &output,bool es_especialidad,
        int tam_cadena_caracteres_y_espacios_en_blanco){
    int n_caracteres=0;
    bool es_mayuscula = true;
    
    input >> ws; // Lectura los espacios en blanco
    
    // Proceso de lectura e impresión de la cadena de caracteres
    while(true){
        char caracter = input.get();
        if(caracter == ' ') break;
        cambiar_caracter(es_especialidad,es_mayuscula,caracter);
        output.put(caracter);
        n_caracteres++;
    }
    
    // Imprimir espacios en blanco
    for(int i=0; i < tam_cadena_caracteres_y_espacios_en_blanco - n_caracteres; i++) output.put(' ');
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que cambia el caracter a mayúscula, a un espacio en blanco o que se mantenga el caracter leído
void cambiar_caracter(bool es_especialidad,bool &es_mayuscula,char &caracter){
    if(es_especialidad){
        // El caracter leído es parte del nombre de la especialidad.
        // Las letras de la especialidad deben ser todas en mayúsculas: GINECOLOGIA
        caracter = (caracter>='a'  and  caracter<='z'  ?  caracter - 'a' + 'A' : caracter);
    } else {
        // El caracter leído no es parte del nombre de una especialidad, sino del nombre del médico
        // La primera letra debe ser en mayúscula y luego, todo en minúscula hasta que se lea un espacio
        // en blanco y la letra leída a continuación debe ser en mayúscula: Jaime Julian Shirakawa Florian
        if(es_mayuscula) es_mayuscula = false;
        else {
            if(caracter == '_'){
                caracter = ' ';
                es_mayuscula = true;
            } else {
                caracter = caracter - 'A' + 'a';  // El caracter leído es una letra en minúscula. Se cambiará a mayúscula.
            }
        }
    }
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que lee una fecha en DD/MM/AAAA y retorna esta fecha en un número entero
int leer_fecha(ifstream &input){
    int dia,mes,anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que imprime la fecha en DD/MM/AAAA
void imprimir_fecha(int fecha,ofstream &output){
    output << setfill('0') << setw(2) << fecha%100 << '/';
    output << setw(2) << fecha/100%100 << '/';
    output << fecha/10000 << setfill(' ');
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que lee un tiempo en HH/MM/SS y retorna esta tiempo en segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/




// Módulo que imprime el tiempo en HH/MM/SS
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo/3600 << ':';
    output << setw(2) << tiempo/60%60 << ':';
    output << setw(2) << tiempo%60 << setfill(' ');
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que imprime el total de ingresos que se obtuvo en el registro de citas médicas
void imprimir_total_ingresos(double total_ingresos,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << "Total de ingresos" << " : " << total_ingresos << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/






// Módulo que imprime el paciente que más gastó en una cita médica
void imprimir_paciente_que_mas_gasto(int dni_paciente_mas_gasto_ha_realizado,
        double monto_paciente_mas_gasto_ha_realizado,ofstream &output){
    output << "Paciente que mas gasto en una cita medica:";
    output << setw(TAM_REPORTE / (N_COLUMNAS+5))<< dni_paciente_mas_gasto_ha_realizado << endl;
    output << "Monto gastado:" << setw(TAM_REPORTE / 4  - 1);
    output << monto_paciente_mas_gasto_ha_realizado << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/





// Módulo que imprime las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}

