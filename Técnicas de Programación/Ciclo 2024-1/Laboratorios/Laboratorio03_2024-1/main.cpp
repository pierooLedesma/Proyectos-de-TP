

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee los archivos "CitasMedicas.txt" y "Medicos.txt", y elabora un reporte
 *              en el archivo "Reporte.txt". Primero, al leer "CitasMedicas.txt", se lee una cita; segundo,
 *              por cada cita, se tendrá que buscar al médico en "Medicos.txt" y se imprimirá los datos
 *              del médico encontrado y se usará este archivo "Medicos.txt" varias veces para una cita
 *              leída. Finalmente, todo ello será leído e impreso en bucle hasta leer todo el archivo
 *              "CitasMedicas.txt" y mostrado en "Reporte.txt".
 * Creado el 19 de abril de 2025, 06:42 PM
 */


#include "Funciones.h"


int main(int argc, char** argv) {
    procesar_reporte("CitasMedicas.txt","Medicos.txt","Reporte.txt");
    return 0;
}

