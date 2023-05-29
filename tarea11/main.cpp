#include <iostream>
using namespace std;

// Función para imprimir el patrón en función del número de líneas n
void imprimirPatron(int n) {
    // Bucle exterior recorre los números del 1 al n
    for (int i = 1; i <= n; i++) {
        // Bucle interior para imprimir i veces el número i
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

// Función para validar si una cadena es un entero positivo
bool esEnteroPositivo(std::string cadena) {
    bool es_entero_positivo = true;
    // Recorre cada carácter de la cadena
    for (char c : cadena) {
        // Si no es un dígito, entonces no es un entero positivo
        if (!std::isdigit(c)) {
            es_entero_positivo = false;
            break;
        }
    }
    // Si es un entero positivo y no comienza con 0, entonces es válido
    if (es_entero_positivo && cadena[0] != '0') {
        return true;
    } else {
        return false;
    }
}

// Función para validar si una cadena es la letra S.
bool esLetraS(std::string cadena) {
    return (cadena == "s" || cadena == "S");
}

int main() {
    string entrada;
    int numLineas = 0;
    bool salirPrograma = false;

    // Mientras el usuario no quiera salir del programa
    while (!salirPrograma) {
        // Pedimos al usuario que introduzca la cantidad de líneas a imprimir o S para salir
        cout << "Introduzca la cantidad de lineas a imprimir o pulse 'S' para salir: ";
        cin >> entrada;

        // Si el usuario introdujo S, sale del programa
        if (esLetraS(entrada)) {
            salirPrograma = true;
        } else {
            // Si la entrada es un entero positivo, lo convierte a int y llama a la función para imprimir el patrón
            if (esEnteroPositivo(entrada)) {
                numLineas = atoi(entrada.c_str());// Convierte la cadena en un entero
                imprimirPatron(numLineas);
            } else {
                // Si la entrada no es válida, pide al usuario que introduzca de nuevo la entrada
                cout << "Entrada no valida. Intente nuevamente." << endl;
            }
        }
    }

    // Mensaje de salida al usuario
    cout << "Saliendo del programa..." << endl;

    return 0;
}
