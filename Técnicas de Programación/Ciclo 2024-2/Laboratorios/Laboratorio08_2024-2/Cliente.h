

/* 
 * Archivo:   Cliente.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 13 de junio del 2025, 12:57 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

struct Cliente{
    int dni;
    char* nombre;
    struct Distrito distrito;
    struct PlatoPedido pedidos[30]; // La máxima cantidad de platos pedidos que
                                    // realiza un cliente es de 30.
    int cantidadDePedidos;
    double montoTotal;
};

#endif /* CLIENTE_H */


