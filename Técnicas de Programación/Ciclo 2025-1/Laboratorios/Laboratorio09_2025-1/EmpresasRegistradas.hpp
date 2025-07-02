

/* 
 * Archivo:   EmpresasRegistradas.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de junio del 2025, 01:09 PM
 */

#ifndef EMPRESASREGISTRADAS_HPP
#define EMPRESASREGISTRADAS_HPP

struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10]; // La máxima cantidad de placas en el arreglo de placas es de 10.
    int numPlacas;
    struct InfraccionCometida *infraccion;
    int cantidadDeInfracciones;
    double totalPagado;
    double totalAdeudado;
};

#endif /* EMPRESASREGISTRADAS_HPP */

