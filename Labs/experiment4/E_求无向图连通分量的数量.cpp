/**
 * E - 求无向图连通分量的数量
 *
 * 题意：给定 n 个点、m 条边的无向图，求图中连通分量的个数。
 * 思路：用邻接表建图，DFS 遍历所有连通分量。
 */

#include <iostream>
#include <vector>
using namespace std;

const int N = 2e6 + 101;

vector<int> g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }

    // 建图
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 统计连通分量数
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
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
