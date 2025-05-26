

/* 
 * Archivo:   FuncionesCadenas.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 22 de mayo de 2025, 01:01 PM
 */


#include "FuncionesCadenas.h"


// Módulo que calcula la longitud de una cadena de caracteres
int longitud_cadena(const char *cadena){
    int longitud;
    
    // Se recorre la cadena caracter por caracter hasta encontrar el
    // terminador nulo '\0'. La condición "cadena[longitud]" es verdadera
    // mientras no sea '\0'.
    for(longitud = 0; cadena[longitud]; longitud++);
    
    
    // Retornar la cantidad de caracteres antes del terminador nulo.
    return longitud;
}





// Función que copia una cadena de caracteres de "fuente" a "destino"
void copiar_cadena(char *destino, const char *fuente){
    
    // Obtener la longitud de la cadena fuente (sin contar el carácter nulo).
    int longitud_fuente = longitud_cadena(fuente);
    
    
    // Copiar caracter por caracter desde "fuente" a "destino",
    // incluyendo el carácter nulo '\0' para finalizar la cadena destino.
    for(int i=0; i <= longitud_fuente; i++) destino[i] = fuente[i];
}






// Función que concatena la cadena "cadena_2" al final de "cadena_1"
void concatenar(char *cadena_1,const char *cadena_2){
    
    // Obtener la longitud actual de "cadena_1" para
    // saber desde dónde empezar a copiar.
    int longitud_cadena_1 = longitud_cadena(cadena_1);
    
    
    // Copiar "cadena_2" al final de "cadena_1" empezando desde la
    // índice justo después del último carácter de "cadena_1"
    copiar_cadena(&cadena_1[longitud_cadena_1], cadena_2);
}

