/**
 * @file nombre.cpp
 * @brief Programa para comprobar diferentes propiedades de un número entero
 * 
 * Este programa permite al usuario introducir un número entero y comprobar si es par, grande, positivo o divisible por 5.
 * También se puede cambiar el número seleccionado o salir del programa.
 * 
 */

#include <iostream>
#include "nombre.h" 
using namespace std;

/**
 * @brief Función para comprobar si un número es par o impar
 * @param n Número entero a comprobar
 * @return true si el número es par, false si es impar
 */
bool par_impar(int n)
{
    return (n % 2 == 0) ? true : false;
}

/**
 * @brief Función para comprobar si un número es grande (mayor que 1000)
 * @param n Número entero a comprobar
 * @return true si el número es grande, false si es menor o igual a 1000
 */
bool grande(int n)
{
    return (n > 1000) ? true : false;
}

/**
 * @brief Función para comprobar si un número es positivo o negativo
 * @param n Número entero a comprobar
 * @return true si el número es positivo o cero, false si es negativo
 */
bool positivo(int n)
{
    return (n >= 0) ? true : false;
}

/**
 * @brief Función para comprobar si un número es divisible por 5
 * @param n Número entero a comprobar
 * @return true si el número es divisible por 5, false si no lo es
 */
bool divisible5(int n)
{
    return (n % 5 == 0) ? true : false;
}

/**
 * @brief Función para pedir al usuario que introduzca un número entero válido
 * @return El número entero introducido por el usuario
 */
int pedirNumeroEntero() {
    string entrada;
    int num;
    bool esValido = false;

    while (!esValido) {
        cout << "Ingrese un número entero: ";
        cin >> entrada;

        // verificar si el primer carácter es '-' o un dígito
        if (entrada[0] == '-' || isdigit(entrada[0])) {
            // verificar si los siguientes caracteres son dígitos
            esValido = true;
            for (char c : entrada.substr(1)) {
                if (!isdigit(c)) {
                    esValido = false;
                    break;
                }
            }
        }

        if (!esValido) {
            cout << "Entrada inválida. Inténtelo nuevamente." << endl;
        }
    }

    num = atoi(entrada.c_str()); // convertir la cadena a un entero
    return num;
}

/**
 * @brief Función para presentar el menú de opciones
 * @param n Número entero seleccionado actualmente
 */
void presentarMenu(int n)
{
    cout << "Seleccione una opción para realizar sobre el numero: " << n << endl;
    cout << endl << "Opciones:" <<endl;
    cout << "  'p' Para comprobar si es par o impar" << endl;
    cout << "  'g' Para comprobar si el número es grande" << endl;
    cout << "  'o' Para comprobar si es positivo" << endl;
    cout << "  'd' Para comprobar si es divisible por 5" << endl << endl;
    cout << "'n' Si desea introducir un nuevo número." << endl;
    cout << "'s' para salir del porgrama." << endl;
    cout << endl;
}

int main()
{
    char opcion;
    int num = 0;
    string entrada;

    while (opcion != 's')
    {
        cout <<endl << "El numero seleccionado actualmente es " << num <<". ";
        presentarMenu(num);
        cin >> opcion;
        switch (opcion)
        {
        case 'n':
            num = pedirNumeroEntero();
            break;
        case 'p':
            cout << num << " es un número " <<((par_impar(num)) ? "par" : "impar") << endl;
            break;
        case 'g':
            cout << num << " es un número " << ((grande(num)) ? "grande > 1000" : "NO grande < 1000") << endl;
            break;
        case 'o':
            cout << num << " es un número " <<((positivo(num)) ? "positivo" : "negativo") << endl;
            break;
        case 'd':
            cout << num << " es un número " <<((divisible5(num)) ? "divisible por 5" : "NO divisible por 5") << endl;
            break;
        case 's':
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opción no válida. Inténtelo nuevamente." << endl;
            break;
        }
    }

    return 0;
}
