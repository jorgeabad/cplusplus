#include <iostream>
using namespace std;

int main() {
  // Declaración e inicialización de variables
  float numero1 = 7.3;
  float numero2;
  float* fpunt = &numero1;
  char s1[100] = "Hola mundo!!!!";
  char* ptr = &s1[0];

  // Imprime el valor de la variable a la que apunta fpunt
  cout << *fpunt << endl;

  // Asigna el valor de la variable a la que apunta fpunt a la variable numero2
  numero2 = *fpunt;
  cout << numero2 << endl;

  // Imprime la dirección de memoria de la variable numero1 y la dirección almacenada en fpunt
  cout << &numero1 << endl;
  cout << fpunt << endl;

  // Imprime el carácter en la posición 5 del array s1 utilizando el puntero ptr
  cout << *(ptr + 5) << endl;

  // Cambia el puntero ptr para que apunte a la posición 10 del array s1
  ptr = &s1[10];

  // Imprime el carácter en la posición 10 del array s1 utilizando el puntero ptr
cout  << *ptr << endl;
  return 0;
}
