

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 3 de julio del 2025, 10:31 AM
 */


#include "Funciones.hpp"


// Módulo que apertura un archivo de lectura sin usar el constructor.
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que apertura un archivo de escritura sin usar el constructor.
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato de tipo "int".
int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato de tipo "double".
double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}


// Módulo que asigna una cadena de caracteres con memoria exacta.
char *asignar_cadena(const char *buffer) {
    char *cadena_a_asignar;
    cadena_a_asignar = new char[strlen(buffer) + 1];
    strcpy(cadena_a_asignar, buffer);
}



// Módulo que lee una cadena de caracteres y lo retorna con memoria exacta.
// Se puede leer la cadena de caracteres con "getline()" o con el operador de lectura.
char *leer_cadena(ifstream &input, char delimitador, bool leer_con_el_operador_de_lectura) {
    char buffer[100], *cadena;
    if(leer_con_el_operador_de_lectura) input >> buffer;
    else  input.getline(buffer, 100, delimitador);
    cadena = asignar_cadena(buffer);
    return cadena;
}



// Módulo que lee un tiempo de la siguiente forma: HH:MM,
// y lo retorna como un valor entero.
int leer_tiempo(ifstream &input) {
    int hora, minuto;
    hora = leer_int(input);
    input.get(); // Lectura de los dos puntos
    minuto = leer_int(input);
    return hora*100 + minuto;
}



// Módulo que imprime el tiempo de la forma: HH:MM AM o PM
void imprimir_tiempo(int tiempo, ofstream &output) {
    output << setfill('0') << setw(2) << tiempo / 100 << ':';
    output << setw(2) << tiempo % 100 << setfill(' ');
    if(tiempo % 100 >= 12  and  tiempo % 100  <= 23) output << " PM";
    else  output << " AM";
    output << endl;
}



// Módulo que pasa todas las letras de una cadena de caracteres a mayúsculas.
void todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice]>='a'  and  cadena[indice]<='z') {
//            cadena[indice] -= ('a' - 'A');
            cadena[indice] -= 32;  // 32 es igual al codigo ASCCI de la diferencia de ('a' - 'A')
        }
    }
}



// Módulo que elabora las líneas del reporte solicitado.
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output) {
    for(int i=0; i<cantCaracteres; i++) output.put(caracter);
    output << endl;
}







// Módulo que procesa el archivo "lexicon.csv" y almacena lo leído en el arreglo de estructuras
// de tipo "Plabra" (el nombre de la variable de ese arreglo es lexicon).
void procesar_lexicon(const char *nombre_archivo, struct Palabra *lexicon, int &cantPlabrasEnLexicon) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantPlabrasEnLexicon = 0;
    while(true) {
        char *palabra;
        palabra = leer_cadena(input, ',', false);
        if(input.eof()) break; // Validar fin del archivo "lexicon.csv".
        lexicon[cantPlabrasEnLexicon].texto = asignar_cadena(palabra);
        lexicon[cantPlabrasEnLexicon].polaridad = leer_int(input);
        input.get(); // Lectura el el cambio de línea.
        cantPlabrasEnLexicon++;
    }
}




// Módulo que procesa el archivo "platos.csv" y almacena los datos leídos en el
// arrelgo de estructuras de tipo "Plato" (el nombre de la variable de ese arreglo es platos).
void procesar_platos(const char *nombre_archivo, struct Plato *platos, int &cantPlatos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantPlatos = 0;
    while(true) {
        char *codigo_del_plato;
        codigo_del_plato = leer_cadena(input, ',', false);
        if(input.eof()) break; // Validar fin del archivo "platos.csv".
        platos[cantPlatos].codigo = asignar_cadena(codigo_del_plato);
        platos[cantPlatos].nombre = leer_cadena(input, ',', false);
        platos[cantPlatos].precio = leer_double(input);
        platos[cantPlatos].cantidad = 0; // Inicializar la cantidad de platos.
        input.get(); // Lectura del cambio de línea.
        cantPlatos++;
    }
}






