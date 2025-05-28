

/* 
 * Archivo:   FuncionesCadenas.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de mayo de 2025, 10:25 AM
 */


#include "FuncionesCadenas.h"


// Módulo que calcula la longitud de una cadena de caracteres
int longitud_cadena(const char *cadena){
    int long_cadena;
    
    // Se recorre la cadena caracter por caracter hasta encontrar el
    // terminador nulo '\0'. La condición "cadena[long_cadena]" es verdadera
    // mientras no sea '\0'.
    for(long_cadena = 0; cadena[long_cadena]; long_cadena++);
    
    // Retornar la cantidad de caracteres antes del terminador nulo.
    return long_cadena;
}



// Función que copia una cadena de caracteres de "fuente" a "destino"
void copiar_cadena(char *destino, const char *fuente){
    
    // Obtener la longitud de la cadena fuente (sin contar el carácter nulo).
    int long_cad_fuente = longitud_cadena(fuente);
    
    // Copiar caracter por caracter desde "fuente" a "destino",
    // incluyendo el carácter nulo '\0' para finalizar la cadena destino.
    for(int indice=0; indice <= long_cad_fuente; indice++) destino[indice] = fuente[indice];
}




// Función que concatena la cadena "cadena_2" al final de "cadena_1"
void concatenar(char *cadena_1, const char *cadena_2){
    
    // Obtener la longitud actual de "cadena_1" para
    // saber desde dónde empezar a copiar.
    int pos = longitud_cadena(cadena_1);
    
    
     // Copiar "cadena_2" al final de "cadena_1" empezando desde la
    // índice justo después del último carácter de "cadena_1"
    copiar_cadena(&cadena_1[pos], cadena_2);
}

