

/* 
 * Archivo:   Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Creado el 21 de junio del 2025, 12:23 PM
 */


#include "Funciones.h"



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




// Módulo que asigna una cadena con memoria exacta.
char *asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char [strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}






// Módulo que construye dinámicamente la ruta completa a un archivo  .csv   combinando una carpeta, un
// tipo de archivo y una zona. Por ejemplo: obtener_ruta("Datos", "Drones", "Lima") -> "Datos/Drones_Lima.csv"
char* obtener_ruta(const char *nombre_carpeta, const char *nombre_tipo_archivo, const char *nombre_zona) {
    char *ruta_de_archivo;
    char buffer[40];  // Buffer temporal para construir la ruta.
    
    strcpy(buffer, nombre_carpeta);         // Copiar el nombre de la carpeta (ejemplo: "Datos")
    strcat(buffer, "/");                    // Añadir el separador de carpeta -> "Datos/"
    strcat(buffer, nombre_tipo_archivo);    // Añadir el tipo de archivo -> "Datos/Drones"
    strcat(buffer, "_");                    // Añadir guion bajo -> "Datos/Drones_"
    strcat(buffer, nombre_zona);            // Añadir el nombre de la zona -> "Datos/Drones_Lima"
    strcat(buffer, ".csv");                 // Añadir la extensión -> "Datos/Drones_Lima.csv"
    
    ruta_de_archivo = asignar_cadena(buffer);  // Copiar el contenido del buffer dinámicamente.
    
    return ruta_de_archivo;  // Retornar la ruta construida.
}






// Módulo que abre un archivo de lectura utilizando una ruta compuesta por el nombre de una carpeta,
// tipo de archivo y nombre de una zona. Se construye la ruta y llama al módulo "aperturar_archivo_lectura()".
void aperturar_archivo_mediante_una_ruta(ifstream &input, const char *nombre_carpeta,
                                         const char *nombre_tipo_archivo, const char *zona) {
    char *ruta;
    
    // Obtener la ruta completa del archivo (por ejemplo: "Datos/Drones_Lima.csv")
    ruta = obtener_ruta(nombre_carpeta, nombre_tipo_archivo, zona);
    
    // Abrir el archivo usando la ruta generada.
    aperturar_archivo_lectura(ruta, input);
}





// Módulo que lee un dato de tipo "int"
int leer_dato_int(ifstream &input) {
    int dato;
    input >> dato;
    input.get(); // Lee un caracter que puede ser   ' / ' , '\n' , ' , '
    return dato;
}





// Módulo que lee un dato de tipo "double"
double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}





// Módulo que lee una cadena de caracteres y lo almacena con memoria exacta.
char *leer_cadena(ifstream &input, char delimitador) {
    char buffer[30], *cadena;
    input.getline(buffer, 100, delimitador);
    if(input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}





// Módulo que lee una fecha de la forma DD/MM/AAAA y
// lo retorna como un valor entero.
int leer_fecha(ifstream &input) {
    int dia, mes, anio;
    
    dia = leer_dato_int(input);
    mes = leer_dato_int(input);
    
    anio = leer_dato_int(input);
    return anio*10000 + mes*100 + dia;
}




// Módulo que retorna una estructura de tipo "fecha".
struct Fecha retornar_estructura_fecha(int fecha_dada_como_entero) {
    struct Fecha fecha;
    fecha.fecha = fecha_dada_como_entero;
    fecha.dd = fecha_dada_como_entero % 100;
    fecha.mm = fecha_dada_como_entero / 100 % 100;
    fecha.aa = fecha_dada_como_entero / 10000;
    
    if(fecha.mm > 12) {
        fecha.mm = 1;
        fecha.aa += 1;
    }
    
    return fecha;
}







// Módulo que imprime una fecha mediante una estrcutura de tipo "Fecha".
void imprimir_fecha(const struct Fecha fecha_proporcionada, ofstream &output) {
    output << setfill('0') << setw(2) << fecha_proporcionada.dd << '/';
    output << setw(2) << fecha_proporcionada.mm << '/' << setfill(' ');
    output << fecha_proporcionada.aa;
}







// Módulo que elabora las líneas del reporte
void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output) {
    for(int i=0; i<cantCaracteres; i++)  output.put(caracter);
    output << endl;
}






// Módulo que imprime el título del reporte
void imprimir_titulo(ofstream &output) {
    output << setw((TAM_REPORTE + TAM_TITULO_1) / 2);
    output << "MINISTERIO DE TRANSPORTES" << endl;
    output << setw((TAM_REPORTE + TAM_TITULO_2) / 2);
    output << "LISTADO DE DRONES POR ZONA" << endl;
}






