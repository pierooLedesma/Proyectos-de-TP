

/* 
 * Archivo:   PlatoPedido.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de junio del 2025, 12:57 PM
 */

#ifndef PLATOPEDIDO_H
#define PLATOPEDIDO_H

struct PlatoPedido{
    int codigoPedido;
    char* codigoPlato;
    char* descripcion;
    int cantidad;
    double precio;
    double subtotal;
};

#endif /* PLATOPEDIDO_H */

