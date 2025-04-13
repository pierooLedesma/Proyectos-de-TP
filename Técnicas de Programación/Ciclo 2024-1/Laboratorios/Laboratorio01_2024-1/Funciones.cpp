

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 12 de abril de 2025, 08:11 PM
 */


#include "Funciones.h"


// Módulo que lee y procesa el archivo "CitasMedicas.txt". Actualiza las estadísticas e imprime el reporte solicitado
void leer_y_procesar_citas_medicas(){
    int fecha,dni,tiempo_inicio,tiempo_final,cant_pacientes=0,cant_pacientes_con_medicinas=0,
            cant_pacientes_en_dermatologia=0,cant_pacientes_no_medicinas=0,cant_pacientes_en_pediatria=0,
            cant_pacientes_en_cardiologia_despues_15012024=0,cant_pacientes_no_medicinas_y_mas_de_350=0;
    char especialidad_medico,hay_medicina;
    double tarifa,monto_medicinas,total_ingresos=0.0,total_gasto_por_medicina_recetada=0.0,
            total_gasto_de_atencion_dermatologia=0.0;
    cout << fixed;
    imprimir_encabezado("EMPRESA DE SALUD S. A.", "REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS");
    while(true){
        if(not leer_linea_de_citas_medicas(fecha,dni,tiempo_inicio,tiempo_final,tarifa,especialidad_medico,
                hay_medicina,monto_medicinas)) break; // Se sale del bucle porque es el fin de archivo
        imprimir_datos_de_cita_medica_leida(fecha,dni,tiempo_inicio,tiempo_final,tarifa,especialidad_medico,
                hay_medicina,monto_medicinas,total_ingresos,cant_pacientes);
        actualizar_estadisticas(fecha,tiempo_inicio,tiempo_final,tarifa,especialidad_medico,
                hay_medicina,monto_medicinas,cant_pacientes_con_medicinas,total_gasto_por_medicina_recetada,
                cant_pacientes_en_dermatologia,total_gasto_de_atencion_dermatologia,
                cant_pacientes_no_medicinas,cant_pacientes_en_pediatria,
                cant_pacientes_en_cardiologia_despues_15012024,cant_pacientes_no_medicinas_y_mas_de_350);
    }
    imprimir_total_de_ingresos(total_ingresos);
    imprimir_estadisticas(cant_pacientes_con_medicinas,total_gasto_por_medicina_recetada,
            cant_pacientes_en_dermatologia,total_gasto_de_atencion_dermatologia,
            cant_pacientes_no_medicinas,cant_pacientes_en_pediatria,cant_pacientes,
            cant_pacientes_en_cardiologia_despues_15012024,cant_pacientes_no_medicinas_y_mas_de_350);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que elabora el encabezado del reporte que se solicita
void imprimir_encabezado(const char *titulo, const char *subtitulo){
    cout << setw((TAM_REPORTE + CANT_CARAC_TITULO) / 2) << titulo << endl;
    elaborar_lineas('=',TAM_REPORTE);
    cout << setw(((TAM_REPORTE - CANT_CARAC_SUBTITULO) / 2) - 10) << subtitulo << endl;
    elaborar_lineas('=',TAM_REPORTE);
    cout << "Fecha" << setw(TAM_REPORTE / NUM_COLUMNAS) << "Paciente";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 6) << "Inicio";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 7) << "Fin";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS + 6) << "Duracion (H:M:S)";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 1) << "Duracion (H)";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS) << "Especialidad";
    cout << setw(TAM_REPORTE / NUM_COLUMNAS + 12) << "Pago (cita+medicinas)" << endl;
    elaborar_lineas('-',TAM_REPORTE);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que lee una línea del archivo "CitasMedicas.txt". En caso lea el fin de archivo, retornará "false";
