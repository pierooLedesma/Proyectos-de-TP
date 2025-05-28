

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 27 de mayo de 2025, 10:25 AM
 */


#include "Funciones.h"


// Módulo que apertura un archivo de lectura sin usar el constructor
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input){
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}



// Módulo que apertura un archivo de escritura sin usar el constructor
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output){
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato de tipo  " int "
int leer_dato_int(ifstream &input){
    int dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo  " double "
double leer_dato_double(ifstream &input){
    double dato;
    input >> dato;
    return dato;
}



// Módulo que lee un dato de tipo  " char "
char leer_dato_char(ifstream &input){
    char dato;
    input >> dato;
    return dato;
}




// Módulo que imprime las líneas del reporte
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output){
    for(int i=0; i<cant_caracteres; i++)  output.put(caracter);
    output << endl;
}




// Módulo que imprime el título del reporte de prueba y del reporte principal solicitado
void imprimir_titulo(bool es_prueba, ofstream &output){
    if(es_prueba){
        // Imprimir el título del reporte de prueba
        output << setw((TAM_REPORTE_PRUEBA + TAM_TITULO_PRUEBA) / 2);
        output << "VERIFICACION DE LA CARGA DE DATOS DE PLATOS" << endl;
        elaborar_lineas('=', TAM_REPORTE_PRUEBA, output);
    } else {
        // Imprimir el título del reporte principal solicitado
        output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
        output << "EMPRESA DE REPARTOS A DOMICILIO TP S. A." << endl;
        output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
        output << "RELACION DE PLATOS VENDIDOS" << endl;
        elaborar_lineas('=', TAM_REPORTE, output);
    }
}




// Módulo que imprime el encabezado del reporte de prueba y del reporte principal solicitado
void imprimir_encabezado(bool es_prueba, ofstream &output){
    if(es_prueba){
        // Imprimir el encabezado del reporte de prueba
        output << "CODIGO" << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2) - 1);
        output << "CANT.VENDIDA" << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS  - 2);
        output << "PRECIO" << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2));
        output << "INGRESO BRUTO" << setw(TAM_REPORTE_PRUEBA / (N_COLUMNAS - 2) - 1);
        output << "HAY DESCUENTO" << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS);
        output << "DESCUENTO" << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS  - 3);
        output << "TOTAL" << endl;
        elaborar_lineas('-',TAM_REPORTE_PRUEBA, output);
    } else {
        // Imprimir el encabezado del reporte principal solicitado
        output << "No." << setw(TAM_REPORTE / N_COLUMNAS - 3);
        output << "PLATO OFRECIDO" << setw(TAM_REPORTE / (N_COLUMNAS - 5) + 3);
        output << "CANTIDAD VENDIDA" << setw(TAM_REPORTE / (N_COLUMNAS + 7) - 1);
        output << "PRECIO" << setw(TAM_REPORTE / (N_COLUMNAS + 3) + 2);
        output << "INGRESO BRUTO" << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2);
        output << "DESCUENTO" << setw(TAM_REPORTE / (N_COLUMNAS + 7) - 1);
        output << "TOTAL" << endl;
        elaborar_lineas('-', TAM_REPORTE, output);
    }
}




// Módulo que lee un valor de descuento 
double leer_valor_del_descuento(ifstream &input){
    double valor_del_descuento;
    char simbolo_porcentaje;
    
    // Se lee el valor numérico del descuento
    valor_del_descuento = leer_dato_double(input);
    
    // Se lee el carácter '%' que sigue al número
    simbolo_porcentaje = leer_dato_char(input);
    
    // Se retorna solo el valor numérico del descuento
    return valor_del_descuento;
}





// Módulo que determina si hay un descuento en la línea actual del archivo
double determinar_descuento(ifstream &input){
    double descuento;
    
    if(input.get() != '\n')
        // Si no se leyó un salto de línea, entonces sí hay un descuento
        descuento = leer_valor_del_descuento(input);
    else
        // Si se leyó un salto de línea, entonces no hay descuento
        descuento = 0.0;
    
    return descuento;
}





