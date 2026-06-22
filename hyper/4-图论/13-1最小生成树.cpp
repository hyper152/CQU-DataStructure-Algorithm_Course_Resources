#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int in;
    int out;
    int weight;
};

// 并查集
class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[rx] > rank[ry]) parent[ry] = rx;
        else { parent[ry] = rx; rank[rx]++; }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].in >> edges[i].out >> edges[i].weight;
    }

    // 按边权升序排序
    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(n);
    long long sum = 0;
    int cnt = 0;

    for (const edge& e : edges) {
        if (cnt == n - 1) break;
        if (dsu.find(e.in) != dsu.find(e.out)) {
            dsu.unite(e.in, e.out);
            sum += e.weight;
            cnt++;
        }
    }

    cout << sum << endl;
    return 0;
}