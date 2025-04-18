

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 16 de abril de 2025, 08:22 PM
 */

#include "Funciones.h"


// Módulo que realiza las preguntas y elabora el reporte
void preguntas_y_elaborarcion_del_reporte(const char *arch_lectura,const char *arch_escritura){
    int distrito_1,distrito_2,tiempo_a_partir_puede_llegar_al_cine,duracion_maxima_cliente;
    char lleva_alimentos;
    preguntas_al_usuario(distrito_1,distrito_2,tiempo_a_partir_puede_llegar_al_cine,
            duracion_maxima_cliente,lleva_alimentos);
    procesar_cartelera(distrito_1,distrito_2,tiempo_a_partir_puede_llegar_al_cine,
            duracion_maxima_cliente,lleva_alimentos,arch_lectura,arch_escritura);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que realiza las preguntas al usuario
void preguntas_al_usuario(int &distrito_1,int &distrito_2,int &tiempo_a_partir_puede_llegar_al_cine,
                          int &duracion_maxima_cliente,char &lleva_alimentos){
    cout << "Ingrese el codigo de dos distritos diferentes (Ejemplo: 4558 4789): ";
    cin >> distrito_1 >> distrito_2;
    cout << "Ingrese la hora a partir puede llegar al cine (Ejemplo: 14:25:35): ";
    tiempo_a_partir_puede_llegar_al_cine = leer_tiempo_cliente();
    cout << "Ingrese la duracion maxima que puede durar la pelicula (Ejemplo: 2:45:35): ";
    duracion_maxima_cliente = leer_tiempo_cliente();
    cout << "Ingrese si desea llevar alimentos (Si es afirmativo, escriba 'S'; caso contrario, escriba 'N'): ";
    cin >> lleva_alimentos;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el tiempo que el cliente ingresa manualmente y retorna este tiempo en segundos
int leer_tiempo_cliente(){
    int hora,minuto,segundo;
    char dos_puntos;
    cin >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que realiza el método de apertura del archivo de lectura sin utilizar el constructor
void apertura_archivo_lectura(ifstream &input,const char *arch_lectura){
    input.open(arch_lectura,ios::in);
    if(not input.is_open()){
        cout << "ERROR. El archivo " << arch_lectura << " no se ha encontrado." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que realiza el método de escritura del archivo de lectura sin utilizar el constructor
void apertura_archivo_escritura(ofstream &output,const char *arch_escritura){
    output.open(arch_escritura,ios::out);
    if(not output.is_open()){
        cout << "ERROR. El archivo " << arch_escritura << " no se ha encontrado." << endl;
        exit(1);
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que procesa el archivo de "CartelerasDeCines.txt" a partir de los datos ingresados por el usuario;
// así mismo, algunas impresiones del reporte solicitado.
void procesar_cartelera(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,const char *arch_lectura,const char *arch_escritura){
    ifstream input;
    ofstream output;
    int cant_peliculas_que_puede_ver = 0;
    apertura_archivo_lectura(input,arch_lectura);
    apertura_archivo_escritura(output,arch_escritura);
    imprimir_datos_ingresados(distrito_1,distrito_2,tiempo_a_partir_puede_llegar_al_cine,
            duracion_maxima_cliente,lleva_alimentos,output);
    imprimir_titulo(output);
    output << fixed << setprecision(2);
    leer_cartelera_de_cines(distrito_1,distrito_2,tiempo_a_partir_puede_llegar_al_cine,
            duracion_maxima_cliente,lleva_alimentos,input,output,cant_peliculas_que_puede_ver);
    impresion_de_cant_peliculas_puede_ver(cant_peliculas_que_puede_ver,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime los datos ingresados por el usuario usuario en el reporte solicitado
void imprimir_datos_ingresados(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ofstream &output){
    output << "Datos ingresados:" << endl;
    
    output << "Distritos: " << distrito_1 << " y " << distrito_2 << endl;
    
    output << "Disponibilidad a partir de las ";
    imprimir_tiempo(tiempo_a_partir_puede_llegar_al_cine,output);
    output << endl;
    
    output << "Duracion maxima: ";
    imprimir_tiempo(duracion_maxima_cliente,output);
    output << " horas" << endl;
    
    output << "El cliente ";
    if(lleva_alimentos == 'S') output << "si";
    else output << "no";
    output << " llevara alimentos" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el título del reporte solicitado
void imprimir_titulo(ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    output << setw((TAM_REPORTE + N_CARAC_TITULO)/2);
    output << "LISTA DE PELICULAS A LAS QUE PUEDE ASISTIR" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el archivo "CarteleraDeCines.txt" y realiza impresiones como actualización de la cantidad
// de películas que puede ver el usuario
void leer_cartelera_de_cines(int distrito_1,int distrito_2,int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ifstream &input,ofstream &output,
        int &cant_peliculas_que_puede_ver){
    int codigo_distrito;
    while(true){
        input >> codigo_distrito; // Lectura del código del distrito del archivo "CarteleraDeCines.txt"
        if(input.eof()) break; // Se sale del bucle si se llega al fin del archivo "CarteleraDeCines.txt"
        leer_nombre_e_imprimir_distrito(codigo_distrito,input,output);
        imprimir_encabezado(input,output);
        if(codigo_distrito == distrito_1  or   codigo_distrito == distrito_2){
            // Si el código del distrito leído pertenece a alguno de los distritos ingresados por el usuario,
            // se continua leyendo la línea.
            leer_juego_de_datos_de_peliculas(tiempo_a_partir_puede_llegar_al_cine,duracion_maxima_cliente,
                    lleva_alimentos,input,output,cant_peliculas_que_puede_ver);
        } else {
            // El código del distrito leído no pertenece a alguno de los distritos ingresados por el usuario,
            // entonces se ignora toda la línea que esta leyendo.
            imprimir_que_no_hay_peliculas(output);
            while(input.get() != '\n');
        }
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el nombre del distrito e imprime el nombre como su código
void leer_nombre_e_imprimir_distrito(int codigo_distrito,ifstream &input,ofstream &output){
    int cant_caracteres = 0;
    output << setw(11) << "DISTRITO:" << setw(6) << codigo_distrito << " - ";
    leer_and_imprimir_nombre(input,output,false);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el encabezado de las películas
void imprimir_encabezado(ifstream &input,ofstream &output){
    output << setw(TAM_REPORTE / N_COLUMNAS - 10) << "SALA";
    output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "PELICULA";
    output << setw(TAM_REPORTE / N_COLUMNAS + 27) << "COSTO";
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "INICIA";
    output << setw(TAM_REPORTE / N_COLUMNAS - 4) << "TERMINA";
    output << setw(TAM_REPORTE / N_COLUMNAS - 3) << "DURACION" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que procesa las lecturas variables (juegos de datos) de una línea del archivo "CartelerasDeCines.txt"
void leer_juego_de_datos_de_peliculas(int tiempo_a_partir_puede_llegar_al_cine,
        int duracion_maxima_cliente,char lleva_alimentos,ifstream &input,ofstream &output,
        int &cant_peliculas_que_puede_ver){
    int cant_peliculas = 0,cod_sala_cine,tiempo_inicio,tiempo_final;
    double costo_entrada;
    char se_puede_llevar_alimentos_al_cine;
    while(true){
        leer_juego_de_datos(cod_sala_cine,costo_entrada,se_puede_llevar_alimentos_al_cine,
                tiempo_inicio,tiempo_final,input);
        if(tiempo_a_partir_puede_llegar_al_cine <= tiempo_inicio and
                duracion_maxima_cliente >= tiempo_final - tiempo_inicio and
                (lleva_alimentos == se_puede_llevar_alimentos_al_cine or
                (se_puede_llevar_alimentos_al_cine == 'S'  and  lleva_alimentos == 'N'))){
            imprimir_juego_de_datos(cod_sala_cine,costo_entrada,se_puede_llevar_alimentos_al_cine,
                    tiempo_inicio,tiempo_final,input,output,cant_peliculas);
        } else {
            ignorar_cadena_de_caracteres(input);
        }
        input.unget(); // Envía al buffer de entrada el último caracter extraido del método "input.get()"
        if(input.get() == '\n') break; // Se sale del bucle si se lee el cambio de línea
    }
    cant_peliculas_que_puede_ver += cant_peliculas;
    if(cant_peliculas == 0) imprimir_que_no_hay_peliculas(output);
    else imprimir_cant_peliculas_parciales(cant_peliculas,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee una la lectura variable (un juego de datos) excepto el nombre de la película
void leer_juego_de_datos(int &cod_sala_cine,double &costo_entrada,
        char &se_puede_llevar_alimentos_al_cine,int &tiempo_inicio,
        int &tiempo_final,ifstream &input){
    input >> cod_sala_cine >> costo_entrada >> se_puede_llevar_alimentos_al_cine;
    tiempo_inicio = leer_tiempo_archivo_cartelera(input);
    tiempo_final = leer_tiempo_archivo_cartelera(input);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el juego de datos leído
void imprimir_juego_de_datos(int cod_sala_cine,double costo_entrada,
        char se_puede_llevar_alimentos_al_cine,int tiempo_inicio,int tiempo_final,ifstream &input,
        ofstream &output,int &cant_peliculas){
    output << setw(2) << ' ' << left << setw(TAM_REPORTE / N_COLUMNAS - 8) << cod_sala_cine << right;
    leer_and_imprimir_nombre(input,output,true);
    output << left << setw(TAM_REPORTE / N_COLUMNAS - 7) << costo_entrada << right;
    imprimir_tiempo(tiempo_inicio,output);
    output << setw(4) << ' ';
    imprimir_tiempo(tiempo_final,output);
    output << setw(4) << ' ';
    imprimir_tiempo(tiempo_final - tiempo_inicio,output);
    output << endl;
    cant_peliculas++;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee e imprime un nombre
void leer_and_imprimir_nombre(ifstream &input,ofstream &output,bool es_pelicula){
    int cant_caracteres = 0;
    input >> ws; // Leer espacios en blanco
    while(true){
        char c = input.get();  // Lectura de un caracter
        if(c == ' '   or   c == '\n') break;
        if(c == '_') c = ' '; // El caracter se cambia a un espacio en blanco
        output.put(c);  // Impresión de un caracter
        cant_caracteres++;
    }
    
    if(es_pelicula){
        // Se ha impreso el nombre de una película, entonces se imprimiran espacios en blanco
        for(int i=0; i < TAM_NOMBRE_PELICULA - cant_caracteres; i++) output.put(' ');
    } else {
        // Se ha impreso el nombre de un distrito, entonces se imprimirá el cabio de línea
        output << endl << endl;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que lee el tiempo del archivo "CarteleraDeCines.txt" y retorna el tiempo en segundos
int leer_tiempo_archivo_cartelera(ifstream &input){
    int hora,minuto,segundo;
    char dos_puntos;
    input >> hora >> dos_puntos >> minuto >> dos_puntos >> segundo;
    return hora*3600 + minuto*60 + segundo;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime el tiempo en el reporte solicitado
void imprimir_tiempo(int tiempo,ofstream &output){
    output << setfill('0') << setw(2) << tiempo/3600 << ':';
    output << setw(2) << tiempo/60%60 << ':';
    output << setw(2) << tiempo%60 << setfill(' ');
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime la cantidad de películas que puede ver el usuario por cada cine
void imprimir_cant_peliculas_parciales(int cant_peliculas,ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE / N_COLUMNAS + 9)<< "CANTIDAD DE PELICULAS: ";
    output << cant_peliculas;
    output << endl << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime que no hay películas para las condiciones que desea el usuario
void imprimir_que_no_hay_peliculas(ofstream &output){
    elaborar_lineas('-',TAM_REPORTE,output);
    output << setw(TAM_REPORTE/2 - 9) << "NO HAY PELICULAS PARA ESAS CONDICIONES.";
    output << endl << endl;
    elaborar_lineas('-',TAM_REPORTE,output);
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que ignora la cadena de caracteres
void ignorar_cadena_de_caracteres(ifstream &input){
    input >> ws;
    while(true){
        char c = input.get();
        if(c == ' '  or   c == '\n') break;
    }
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que imprime la cantidad de películas que el usuario puede ver
void impresion_de_cant_peliculas_puede_ver(int cant_peliculas_que_puede_ver,ofstream &output){
    elaborar_lineas('=',TAM_REPORTE,output);
    if(cant_peliculas_que_puede_ver == 0){
        output << "No hay ninguna opcion de peliculas ";
    } else if (cant_peliculas_que_puede_ver == 1){
        output << "Tiene " << cant_peliculas_que_puede_ver;
        output << " opcion de pelicula ";
    } else {
        output << "Tiene " << cant_peliculas_que_puede_ver;
        output << " opciones de peliculas ";
    }
    output << "con los datos que ha ingresado" << endl;
}
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/





// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter,int cantCaracteres,ofstream &output){
    for(int i=0;i<cantCaracteres;i++) output.put(caracter);
    output<<endl;
}