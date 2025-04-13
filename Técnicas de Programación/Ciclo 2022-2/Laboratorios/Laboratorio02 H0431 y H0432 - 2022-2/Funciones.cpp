

/* 
 * File:   Funciones.cpp
 * Author: Alessandro Piero Ledesma Guerra
 * Código: 20217340
 * Creado el 29 de marzo de 2025, 11:27 PM
 */

#include "Funciones.h"


// Módulo que apertura los archivos para la lectura y la impresión
void elaborarReporteSolicitado(const char *nombre_archivo_medicos_txt,
                                                       const char *nombre_archivo_pacientes_txt,
                                                       const char *nombre_archivo_citas_txt,
                                                       const char *nombre_archivo_reporte_txt){
    /* Apertura del archivo "Medicos.txt" */
    ifstream archMedicos(nombre_archivo_medicos_txt, ios::in);
    if(not archMedicos.is_open()){
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo_medicos_txt << endl;
    }
    
    /* Apertura del archivo "Pacientes.txt" */
    ifstream archPacientes(nombre_archivo_pacientes_txt,ios::in);
    if(not archPacientes.is_open()){
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo_pacientes_txt << endl;
    }
    
    /* Apertura del archivo "Citas.txt" */
    ifstream archCitas(nombre_archivo_citas_txt,ios::in);
    if(not archCitas.is_open()){
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo_citas_txt << endl;
    }
    
    /* Apertura del archivo "Reporte.txt" */
    ofstream archReporte(nombre_archivo_reporte_txt,ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo_reporte_txt << endl;
    }
    
    archReporte << setprecision(2) << fixed;
    procesarMedicos(archMedicos,archCitas,archPacientes,archReporte);
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Módulo que procesar el archivo de "Medicos.txt" e imprime el total recaudado por la clínica
void procesarMedicos(ifstream &archMedicos,ifstream &archCitas,ifstream &archPacientes,
                                        ofstream &archReporte){
    int codigo_del_medico;
    double tarifa,totalRecaudado=0.0;
    
    elaborarEncabezados(1,archReporte);  // Elaborar el encabezado principal del reporte
    
    while(true){
        archMedicos >> codigo_del_medico;
        if(archMedicos.eof()) break; // Fin del archivo "Medicos.txt"
        elaborarEncabezados(2,archReporte);  // Elaborar el encabezado del médico
        archReporte << setw(15) << codigo_del_medico << setw(9) << ' ';
        imprimirNombre(archMedicos,false,LONGITUD_DEL_NOMBRE_MEDICO_Y_ESPACIOS,' ',archReporte);
        archMedicos >> tarifa;
        archReporte << tarifa << endl << endl;
        procesarCitas(codigo_del_medico,tarifa,totalRecaudado,archCitas,archPacientes,archReporte);
    }
    
    // Impresión del total recaudado por la clínica (suma total del "total de gastos por citas"):
    elaborarLineas('=',CANT_MAX_LINEAS,archReporte);
    archReporte << "TOTAL RECAUDADO POR LA CLINICA: " << setw(15) << totalRecaudado << endl;
    elaborarLineas('=',CANT_MAX_LINEAS,archReporte);
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Módulo que procesa el archivo "Citas.txt"
void procesarCitas(int codigo_del_medico,double tarifa,double &totalRecaudado,ifstream &archCitas,
                               ifstream &archPacientes,ofstream &archReporte){
    char c;
    int dni_paciente,dia,mes,anio,codMedico,hora_Inicio,minuto_Inicio,segundo_Inicio,hora_Fin,minuto_Fin,
         segundo_Fin;
    double total_gasto_citas = 0.0;
    
    archCitas.clear(); // Limpiar banderas
    archCitas.seekg(0,ios::beg); // Mover el indicador al inicio del archivo "Citas.txt"
    
    elaborarEncabezados(3,archReporte);  // Elaborar el encabezado de la cita y del paciente
    
    while(true){
        archCitas >> dni_paciente;
        if(archCitas.eof()) break; // Fin del archivo "Citas.txt"
        archCitas >> codMedico;
        if(codMedico == codigo_del_medico){
            // El código del médico del archivo leído "Citas.txt" (codMedico) es igual
            // al código del médico leído del archivo "Medicos.txt" (codigo_del_medico).
            archCitas >> dia >> c >> mes >> c >> anio >> hora_Inicio >> c >> minuto_Inicio >> c;
            archCitas >> segundo_Inicio >> hora_Fin >> c >> minuto_Fin >> c >> segundo_Fin;
            procesarPaciente(dia,mes,anio,dni_paciente,hora_Inicio,minuto_Inicio,segundo_Inicio,hora_Fin,
                                         minuto_Fin,segundo_Fin,tarifa,totalRecaudado,archPacientes,archReporte,
                                         total_gasto_citas);
        } else{
            while(archCitas.get() != '\n');   // Descartar línea
        }
    }
    elaborarLineas('-',CANT_MAX_LINEAS,archReporte);
    archReporte << setw(36) << "Total de gastos por citas: " << total_gasto_citas << endl;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Módulo que procesa el archivo "Pacientes.txt". Encuentra el DNI del paciente que se busca.
void procesarPaciente(int dia,int mes,int anio,int dni_paciente,int hora_Inicio,int minuto_Inicio,int segundo_Inicio,
                                        int hora_Fin,int minuto_Fin,int segundo_Fin,double tarifa,double &totalRecaudado,
                                        ifstream &archPacientes,ofstream &archReporte,double &total_gasto_citas){
    int el_dni_del_paciente;
    
    archPacientes.clear(); // Limpiar banderas
    archPacientes.seekg(0,ios::beg); // Mover el indicador al inicio del archivo "Pacientes.txt"
    
    while(true){
        archPacientes >> el_dni_del_paciente;
        if(archPacientes.eof()) break;  // Fin del archivo "Pacientes.txt"
        if(el_dni_del_paciente == dni_paciente){
            // El DNI del pacienrte del archivo leído "Citas.txt" (dni_paciente) es igual
            // al DNI del paciente leído del archivo "Pacientes.txt" (el_dni_del_paciente).
            impresionDelPacienteConSuCitaMedica(dia,mes,anio,dni_paciente,hora_Inicio,minuto_Inicio,
                                                                            segundo_Inicio,hora_Fin,minuto_Fin,segundo_Fin,tarifa,
                                                                            totalRecaudado,archPacientes,archReporte,total_gasto_citas);
            break;
        } else {
            while(archPacientes.get() != '\n');   // Descartar línea
        }
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Imprime los datos del paciente de su respectiva cita. Se imprime el nombre del paciente en un módulo aparte y
// se actualiza el "total de gastos de citas" como también el "total recaudado por la clínica".
void impresionDelPacienteConSuCitaMedica(int dia,int mes,int anio,int dni_paciente,int hora_Inicio,
                                                                            int minuto_Inicio,int segundo_Inicio,int hora_Fin,int minuto_Fin,
                                                                            int segundo_Fin,double tarifa,double &totalRecaudado,
                                                                            ifstream &archPacientes,ofstream &archReporte,
                                                                            double &total_gasto_citas){
    int telefono;
    double duracion_del_tiempo_en_minutos,pago;
    
    duracion_del_tiempo_en_minutos = (hora_Fin*60 + minuto_Fin + (double)segundo_Fin/60) - 
                                                              (hora_Inicio*60 + minuto_Inicio + (double)segundo_Inicio/60);
    pago = (duracion_del_tiempo_en_minutos/60)*tarifa;
    
    archReporte << setw(9) << ' ' << setfill('0') << setw(2) << dia << '/' << setw(2) << mes << '/' << setw(2) << anio;
    archReporte << setfill(' ') << setw(14) << dni_paciente << " - ";
    imprimirNombre(archPacientes,true,LONGITUD_DEL_NOMBRE_PACIENTE_Y_ESPACIOS,']',archReporte);
    archPacientes >> telefono;
    archReporte << left << setw(15) << telefono << right << setfill('0') << setw(2) << hora_Inicio << ':';
    archReporte << setw(2) << minuto_Inicio << ':' << setw(2) << segundo_Inicio << setfill(' ') << setw(8) << ' ';
    archReporte << setfill('0') << setw(2) << hora_Fin << ':' << setw(2) << minuto_Fin << ':';
    archReporte << setw(2) << segundo_Fin << setfill(' ') << setw(15) << duracion_del_tiempo_en_minutos;
    archReporte << setw(19) << pago << endl;
    
    total_gasto_citas += pago;
    totalRecaudado += total_gasto_citas;
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Módulo que imprime el nombre del paciente o de un médico
void imprimirNombre(ifstream &archLectura,bool esPaciente,int longitud_total_entre_nombre_y_espacios,
                                    char caracter_de_finalizacion,ofstream &archReporte){
    char c;
    bool esMayuscula = true;
    int cantidad_de_caracteres_del_nombre = 0;
    archLectura >> ws;  // Lectura de espacios en blanco
    if(esPaciente) archLectura.get();  //El caracter inicial del nombre del paciente tiene un corchete al inicio ( [ )
    while(true){
        c = archLectura.get();  // Lectura de un caracter
        if(c == caracter_de_finalizacion) break;
        if(esMayuscula){
            // Se leyó una letra en mayúscula
            archReporte.put(c); // Impresión de una letra en mayúscula
            esMayuscula = false; // El siguiente caracter a leer es una letra en minúscula
        } else if (c == '_'  or   c == ' '){
            // Se leyó un caracter, sea este caracter un espacio en blanco (' ') o un guion bajo ('_')
            archReporte.put(' '); // Impresión de un espacio en blanco
            esMayuscula = true;
        } else if (not esMayuscula   and   esPaciente){
            // Se leyó una letra en minúscula, pero es el nombre de un paciente
            c = c - 'a' + 'A';  // Cambio de una letra minúscula a una letra mayúscula
            archReporte.put(c);  // Impresión de una letra en mayúscula
        } else {
            // Lectura de una letra en minúscula
            archReporte.put(c);  // Impresión de una letra en minúscula
        }
        cantidad_de_caracteres_del_nombre++;
    }
    
    /* Impresión de espacios en blanco entre el nombre y el siguiente valor ("tarifa por hora" o "teléfono") */
    for(int i=0;  i < longitud_total_entre_nombre_y_espacios - cantidad_de_caracteres_del_nombre ; i++){
        archReporte.put(' '); // Impresión de un espacio en blanco
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/




// Módulo que elabora los encabezados del reporte
void elaborarEncabezados(int opcion,ofstream &archReporte){
    switch (opcion){
        case 1:
            /* Encabezado principal del reporte */
            archReporte << setw(88) << "CLINICA PSICOLOGICA TP." << endl;
            archReporte << setw(90) << "RELACION DE CITAS POR MEDICO" << endl;
            break;
        case 2:
            /* Encabezado del médico */
            elaborarLineas('=',CANT_MAX_LINEAS,archReporte);
            archReporte << setw(15) << "Codigo" << setw(15) << "Medico" << setw(54) << "Tarifa por hora" << endl;
            break;
        case 3:
            /* Encabezado de la cita y del paciente */
            archReporte << setw(26) << "CITAS ATENDIDAS :" << endl;
            elaborarLineas('-',CANT_MAX_LINEAS,archReporte);
            archReporte << setw(14) << "FECHA" << setw(31) << "DNI  -  PACIENTE" << setw(48) << "TELEFONO";
            archReporte << setw(14) << "LLEGADA" << setw(16) << "SALIDA" << setw(23) << "TIEMPO(minutos)";
            archReporte << setw(11) << "PAGO" << endl;
            elaborarLineas('-',CANT_MAX_LINEAS,archReporte);
    }
}
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/


// Módulo que imprime las líneas del reporte
void elaborarLineas(char caracter,int cantidad_de_lineas,ofstream &archReporte){
    for(int i=0; i < cantidad_de_lineas; i++){
        archReporte.put(caracter); /* Impresión del caracter */
    }
    archReporte << endl;  /* Impresión del cambio de línea */
}