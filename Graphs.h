#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <limits>

using namespace std;   

const int INF = numeric_limits<int>::max();

struct Nodo {
    int nodo;
    int distancia;
    vector<int> ruta;
};

vector<Nodo> dijkstra(int n, int origen, const vector<vector<pair<int, int>>>& grafo);

#endif // GRAPHS_H