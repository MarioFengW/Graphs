#include <iostream>
#include "Graphs.h"

using namespace std;

int main() {
    int n = 24; // Número de nodos
    vector<vector<pair<int, int>>> grafo(n);

    // Añadir aristas al grafo {nodo_destino, peso}
    grafo[0].push_back({1, 47});
    grafo[0].push_back({23, 14});

    grafo[1].push_back({2, 288});
    grafo[1].push_back({10, 49});

    grafo[2].push_back({3, 45});

    grafo[3].push_back({4, 48});
    grafo[3].push_back({11, 129});

    grafo[4].push_back({5, 53});
    grafo[4].push_back({12, 133});

    grafo[5].push_back({6, 47});
    grafo[5].push_back({19, 172});

    grafo[6].push_back({7, 50});

    grafo[7].push_back({8, 41});

    grafo[8].push_back({9, 47});
    grafo[8].push_back({14, 106});

    grafo[9].push_back({15, 120});
    grafo[9].push_back({16, 267});

    grafo[10].push_back({2, 145});
    grafo[10].push_back({11, 51});

    grafo[11].push_back({12, 47});

    grafo[12].push_back({20, 39});

    grafo[13].push_back({7, 103});
    grafo[13].push_back({14, 46});

    grafo[14].push_back({15, 46});

    grafo[15].push_back({9, 120});
    grafo[15].push_back({16, 46});

    grafo[16].push_back({21, 99});

    grafo[17].push_back({13, 52});
    grafo[17].push_back({18, 53});

    grafo[18].push_back({6, 161});
    grafo[18].push_back({19, 47});

    grafo[19].push_back({5, 172});
    grafo[19].push_back({20, 57});

    grafo[20].push_back({23, 87});

    grafo[22].push_back({17, 36});
    grafo[22].push_back({21, 12});

    int origen;
    cout << "Ingrese el nodo de origen: ";
    cin >> origen; // Nodo de origen

    vector<Nodo> resultado = dijkstra(n, origen, grafo);

    // Imprimir todas las distancias desde el nodo de origen
    cout << "Distancias desde el nodo " << origen << ":\n";
    for (const auto& nodo : resultado) {
        if (nodo.distancia == INF)
            cout << "Nodo " << nodo.nodo << ": Inalcanzable\n";
        else
            cout << "Nodo " << nodo.nodo << ": " << nodo.distancia << " metros\n";
    }

    // Mostrar formato específico para un nodo de destino
    int destino;
    cout << "Ingrese el nodo de destino: ";
    cin >> destino;

    cout << "\nCalculando ruta mas corta de " << origen << " a " << destino << ":\n";

    if (resultado[destino].distancia == INF) {
        cout << "No hay ruta disponible desde el nodo " << origen << " hasta el nodo " << destino << "\n";
    } else {
        cout << "Ruta elegida: ";
        for (size_t i = 0; i < resultado[destino].ruta.size(); ++i) {
            cout << resultado[destino].ruta[i];
            if (i < resultado[destino].ruta.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\n";

        cout << "Distancia total: " << resultado[destino].distancia << " metros ("
                  << resultado[destino].distancia / 1000.0 << " km)\n";

        cout << "Pasos realizados: " << resultado[destino].ruta.size() - 1 << " pasos\n";
    }

    return 0;
}