// Módulo que imprime el título de una zona.
void imprimir_titulo_zona(char *zona, ofstream &output) {
    char titulo_zona[40];
    
    strcpy(titulo_zona, "INFORMACION DE LA ZONA DE ");
    strcat(titulo_zona, zona);
    
    elaborar_lineas('=', TAM_REPORTE, output);
    output << setw((TAM_REPORTE + strlen(titulo_zona)) / 2) << titulo_zona << endl;
    elaborar_lineas('=', TAM_REPORTE, output);
}





// Módulo que imprime el encabezado de drones en el reporte.
void imprimir_encabezado_drones(int opcion_drone, ofstream &output) {
    output << setw(8) << "No.";
    output << setw(6) << "ID";
    output << setw(16) << "UBICACION";
    output << setw(14) << "CAPACIDAD";
    output << setw(21) << "No. INFRACCIONES";
    
    if(opcion_drone == 1) output << setw(29) << "VELOCIDAD MAX. PERMITIDA";
    else if(opcion_drone == 2)  output << setw(14) << "LUZ ROJA";
    else  output << setw(19) << "ZONA DE CARGA";
    
    output << endl;
}







// Módulo que imprime el encabezado de infracciones en el reporte.
void imprimir_encabezado_infracciones(ofstream &output) {
    output << setw(37) << "INFORMACION DE LAS INFRACCIONES:" << endl;
    output << setw(14) << "No.";
    output << setw(18) << "FECHA INFRACCION";
    output << setw(10) << "PLACA";
    output << setw(14) << "GRAVEDAD";
    output << setw(19) << "MULTA A PAGAR";
    output << setw(18) << "FECHA A PAGAR";
    output << endl;
}







// Módulo que imprime los datos correspondientes a un drone.
void imprimir_dato_de_un_drone(int n_drone, const struct Drone un_drone, ofstream &output) {
    output << setw(7) << n_drone << ')';
    output << setw(8) << un_drone.id;
    output << setw(14) << un_drone.ubicacion;
    output << setw(10) << un_drone.capacidad;
    output << setw(18) << un_drone.cantidad_infracciones;
}






// Módulo que imprime el todas las infracciones cometidas.
void imprimir_infracciones(const struct Infraccion *infracciones, int cantidad_infracciones, ofstream &output) {
    if(cantidad_infracciones > 0) {
        imprimir_encabezado_infracciones(output);
        for(int indice = 0; indice < cantidad_infracciones; indice++) {
            output << setw(13) << indice + 1 << ')';
            output << setw(4) << ' ';
            imprimir_fecha(infracciones[indice].fecha_evento, output);
            output << setw(15) << infracciones[indice].placa;
            output << setw(6) << ' ' << left;
            output << setw(16) << infracciones[indice].tipo_infraccion;
            output << right << infracciones[indice].monto;
            output << setw(10) << ' ';
            imprimir_fecha(infracciones[indice].fecha_pago_limite, output);
            output << endl;
        }
    } else {
        output << setw(64) << "NO EXISTE ALGUNA INFRACCION COMETIDA" << endl;
    }
    output << setw(5) << ' ';
    elaborar_lineas('/', TAM_REPORTE - 5, output);
    output << endl;
}





// Módulo que imprime los datos de los drones de velocidad.
void imprimir_drones_velocidad(const struct DroneDeVelocidad *drones_velocidad, int n_drones, ofstream &output) {
    output << "DRONES DE VELOCIDAD:" << endl;
    for(int indice = 0; indice < n_drones; indice++) {
        imprimir_encabezado_drones(1, output);
        imprimir_dato_de_un_drone(indice + 1, drones_velocidad[indice].datos_drone, output);
        output << setw(24) << drones_velocidad[indice].velocidad_maxima_permitida << endl;
        output << setw(5) << ' ';
        elaborar_lineas('-', TAM_REPORTE - 5, output);
        imprimir_infracciones(drones_velocidad[indice].datos_drone.infracciones,
                              drones_velocidad[indice].datos_drone.cantidad_infracciones, output);
    }
}






