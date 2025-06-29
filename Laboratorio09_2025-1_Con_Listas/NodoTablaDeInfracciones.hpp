

/* 
 * Archivo:   NodoTablaDeInfracciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 28 de junio del 2025, 02:45 PM
 */

#ifndef NODOTABLADEINFRACCIONES_HPP
#define NODOTABLADEINFRACCIONES_HPP

struct NodoTablaDeInfracciones {
    struct TablaDeInfracciones dato;
    struct NodoTablaDeInfracciones *siguiente;
};

#endif /* NODOTABLADEINFRACCIONES_HPP */