// Módulo que procesa el archivo "atenciones.txt" y almacena los datos leídos en el
// arreglo de estructuras de tipo "Atencion". Para almacenar los platos atendidos,
// se verifica si existe el plato mediante el arreglo de platos.
void procesar_atenciones(const char *nombre_archivo, struct Atencion *atenciones,
                         int &cantAtenciones, struct Plato *platos, int cantPlatos) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    cantAtenciones = 0;
    int numero_de_atencion;
    while(true) {
        numero_de_atencion = leer_int(input);
        if(input.eof()) break; // Validar el fin del archivo "atenciones.txt".
        atenciones[cantAtenciones].codigo = numero_de_atencion;
        atenciones[cantAtenciones].hora = leer_tiempo(input);
        
        // Reservar memoria para los campos que son arreglos dinámicos e inicializarlos.
        atenciones[cantAtenciones].platos_atendidos = new struct Plato[MAX_PLATOS_ATENDIDOS_POR_ATENCION]{};
        atenciones[cantAtenciones].comentarios = new struct Comentario[MAX_COMENTARIOS_POR_ATENCION]{};
        
        leer_platos_atendidos(atenciones[cantAtenciones].platos_atendidos,
                              atenciones[cantAtenciones].cantidad_platos, platos, cantPlatos, input);
        
        cantAtenciones++;
    }
}





// Módulo que busca el código de un plato mediante el arreglo de estructuras de tipo "Plato".
int buscar_plato(char *codigo_del_plato_leido, struct Plato *platos, int cantPlatos) {
    for(int indice = 0; indice < cantPlatos; indice++) {
        if(strcmp(codigo_del_plato_leido, platos[indice].codigo) == 0) return indice;
    }
    return NO_ENCONTRADO;
}





// Módulo que lee el listado de platos atendidos de una atención del archivo "atenciones.txt".
void leer_platos_atendidos(struct Plato *platos_atendidos, int &cantidad_platos_atendidos,
                           struct Plato *platos, int cantPlatos, ifstream &input) {
    while(true) {
        char *codigo_del_plato_leido;
        int cantidad_atendida, indice_plato;
        
        codigo_del_plato_leido = leer_cadena(input, ' ', true);
        cantidad_atendida = leer_int(input);
        
        indice_plato = buscar_plato(codigo_del_plato_leido, platos, cantPlatos);
        if(indice_plato != NO_ENCONTRADO) {
            // El plato existe, entonces almacenar los datos en el arreglo de platos atendidos.
            platos_atendidos[cantidad_platos_atendidos].codigo = asignar_cadena(codigo_del_plato_leido);
            platos_atendidos[cantidad_platos_atendidos].nombre = asignar_cadena(platos[indice_plato].nombre);
            platos_atendidos[cantidad_platos_atendidos].precio = platos[indice_plato].precio;
            platos_atendidos[cantidad_platos_atendidos].cantidad = cantidad_atendida;
            cantidad_platos_atendidos++;
        }
        
        if(input.get() == '\n') break;
    }
}






// Módulo que procesa el archivo "comentarios.csv" y almacena los comentarios en el arreglo "atenciones".
void procesar_comentarios(const char *nombre_archivo, struct Atencion *atenciones,
                          int cantAtenciones, struct Palabra *lexicon, int cantPlabrasEnLexicon) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    int numero_de_atencion_leida, indice_atencion, indice_comentario;
    while(true) {
        char *comentario;
        numero_de_atencion_leida = leer_int(input);
        if(input.eof()) break; // Validar fin del "comentarios.csv".
        input.get(); // Lectura de la coma.
        comentario = leer_cadena(input, '\n', false);
        indice_atencion = buscar_atencion(numero_de_atencion_leida, atenciones, cantAtenciones);
        if(indice_atencion != NO_ENCONTRADO) {
            indice_comentario = atenciones[indice_atencion].cantidad_comentarios;
            procesamiento_de_un_comentario(atenciones[indice_atencion].comentarios[indice_comentario],
                                           comentario, lexicon, cantPlabrasEnLexicon);
            atenciones[indice_atencion].cantidad_comentarios++;
        }
    }
}



