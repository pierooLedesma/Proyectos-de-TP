

/* 
 * Archivo:   Infraccion.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 21 de junio del 2025, 02:16 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

struct Infraccion {
    struct Fecha fecha_evento;
    char *tipo_infraccion;
    double monto;
    struct Fecha fecha_pago_limite;
    char *placa;
};

#endif /* INFRACCION_H */


