/**
 * C - 气数已尽
 *
 * 题意：围棋棋盘上，'1' 表示棋子，'0' 表示空位。
 *       对每个由 '1' 组成的连通块，统计其"气"（即与它相邻的空位个数）。
 *       找到"气"最少的连通块，输出该连通块的大小和"气"数。
 *
 * 思路：DFS 找连通块，用 map 统计每个连通块周围的空位（去重）。
 */

#include <iostream>
#include <map>
#include <climits>
using namespace std;

const int MAXN = 1005;

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
map<pair<int, int>, int> mp;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
int ans1, ans2 = INT_MAX;
int cnt;  // 当前连通块的"气"数
int sz;   // 当前连通块的大小

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (grid[x][y] == '0' || visited[x][y]) return;

    visited[x][y] = true;
    sz++;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

        if (grid[xx][yy] == '0') {
            // 空位，算一口气（去重）
            if (mp[{xx, yy}] == 0) {
                cnt++;
                mp[{xx, yy}] = 1;
            }
        } else if (grid[xx][yy] == '1' && !visited[xx][yy]) {
            dfs(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                cnt = 0;
                sz = 0;
                dfs(i, j);

                // 更新"气"最少的连通块
                if (cnt < ans2) {
                    ans2 = cnt;
                    ans1 = sz;
                }

                mp.clear();
            }
        }
    }

    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}