// Módulo que busca el número de una atención en un arreglo de estructuras de tipo "Atencion".
int buscar_atencion(int numero_de_atencion_leida, struct Atencion *atenciones, int cantAtenciones) {
    for(int indice = 0; indice < cantAtenciones; indice++) {
        if(atenciones[indice].codigo == numero_de_atencion_leida) return indice;
    }
    return NO_ENCONTRADO;
}





// Módulo que procesa un comentario (se pasa a minúsculas las palabras del comentario como también se calcula la polaridad del comentario).
void procesamiento_de_un_comentario(struct Comentario &comentario, const char *comentario_leido,
                                    struct Palabra *lexicon, int cantPlabrasEnLexicon) {
    comentario.texto = asignar_cadena(comentario_leido);
    pre_procesar_el_comentario(comentario.texto, comentario.pre_procesado);
    procesar_el_comentario(comentario.pre_procesado, comentario.palabras,
                           comentario.cantidad_palabras, lexicon, cantPlabrasEnLexicon);
    calcular_polaridad_total(comentario.palabras, comentario.cantidad_palabras, comentario.polaridad_total);
}






// Módulo que procesa un comentario original y genera una versión preprocesada sin signos de puntuación
// ni mayúsculas (las letras en mayúsculas los convierte a minúsculas).
void pre_procesar_el_comentario(const char *comentario, char *&comentario_pre_procesado) {
    char caracter, linea_pre_procesada[100];
    int cant_caracteres_de_comentario_pre_procesado = 0;

    // Recorrer el comentario caracter por caracter hasta llegar al final de la cadena "comentario" ('\0').
    for(int indice = 0; comentario[indice]; indice++) {

        caracter = comentario[indice]; // Se guarda el caracter actual en la variable "caracter".

        // Solo se conservarán letras (isalpha) o espacios.
        if(isalpha(caracter) or caracter == ' ') {

            // Se convierte el caracter a minúscula (lo que hace "tolower") y se guarda en el arreglo.
            linea_pre_procesada[cant_caracteres_de_comentario_pre_procesado] = tolower(caracter);

            // Se incrementa el contador para el siguiente índice del arreglo.
            cant_caracteres_de_comentario_pre_procesado++;
        }
    }

    // Se coloca el caracter nulo ('\0') al final de la cadena "linea_pre_procesada".
    linea_pre_procesada[cant_caracteres_de_comentario_pre_procesado] = '\0';

    // Se le asigna un nuevo espacio de memoria dinámica y se copia la cadena "linea_pre_procesada" a la cadena "comentario_pre_procesado".
    comentario_pre_procesado = asignar_cadena(linea_pre_procesada);
}






// Módulo que analiza el comentario "comentario_pre_procesado", lo separa en palabras y asigna a cada palabra
// su polaridad según el "lexicon" (en caso no haya una palabra del comentario en lexicon, pues su polaridad es cero).
void procesar_el_comentario(const char *comentario_pre_procesado, struct Palabra *palabras,
                            int &cantidad_palabras, struct Palabra *lexicon, int cantPlabrasEnLexicon) {

    cantidad_palabras = contar_palabras(comentario_pre_procesado); // Calcular cuántas palabras hay en "comentario_pre_procesado".
    
    // Se recorre cada palabra desde la primera hasta la última palabra de "comentario_pre_procesado" (índice empieza en 1).
    // Solo se entra en el bucle si hay al menos una palabra en "comentario_pre_procesado".
    for(int n_palabra = 1; n_palabra <= cantidad_palabras; n_palabra++) {
        char *palabra_extraida;
        
        // Extraer la n-ésima palabra del comentario y guardar en "palabra_extraida".
        extraer_palabra(comentario_pre_procesado, n_palabra, palabra_extraida);
        
        palabras[n_palabra].texto = asignar_cadena(palabra_extraida); // Asignar la palabra extraída al campo "texto" del arreglo palabras.
        int indice_lexicon = buscar_lexicon(palabra_extraida, lexicon, cantPlabrasEnLexicon);
        
        // Si la palabra fue encontrada en "lexicon", entonces se le asigna su polaridad.
        if(indice_lexicon != NO_ENCONTRADO) palabras[n_palabra].polaridad = lexicon[indice_lexicon].polaridad;
        else  palabras[n_palabra].polaridad = 0; // La palabra no fue encontrada en "lexicon", entonces se le asigna una polaridad neutral (0).
    }
}