// caso contrario, retornará "true" en el cual se podrá seguir leyeno una línea más en la siguiente
// llamada de esta función.
bool leer_linea_de_citas_medicas(int &fecha,int &dni,int &tiempo_inicio,int &tiempo_final,double &tarifa,
        char &especialidad_medico,char &hay_medicina,double &monto_medicinas){
    fecha = leer_fecha();
    if(cin.eof()) return false; // No se sigue leyendo porque se llegó al fin del archivo "CitasMedicas.txt"
    cin >> dni;
    tiempo_inicio = leer_tiempo();
    tiempo_final = leer_tiempo();
    cin >> tarifa >> especialidad_medico;
    leer_si_se_recetaron_medicamentos(hay_medicina,monto_medicinas);
    return true;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que lee la fecha y la retorna como un valor entero
int leer_fecha(){
    char slash;
    int dia, mes, anio;
    cin >> dia >> slash >> mes >> slash >> anio;
    return anio*10000 + mes*100 + dia;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que lee el tiempo y lo retorna en segundos
int leer_tiempo(){
    char dos_puntos;
    int hora,minuto,segundo;
    cin >> hora >> dos_puntos;
    cin >> minuto >> dos_puntos;
    cin >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que lee la parte si es que se recetaron las medicinas y el monto de ellas
void leer_si_se_recetaron_medicamentos(char &hay_medicina,double &monto_medicinas){
    cin >> hay_medicina;
    if(hay_medicina == 'S') cin >> monto_medicinas;  // Sí se recetaron medicinas
    else monto_medicinas = 0.0;  // No se recetaron medicinas
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que imprime los datos leídos de la cita médica y actualiza el total de ingresos
void imprimir_datos_de_cita_medica_leida(int fecha,int dni,int tiempo_inicio,int tiempo_final,double tarifa,
        char especialidad_medico,char hay_medicina,double monto_medicinas,double &total_ingresos,
        int &cant_pacientes){
    double tiempo_en_horas = (double)(tiempo_final - tiempo_inicio)/3600;
    double cantidad_pagada = (tiempo_en_horas*(tarifa+monto_medicinas));
    imprimir_fecha(fecha);
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 5) << dni;
    imprimir_tiempo(tiempo_inicio,13);
    imprimir_tiempo(tiempo_final,13);
    imprimir_tiempo(tiempo_final - tiempo_inicio,9);
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 1) << setprecision(4) << tiempo_en_horas;
    imprimir_especialidad(especialidad_medico);
    cout << setprecision(2) << setw(TAM_REPORTE / NUM_COLUMNAS - 6) << cantidad_pagada << endl;
    total_ingresos += cantidad_pagada;
    cant_pacientes++;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que imprime la fecha en  " dia / mes / año "
void imprimir_fecha(int fecha){
    cout << setfill('0') << setw(2) << fecha%100 << '/';
    cout << setw(2) << (fecha / 100)%100 << '/';
    cout << fecha / 10000 << setfill(' ');
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que imprime el tiempo en  " hora : minuto : segundo "
void imprimir_tiempo(int tiempo,int num_para_restar){
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - num_para_restar) << ' ';
    cout << setfill('0') << setw(2) << tiempo / 3600 << ':';
    cout << setw(2) << (tiempo / 60)%60 << ':';
    cout << setw(2) << tiempo%60 << setfill(' ');
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que imprime la especialidad del médico
void imprimir_especialidad(char especialidad_medico){
    cout << setw(TAM_REPORTE / NUM_COLUMNAS - 7) << ' ';
    if(especialidad_medico == 'C') cout << "Cardiologia" << setw(8) << ' ';
    else if(especialidad_medico == 'D') cout << "Dermatologia" << setw(7) << ' ';
    else cout << "Pediatria" << setw(10) << ' ';
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que imprime el total de ingresos
void imprimir_total_de_ingresos(double total_ingresos){
    elaborar_lineas('=',TAM_REPORTE);
    cout << "Total de ingresos : " << total_ingresos << endl;
    elaborar_lineas('=',TAM_REPORTE);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que actualiza las estadísticas
void actualizar_estadisticas(int fecha,int tiempo_inicio,int tiempo_final,double tarifa,char especialidad_medico,
        char hay_medicina,double monto_medicinas,int &cant_pacientes_con_medicinas,
        double &total_gasto_por_medicina_recetada,int &cant_pacientes_en_dermatologia,
        double &total_gasto_de_atencion_dermatologia,int &cant_pacientes_no_medicinas,
        int &cant_pacientes_en_pediatria,int &cant_pacientes_en_cardiologia_despues_15012024,
        int &cant_pacientes_no_medicinas_y_mas_de_350){
    if(hay_medicina == 'S'){
        cant_pacientes_con_medicinas++;
        total_gasto_por_medicina_recetada += monto_medicinas;
    }
    if(especialidad_medico == 'D'){
        cant_pacientes_en_dermatologia++;
        total_gasto_de_atencion_dermatologia += monto_medicinas;
    }
    if(hay_medicina == 'N') cant_pacientes_no_medicinas++;
    if(especialidad_medico == 'P') cant_pacientes_en_pediatria++;
    cant_pacientes_en_cardiologia_despues_15012024 += es_despues_del_15012024(fecha,especialidad_medico);
    cant_pacientes_no_medicinas_y_mas_de_350 += no_medicina_y_mayor_350(hay_medicina,tarifa);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




int es_despues_del_15012024(int fecha,char especialidad_medico){
    return fecha > 20240115  and  especialidad_medico == 'C';
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




int no_medicina_y_mayor_350(char hay_medicina,double tarifa){
    return hay_medicina == 'N'   and  (tarifa) > 350;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




void imprimir_estadisticas(int cant_pacientes_con_medicinas,double total_gasto_por_medicina_recetada,
        int cant_pacientes_en_dermatologia,double total_gasto_de_atencion_dermatologia,
        int cant_pacientes_no_medicinas,int cant_pacientes_en_pediatria,int cant_pacientes,
        int cant_pacientes_en_cardiologia_despues_15012024,int cant_pacientes_no_medicinas_y_mas_de_350){
    imprimir_primera_parte_de_estadisticas(total_gasto_por_medicina_recetada,cant_pacientes_con_medicinas,
            total_gasto_de_atencion_dermatologia,cant_pacientes_no_medicinas,cant_pacientes);
    
    imprimir_segunda_parte_de_estadisticas(cant_pacientes_en_pediatria,cant_pacientes,
            cant_pacientes_en_cardiologia_despues_15012024,cant_pacientes_no_medicinas_y_mas_de_350);
    
    elaborar_lineas('=',TAM_REPORTE);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




void imprimir_primera_parte_de_estadisticas(double total_gasto_por_medicina_recetada,
        int cant_pacientes_con_medicinas,double total_gasto_de_atencion_dermatologia,
        int cant_pacientes_no_medicinas,int cant_pacientes){
    cout << setw(CANT_CARAC_TITULO_ESTADISTICAS);
    cout << "ESTADISTICAS OBTENIDAS:" << endl;
    
    cout << setw(CANT_CARAC_ESTADISTICAS - 8);
    cout << "Promedio de gastos por medicina de los pacientes que le recetaron medicinas";
    cout << setw(TAM_REPORTE - (CANT_CARAC_ESTADISTICAS + 13));
    cout << total_gasto_por_medicina_recetada / cant_pacientes_con_medicinas << endl;
    
    cout << setw(CANT_CARAC_ESTADISTICAS - 1);
    cout << "Promedio de gastos por medicina de los pacientes que se atendieron en dermatologia";
    cout << setw(TAM_REPORTE - (CANT_CARAC_ESTADISTICAS + 20));
    cout << total_gasto_de_atencion_dermatologia / cant_pacientes_no_medicinas << endl;
    
    cout << setw(CANT_CARAC_ESTADISTICAS - (CANT_CARAC_TITULO_ESTADISTICAS+1));
    cout << "Porcentaje de pacientes que no le recetaron medicinas";
    cout << setw((TAM_REPORTE+9) - CANT_CARAC_ESTADISTICAS);
    cout << ((double)cant_pacientes_no_medicinas / cant_pacientes) * 100 << '%' << endl;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




void imprimir_segunda_parte_de_estadisticas(int cant_pacientes_en_pediatria,int cant_pacientes,
        int cant_pacientes_en_cardiologia_despues_15012024,int cant_pacientes_no_medicinas_y_mas_de_350){
    cout << setw(CANT_CARAC_ESTADISTICAS - CANT_CARAC_TITULO_ESTADISTICAS);
    cout << "Porcentaje de pacientes que se atendieron en pediatria";
    cout << setw((TAM_REPORTE + 8) - CANT_CARAC_ESTADISTICAS);
    cout << ((double)cant_pacientes_en_pediatria / cant_pacientes) * 100 << '%' << endl;
    
    cout << setw(CANT_CARAC_ESTADISTICAS - 6);
    cout << "Cantidad de pacientes que se atendieron en cardiologia despues del 15/01/2024";
    cout << setw(TAM_REPORTE - (CANT_CARAC_ESTADISTICAS + 18));
    cout << cant_pacientes_en_cardiologia_despues_15012024 << endl;
    
    cout << setw(CANT_CARAC_ESTADISTICAS - 4);
    cout << "Porcentaje de pacientes que no le recetaron medicinas y que gasto mas de 350.00";
    cout << setw(TAM_REPORTE - (CANT_CARAC_ESTADISTICAS + 17));
    cout << ((double)cant_pacientes_no_medicinas_y_mas_de_350 / cant_pacientes) * 100 << '%' << endl;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/




// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres){
    for(int i=0; i < cant_caracteres; i++) cout.put(caracter);
    cout << endl;
}