// Módulo que lee un juego de datos de un plato ofrecido del archivo "PlatosOfrecidos.txt"
void leer_un_plato_ofrecido(int &cod_plato_leido, char *plato, double &precio, char *categoria,
                            double &descuento,ifstream &input, bool &fin_de_archivo){
    // Leer el código del plato (un número entero)
    cod_plato_leido = leer_dato_int(input);
    
    // Verificar si se ha llegado al final del archivo "PlatosOfrecidos.txt"
    if(input.eof()){
        // Si es el fin del archivo, se activa la bandera y se sale de la función
        fin_de_archivo = true;
        return;
    }
    
    // Leer el nombre del plato
    input >> plato;
    
    // Leer el precio del plato
    precio = leer_dato_double(input);
    
    // Leer la categoría del plato
    input >> categoria;
    
    // Determinar y leer el valor del descuento si está presente en la línea
    descuento = determinar_descuento(input);
}





// Módulo que realiza una búsqueda binaria en un arreglo ordenado de forma descendente.
int busqueda_binaria(int dato_buscado, int *arreglo, int cant_datos){
    int lim_inferior = 0, lim_superior = cant_datos - 1, punto_medio;
    while(true){
        // Si los límites se cruzan, el valor no está en el arreglo
        if(lim_inferior > lim_superior) return NO_ENCONTRADO;
        
        // Cálculo del índice del punto medio del rango actual
        punto_medio = (lim_inferior + lim_superior) / 2;
        
        // Verificar si el valor en el punto medio es el buscado
        if(arreglo[punto_medio] == dato_buscado) return punto_medio;
        
        if(arreglo[punto_medio] > dato_buscado){
            // Si el valor en el punto medio es mayor al dato buscado,
            // se busca en la mitad derecha o en la mitad de abajo del arreglo (valores más pequeños).
            lim_inferior = punto_medio + 1;
        } else {
            // Si el valor en el punto medio es menor al dato buscado,
            // se busca en la mitad izquierda o en la mitad de arriba del arreglo (valores más grandes).
            lim_superior = punto_medio - 1;
        }
    }
}





// Módulo que recorre una cadena y reemplaza cada guion bajo ('_') por un espacio en blanco (' ')
void cambiar_guion_a_espacio_en_blanco(char *cadena){
    for(int indice=0; cadena[indice]; indice++){
        if(cadena[indice] == '_')   cadena[indice] = ' ';
    }
}





// Módulo que convierte a minúsculas todas las letras de una palabra, excepto la primera letra.
// La cadena inicialmente está todo con mayúscula y contiene palabras separadas por espacios.
void pasar_a_mayuscula_la_primera_palabra(char *cadena){
    for(int indice = 1; cadena[indice]; indice++){
        
        // Si el caracter anterior no es un espacio en blanco (' ')  y el caracter actual es una letra mayúscula,
        // entonces se procede a convertir a minúscula.
        if(cadena[indice - 1] != ' '    and    (cadena[indice] >= 'A'   and   cadena[indice] <= 'Z')){
            cadena[indice] = cadena[indice] - 'A' + 'a';
        }
    }
}





// Módulo que agrega al final del nombre del plato la categoría separada por un guion
void colocar_la_categoria_al_nombre_del_plato(char *nombre_plato, const char *categoria_plato){
    concatenar(nombre_plato, "-");
    concatenar(nombre_plato, categoria_plato);
}





// Módulo que busca el índice de un carácter específico dentro de una cadena
int buscar_caracter(char caracter, const char *cadena){
    for(int indice=0; cadena[indice]; indice++){
        if(cadena[indice] == caracter) return indice;
    }
    return NO_ENCONTRADO;
}





// Módulo que inserta una cadena dentro de otra justo después del primer guion encontrado.
// Por ejemplo: "Tallarines Rojos-ESPECIAL" con "PROMOCIONADO"  ->  "Tallarines-PROMOCIONADO-Rojos"
void insertar_cadena_en_medio_de_otra_cadena(char *cadena, const char *cadena_a_insertar){
    char categoria[MAX_CARACTERES_CATEGORIA];
    int pos_del_guion;
    
    // Buscar la posición del primer guion en la cadena
    pos_del_guion = buscar_caracter('-', cadena);
    
    
    if(pos_del_guion != NO_ENCONTRADO){
        
        // Copiar lo que está después del guion
        copiar_cadena(categoria, &cadena[pos_del_guion + 1]);  // categoria = "ESPECIAL"
        
        // Terminar la cadena justo después del guion
        cadena[pos_del_guion + 1] = '\0';  // cadena = Tallarines Rojos-'\0'SPECIAL'\0'
        
        // Insertar la nueva cadena ("PROMOCIONADO") en el medio
        concatenar(cadena, cadena_a_insertar); // cadena = "Tallarines Rojos-PROMOCIONADO"
        concatenar(cadena, "-");   // cadena = "Tallarines Rojos-PROMOCIONADO-"
        
        // Volver a agregar la parte que se guardó (lo que estaba después del guion)
        concatenar(cadena, categoria);   // cadena = "Tallarines Rojos-PROMOCIONADO-ESPECIAL"
    }
}






