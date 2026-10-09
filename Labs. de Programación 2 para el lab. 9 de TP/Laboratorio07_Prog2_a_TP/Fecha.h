Inicio
    C0 ← 0; C1 ← 0; C2 ← 0
    S0 ← 0; S1 ← 0; S2 ← 0
    SPar ← 0; SImpar ← 0

    Para i ← 1 Hasta 10 Hacer
        Leer NUM

        Si NUM = 0 Entonces
            C0 ← C0 + 1
            S0 ← S0 + NUM
        SiNo
            Si NUM = 1 Entonces
                C1 ← C1 + 1
                S1 ← S1 + NUM
            SiNo
                Si NUM = 2 Entonces
                    C2 ← C2 + 1
                    S2 ← S2 + NUM
                FinSi
            FinSi
        FinSi

        Si i MOD 2 = 0 Entonces
            SPar ← SPar + NUM
        SiNo
            SImpar ← SImpar + NUM
        FinSi
    FinPara

    Escribir C0, C1, C2
    Escribir S0, S1, S2
    Escribir SPar, SImpar
Fin



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



