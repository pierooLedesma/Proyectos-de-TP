

/* 
 * Archivo:   InfraccionCometida.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 29 de junio del 2025, 01:12 PM
 */

#ifndef INFRACCIONCOMETIDA_HPP
#define INFRACCIONCOMETIDA_HPP

struct InfraccionCometida {
    struct Fecha fechaDeInfraccion;
    char *placa;
    char *codigoDeLaInfraccion;
    double multa;
    char *descripcion;
    bool multaPagada;
    struct Fecha fechaDePago;
};

#endif /* INFRACCIONCOMETIDA_HPP */