// Módulo que modifica el nombre del plato en el que el nombre del plato, por cada palabra, la primera letra
// es en minúscula, pero el nombre de la categoría se mantiene en mayúscula. Luego, insertar la cadena
// "PROMOCIONADO" en el medio de la cadena principal si el plato tiene un descuento.
void modificar_cadena(char *nombre_plato, const char *categoria_plato, bool tiene_descuento){
    cambiar_guion_a_espacio_en_blanco(nombre_plato);
    pasar_a_mayuscula_la_primera_palabra(nombre_plato);
    colocar_la_categoria_al_nombre_del_plato(nombre_plato, categoria_plato);
    if(tiene_descuento)  insertar_cadena_en_medio_de_otra_cadena(nombre_plato, "PROMOCIONADO");
}






// Módulo que imprime la información de un plato vendido y actualiza los totales de ingreso bruto y con descuento.
void imprimir_un_plato_vendido(double &total_ingreso_bruto, double &total_ingreso_con_descuento,
                    int n_plato, int codigoPlatos, int numPlatosVendidos, double precio, double ingresoBruto,
                    bool tieneDescuento, double descuento, double total, char *plato_ofrecido,
                    char *categoria_plato,ofstream &output){
    output << setfill('0') << setw(3) << n_plato << setfill(' ') << ')' << setw(2) << ' ';
    output << left << setw(TAM_REPORTE / (N_COLUMNAS + 6) - 2) << codigoPlatos;
    
    modificar_cadena(plato_ofrecido, categoria_plato, tieneDescuento);
    output << setw(TAM_REPORTE / (N_COLUMNAS - 5)) << plato_ofrecido << right;
    
    output << setw(3) << numPlatosVendidos <<  setw(TAM_REPORTE / (N_COLUMNAS + 3)) << precio;
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3)) << ingresoBruto;
    
    if(tieneDescuento) output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2) << descuento << '%';
    else  output << setw(TAM_REPORTE / (N_COLUMNAS + 7)) << '-' << setw(3) << ' ';
    
    output << setw(TAM_REPORTE / (N_COLUMNAS + 3) - 2) << total << endl;
    
    total_ingreso_bruto += ingresoBruto;
    total_ingreso_con_descuento += total;
}






// Módulo que lee todos los platos desde el archivo de "PlatosOfrecidos.txt" y los imprime si han sido vendidos.
// Además, acumula los ingresos brutos y los ingresos con descuento.
void imprimir_todos_los_platos(double &total_ingreso_bruto, double &total_ingreso_con_descuento,
                               int *arrCodigoPlatos, int *arrNumPlatosVendidos, double *arrPrecio,
                               double *arrIngresoBruto, bool *arrTieneDescuento, double *arrDescuento,
                               double *arrTotal, int cant_platos, ifstream &input, ofstream &output){
    input.clear(); // Liberar el buffer del archivo "PlatosOfrecidos.txt" y limpiar las banderas levantadas.
    input.seekg(0, ios::beg); // Devolver el puntero al inicio del archivo "PlatosOfrecidos.txt".
    int cod_plato_leido, pos_plato, n_platos = 0;
    double precio, descuento;
    char plato_ofrecido[MAX_CARACTERES_PLATO_OFRECIDO], categoria_plato[MAX_CARACTERES_CATEGORIA];
    bool fin_de_archivo = false;
    
    // Leer y procesar todos los platos ofrecidos desde el archivo "PlatosOfrecidos.txt"
    while(true){
        leer_un_plato_ofrecido(cod_plato_leido, plato_ofrecido, precio,
                               categoria_plato, descuento, input, fin_de_archivo);
        if(fin_de_archivo) break; // Se sale del bucle si se llegó al fin del archivo "PlatosOfrecidos.txt".
        
        // Buscar el código del plato en el arreglo de platos vendidos
        pos_plato = busqueda_binaria(cod_plato_leido, arrCodigoPlatos, cant_platos);
        
        // Si fue vendido, imprimir su información
        if(pos_plato != NO_ENCONTRADO){
            n_platos++;
            imprimir_un_plato_vendido(total_ingreso_bruto, total_ingreso_con_descuento, n_platos,
                                      arrCodigoPlatos[pos_plato], arrNumPlatosVendidos[pos_plato],
                                      arrPrecio[pos_plato], arrIngresoBruto[pos_plato],
                                      arrTieneDescuento[pos_plato], arrDescuento[pos_plato],
                                      arrTotal[pos_plato], plato_ofrecido, categoria_plato, output);
        }
    }
}



