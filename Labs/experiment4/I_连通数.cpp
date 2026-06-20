/**
 * I - 连通数
 *
 * 题意：给定一个 n × n 的邻接矩阵表示有向图，计算图中"连通数"——
 *       即所有有序对 (i, j) 中满足从 i 能到达 j 的对数。
 *
 * 思路：对每个起点 i 做 DFS，统计所有能到达的点数。
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2001;

vector<int> lst[MAXN];
int visited[MAXN];
int n;
int ans = 0;

void dfs(int x) {
    visited[x] = 1;
    for (size_t i = 0; i < lst[x].size(); i++) {
        int v = lst[x][i];
        if (!visited[v]) dfs(v);
    }
}

int main() {
    cin >> n;

    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '1') {
                lst[i].push_back(j);
            }
        }
    }

    // 对每个起点进行 DFS
    for (int i = 1; i <= n; i++) {
        // 重置 visited
        for (int p = 1; p <= n; p++) visited[p] = 0;

        dfs(i);

        // 统计从 i 能到达的所有点
        for (int j = 1; j <= n; j++) {
            ans += visited[j];
        }
    }

    cout << ans << endl;

    return 0;
}
