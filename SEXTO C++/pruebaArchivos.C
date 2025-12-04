#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int opcion;
    while (true)
    {
        cout << "\nMENU\n";
        cout << "1. agregar tarea\n";
        cout << "2. mostrar tareas\n";
        cout << "3. editar tarea\n";
        cout << "4. salir\n";
        cout << "opcion: ";
        cin >> opcion;
        cin.ignore();
       
        if (opcion == 1)
        {
            ofstream archivo("tareas.txt", ios::app);
            string tarea;
            cout << "ingrese la tarea: ";
            getline(cin, tarea);
            archivo << tarea << "\n";
            archivo.close();
            cout << "tarea agregada\n";
        }

        else if (opcion == 2)
        {
            ifstream archivo("tareas.txt");
            string linea;
            int i = 1;
            cout << "\nTAREAS\n";
            while (getline(archivo, linea))
            {
                cout << i << "- " << linea << "\n";
                i++;
            }
            archivo.close();

            if (i == 1) cout << "no hay tareas\n";
        }

        else if (opcion == 3)
        {
            ifstream archivoIfs("tareas.txt");
            vector<string> tareas;
            string linea;

            while (getline(archivoIfs, linea))
                tareas.push_back(linea);
            archivoIfs.close();

            if (tareas.empty())
            {
                cout << "no hay tareas\n";
                continue;
            }

            cout << "\nTAREAS\n";
            for (int i = 0; i < tareas.size(); i++)
                cout << i + 1 << "- " << tareas[i] << "\n";

            int num;
            cout << "numero de la tarea a editar: ";
            cin >> num;
            cin.ignore();
            if (num < 1 || num > tareas.size())
            {
                cout << "numero invalido.\n";
                continue;
            }

            cout << "nueva tarea: ";
            getline(cin, tareas[num - 1]);

            ofstream archivoOfs("tareas.txt");
            for (int i = 0; i < tareas.size(); i++)
            {
                string t = tareas[i];
                archivoOfs << t << "\n";
            }
            archivoOfs.close();

            cout << "tarea editada\n";
        }

        else if (opcion == 4)
        {
            cout << "chauuuu\n";
            break;
        }
    }
    return 0;
}