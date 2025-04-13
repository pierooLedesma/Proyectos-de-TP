

/* 
 * File:   main.cpp
 * Author: Alessandro Piero Ledesma Guerra
 * Código: 20217340
 * Creado el 29 de marzo de 2025, 11:18 PM
 */


#include "Funciones.h"


/*
 * El programa imprime el reporte solicitado en el problema. Lee primero el archivo "Medicos.txt";
 * luego, después de leer el primer médico, se procede a leer el achivo "Citas.txt" en el cual se imprimirá
 * los datos de cada cita por el médico leído y, para poder imprimir ello, se procede a leer el archivo
 * "Pacientes.txt". Finalmente, se imprime las citas mediante la información del paciente. Los nombres de
 * los médicos se imprimen tal como está sin los guiones y el de los pacientes todo en mayúscula sin corchetes. 
 */


int main(int argc, char** argv) {
    elaborarReporteSolicitado("Medicos.txt","Pacientes.txt","Citas.txt","ReporteDeCitasPorMedico.txt");
    return 0;
}

