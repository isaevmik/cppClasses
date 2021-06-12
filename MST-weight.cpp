#include <climits>
#include <iostream>
#include <vector>

using namespace std;

size_t weightCounter = 0;
bool isExist = true;
void Prim(size_t sz, vector<vector<int>>& g) {
    size_t sizePlusOneIndex = sz + 1;
    vector<bool> visited(sizePlusOneIndex);
    vector<int> minimumEdgeFromV(sizePlusOneIndex, INT_MAX),
    endOfMinEdge (sizePlusOneIndex + 1, -1);
    minimumEdgeFromV[1] = 0;
    for (size_t i = 1; i <= sz; ++i) {
        int vertex = -1;
        for (size_t j = 1; j <= sz; ++j) {
            if (((minimumEdgeFromV[j] < minimumEdgeFromV[vertex]) ||
            (vertex == -1)) && !visited[j]) {
                vertex = j;
            }
        }
        if (minimumEdgeFromV[vertex] == INT_MAX) {
            isExist = false;
            return;
        }
        visited[vertex] = true;
        if (endOfMinEdge[vertex] != -1) {
            weightCounter += g[vertex][endOfMinEdge[vertex]];
        }
        for (size_t to = 1; to <= sz; ++to) {
            if (g[vertex][to] < minimumEdgeFromV[to]) {
                minimumEdgeFromV[to] = g[vertex][to];
                endOfMinEdge[to] = vertex;
            }
        }
    }
}

int main() {
    size_t n, m;
    cin >> n >> m;
    size_t sizePlusOneIndex = n + 1;
    vector<vector<int>> graph(sizePlusOneIndex,
                              vector<int>(sizePlusOneIndex, INT_MAX));
    for (size_t i = 0; i < m; ++i) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
    }
    Prim(n, graph);
    cout << ((isExist) ? weightCounter : 0) << endl;
    return 0;
}

