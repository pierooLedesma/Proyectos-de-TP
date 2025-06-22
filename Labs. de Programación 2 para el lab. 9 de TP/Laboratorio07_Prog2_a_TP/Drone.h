

/* 
 * Archivo:   Drone.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 21 de junio del 2025, 02:11 PM
 */

#ifndef DRONE_H
#define DRONE_H

struct Drone {
    char *id;
    char *ubicacion;
    int capacidad;
    struct Infraccion *infracciones;
    int cantidad_infracciones;
};

#endif /* DRONE_H */


