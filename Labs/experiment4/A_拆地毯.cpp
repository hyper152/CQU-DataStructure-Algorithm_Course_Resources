/**
 * A - 拆地毯
 * 最小生成树模板题（Kruskal 算法）
 *
 * 题意：给定 n 个点、m 条边，从中选出 K 条边形成一个森林（无环），
 *       使得选出的边权和最大。
 * 思路：按边权从大到小排序，用并查集维护连通性，贪心取边直到取满 K 条。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e6 + 101;

struct Edge {
    int u, v, w;
};

int parent[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

void solve() {
    int n, m, K;
    cin >> n >> m >> K;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 并查集初始化
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 按边权从大到小排序
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w > b.w;
    });

    int cnt = 0;   // 已选边数
    int ans = 0;   // 总权值
    for (auto& e : edges) {
        if (cnt >= K) break;
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            ans += e.w;
            cnt++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