// Módulo que cuenta la cantidad de palabras en un comentario (separadas por un espacio).
int contar_palabras(const char *comentario) {
    if(comentario[0] == '\0') return 0; // Si el comentario está vacío, retorna 0.
    int cant_palabras = 1; // Se asume que al menos hay una palabra en el comentario.

    // Se cuenta un espacio como un separador de palabras.
    for(int indice = 0; comentario[indice]; indice++) {
        if(comentario[indice] == ' ') cant_palabras++;
    }

    // Devolver el total de palabras que hay en un comentario.
    return cant_palabras;
}





// Módulo que extrae la n-ésima palabra del comentario.
void extraer_palabra(const char *comentario, int n_palabra, char *&palabra_extraida) {
    int indice_inicial, indice_final;

    // Buscar dónde comienza la palabra en el comentario.
    indice_inicial = buscar_inicio_de_la_palabra(n_palabra, comentario);

    // Si no se encuentra dónde comienza la palabra en el comentario, entonces salir del módulo.
    if(indice_inicial == NO_ENCONTRADO) return;

    // Buscar dónde termina la palabra.
    indice_final = buscar_indice_final(n_palabra, indice_inicial, comentario);

    // Copiar la palabra desde el comentario hacia la variable "palabra_extraida".
    copiar_palabra(comentario, indice_inicial, indice_final, palabra_extraida);
}






// Módulo que busca el índice donde inicia la n-ésima palabra en el comentario.
int buscar_inicio_de_la_palabra(int n_palabra, const char *comentario) {
    if(comentario[0] == '\0') return NO_ENCONTRADO; // Si el comentario está vacío, se retorna un error.
    int indice_inicial;
    int contador_palabras = 1; // Se empieza desde la primera palabra del comentario.

    // Recorrer el comentario hasta encontrar la palabra deseada.
    for(indice_inicial = 0; comentario[indice_inicial]; indice_inicial++) {
        if(contador_palabras == n_palabra) break;
        if(comentario[indice_inicial] == ' ') contador_palabras++;
    }

    // Devolver el índice de inicio de esa palabra existente en "comentario".
    return indice_inicial;
}







// Módulo que encuentra el índice final de la palabra partiendo desde un índice inicial dentro de la cadena "comentario".
int buscar_indice_final(int n_palabra, int indice_inicial, const char *comentario) {
    int indice_final = indice_inicial;

    // Avanzar hasta encontrar un espacio o el fin de la cadena de caracteres "comentario".
    while(true) {
        if (comentario[indice_final] == '\0'   or   comentario[indice_final] == ' ') break;
        indice_final++;
    }

    // Devolver el índice del último caracter de la palabra en la cadena de carcteres "comentario".
    return indice_final - 1;
}







// Módulo que copia los caracteres de una palabra desde el comentario original.
char *copiar_palabra(const char *comentario, int indice_inicial, int indice_final, char *&palabra_extraida) {
    char palabra_a_copiar[20];
    int indice_comentario = indice_inicial, indice_palabra = 0;

    // Copiar caracter por caracter hasta llegar al final de la palabra.
    while(indice_comentario <= indice_final) {
        palabra_a_copiar[indice_palabra] = comentario[indice_comentario];
        indice_comentario++;
        indice_palabra++;
    }

    // Agregar el caracter nulo al final de la cadena de caracteres "palabra_a_copiar".
    palabra_a_copiar[indice_palabra] = '\0';

    // Se asigna a la cadena "palabra_extraida" la palabra copiada "palabra_a_copiar" y se retorna.
    palabra_extraida = asignar_cadena(palabra_a_copiar);
    return palabra_extraida;
}






