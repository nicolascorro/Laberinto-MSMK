// Laberinto2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // Vector de vectores de tipo int
    vector<vector<int>> laberinto = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0}
    };

    // Número de filas y columnas
    int numFilas = laberinto.size();
    int numCols = laberinto[0].size();

    // Matriz de nodos visitados    
    vector<vector<bool>> visitados(numFilas, vector<bool>(numCols, false));

    // Lo llenamos de valores false indicando que no han sido visitados aún
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numCols; ++j) {
            visitados[i][j] = false;
        }
    }

    // Pila de pares ordenados de los caminos elegidos
    stack<pair<int, int>> caminosElegidos;

    int pasable = 1;
    int noPasable = 0;

    int filActual = 9;
    int colActual = 3;

    // Empezar la pila con el primer nodo (9, 3)
    caminosElegidos.push({ filActual, colActual });

    // Búsqueda en profundidad hasta que llegue al final (0, 9)
    while (filActual != 0 || colActual != 9) {
        
        // Marcar la posición actual como visitada
        visitados[filActual][colActual] = true;

        // Verifica si hay opciones de movimiento cada vuelta (al final del bucle)
        int caminosDisponibles = 0;

        // Izquierda
        if (colActual - 1 >= 0 && laberinto[filActual][colActual - 1] == pasable && visitados[filActual][colActual - 1] == false) {
            colActual--;
            caminosElegidos.push({ filActual, colActual });
            caminosDisponibles++;
        }
        // Arriba
        else if (filActual - 1 >= 0 && laberinto[filActual - 1][colActual] == pasable && visitados[filActual - 1][colActual] == false) {
            filActual--;
            caminosElegidos.push({ filActual, colActual });
            caminosDisponibles++;
        }
        // Derecha
        else if (colActual + 1 < numCols && laberinto[filActual][colActual + 1] == pasable && visitados[filActual][colActual + 1] == false) {
            colActual++;
            caminosElegidos.push({ filActual, colActual });
            caminosDisponibles++;
        }
        // Abajo
        else if (filActual + 1 < numFilas && laberinto[filActual + 1][colActual] == pasable && visitados[filActual + 1][colActual] == false) {
            filActual++;
            caminosElegidos.push({ filActual, colActual });
            caminosDisponibles++;
        }

        // Si no hay opciones, retrocede a la posición anterior almacenada en la pila
        if (caminosDisponibles == 0) {
            if (!caminosElegidos.empty()) {
                caminosElegidos.pop();
                pair<int, int> anterior = caminosElegidos.top();
                filActual = anterior.first;
                colActual = anterior.second;
            }
            else {
                // No hay opciones y la pila está vacía, salir del bucle
                break;
            }
        }
    }

    cout << "¡Llegaste a la meta!"<<endl<<filActual<<" "<<colActual;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
