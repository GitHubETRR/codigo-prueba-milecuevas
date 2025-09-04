#include <iostream>
using namespace std;
#define MAX 20

class persona 
{
private:
    string nombre;
    string apellido;

public:
    persona()
    {
        nombre = "sinNombre";
        apellido = "sinApellido";
    }

    string getNombre() 
    { 
        return nombre; 
    }
    
    string getApellido() 
    { 
        return apellido; 
    }
    
    void setNombre(string n) 
    { 
        nombre = n;
    }
    
    void setApellido(string a) 
    { 
        apellido = a; 
    }
};

class piloto : public persona 
{
private:
    string escuderia;
    int numAuto;
    int puntos;

public:
    piloto() 
    {
        escuderia = "sinEscuderia";
        numAuto = 0;
        puntos = 0;
    }

    void cargar() 
    {
        string n, a;
        cout << "Ingrese nombre: ";
        cin >> n;
        setNombre(n);
        cout << "Ingrese apellido: ";
        cin >> a;
        setApellido(a);
        cout << "Ingrese escuderia: ";
        cin >> escuderia;
        cout << "Ingrese numero de auto: ";
        cin >> numAuto;
        cout << "Ingrese puntos en el campeonato: ";
        cin >> puntos;
    }

    void mostrar() 
    {
        cout << "Nombre: " << getNombre() << "\n";
        cout << "Apellido: " << getApellido() << "\n";
        cout << "Escuderia: " << escuderia << "\n";
        cout << "Numero de auto: " << numAuto << "\n";
        cout << "Puntos: " << puntos << "\n";
    }

    void editar() 
    {
        int opcionEditar;
        cout << "\nQue quiere editar?: \n";
        cout << "1. Nombre\n";
        cout << "2. Apellido\n";
        cout << "3. Escuderia\n";
        cout << "4. Numero de auto\n";
        cout << "5. Puntos\n";
        cout << "Ingrese la opción: ";
        cin >> opcionEditar;

        switch (opcionEditar) 
        {
            case 1: 
            {
                string nuevoNombre;
                cout << "Nuevo nombre: ";
                cin >> nuevoNombre;
                setNombre(nuevoNombre);
                break;
            }
            case 2: 
            {
                string nuevoApellido;
                cout << "Nuevo apellido: ";
                cin >> nuevoApellido;
                setApellido(nuevoApellido);
                break;
            }
            case 3:
                cout << "Nueva escuderia: ";
                cin >> escuderia;
                break;
            case 4:
                cout << "Nuevo numero de auto: ";
                cin >> numAuto;
                break;
            case 5:
                cout << "Nuevos puntos: ";
                cin >> puntos;
                break;
        }
    }

    int getNumAuto() 
    { 
        return numAuto; 
        
    }
};

int main() 
{
    piloto pilotos[MAX];
    int cantidad = 0;
    int opcion;
    do {
        cout << "\nSeleccione una opcion\n";
        cout << "1. Cargar piloto\n";
        cout << "2. Mostrar pilotos\n";
        cout << "3. Editar piloto\n";
        cout << "4. Buscar piloto\n";
        cout << "5. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                if (cantidad < 20) 
                {
                    pilotos[cantidad].cargar();
                    cantidad++;
                } else {
                    cout << "No se pueden cargar mas pilotos.\n";
                }
                break;
            case 2:
                if (cantidad == 0) 
                {
                    cout << "No hay pilotos cargados.\n";
                } else {
                    for (int i = 0; i < cantidad; i++) 
                    {
                        cout << "\nPiloto " << i + 1 << "\n";
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
                if (indice > 0 && indice <= cantidad)
                {
                    cout << "Datos actuales:\n";
                    pilotos[indice - 1].mostrar();
                    pilotos[indice - 1].editar();
                } else {
                    cout << "Numero no valido.\n";
                }
                break;
            }
            case 4: 
            {
                if (cantidad == 0) 
                {
                    cout << "No hay pilotos cargados.\n";
                    break;
                }
                int numBuscar;
                cout << "Ingrese el numero de auto a buscar: ";
                cin >> numBuscar;
                bool encontrado = false;
                for (int i = 0; i < cantidad; i++) 
                {
                    if (pilotos[i].getNumAuto() == numBuscar) 
                    {
                        cout << "\nPiloto encontrado:\n";
                        pilotos[i].mostrar();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado)
                    cout << "No hay ningun piloto con ese numero de auto\n";
                break;
            }
            case 5:
                cout << "Chauuuuu\n";
                break;
        }
    } while (opcion != 5);
    return 0;
}