// Módulo que busca si "palabra_extraida" se encuentra en lexicon.
int buscar_lexicon(const char *palabra_extraida, struct Palabra *lexicon, int cantPlabrasEnLexicon) {

    // Recorrer el arreglo "lexicon" y se compara palabra por palabra.
    for(int indice = 0; indice < cantPlabrasEnLexicon; indice++) {
        if(strcmp(palabra_extraida, lexicon[indice].texto) == 0) return indice;
    }

    return NO_ENCONTRADO;
}





// Módulo que calcula la polaridad de un comentario.
void calcular_polaridad_total(struct Palabra *palabras, int cantidad_palabras, int &polaridad_total) {
    for(int indice = 0; indice < cantidad_palabras; indice++) {
        polaridad_total += palabras[indice].polaridad;
    }
}





// Módulo que emite el reporte solicitado.
void emitir_reporte(const char *nombre_archivo, struct Atencion *atenciones, int cantAtenciones) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    imprimir_titulo(output);
    for(int indice = 0; indice < cantAtenciones; indice++) {
        imprimir_numero_y_hora_de_la_atencion(atenciones[indice].codigo, atenciones[indice].hora, output);
        imprimir_platos(atenciones[indice].platos_atendidos, atenciones[indice].cantidad_platos, output);
        imprimir_polaridad_total_de_los_comentarios(atenciones[indice].comentarios,
                                    atenciones[indice].cantidad_comentarios, output);
    }
}



// Módulo que imprime el título del reporte solicitado.
void imprimir_titulo(ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "EMPRESA DE REPARTO A DOMICILIO TP S. A." << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "RELACION DE ATENCIONES" << endl;
}



// Módulo que imprime el número y la hora de una atención en el reporte solicitado.
void imprimir_numero_y_hora_de_la_atencion(int numero_de_atencion, int hora_atencion, ofstream &output) {
    elaborar_lineas('=', TAM_REPORTE, output);
    output << "NO. ATENCION " << numero_de_atencion;
    output << setw(7 * (TAM_REPORTE / (N_COLUMNAS + 5)) + 2) << "Atendido a las: ";
    imprimir_tiempo(hora_atencion, output);
    elaborar_lineas('-', TAM_REPORTE, output);
}



// Módulo que imprime los platos atendidos en el reporte solicitado.
void imprimir_platos(struct Plato *platos_atendidos, int cantidad_platos, ofstream &output) {
    for(int indice = 0; indice < cantidad_platos; indice++) {
        output << platos_atendidos[indice].codigo << ")  ";
        output << left << setw(TAM_REPORTE / (N_COLUMNAS - 2) + 2) << platos_atendidos[indice].nombre << right;
        output << setw((TAM_REPORTE / N_COLUMNAS) / 4) << platos_atendidos[indice].precio;
        output << setw((TAM_REPORTE / N_COLUMNAS) / 2) << platos_atendidos[indice].cantidad;
        output << setw(TAM_REPORTE / (N_COLUMNAS + 2) + 1) << platos_atendidos[indice].precio * platos_atendidos[indice].cantidad;
        output << endl;
    }
}




// Módulo que calcula la polaridad total de los comentarios e imprime esa polaridad en el reporte solicitado.
void imprimir_polaridad_total_de_los_comentarios(struct Comentario *comentarios, int cantidad_comentarios, ofstream &output) {
    int polaridad_comentario = 0;
    for(int indice = 0; indice < cantidad_comentarios; indice++) polaridad_comentario += comentarios[indice].polaridad_total;
    output << "Polaridad total de los comentarios: " << polaridad_comentario << endl;
}


