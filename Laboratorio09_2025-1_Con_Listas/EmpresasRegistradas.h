

/* 
 * Archivo:   EmpresasRegistradas.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 28 de junio del 2025, 02:16 PM
 */

#ifndef EMPRESASREGISTRADAS_H
#define EMPRESASREGISTRADAS_H

struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10];  // Cada empresa tiene como máximo 10 vehículos.
    int numPlacas;
    struct InfraccionCometida *infracciones;
    int cantidadDeInfracciones;
    double totalPagado;
    double totalAdeudado;
};

#endif /* EMPRESASREGISTRADAS_H */