// Módulo que imprime los datos de los drones de semáforo.
void imprimir_drones_semaforo(const struct DroneSemaforo *drones_semaforo, int n_drones, ofstream &output) {
    output << endl << endl;
    output << "DRONES DE SEMAFORO:" << endl;
    for(int indice = 0; indice < n_drones; indice++) {
        imprimir_encabezado_drones(2, output);
        imprimir_dato_de_un_drone(indice + 1, drones_semaforo[indice].informacion_drone, output);
        output << setw(18);
        output << (drones_semaforo[indice].luz_roja ? "SI" : "NO") << endl;
        output << setw(5) << ' ';
        elaborar_lineas('-', TAM_REPORTE - 5, output);
        imprimir_infracciones(drones_semaforo[indice].informacion_drone.infracciones,
                              drones_semaforo[indice].informacion_drone.cantidad_infracciones, output);
    }
}






// Módulo que imprime los datos de los drones de estacionamiento.
void imprimir_drones_estacionamiento(const struct DroneEstacionamiento *drones_estacionamiento, int n_drones, ofstream &output) {
    output << endl << endl;
    output << "DRONES DE ESTACIONAMIENTO:" << endl;
    for(int indice = 0; indice < n_drones; indice++) {
        imprimir_encabezado_drones(3, output);
        imprimir_dato_de_un_drone(indice + 1, drones_estacionamiento[indice].info_drone, output);
        output << setw(20);
        output << (drones_estacionamiento[indice].zona_carga ? "SI" : "NO") << endl;
        output << setw(5) << ' ';
        elaborar_lineas('-', TAM_REPORTE - 5, output);
        imprimir_infracciones(drones_estacionamiento[indice].info_drone.infracciones,
                              drones_estacionamiento[indice].info_drone.cantidad_infracciones, output);
    }
}






// Módulo que imprime la cantidad de multas registradas como el total de multas acumuladas de una zona.
void imprimir_totales_de_la_zona(int cantidad_multas_registradas, double total_multas_acumuladas, ofstream &output) {
    elaborar_lineas('*', TAM_REPORTE, output);
    output << "CANTIDAD DE MULTAS REGISTRADAS: " << cantidad_multas_registradas;
    output << setw(46) << "TOTAL DE MULTAS ACUMULADAS: " << total_multas_acumuladas;
    output << endl << endl;
}






// Módulo que emite el reporte.
void emitir_reporte(const char *nombre_archivo, const struct Zona *arrZonas, int cantidad_zonas) {
    ofstream output;
    aperturar_archivo_escritura(nombre_archivo, output);
    output << fixed << setprecision(2);
    imprimir_titulo(output);
    for(int indice = 0; indice < cantidad_zonas; indice++) {
        imprimir_titulo_zona(arrZonas[indice].zona, output);
        imprimir_drones_velocidad(arrZonas[indice].drones_velocidad, arrZonas[indice].n_drones_velocidad, output);
        imprimir_drones_semaforo(arrZonas[indice].drones_semaforo, arrZonas[indice].n_drones_semaforo, output);
        imprimir_drones_estacionamiento(arrZonas[indice].drones_estacionamiento, arrZonas[indice].n_drones_estacionamiento, output);
        imprimir_totales_de_la_zona(arrZonas[indice].cantidad_multas_registradas, arrZonas[indice].total_multas_acumuladas, output);
    }
}









// Módulo que lee un evento de infracción de un archivo CSV de eventos.
void leer_un_evento_de_la_zona(char *&id_leido, char *&placa, int &fecha_infraccion,
                               int &aviso_observado, ifstream &input) {
    id_leido = leer_cadena(input, ',');      // Leer el ID del dron (hasta la coma).
    if(id_leido == nullptr) return;          // Si no hay más datos a leer, entonces salir del módulo.
    placa = leer_cadena(input, ',');         // Leer la placa del vehículo.
    fecha_infraccion = leer_fecha(input);    // Leer la fecha (como entero).
    aviso_observado = leer_dato_int(input);  // Leer el valor observado (velocidad, semáforo, zona de carga).
}







// Módulo que busca un dron de tipo "Velocidad" por su ID. Si lo encuentra, devuelve su índice.
bool encontrar_drone_velocidad(char *id_leido, const struct DroneDeVelocidad *drones_velocidad,
                               int n_drones_velocidad, int &indice_a_retornar) {
    for(int indice = 0; indice < n_drones_velocidad; indice++) {
        if(strcmp(drones_velocidad[indice].datos_drone.id, id_leido) == 0) {
            indice_a_retornar = indice;
            return true;
        }
    }
    return false;
}






