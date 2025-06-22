

/* 
 * Archivo:   Zona.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 21 de junio del 2025, 02:50 PM
 */

#ifndef ZONA_H
#define ZONA_H

struct Zona {
    char *zona;
    
    struct DroneDeVelocidad *drones_velocidad;
    int n_drones_velocidad;
    
    struct DroneSemaforo *drones_semaforo;
    int n_drones_semaforo;
    
    struct DroneEstacionamiento *drones_estacionamiento;
    int n_drones_estacionamiento;
    
    int cantidad_multas_registradas;
    double total_multas_acumuladas;
};

#endif /* ZONA_H */



