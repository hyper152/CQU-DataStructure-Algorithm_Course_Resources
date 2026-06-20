/**
 * F - 单源最短路
 *
 * 题意：给定 n 个点、m 条带权有向边（或无向边），求从起点 s 到所有其他点的最短距离。
 * 思路：Dijkstra 算法（堆优化），适用于非负权图。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
const int N = 2e6 + 101;
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
};

vector<Edge> g[N];
ll dist[N];

void dijkstra(int s, int n) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    // 优先队列（小根堆）：(距离, 顶点)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;  // 已过时

        for (auto& e : g[u]) {
            int v = e.to;
            ll nd = d + e.w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;

    // 初始化
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // 如果是无向图，取消下面的注释：
        // g[v].push_back({u, w});
    }

    dijkstra(s, n);

    // 输出结果
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
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
