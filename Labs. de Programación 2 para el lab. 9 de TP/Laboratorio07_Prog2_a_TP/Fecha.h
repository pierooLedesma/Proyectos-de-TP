Algoritmo DescuentoCompra

    Escribir "Ingrese el monto de compra:"
    Leer monto

    Si monto >= 1000 Entonces
        porcentaje <- 20
    SiNo
        Si monto >= 500 Entonces
            porcentaje <- 15
        SiNo
            Si monto >= 250 Entonces
                porcentaje <- 10
            SiNo
                porcentaje <- 0
            FinSi
        FinSi
    FinSi

    descuento <- monto * porcentaje / 100
    total <- monto - descuento

    Escribir "Porcentaje de descuento: ", porcentaje, "%"
    Escribir "Valor del descuento: S/ ", descuento
    Escribir "Total a pagar: S/ ", total

FinAlgoritmo



/* 
 * Archivo:   Fecha.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 21 de junio del 2025, 12:51 PM
 */

#ifndef FECHA_H
#define FECHA_H

struct Fecha {
    int dd;
    int mm;
    int aa;
    int fecha;
};

#endif /* FECHA_H */



