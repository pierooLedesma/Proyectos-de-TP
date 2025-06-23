

/* 
 * Archivo:   EmpresasRegistradas.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 20 de junio del 2025, 02:38 PM
 */

#ifndef EMPRESASREGISTRADAS_H
#define EMPRESASREGISTRADAS_H

struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10];
    int numPlacas;
    struct Fecha fechaDeInfraccion;
    struct Fecha fechaDePago;
    double totalPagado;
    double totalAdeudado;
    int cantidadDeFaltas;
};

#endif /* EMPRESASREGISTRADAS_H */

