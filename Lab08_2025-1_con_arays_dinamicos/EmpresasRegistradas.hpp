

/* 
 * Archivo:   EmpresasRegistradas.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 23 de junio del 2025, 11:11 AM
 */

#ifndef EMPRESASREGISTRADAS_HPP
#define EMPRESASREGISTRADAS_HPP

struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10]; // En el arreglo de "placas", habrá máximo 10 placas.
    int numPlacas;
    struct Fecha fechaDeInfraccion;
    struct Fecha fechaDePago;
    double totalDeMultas;
    double totalPagado;
    double totalAdeudado;
    int cantidadDeFaltas;
};

#endif /* EMPRESASREGISTRADAS_HPP */


