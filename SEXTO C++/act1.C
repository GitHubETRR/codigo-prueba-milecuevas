#include <iostream>
using namespace std;

#define MAX 20

class piloto {
private:
    string nombre;
    string apellido;
    int numAuto;

public:
    piloto()
    {
        nombre = "sinNombre";
        apellido = "sinApellido";
        numAuto = 0;
    }

    void cargar()
    {
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cout << "Ingrese apellido: ";
        cin >> apellido;
        cout << "Ingrese numero de auto: ";
        cin >> numAuto;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << "\n";
        cout << "Apellido: " << apellido << "\n";
        cout << "Auto: " << numAuto << "\n";
    }

    void editar()
    {
        int opcionEditar;
        cout << "\nQue quiere editar?: \n";
        cout << "1. Nombre\n";
        cout << "2. Apellido\n";
        cout << "3. Numero de auto\n";
        cout << "Ingrese la opción:\n ";
        cin >> opcionEditar;

        switch (opcionEditar)
        {
            case 1:
                cout << "Nuevo nombre: ";
                cin >> nombre;
                break;
            case 2:
                cout << "Nuevo apellido: ";
                cin >> apellido;
                break;
            case 3:
                cout << "Nuevo numero de auto: ";
                cin >> numAuto;
                break;
        }
    }
};

int main() {
    piloto pilotos[MAX];
    int cantidad = 0;
    int opcion;

    do
    {
        cout << "Seleccione una opcion\n";
        cout << "1. Cargar piloto\n";
        cout << "2. Mostrar piloto\n";
        cout << "3. Editar piloto\n";
        cout << "4. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                if (cantidad < MAX)
                {
                    pilotos[cantidad].cargar();
                    cantidad++;
                } else {
                    cout << "No se pueden cargar más pilotos.\n";
                }
                break;

            case 2:
                if (cantidad == 0)
                {
                    cout << "No hay pilotos cargados.\n";
                } else {
                    for (int i = 0; i < cantidad; i++)
                    {
                        cout << "\nPiloto " << i + 1 <<"\n";
                        pilotos[i].mostrar();
                    }
                }
                break;

            case 3:
            {
                if (cantidad == 0)
                {
                    cout << "No hay pilotos para editar.\n";
                    break;
                }
                int indice;
                cout << "Ingrese numero de piloto a editar (1-" << cantidad << "): ";
                cin >> indice;
                if (indice > 0 && indice <= cantidad) {
                    cout << "Datos actuales:\n";
                    pilotos[indice - 1].mostrar();
                    pilotos[indice - 1].editar();
                } else {
                    cout << "Numero no valido.\n";
                }
                break;
            }

            case 4:
                cout << "Chauuuuu\n";
                break;
        }
    } while (opcion != 4);
    return 0;
}