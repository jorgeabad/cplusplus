/**
 * @file programaUno.cpp
 *
 * @brief Programa para leer datos de clientes proporcionados por terminal y escribirlos en un archivo.
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Función para validar que una cadena solo contenga caracteres alfabéticos
 *
 * @param cadena Cadena a validar
 * @return true si la cadena solo contiene caracteres alfabéticos, false en caso contrario
 */
bool esCadenaAlfabetica(string cadena)
{
    for (char c : cadena)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Función para validar que una cadena solo contenga números y esté en el rango correcto de edades
 *
 * @param cadena Cadena a validar
 * @return true si la cadena solo contiene números y está en el rango correcto de edades, false en caso contrario
 */
bool esEdadValida(string cadena)
{
    if (cadena.empty()) // Verificar que la cadena no esté vacía
        return false;
    for (char c : cadena)
    {
        if (!isdigit(c) && !isspace(c)) // Verificar que el carácter actual sea numérico o un espacio en blanco
        {
            return false;
        }
    }
    int edad = stoi(cadena);     // Convertir la cadena a un entero
    if (edad < 16 || edad > 100) // Verificar que la edad esté en el rango correcto
        return false;
    return true;
}


/**
 * @brief Función para escribir los datos en un archivo
 *
 * @param archivo Archivo donde se escribirán los datos
 * @param nombre Nombre del cliente
 * @param apellido Apellido del cliente
 * @param edad Edad del cliente
 */
void escribirDatos(ofstream &archivo, string nombre, string apellido, int edad)
{
    archivo << nombre << " " << apellido << " " << edad << endl;
}

int main()
{
    string nombre, apellido, edadStr;
    int edad;
    ofstream archivo("datos.txt");

    // Leer datos de clientes
    while (true)
    {
        // Leer nombre
        cout << "Introduzca el nombre del cliente (deje en blanco para terminar): ";
        getline(cin, nombre);

        // Salir si se dejó el nombre en blanco
        if (nombre.empty())
        {
            break;
        }

        // Validar que el nombre solo contenga caracteres alfabéticos
        while (!esCadenaAlfabetica(nombre))
        {
            cout << "El nombre solo puede contener letras. Introduzca el nombre del cliente: ";
            getline(cin, nombre);
        }

        // Leer apellido
        cout << "Introduzca el primer apellido del cliente: ";
        getline(cin, apellido);

        // Validar que el apellido solo contenga caracteres alfabéticos y no esté en blanco.
        while (!esCadenaAlfabetica(apellido)||apellido.empty())
        {
            cout << "El apellido solo puede contener letras. Introduzca el primer apellido del cliente: ";
            getline(cin, apellido);
        }

        // Leer edad
        cout << "Introduzca la edad del cliente (debe estar entre 16 y 100 años): ";
        getline(cin, edadStr);

        // Validar que la edad solo contenga números y esté en el rango correcto
        while (!esEdadValida(edadStr) || edadStr.empty())
        {
            cout << "La edad debe ser un número entre 16 y 100. Introduzca la edad del cliente: ";
            getline(cin, edadStr);
        }

        // Convertir edad a entero
        edad = stoi(edadStr);

        // Escribir datos en el archivo
        escribirDatos(archivo, nombre, apellido, edad);
    }
}
