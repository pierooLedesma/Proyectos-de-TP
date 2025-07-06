

/* 
 * Archivo:   Atencion.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de julio del 2025, 10:56 AM
 */

#ifndef ATENCION_HPP
#define ATENCION_HPP

struct Atencion {
    int codigo;
    struct Plato *platos_atendidos;
    int cantidad_platos;
    double total_venta;
    int hora;
    struct Comentario *comentarios;
    int cantidad_comentarios;
};

#endif /* ATENCION_HPP */

