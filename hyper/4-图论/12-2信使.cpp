#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; ++i) graph[i][i] = 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // 无向图，双向赋值，取最小权值（如果有重边）
        if (w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }
    
    // Dijkstra算法
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    dist[1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        // 找到未访问节点中dist最小的
        int u = -1, minDist = INF;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 剩余节点不可达
        visited[u] = true;
        // 更新邻接点
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << -1 << endl;
            return 0;
        }
        if (dist[i] > maxDist) maxDist = dist[i];
    }
    cout << maxDist << endl;
    
    return 0;
}