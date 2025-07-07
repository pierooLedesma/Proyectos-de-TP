

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 11 de mayo de 2025, 01:05 PM
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
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo,ofstream &output){
    output.open(nombre_archivo,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cant_caracteres,ofstream &output){
    for(int i=0; i < cant_caracteres; i++) output.put(caracter);
    output << endl;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que elabora los títulos de médicos y de medicinas
void imprimir_titulo(bool es_para_medicos,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "EMPRESA DE SALUD S. A." << endl;
    if(es_para_medicos){
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "REGISTRO DE INGRESOS POR MEDICO" << endl;
    } else {
        output << setw((TAM_REPORTE + TAM_TITULO_3) / 2);
        output << "REGISTRO DE INGRESOS POR MEDICAMENTO" << endl;
    }
    elaborar_lineas('=',TAM_REPORTE,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que imprime el encabezado del registro de médicos
void imprimir_encabezado_medico(ofstream &output){
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 5) - 2) << "No.";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 1) << "Codigo del";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 4) << "Tarifa";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 2) << "Ingresos por";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 3) << "Ingresos por";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 3) << "Total";
    output << setw(TAM_REPORTE / N_COLUMNAS + 8) << "Pacientes atendidos";
    output << setw(TAM_REPORTE / N_COLUMNAS + 9) << "Pacientes atendidos";
    output << "Total de"  << right<< endl;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 1) << "Medico";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4) + 1) << "las citas";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 4) << "medicamentos";
    output << setw(TAM_REPORTE / N_COLUMNAS  - 2) << "ingresado";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 6) << "con medicinas";
    output << setw(TAM_REPORTE / N_COLUMNAS  + 8) << "sin medicinas";
    output << setw(TAM_REPORTE / N_COLUMNAS + 2) << "pacientes" << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que imprime el encabezado del registro de medicinas