// Módulo que busca un dron de tipo "Semaforo" por su ID. Si se encuentra este ID, entonces devuelve su índice.
bool encontrar_drone_semaforo(char *id_leido, const struct DroneSemaforo *drones_semaforo,
                              int n_drones_semaforo, int &indice_a_retornar) {
    for(int indice = 0; indice < n_drones_semaforo; indice++) {
        if(strcmp(drones_semaforo[indice].informacion_drone.id, id_leido) == 0) {
            indice_a_retornar = indice;
            return true;
        }
    }
    return false;
}







// Módulo que busca un dron de tipo "Estacionamiento" por su ID. Si se encuentra , entonces se devuelve el índice.
bool encontrar_drone_estacionamiento(char *id_leido, const struct DroneEstacionamiento *drones_estacionamiento,
                                     int n_drones_estacionamiento, int &indice_a_retornar) {
    for(int indice = 0; indice < n_drones_estacionamiento; indice++) {
        if(strcmp(drones_estacionamiento[indice].info_drone.id, id_leido) == 0) {
            indice_a_retornar = indice;
            return true;
        }
    }
    return false;
}








// Módulo que registra una infracción en el arreglo de infracciones del dron correspondiente.
void actualizar_infracciones(struct Infraccion *infracciones, int &cantidad_infracciones, char *placa, 
                             int fecha_infraccion, int aviso_observado, int aviso_permitido,
                             int &cantidad_multas_registradas, double &total_multas_acumuladas) {
    
    // Registrar la fecha del evento.
    infracciones[cantidad_infracciones].fecha_evento = retornar_estructura_fecha(fecha_infraccion);
    
    // Determinar el tipo de infracción.
    infracciones[cantidad_infracciones].tipo_infraccion = asignar_cadena(aviso_observado < aviso_permitido ? "Leve" : "Grave");
    
    // Calcular el monto de la multa (5% o 8% de una UIT).
    infracciones[cantidad_infracciones].monto = (aviso_observado < aviso_permitido ? VALOR_UIT*((double)5/100) : VALOR_UIT*((double)8/100));
    
    // Fecha límite de pago (30 días calendario después del evento).
    infracciones[cantidad_infracciones].fecha_pago_limite = retornar_estructura_fecha(fecha_infraccion + 100);
    
    // Asignar la placa del vehículo.
    infracciones[cantidad_infracciones].placa = asignar_cadena(placa);
    
    // Actualizar el contador de infracciones del dron.
    cantidad_infracciones++;
    
    // Actualizar los acumuladores generales
    total_multas_acumuladas += infracciones[cantidad_infracciones - 1].monto;
    cantidad_multas_registradas++;
}









// Módulo que procesa los eventos de una zona: identifica al dron e incrementa su lista de infracciones.
void procesar_eventos_de_una_zona(struct DroneDeVelocidad *drones_velocidad,
                                  int n_drones_velocidad, struct DroneSemaforo *drones_semaforo, int n_drones_semaforo,
                                  struct DroneEstacionamiento *drones_estacionamiento, int n_drones_estacionamiento,
                                  int &cantidad_multas_registradas, double &total_multas_acumuladas, ifstream &input) {
    int fecha_infraccion, aviso_observado, indice;
    char *id_leido, *placa;
    while(true) {
        leer_un_evento_de_la_zona(id_leido, placa, fecha_infraccion, aviso_observado, input);
        if(input.eof()) break;
        
        // Buscar el dron en cada tipo y registrar infracción si se encuentra.
        if( encontrar_drone_velocidad(id_leido, drones_velocidad, n_drones_velocidad, indice) ) {
            actualizar_infracciones(drones_velocidad[indice].datos_drone.infracciones,
                                    drones_velocidad[indice].datos_drone.cantidad_infracciones,
                                    placa, fecha_infraccion, aviso_observado, drones_velocidad[indice].velocidad_maxima_permitida,
                                    cantidad_multas_registradas, total_multas_acumuladas);
        }
        if( encontrar_drone_semaforo(id_leido, drones_semaforo, n_drones_semaforo, indice) ) {
            actualizar_infracciones(drones_semaforo[indice].informacion_drone.infracciones,
                                    drones_semaforo[indice].informacion_drone.cantidad_infracciones,
                                    placa, fecha_infraccion, aviso_observado, drones_semaforo[indice].luz_roja,
                                    cantidad_multas_registradas, total_multas_acumuladas);
        }
        if( encontrar_drone_estacionamiento(id_leido, drones_estacionamiento, n_drones_estacionamiento, indice) ) {
            actualizar_infracciones(drones_estacionamiento[indice].info_drone.infracciones,
                                    drones_estacionamiento[indice].info_drone.cantidad_infracciones,
                                    placa, fecha_infraccion, aviso_observado, drones_estacionamiento[indice].zona_carga,
                                    cantidad_multas_registradas, total_multas_acumuladas);
        }
    }
}









