

/* 
 * Archivo:   FuncionesCadenas.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de junio del 2025, 10:43 AM
 */


#include "FuncionesCadenas.h"


// Módulo que calcula la longitud de una cadena de caracteres
int longitud_cadena(const char *cadena) {
    int longitud_de_la_cadena;
    
    // Se recorre la cadena caracter por caracter hasta encontrar el
    // terminador nulo '\0'. La condición "cadena[longitud_de_la_cadena]" es verdadera
    // mientras no sea '\0'.
    for(longitud_de_la_cadena = 0; cadena[longitud_de_la_cadena]; longitud_de_la_cadena++);
    
    // Retornar la cantidad de caracteres antes del terminador nulo.
    return longitud_de_la_cadena;
}





// Función que copia una cadena de caracteres de "fuente" a "destino"
void copiar_cadena(char *destino, const char *fuente) {
    
    // Obtener la longitud de la cadena fuente (sin contar el carácter nulo).
    int long_fuente = longitud_cadena(fuente);
    
    // Copiar caracter por caracter desde "fuente" a "destino",
    // incluyendo el carácter nulo '\0' para finalizar la cadena destino.
    for(int indice = 0; indice <= long_fuente; indice++) destino[indice] = fuente[indice];
}





// Función que concatena la cadena "cadena_2" al final de "cadena_1"
void concatenar_cadena(char *cadena_1, const char *cadena_2) {
    
    // Obtener la longitud actual de "cadena_1" para
    // saber desde dónde empezar a copiar.
    int indice_final_de_cadena_1 = longitud_cadena(cadena_1);
    
    // Copiar "cadena_2" al final de "cadena_1" empezando desde el
    // índice justo después del último carácter de "cadena_1"
    copiar_cadena(&cadena_1[indice_final_de_cadena_1], cadena_2);
}






// Módulo que compara dos cadenas carácter por carácter.
// Retorna:
//   - Un valor negativo si "cadena_1" es menor que "cadena_2" en orden alfabético,
//   - Cero si ambas cadenas son iguales,
//   - Un valor positivo si "cadena_1" es mayor que "cadena_2".
//
// La comparación se realiza según los valores ASCII de los caracteres correspondientes.
int comparar_cadenas(const char *cadena_1, const char *cadena_2) {
    int indice;
    
    // Se recorren los caracteres mientras no se llegue al final de "cadena_1".
    for(indice = 0; cadena_1[indice]; indice++) {
        // Si hay una diferencia en el carácter actual, se retorna la diferencia de ASCII.
        if(cadena_1[indice] != cadena_2[indice])
            return cadena_1[indice] - cadena_2[indice];
    }
    
    // Se recorrió todo "cadena_1", puede que "cadena_2" tenga más caracteres.
    // Se retorna la diferencia entre el carácter nulo ('\0') de "cadena_1" y el carácter actual de "cadena_2".
    return cadena_1[indice] - cadena_2[indice];
}