// Imprime los totales generales del reporte (el resumen del reporte solicitado)
void imprimir_totales(double total_ingreso_bruto, double total_ingreso_con_descuento, ofstream &output){
    elaborar_lineas('=', TAM_REPORTE, output);
    
    // Imprimir el total sin descuento y el total con descuento:
    output << "TOTAL:";
    output << setw( 3 * (TAM_REPORTE / (N_COLUMNAS - 3) )  + 4);
    output << total_ingreso_bruto;
    output << setw(TAM_REPORTE / N_COLUMNAS  + 5);
    output << total_ingreso_con_descuento;
    output << endl;
}




// Módulo que elabora el reporte solicitado de platos vendidos mediante el archivo "PlatosOfrecidos.txt"
void emitir_reporte(const char *nombre_archivo, int *arrCodigoPlatos, int *arrNumPlatosVendidos,
                    double *arrPrecio, double *arrIngresoBruto, double *arrDescuento,double *arrTotal,
                    bool *arrTieneDescuento, int cant_platos, ifstream &input){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    
    imprimir_titulo(false, output);
    imprimir_encabezado(false, output);
    
    double total_ingreso_bruto = 0.0, total_ingreso_con_descuento = 0.0;
    
    imprimir_todos_los_platos(total_ingreso_bruto, total_ingreso_con_descuento, arrCodigoPlatos,
                              arrNumPlatosVendidos, arrPrecio,arrIngresoBruto, arrTieneDescuento,
                              arrDescuento, arrTotal, cant_platos, input, output);
    
    imprimir_totales(total_ingreso_bruto, total_ingreso_con_descuento, output);
}





// Módulo que imprime solo un juego de datos de un plato para el reporte de prueba
void imprimir_juego_de_datos_reporte_prueba(int codigoPlatos,int numPlatosVendidos, double precio,
                double ingresoBruto,double descuento, double total, bool tieneDescuento,ofstream &output){
    output << codigoPlatos;
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS);
    output << numPlatosVendidos;
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS  + 3);
    output << precio;
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS  + 2);
    output << ingresoBruto;
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS);
    output << (tieneDescuento ? "SI" : "NO");
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS  + 4);
    output << descuento;
    output << setw(TAM_REPORTE_PRUEBA / N_COLUMNAS);
    output << total;
    output << endl;
}




// Módulo que elabora un reporte de prueba para verificar la correcta asignación de los datos guardados en los arreglos.
void reportePrueba(const char *nombre_archivo, int *arrCodigoPlatos, int *arrNumPlatosVendidos,
                   double *arrPrecio, double *arrIngresoBruto, double *arrDescuento, double *arrTotal,
                   bool *arrTieneDescuento, int cant_platos){
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(true, output);
    imprimir_encabezado(true, output);
    for(int indice = 0; indice < cant_platos; indice++){
        imprimir_juego_de_datos_reporte_prueba(arrCodigoPlatos[indice], arrNumPlatosVendidos[indice],
                        arrPrecio[indice], arrIngresoBruto[indice], arrDescuento[indice], arrTotal[indice],
                        arrTieneDescuento[indice], output);
    }
    elaborar_lineas('=',TAM_REPORTE_PRUEBA,output);
}




// Módulo que actualiza las cantidades de un plato (precio, ingreso bruto, descuento, total ingresado)
void actualizar_cantidades(int numPlatosVendidos, double &precio, double &ingresoBruto,
                           double &descuento, double &total, bool &tieneDescuento,
                           double precio_asignado, double descuento_asignado){
    precio = precio_asignado;
    ingresoBruto = numPlatosVendidos * precio;
    descuento = descuento_asignado;
    tieneDescuento = (descuento > 0.0 ? true : false);
    total = numPlatosVendidos * (precio * (1 - descuento / 100));
}





