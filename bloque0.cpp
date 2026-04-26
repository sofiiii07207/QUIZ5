#include <iostream>
#include <string>
using namespace std;

struct Espada {
string nombre;
int dano;
};

int main() {
Espada e;
e.nombre = "Hacha";
e.dano = 42;
cout << e.nombre << " -- dano: " << e.dano << endl;
return 0;
}
