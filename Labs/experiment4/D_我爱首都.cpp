/**
 * D - 我爱首都
 *
 * 题意：给定 n 个城市、m 条带权无向边。
 *       选择一个城市作为首都，要求它到所有其他城市的最短距离之和最小。
 *       若有多个解，输出编号最小的城市。
 *
 * 思路：Floyd-Warshall 求全源最短路，然后枚举每个城市计算总距离。
 */

#include <iostream>
#include <climits>
using namespace std;

const int INF = 1e18;
const int MAXN = 110;

long long dist[MAXN][MAXN];

void solve() {
    int n, m;
    cin >> n >> m;

    // 初始化距离矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = min(dist[u][v], (long long)d);
        dist[v][u] = min(dist[v][u], (long long)d);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 找总距离最小的城市
    long long min_sum = INF;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        bool valid = true;

        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                valid = false;
                break;
            }
            sum += dist[i][j];
        }

        if (valid) {
            if (sum < min_sum) {
                min_sum = sum;
                ans = i;
            } else if (sum == min_sum && (ans == 0 || i < ans)) {
                ans = i;
            }
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
