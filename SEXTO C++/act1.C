#include <iostream>
using namespace std;

class Piloto {
private:
    string nombre;
    string apellido;
    int numAuto;

public:
    Piloto(string nom, string a, int num) {
        nombre = nom;
        apellido = a;
        numAuto = num;
    }
    void cargar() {
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cout << "Ingrese apellido: ";
        cin >> apellido;
        cout << "Ingrese número de auto: ";
        cin >> numAuto;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout <<"Apellido: " << apellido << endl;
        cout <<"Auto: " << numAuto << endl;
    }
};

int main() {
    Piloto piloto1("Charles", "Leclerc", 16);

    piloto1.mostrar();

    return 0;
}
