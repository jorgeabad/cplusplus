/**
 * @file programaDos.cpp
 *
 * @brief Programa para leer el archivo datos.txt e imprimir el nombre y apellido de las personas que tienen 30 años o más
 *
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Verifica si una cadena es una edad válida.
 *
 * @param cadena Cadena a verificar.
 * @return true si la cadena contiene solo números y espacios en blanco, de lo contrario, retorna false.
 */
bool esEdadValida(string cadena)
{
    // Recorre cada carácter de la cadena
    for (char c : cadena)
    {
        // Verificar que el carácter actual sea numérico o un espacio en blanco
        if (!isdigit(c) && !isspace(c))
        {
            return false;
        }
    }

    // Si todos los caracteres son numéricos o espacios en blanco, la cadena es una edad válida
    return true;
}

/**
 * @brief Función que procesa una línea del archivo y devuelve el nombre de la persona si su edad es mayor o igual a 30.
 *
 * @param linea Línea del archivo a procesar.
 * @return Nombre de la persona si su edad es mayor o igual a 30, o una cadena vacía en caso contrario.
 */
string procesarLinea(const string &linea)
{
    string nombre;                                  // Variable para almacenar el nombre de la persona
    int edad = 0;                                   // Variable para almacenar la edad de la persona
    int posUltimoEspacio = linea.find_last_of(" "); // Buscar el último espacio en blanco en la línea

    // Si se encontró el último espacio en blanco en la línea
    if (posUltimoEspacio != string::npos)
    {
        // Extraer el nombre y la edad de la línea
        nombre = linea.substr(0, posUltimoEspacio);
        string edad_str = linea.substr(posUltimoEspacio + 1);

        // Si la edad es válida, convertirla a entero
        if (esEdadValida(edad_str))
        {
            edad = stoi(edad_str);
        }
        else // Si la edad no es válida, imprimir mensaje de error
        {
            cout << "La edad no es un número válido: " << edad_str;

            // Devolver la cadena "error" para indicar que hubo un error de formato en la línea
            return "error";
        }
    }

    // Si la edad es mayor o igual a 30, devolver el nombre de la persona
    if (edad >= 30)
    {
        return nombre;
    }

    // Si la edad es menor a 30, devolver una cadena vacía
    return "";
}

/**
 * @brief Función principal que lee un archivo de texto con información de personas y muestra el nombre de las personas mayores de 30 años.
 *
 * @return int
 */
int main()
{
    const string nombreArchivo = "datos.txt"; // variable que almacena el nombre de larchivo a leer
    string linea;                             // variable que almacena cada línea del archivo
    int numLinea = 0;                         // contador de línea para imprimir en caso de error de formato

    ifstream miArchivo(nombreArchivo); // abrir archivo

    if (miArchivo.is_open()) // si se pudo abrir el archivo correctamente
    {
        while (getline(miArchivo, linea)) // leer cada línea del archivo
        {

            // Procesar la línea para obtener el nombre de la persona
            string nombreApellido = procesarLinea(linea);
            
            // Si el nombre no está vacío
            if (!nombreApellido.empty())
            {
                nombreApellido != "error" ? cout << nombreApellido << endl : cout << " Error de formato en linea " << numLinea;
            }
            numLinea++; // aumentar el contador de línea
        }
        miArchivo.close(); // cerrar archivo
    }
    else // si no se pudo abrir el archivo
    {
        cout << "no fue posible abrir el archivo datos.txt";
    }

    return 0; // indicar que el programa ha terminado correctamente
}