// Módulo que procesa los archivos de eventos de todas las zonas registradas.
void procesar_eventos(const char *nombre_carpeta, struct Zona *arrZonas, int cantidad_zonas) {
    for(int indice = 0; indice < cantidad_zonas; indice++) {
        ifstream input;
        
        // Abrir el archivo correspondiente usando el nombre de carpeta y la zona.
        aperturar_archivo_mediante_una_ruta(input, nombre_carpeta, "Eventos", arrZonas[indice].zona);
        
        // Procesar todos los eventos de una zona.
        procesar_eventos_de_una_zona(arrZonas[indice].drones_velocidad,arrZonas[indice].n_drones_velocidad,
                                     arrZonas[indice].drones_semaforo, arrZonas[indice].n_drones_semaforo,
                                     arrZonas[indice].drones_estacionamiento, arrZonas[indice].n_drones_estacionamiento,
                                     arrZonas[indice].cantidad_multas_registradas, arrZonas[indice].total_multas_acumuladas,input);
    }
}









// Módulo que lee una línea de datos de un drone desde el archivo "Drones_<ZONA>.csv".
void leer_datos_de_un_drone(char *&tipo_de_drone, char *&id, char *&ubicacion,
                            int &capacidad_de_almacenamiento, int &aviso, ifstream &input) {
    tipo_de_drone = leer_cadena(input, ',');
    if(tipo_de_drone == nullptr) return;  // Si no hay datos más datos para leer en el archivo, entonces salir del módulo.
    id = leer_cadena(input, ',');         // Leer el ID del dron.
    ubicacion = leer_cadena(input, ',');  // Leer la ubicación del dron.
    capacidad_de_almacenamiento = leer_dato_int(input);  // Leer la capacidad del dron (entero).
    
    if(strcmp(tipo_de_drone, "Velocidad") == 0) {
        // El tipo del drone es "Velocidad",entonces el siguiente dato a leer es un número entero (velocidad máxima permitida).
        aviso = leer_dato_int(input);
    } else {
        // El tipo del drone no es "Velocidad", entonces el siguiente dato a leer  es una cadena de caracteres (true o false).
        char *leer_palabra_true_o_false = leer_cadena(input, '\n');
        
        if(strcmp(leer_palabra_true_o_false, "true") == 0)  aviso = 1; // Se completa con 1, porque se leyó "true".
        else  aviso = 0;  // Se completa con el valor de 0, porque se leyó "false".
    }
}









// Módulo que completa los campos de un drone en una estructura Drone.
void completar_campo_estructura_drone(struct Drone &un_drone, char *id, char *ubicacion, int capacidad) {
    un_drone.id = asignar_cadena(id);   // Copiar el ID a memoria dinámica.
    un_drone.ubicacion = asignar_cadena(ubicacion);   // Copiar la ubicación a memoria dinámica.
    un_drone.capacidad = capacidad;   // Asignar la capacidad.
    
    un_drone.infracciones = new struct Infraccion[MAX_CANT_INFRACCIONES];  // Asignar memoria al arreglo "infracciones".
    un_drone.cantidad_infracciones = 0;   // Inicializar la cantidad de infracciones al valor de cero.
}









