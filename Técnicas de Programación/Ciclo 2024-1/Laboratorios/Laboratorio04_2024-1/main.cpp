

/* 
 * Archivo:   main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Descripción: El programa lee primero el archivo "Medicos.txt", ya que procesará la lista de médicos.
 *              Luego, procesará el archivo "CitasMedicas.txt" para procesar las citas que atendió el
 *              médico. Posterior a ello, procesará el archivo "Medicinas.txt" en el cual se imprimirá el
 *              nombre de cada medicina recetada al paciente en la cita que atendió el médico.
 *              Finalmente, se imprimirá el resumen del médico que aportó más al instituto.
 * Creado el 24 de abril de 2025, 10:47 AM
 */


#include "Funciones.h"



int main(int argc, char** argv) {
    procesar_reporte("Medicos.txt","CitasMedicas.txt",
                     "Medicinas.txt","Reporte.txt");
    return 0;
}

