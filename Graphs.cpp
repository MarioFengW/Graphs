#include "Graphs.h"
#include <queue>

using namespace std; 


vector<Nodo> dijkstra(int n, int origen, const vector<vector<pair<int, int>>>& grafo) {
    vector<int> distancias(n, INF);
    vector<vector<int>> rutas(n);
    distancias[origen] = 0;
    rutas[origen] = {origen};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        int distancia_actual = pq.top().first;
        int nodo_actual = pq.top().second;
        pq.pop();

        if (distancia_actual > distancias[nodo_actual]) continue;

        for (const auto& vecino : grafo[nodo_actual]) {
            int nodo_vecino = vecino.first;
            int peso_arista = vecino.second;
            int nueva_distancia = distancia_actual + peso_arista;

            if (nueva_distancia < distancias[nodo_vecino]) {
                distancias[nodo_vecino] = nueva_distancia;
                rutas[nodo_vecino] = rutas[nodo_actual];
                rutas[nodo_vecino].push_back(nodo_vecino);
                pq.push({nueva_distancia, nodo_vecino});
            }
        }
    }

    vector<Nodo> resultado;
    for (int i = 0; i < n; ++i) {
        resultado.push_back({i, distancias[i], rutas[i]});
    }

    return resultado;
}