// Módulo que lee todos los drones de un archivo "Drones_<ZONA>.csv" y los separa por tipo en sus respectivos arreglos.
void cargar_datos_de_un_drone(struct DroneDeVelocidad *drones_velocidad, int &n_drones_velocidad,
                              struct DroneSemaforo *drones_semaforo, int &n_drones_semaforo,
                              struct DroneEstacionamiento *drones_estacionamiento, int &n_drones_estacionamiento,ifstream &input) {
    // Inicializar los contadores de drones a cero.
    n_drones_velocidad = n_drones_semaforo = n_drones_estacionamiento = 0;
    
    // Variables para almacenar datos leídos temporalmente.
    char *tipo_de_drone, *id, *ubicacion;
    int capacidad, aviso;
    while(true) {
        leer_datos_de_un_drone(tipo_de_drone, id, ubicacion, capacidad, aviso, input);
        if(input.eof()) break; // Validar el fin del archivo.
        
        // Según el tipo del drone, se almacena en la estructura correspondiente.
        if(strcmp(tipo_de_drone, "Velocidad") == 0) {
            completar_campo_estructura_drone(drones_velocidad[n_drones_velocidad].datos_drone, id, ubicacion, capacidad);
            drones_velocidad[n_drones_velocidad].velocidad_maxima_permitida = aviso;
            n_drones_velocidad++;
        } else if(strcmp(tipo_de_drone, "Semaforo") == 0) {
            completar_campo_estructura_drone(drones_semaforo[n_drones_semaforo].informacion_drone, id, ubicacion, capacidad);
            drones_semaforo[n_drones_semaforo].luz_roja = aviso;
            n_drones_semaforo++;
        } else {
            // El tipo del drone es "Estacionamiento".
            completar_campo_estructura_drone(drones_estacionamiento[n_drones_estacionamiento].info_drone, id, ubicacion, capacidad);
            drones_estacionamiento[n_drones_estacionamiento].zona_carga = aviso;
            n_drones_estacionamiento++;
        }
    }
}







// Módulo que recorre todas las zonas y carga los drones de cada una desde su archivo correspondiente.
void procesar_drones(const char *nombre_carpeta, struct Zona *arrZonas, int cantidad_zonas) {
    for(int indice = 0; indice < cantidad_zonas; indice++) {
        ifstream input;
        
        // Abrir el archivo correspondiente usando el nombre de carpeta y la zona.
        aperturar_archivo_mediante_una_ruta(input, nombre_carpeta, "Drones", arrZonas[indice].zona);
        
        // Cargar los drones de esa zona.
        cargar_datos_de_un_drone(arrZonas[indice].drones_velocidad,arrZonas[indice].n_drones_velocidad,
                                 arrZonas[indice].drones_semaforo, arrZonas[indice].n_drones_semaforo,
                                 arrZonas[indice].drones_estacionamiento, arrZonas[indice].n_drones_estacionamiento,input);
    }
}






// Módulo que pasa todas las letras de una cadena de caracteres a mayúsculas.
void pasar_todo_a_mayusculas(char *cadena) {
    for(int indice = 0; cadena[indice]; indice++) {
        if(cadena[indice] >= 'a'   and   cadena[indice] <= 'z') {
            // cadena[indice] = cadena[indice] - ('a' - 'A')
            cadena[indice] -= 32;  // 32 es igual al codigo ASCCI de la diferencia de ('a' - 'A')
        }
    }
}







// Módulo que procesa el archivo que contiene los nombres de las zonas y los almacena en el arreglo de
// estructuras de tipo "Zona". Además, inicializa cada campo de la estructura como también reserva memoria
// en los campos que se requiere de ello.
void procesar_zonas(const char *ruta_de_archivo, struct Zona *&arrZonas, int &cantidad_zonas) {
    ifstream input;
    aperturar_archivo_lectura(ruta_de_archivo, input);
    
    arrZonas = new struct Zona[MAX_CANT_ZONAS];  // Reservar memoria para el arreglo de zonas.
    
    char *zona;
    cantidad_zonas = 0;
    while(true) {
        zona = leer_cadena(input, '\n');
        if(zona == nullptr) break; // Se llegó al fin del archivo, entonces salir de bucle.
        pasar_todo_a_mayusculas(zona);
        arrZonas[cantidad_zonas].zona = asignar_cadena(zona);  // Copiar el nombre de la zona al arreglo.
        
        // Reservar memoria para los tres tipos de drones asociados a la zona.
        arrZonas[cantidad_zonas].drones_velocidad = new struct DroneDeVelocidad[MAX_CANT_DRONES];
        arrZonas[cantidad_zonas].drones_semaforo = new struct DroneSemaforo[MAX_CANT_DRONES];
        arrZonas[cantidad_zonas].drones_estacionamiento = new struct DroneEstacionamiento[MAX_CANT_DRONES];
        
        // Inicializar los contadores de drones en cero y la cantidad como el total a pagar de multas.
        arrZonas[cantidad_zonas].n_drones_velocidad = 0;
        arrZonas[cantidad_zonas].n_drones_semaforo = 0;
        arrZonas[cantidad_zonas].n_drones_estacionamiento = 0;
        arrZonas[cantidad_zonas].cantidad_multas_registradas = 0;
        arrZonas[cantidad_zonas].total_multas_acumuladas = 0;
        
        cantidad_zonas++; // Actualizar la cantidad de zonas.
    }
}