void imprimir_encabezado_medicina(ofstream &output){
    output << left << setw(TAM_REPORTE / ((N_COLUMNAS - 3) + 5) - 2) << "No.";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 1) << "Codigo del";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  - 9) << "Precio";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 8) << "Cantidad de unidades";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 2) << "Ingresos sin";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 3) << "Descuentos por";
    output << "Total"  << right<< endl;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  - 2) << "Medicamento";
    output << setw(TAM_REPORTE / ((N_COLUMNAS - 3) - 3) - 5) << "vendidas";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 5) << "descuentos";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 3) << "los seguros";
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  - 2) << "ingresado" << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que lee una fecha de la siguiente forma: DD/MM/AAAA
void leer_fecha(ifstream &input){
    int dia,mes,anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que lee el tiempo de la forma HH:MM:SS y retorna el tiempo en segundos
int leer_tiempo(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que lee un dato de tipo "int"
int leer_dato_tipo_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que lee un dato de tipo "double"
double leer_dato_tipo_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que lee un dato de tipo "char"
char leer_dato_tipo_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que ignora una cadena de caracteres
void ignorar_hasta_delimitador(char delimitador,bool es_nombre_medico,ifstream &input){
    input >> ws; // Lectura de espacios en blanco;
    if(es_nombre_medico) input.get(); // Lectura del caracter '/'
    while(input.get() != delimitador);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo para eliminar datos de un arreglo mediante un índice para eliminar los datos de ese índice
void eliminar_datos_de_un_arreglo(int indice_de_datos_a_eliminar,
                        int *arr_codigo_medico,double *arr_tarifa_medico,int &cant_medicos,
                        double *arr_ingresos_por_medico,int *arr_totales_clientes){
    for(int indice = indice_de_datos_a_eliminar; indice < cant_medicos - 1; indice++){
        // Código de un médico
        arr_codigo_medico[indice] = arr_codigo_medico[indice + 1];
        
        // Tarifa de un médico
        arr_tarifa_medico[indice] = arr_tarifa_medico[indice + 1];
        
        // Total de ingresos por las citas de un médico
        arr_ingresos_por_medico[3*indice] = arr_ingresos_por_medico[3*(indice+1)];
        
        // Total de ingresos por medicamentos de un médico
        arr_ingresos_por_medico[3*indice + 1] = arr_ingresos_por_medico[3*(indice+1) + 1];
        
        // Total ingresado de un médico
        arr_ingresos_por_medico[3*indice + 2] = arr_ingresos_por_medico[3*(indice+1) + 2];
        
        // Pacientes atendidos con medicinas
        arr_totales_clientes[3*indice] = arr_totales_clientes[3*(indice+1)];
        
        // Pacientes atendidos sin medicinas
        arr_totales_clientes[3*indice + 1] = arr_totales_clientes[3*(indice+1) + 1];
        
        // Total de pacientes atendidos
        arr_totales_clientes[3*indice + 2] = arr_totales_clientes[3*(indice+1) + 2];
    }
    cant_medicos--;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que realiza el procesa de eliminación de datos de los
// médicos que sean menor que el promedio de los ingresos totales.
void eliminar_datos(int *arr_codigo_medico,double *arr_tarifa_medico,int &cant_medicos,
                    double *arr_ingresos_por_medico,int *arr_totales_clientes){
    double ingresos_totales = 0.0,promedio_ingresos_totales;
    
    // Cálculo del ingreso total de todos los médicos
    for(int indice = 0; indice < cant_medicos; indice++){
        // Ingresos totales  +=  ingreso total de un médico
        ingresos_totales += arr_ingresos_por_medico[3*indice + 2];
    }
    
    // Cálculo del promedio de ingresos totales
    promedio_ingresos_totales = ingresos_totales / cant_medicos;
    
    // Eliminar a los médicos que tienen el menor dato
    int indice = 0;
    while(indice < cant_medicos){
        if(arr_ingresos_por_medico[3*indice + 2] < promedio_ingresos_totales){
            eliminar_datos_de_un_arreglo(indice,arr_codigo_medico,arr_tarifa_medico,cant_medicos,
                                         arr_ingresos_por_medico,arr_totales_clientes);
            // No incrementar el índice para revisar el nuevo que quedó en esta posición.
        } else {
            indice++; // Solo si no se eliminó algún dato.
        }
    }
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que imprime un juego de datos del registro de un médico
void imprimir_juego_de_datos_de_un_medico(int codigo_medico,double tarifa_medico,
        double ingresos_por_cita_de_un_medico,double ingresos_por_medicamentos_por_medicos,
        double total_ingresado,int pacientes_atendidos_con_medicina_por_medico,
        int pacientes_atendidos_sin_medicina_por_medico,int total_pacientes_por_medico,
        int indice,ofstream &output){
    output << setfill('0') << setw(3) << indice + 1 << setfill(' ');
    output << setw(TAM_REPORTE / N_COLUMNAS  - 3) << codigo_medico;
    output << setw(TAM_REPORTE / N_COLUMNAS) << tarifa_medico;
    output << setw(TAM_REPORTE / N_COLUMNAS) << ingresos_por_cita_de_un_medico;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 2) << ingresos_por_medicamentos_por_medicos;
    output << setw(TAM_REPORTE / N_COLUMNAS) << total_ingresado;
    output << setw(TAM_REPORTE / N_COLUMNAS) << pacientes_atendidos_con_medicina_por_medico;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) + 3);
    output << pacientes_atendidos_sin_medicina_por_medico;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2));
    output << total_pacientes_por_medico << endl;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que actualiza todo los totales existentes por cada total de los registros de médicos
void actualizar_montos_y_totales_del_registro_de_medicos(double &total_ingreso_citas,
                    double &total_ingreso_medicamentos,double &total_del_total_ingresado,
                    int &total_pacientes_con_medicinas,int &total_pacientes_sin_medicinas,
                    int &total_del_total_pacientes,double ingresos_por_cita_de_un_medico,
                    double ingresos_por_medicamentos_por_medicos,double total_ingresado,
                    int pacientes_atendidos_con_medicina_por_medico,
                    int pacientes_atendidos_sin_medicina_por_medico,int total_pacientes_por_medico){
    total_ingreso_citas += ingresos_por_cita_de_un_medico;
    total_ingreso_medicamentos += ingresos_por_medicamentos_por_medicos;
    total_del_total_ingresado += total_ingresado;
    total_pacientes_con_medicinas += pacientes_atendidos_con_medicina_por_medico;
    total_pacientes_sin_medicinas += pacientes_atendidos_sin_medicina_por_medico;
    total_del_total_pacientes += total_pacientes_por_medico;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que imprime los totales existentes por cada total de los registros de médicos
void imprimir_totales_del_registro_de_medicos(double total_ingreso_citas,
            double total_ingreso_medicamentos,double total_del_total_ingresado,
            int total_pacientes_con_medicinas,int total_pacientes_sin_medicinas,
            int total_del_total_pacientes,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "Totales:" << setw(TAM_REPORTE / (N_COLUMNAS - 5) + 2);
    output << total_ingreso_citas;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 2) << total_ingreso_medicamentos;
    output << setw(TAM_REPORTE / N_COLUMNAS) << total_del_total_ingresado;
    output << setw(TAM_REPORTE / N_COLUMNAS) << total_pacientes_con_medicinas;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2) + 3) << total_pacientes_sin_medicinas;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 2)) << total_del_total_pacientes;
    output << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que imprime el registro de médicos
