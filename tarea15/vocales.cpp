// Incluimos las bibliotecas necesarias
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Determina si un carácter es una vocal en minúscula o mayúscula.
 * @param letra Carácter a evaluar.
 * @return Verdadero si la letra es una vocal, falso en caso contrario.
 */
bool es_vocal(char letra)
{
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'}; // Definimos un array con las vocales en minúscula
    char miLetra = tolower(letra);               // Pasamos el caracter a minúscula
    for (int i = 0; i < 5; i++)
    {
        if (miLetra == vocales[i])
        {
            return true; // Si es una vocal, devolvemos verdadero
        }
    }
    return false; // Si no es una vocal, devolvemos falso
}

/**
 * @brief Determina si un carácter es un símbolo de puntuación.
 * @param c Carácter a evaluar.
 * @return Verdadero si el carácter es un símbolo, falso en caso contrario.
 */
bool esPuntuacion(char c)
{
    string puntuacion = ".,;:!¡¿?-()[]{}\"\'";  // Definimos una cadena de caracteres con varios simbolos de puntuación
    for (int i = 0; i < puntuacion.length(); i++)
    {
        if (c == puntuacion[i])
        {
            return true; // Si es un caracter de puntuación, devolvemos verdadero
        }
    }
    return false; // Si no es un caracter de puntuación, devolvemos falso
}


/**
 * @brief Imprime una palabra.
 * @param spalabra Palabra a imprimir.
 */
void imprimir_palabra(string spalabra)
{
    cout << spalabra << endl; // Imprimimos la palabra seguida de un salto de línea
}

/**
 * @brief Procesa una línea de texto e imprime las palabras que empiezan por vocal.
 * @param slinea Línea de texto a procesar.
 */
void procesar_linea(string slinea)
{
    string spalabra = ""; // Inicializamos una variable string vacía para ir construyendo la palabra
    for (int i = 0; i <= slinea.length(); i++)
    {
        if (slinea[i] == ' ') // Si encontramos un espacio, significa que la palabra ha terminado
        {
            if (es_vocal(spalabra[0])) // Comprobamos si la primera letra es una vocal
            {
                imprimir_palabra(spalabra); // Si lo es, imprimimos la palabra
            }
            spalabra = ""; // Reseteamos la variable para construir la siguiente palabra
        }
        else
        {
            if (!esPuntuacion(slinea[i])) spalabra += slinea[i]; // Si no es un espacio ni un símbolo de puntuación, añadimos el caracter a la palabra
        }
    }
    if (es_vocal(spalabra[0])) // Comprobamos si la última palabra de la línea empieza por vocal ya que la línea podría haber terminado sin un espacio en blanco que indique el final de una palabra
    {
        imprimir_palabra(spalabra); // Si lo es, imprimimos la palabra
    }
    spalabra = ""; // Reseteamos la variable para la siguiente línea
}

/**
 * @brief Abre un archivo y procesa cada una de sus líneas para imprimir las palabras que empiezan por vocal.
 * @param nombre_archivo Nombre del archivo a abrir.
 */
void imprimir_palabras(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str()); // Abrimos el archivo
    if (!archivo.is_open())                   // Comprobamos si se pudo abrir el archivo
    {
        cout << "No se pudo abrir el archivo" << endl; // Si no se pudo abrir, mostramos un mensaje de error
        return;
    }

    string slinea;
    while (getline(archivo, slinea)) // Leemos línea por línea el archivo
    {
        procesar_linea(slinea); // Procesamos cada línea
    }

    archivo.close(); // Cerramos el archivo
}

int main()
{
    string nombre_archivo;
    cout << "Ingresa el nombre del archivo: ";
    cin >> nombre_archivo;

    imprimir_palabras(nombre_archivo);

    return 0;
}