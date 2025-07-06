

/* 
 * Archivo:   Comentario.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de julio del 2025, 10:48 AM
 */

#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

struct Comentario {
    char *texto;
    char *pre_procesado;
    struct Palabra palabras[20]; // Como máximo hay 20 palabras en un comentario.
    int cantidad_palabras;
    int polaridad_total;
};

#endif /* COMENTARIO_HPP */