void imprimir_registro_de_medicos(ofstream &output,int *arr_codigo_medico,
        double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
        int *arr_totales_clientes){
    double total_ingreso_citas=0.0,total_ingreso_medicamentos=0.0,total_del_total_ingresado=0.0;
    int total_pacientes_con_medicinas=0,total_pacientes_sin_medicinas=0,total_del_total_pacientes=0;
    imprimir_titulo(true,output);
    imprimir_encabezado_medico(output);
    for(int indice = 0; indice < cant_medicos; indice++){
        imprimir_juego_de_datos_de_un_medico(arr_codigo_medico[indice],arr_tarifa_medico[indice],
                                    arr_ingresos_por_medico[3*indice],arr_ingresos_por_medico[3*indice +1],
                                    arr_ingresos_por_medico[3*indice +2],arr_totales_clientes[3*indice],
                                    arr_totales_clientes[3*indice + 1],arr_totales_clientes[3*indice + 2],
                                    indice,output);
        actualizar_montos_y_totales_del_registro_de_medicos(total_ingreso_citas,
                total_ingreso_medicamentos,total_del_total_ingresado,total_pacientes_con_medicinas,
                total_pacientes_sin_medicinas,total_del_total_pacientes,arr_ingresos_por_medico[3*indice],
                arr_ingresos_por_medico[3*indice + 1],arr_ingresos_por_medico[3*indice + 2],
                arr_totales_clientes[3*indice],arr_totales_clientes[3*indice +1],arr_totales_clientes[3*indice +2]);
    }
    imprimir_totales_del_registro_de_medicos(total_ingreso_citas,total_ingreso_medicamentos,
            total_del_total_ingresado,total_pacientes_con_medicinas,total_pacientes_sin_medicinas,
            total_del_total_pacientes,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que imprime un juego de datos del registro de un medicina
void imprimir_juego_de_datos_de_una_medicina(int indice,int codigo_medicina,
        double precio_medicina,int cant_unidades_vendidas,
        double ingresos_sin_descuentos_por_medicamento,
        double descuentos_por_los_seguros_por_medicamento,double total_ingresado,ofstream &output){
    output << setfill('0') << setw(3) << indice + 1 << setfill(' ');
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  - 8) << codigo_medicina;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) - 1) << precio_medicina;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) - 4) << cant_unidades_vendidas;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3)  + 6);
    output << ingresos_sin_descuentos_por_medicamento;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) + 3);
    output << descuentos_por_los_seguros_por_medicamento;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 3) - 2) << total_ingresado;
    output << endl;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que actualiza todo los totales existentes por cada total de los registros de las medicinas
