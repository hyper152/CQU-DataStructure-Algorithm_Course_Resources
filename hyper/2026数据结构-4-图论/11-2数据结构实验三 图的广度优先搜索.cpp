#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 使用 vector 的邻接表（不需要 new/delete）
struct ALGraph {
    vector<int> vertices[20];  // 直接用 vector 存储邻接点
    int vernum, arcnum;
};

// 创建图
void CreateGraph(ALGraph& G, int n, int e) {
    G.vernum = n;
    G.arcnum = e;
    
    // 不需要手动初始化，vector 自动为空
    
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        
        // 直接添加，不需要 new
        G.vertices[u].push_back(v);
        G.vertices[v].push_back(u);
    }
}

// 排序邻接表
void SortAdjList(ALGraph& G) {
    for (int i = 0; i < G.vernum; i++) {
        sort(G.vertices[i].begin(), G.vertices[i].end());
    }
}

// BFS 遍历
void BFS(ALGraph& G, int start, vector<bool>& visited, vector<int>& traversal) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        traversal.push_back(current);
        
        // 遍历 vector 中的所有邻接点
        for (int neighbor : G.vertices[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    
    ALGraph G;
    CreateGraph(G, n, e);
    SortAdjList(G);
    
    vector<bool> visited(n, false);
    vector<int> traversal;
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(G, i, visited, traversal);
            components++;
        }
    }
    
    for (int i = 0; i < traversal.size(); i++) {
        cout << traversal[i] << " ";
    }
    cout << endl;
    cout << components << endl;
    cout << e << endl;
    
    return 0;
}