// Módulo que actualiza las cantidades (precio, ingreso bruto, descuento, total ingresado)
// de cada plato que está en los arreglos mediante el archivo "PlatosOfrecidos.txt"
void actualizar_cantidades_con_platos_ofrecidos(ifstream &input, int *arrCodigoPlatos,
                        int *arrNumPlatosVendidos, double *arrPrecio,double *arrIngresoBruto,
                        double *arrDescuento, double *arrTotal, bool *arrTieneDescuento, int cant_platos){
    int cod_plato_leido, pos_plato;
    double precio, descuento;
    char plato[MAX_CARACTERES_PLATO], categoria[MAX_CARACTERES_CATEGORIA];
    bool fin_de_archivo = false;
    while(true){
        leer_un_plato_ofrecido(cod_plato_leido,plato,precio,categoria,descuento,input,fin_de_archivo);
        if(fin_de_archivo) break; // Se sale del bucle si se llegó al fin del archivo "PlatosOfrecidos.txt"
        pos_plato = busqueda_binaria(cod_plato_leido, arrCodigoPlatos, cant_platos);
        if(pos_plato != NO_ENCONTRADO){
            actualizar_cantidades(arrNumPlatosVendidos[pos_plato], arrPrecio[pos_plato],
                                  arrIngresoBruto[pos_plato], arrDescuento[pos_plato], arrTotal[pos_plato],
                                  arrTieneDescuento[pos_plato], precio, descuento);
        }
    }
}




// Módulo que inserta un nuevo plato vendido en su posición correcta dentro de un arreglo ordenado
// en forma descendente por código de plato. También mueve las cantidades asociadas a cada código.
// Al finalizar, incrementa la cantidad total de platos registrados.
void insertar_dato_ordenando_descendentemente(int cod_plato, int cant_platos_vendidos,
                            int *arrCodigoPlatos, int *arrNumPlatosVendidos, int &cant_platos){
    // Empezar desde el final del arreglo de platos.
    int indice = cant_platos - 1;
    
    // Desplazar los elementos hacia la derecha, o hacia abajo según como uno desea ver la forma
    // de los arreglos, para hacer espacio al nuevo plato, siempre que el código actual sea menor
    // que el nuevo (para mantener orden descendente).
    for(indice; indice>=0 and arrCodigoPlatos[indice] < cod_plato; indice--){
        arrCodigoPlatos[indice + 1] = arrCodigoPlatos[indice];
        arrNumPlatosVendidos[indice + 1] = arrNumPlatosVendidos[indice];
    }
    
    // Insertar el nuevo plato en la posición correcta.
    arrCodigoPlatos[indice + 1] = cod_plato;
    arrNumPlatosVendidos[indice + 1] = cant_platos_vendidos;
    
    // Aumentar el número total de platos registrados.
    cant_platos++;
}





// Módulo que lee una línea de datos con varios platos vendidos y los inserta en los arreglos
// manteniéndolos ordenados descendentemente por código de plato.
void leer_lista_de_platos(int *arrCodigoPlatos, int *arrNumPlatosVendidos, int &cant_platos, ifstream &input){
    int cant_platos_vendidos, cod_plato, pos_plato;
    while(true){
        // Leer cantidad de platos vendidos y el código del plato
        cant_platos_vendidos = leer_dato_int(input);
        cod_plato = leer_dato_int(input);
        
        // Buscar si el código del plato ya está en el arreglo
        pos_plato = busqueda_binaria(cod_plato, arrCodigoPlatos, cant_platos);
        
        if(pos_plato == NO_ENCONTRADO){
            // Si es un nuevo plato, se inserta en los arreglos en orden descendente por código de plato
            insertar_dato_ordenando_descendentemente(cod_plato,cant_platos_vendidos, arrCodigoPlatos,
                                                     arrNumPlatosVendidos, cant_platos);
        } else {
            // Si el plato ya existe en los arreglos, se acumula la cantidad vendida
            arrNumPlatosVendidos[pos_plato] += cant_platos_vendidos;
        }
        if(input.get() == '\n') break;
    }
}




// Módulo que lee el archivo "RepartosARealizar.txt" y almacena los datos de platos en arreglos
void leer_repartos_a_realizar(const char *nombre_archivo, int *arrCodigoPlatos,
                              int *arrNumPlatosVendidos, int &cant_platos){
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int num_pedido, dni_cliente;
    cant_platos = 0;
    while(true){
        num_pedido = leer_dato_int(input);
        if(input.eof()) break; // Validar fin del archivo "RepartosARealizar.txt"
        dni_cliente = leer_dato_int(input);
        leer_lista_de_platos(arrCodigoPlatos, arrNumPlatosVendidos, cant_platos, input);
    }
}