void actualizar_montos_y_totales_del_registro_de_medicinas(int &total_cant_unidades,
        double &total_ingreso_sin_descuento,double &total_ingreso_con_descuento,
        double &total_del_total_ingresado,double ingresos_sin_descuentos_por_medicamento,
        double descuentos_por_los_seguros_por_medicamento,double total_ingresado,
        int cant_unidades_vendidas){
    total_cant_unidades += cant_unidades_vendidas;
    total_ingreso_sin_descuento += ingresos_sin_descuentos_por_medicamento;
    total_ingreso_con_descuento += descuentos_por_los_seguros_por_medicamento;
    total_del_total_ingresado += total_ingresado;
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que imprime los totales existentes por cada total de los registros de las medicinas
void imprimir_totales_del_registro_de_medicos(int total_cant_unidades,
        double total_ingreso_sin_descuento,double total_ingreso_con_descuento,
        double total_del_total_ingresado,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << "Totales:" << setw(TAM_REPORTE / (N_COLUMNAS - 6) + 5);
    output << total_cant_unidades;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4)  + 1) << total_ingreso_sin_descuento;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4) - 2) << total_ingreso_con_descuento;
    output << setw(TAM_REPORTE / (N_COLUMNAS - 4) - 7) << total_del_total_ingresado;
    output << endl;
    elaborar_lineas('=',TAM_REPORTE,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que imprime el registro de medicinas
void imprimir_registro_de_medicinas(int *arr_codigo_medicina,double *arr_precio_medicina,
        int cant_medicinas,int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,
        ofstream &output){
    int total_cant_unidades =0;
    double total_ingreso_sin_descuento = 0.0,total_ingreso_con_descuento = 0.0,
                total_del_total_ingresado = 0.0;
    imprimir_titulo(false,output);
    imprimir_encabezado_medicina(output);
    for(int indice = 0; indice < cant_medicinas; indice++){
        imprimir_juego_de_datos_de_una_medicina(indice,arr_codigo_medicina[indice],
                arr_precio_medicina[indice],arr_cant_unidades_vendidas[indice],
                arr_montos_por_medicamento[3*indice],arr_montos_por_medicamento[3*indice + 1],
                arr_montos_por_medicamento[3*indice + 2],output);
        actualizar_montos_y_totales_del_registro_de_medicinas(total_cant_unidades,
                total_ingreso_sin_descuento,total_ingreso_con_descuento,total_del_total_ingresado,
                arr_montos_por_medicamento[3*indice],arr_montos_por_medicamento[3*indice + 1],
                arr_montos_por_medicamento[3*indice + 2],arr_cant_unidades_vendidas[indice]);
    }
    imprimir_totales_del_registro_de_medicos(total_cant_unidades,
            total_ingreso_sin_descuento,total_ingreso_con_descuento,total_del_total_ingresado,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que elabora el reporte solicitado
void elaborar_reporte(const char *nombre_archivo,int *arr_codigo_medico,
        double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
        int *arr_totales_clientes,int *arr_codigo_medicina,double *arr_precio_medicina,int cant_medicinas,
        int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,bool imprimir_medicinas){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    imprimir_registro_de_medicos(output,arr_codigo_medico,arr_tarifa_medico,cant_medicos,
                                 arr_ingresos_por_medico,arr_totales_clientes);
    if(imprimir_medicinas){
        // Sí se requiere de imprimir el registro de medicinas
        output << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        imprimir_registro_de_medicinas(arr_codigo_medicina,arr_precio_medicina,cant_medicinas,
                arr_cant_unidades_vendidas,arr_montos_por_medicamento,output);
    }
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que busca un dato entero en un arreglo de datos de tipo entero (" int ")
int buscar_dato_tipo_int_en_un_arreglo(int dato,int *arreglo,int cant_datos){
    for(int indice = 0; indice < cant_datos; indice++){
        if(arreglo[indice] == dato){
            return indice; // Se encontró el dato buscado en el arreglo.
        }
    }
    return NO_ENCONTRADO; // No se encontró el dato buscado en el arreglo.
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que lee los datos de lectura fija del archivo "CItasMedicas.txt"
void leer_datos_fijos_de_CitasMedicas(double &porcentaje_descuento_cliente,int &tiempo_inicio,
                                      int &tiempo_fin,int &codigo_medico_leido,ifstream &input){
    int dni_paciente;
    dni_paciente = leer_dato_tipo_int(input);
    porcentaje_descuento_cliente = leer_dato_tipo_double(input);
    tiempo_inicio = leer_tiempo(input);
    tiempo_fin = leer_tiempo(input);
    codigo_medico_leido = leer_dato_tipo_int(input);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que procesa la lectura variable del archivo "CitasMedicas.txt". Realiza actualizaciones
// en los arreglos que son de sumar totales y montos por cada médico y medicina.
void procesar_lista_de_medicamentos(double tarifa_medico,double &ingreso_por_las_citas,
        double &ingreso_por_los_medicamentos,int &cant_pacientes_con_medicinas,
        int &cant_pacientes_sin_medicinas,int *arr_codigo_medicina,double *arr_precio_medicina,
        int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento,int cant_medicinas,
        ifstream &input,double porcentaje_descuento_cliente,int duracion_en_segundos){
    int pacientes_atendidos_con_medicinas = 0,codigo_medicina_leida,cantidad_recetada,pos_medicina;
    while(true){
        if(input.get() == '\n') break;
        codigo_medicina_leida = leer_dato_tipo_int(input);
        cantidad_recetada = leer_dato_tipo_int(input);
        pos_medicina = buscar_dato_tipo_int_en_un_arreglo(codigo_medicina_leida,
                                                          arr_codigo_medicina,cant_medicinas);
        if(pos_medicina != NO_ENCONTRADO){
            ingreso_por_las_citas += ( tarifa_medico * (1 - porcentaje_descuento_cliente / 100) ) *
                                     ( (int)duracion_en_segundos / 3600 );
            ingreso_por_los_medicamentos += ( arr_precio_medicina[pos_medicina] *
                                            (1 - (porcentaje_descuento_cliente / 2) / 100) ) * cantidad_recetada;
            // Cantidad de unidades vendidas de una medicina:
            arr_cant_unidades_vendidas[pos_medicina] += cantidad_recetada;
            
            // Ingreso de un medicamento sin el descuento:
            arr_montos_por_medicamento[3*pos_medicina] += arr_precio_medicina[pos_medicina] *
                                                          cantidad_recetada;
            
            // Ingreso de un medicamento con el descuento por el seguro médico del paciente:
            arr_montos_por_medicamento[3*pos_medicina + 1] += ( arr_precio_medicina[pos_medicina] *
                                                              (1 - (porcentaje_descuento_cliente / 2) / 100) ) *
                                                              cantidad_recetada;
            pacientes_atendidos_con_medicinas++;
        }
    }
    cant_pacientes_con_medicinas += (pacientes_atendidos_con_medicinas > 0 ? 1 : 0);
    cant_pacientes_sin_medicinas += (pacientes_atendidos_con_medicinas == 0 ? 1 : 0);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que actualiza los totales ingresados por cada medicina y por cada médico,
// y el total de pacientes que atendió cada paciente.
void actualizar_totales_medicinas_y_de_medicos(int *arr_totales_clientes,
                                    double *arr_ingresos_por_medico,int cant_medicos,
                                    double *arr_montos_por_medicamento,int cant_medicinas){
    /******** Totales y montos para médicos ************/
    for(int indice=0; indice < cant_medicos; indice++){
        // Total ingresado     =     Ingresos por las citas    +   Ingresos por medicamentos 
        arr_ingresos_por_medico[3*indice + 2] = arr_ingresos_por_medico[3*indice] +
                                                arr_ingresos_por_medico[3*indice + 1];
        
        // Total Pacientes   =   Pacientes atendidos con medicinas   +   Pacientes atendidos sin medicinas
        arr_totales_clientes[3*indice + 2] = arr_totales_clientes[3*indice] + arr_totales_clientes[3*indice + 1];
    }
    
    
    /******** Totales para medicinas ********/
    for(int indice=0; indice < cant_medicinas; indice++){
        // Total ingresado   =   Ingresos sin descuentos  -   Descuentos por los seguros
        arr_montos_por_medicamento[3*indice + 2] = arr_montos_por_medicamento[3*indice] -
                                                   arr_montos_por_medicamento[3*indice + 1];
    }
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/








// Módulo que realiza la actualización de arreglos de montos
// y totales mediante el archivo "CitasMedicas.txt".
void actualizar_montos_y_totales(const char *nombre_archivo,int *arr_codigo_medico,
                   double *arr_tarifa_medico,int cant_medicos,double *arr_ingresos_por_medico,
                   int *arr_totales_clientes,int *arr_codigo_medicina,double *arr_precio_medicina,
                   int cant_medicinas,int *arr_cant_unidades_vendidas,double *arr_montos_por_medicamento){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int fecha,codigo_medico_leido,tiempo_inicio,tiempo_fin,pos_medico;
    double porcentaje_descuento_cliente;
    while(true){
        leer_fecha(input);
        if(input.eof()) break; // Validar fin del archivo "CitasMedicas.txt"
        leer_datos_fijos_de_CitasMedicas(porcentaje_descuento_cliente,tiempo_inicio,tiempo_fin,
                                         codigo_medico_leido,input);
        pos_medico = buscar_dato_tipo_int_en_un_arreglo(codigo_medico_leido,
                                                        arr_codigo_medico,cant_medicos);
        if(pos_medico != NO_ENCONTRADO)
            procesar_lista_de_medicamentos(arr_tarifa_medico[pos_medico],
                    arr_ingresos_por_medico[3*pos_medico],arr_ingresos_por_medico[3*pos_medico + 1],
                    arr_totales_clientes[3*pos_medico],arr_totales_clientes[3*pos_medico + 1],
                    arr_codigo_medicina,arr_precio_medicina,arr_cant_unidades_vendidas,
                    arr_montos_por_medicamento,cant_medicinas,input,porcentaje_descuento_cliente,
                    tiempo_fin - tiempo_inicio);
        else 
            ignorar_hasta_delimitador('\n',false,input);
    }
    actualizar_totales_medicinas_y_de_medicos(arr_totales_clientes,arr_ingresos_por_medico,cant_medicos,
                                              arr_montos_por_medicamento,cant_medicinas);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que imprime los datos de los arreglos (para arreglos de médicos 
// como para arreglos de medicinas) para el reporte de prueba.
void imprimir_datos_arreglo_para_reporte_prueba(int *arr_codigos,
                              double *arr_precios,int cant_datos,ofstream &output){
    for(int indice = 0; indice < cant_datos; indice++){
        output << setw(4) << indice + 1 << ')';
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 2);
        output << arr_codigos[indice];
        output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6));
        output << arr_precios[indice];
        output << endl;
    }
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/






// Módulo que elabora el reporte de prueba para verificar la correcta asignación de los datos en los arreglos.
void elaborar_reporte_prueba(const char *nombre_archivo,int *arr_codigo_medico,
                            double *arr_tarifa_medico,int cant_medicos,int *arr_codigo_medicina,
                            double *arr_precio_medicina,int cant_medicinas){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo,output);
    output << fixed << setprecision(2);
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
    output << setw((TAM_REPORTE_PRUEBA + TAM_NOMBRE_PRUEBA_1) / 2   - 3);
    output << "DATOS DE MEDICOS" << endl;
    output << setw(5) << "No." << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 1) << "Codigo";
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 1) << "Tarifa" << endl;
    imprimir_datos_arreglo_para_reporte_prueba(arr_codigo_medico,arr_tarifa_medico,
                                               cant_medicos,output);
    output << endl << endl << endl << endl;
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
    output << setw((TAM_REPORTE_PRUEBA + TAM_NOMBRE_PRUEBA_2) / 2   - 2);
    output << "DATOS DE MEDICINAS" << endl;
    output << setw(5) << "No." << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 1) << "Codigo";
    output << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 6) - 1) << "Precio" << endl;
    imprimir_datos_arreglo_para_reporte_prueba(arr_codigo_medicina,arr_precio_medicina,
                                               cant_medicinas,output);
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que lee los datos del archivo "Medicinas.txt" y
// almacena el código de la medicina y su precio en arreglos.
void procesarMedicinas(const char *nombre_archivo,int *arr_codigo_medicina,
                       double *arr_precio_medicina,int &cant_medicinas){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int codigo_medicina;
    cant_medicinas = 0;
    while(true){
        codigo_medicina = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "Medicinas.txt"
        arr_codigo_medicina[cant_medicinas] = codigo_medicina;
        ignorar_hasta_delimitador(' ',false,input);
        arr_precio_medicina[cant_medicinas] = leer_dato_tipo_double(input);
        cant_medicinas++;
    }
}
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/







// Módulo que lee los datos del archivo "Medicos.txt" y
// almacena el código del médico y su tarifa en arreglos.
void procesarMedicos(const char *nombre_archivo,int *arr_codigo_medico,
                     double *arr_tarifa_medico,int &cant_medicos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo,input);
    int codigo_medico;
    cant_medicos = 0;
    while(true){
        codigo_medico = leer_dato_tipo_int(input);
        if(input.eof()) break; // Validar fin del archivo "Medicos.txt"
        arr_codigo_medico[cant_medicos] = codigo_medico;
        ignorar_hasta_delimitador('/',true,input);
        ignorar_hasta_delimitador(' ',false,input);
        arr_tarifa_medico[cant_medicos] = leer_dato_tipo_double(input);
        cant_medicos++;
    }
}

