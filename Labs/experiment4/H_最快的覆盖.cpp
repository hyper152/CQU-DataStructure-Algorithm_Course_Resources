/**
 * H - 最快的覆盖
 *
 * 题意：n × m 网格中，每个格子是 0 或 1。可以选择任意一个格子"激活"，
 *       它能覆盖所有与它曼哈顿距离 ≤ t 的格子。
 *       求最小的 t，使得存在一个格子能覆盖所有值为 1 的格子。
 *
 * 思路：二分答案 t。对于给定的 t：
 *       1. 多源 BFS 从所有已覆盖点出发，标记所有在距离 t 内能到达的点
 *       2. 收集所有未被覆盖的点
 *       3. 检查是否存在一个格子，到所有未被覆盖点的曼哈顿距离 ≤ t
 *       判断方法：只需考虑 max(x+y), min(x+y), max(x-y), min(x-y) 四个极值点
 *       时间复杂度 O(nm log(n+m))
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 101;

int n, m;
int a[N];
bool vis[N];
int dist[N];

struct node {
    int x, y;
};

vector<node> vec1, vec2;

bool cmp1(node n1, node n2) {
    return n1.x + n1.y < n2.x + n2.y;
}

bool cmp2(node n1, node n2) {
    return n1.x - n1.y < n2.x - n2.y;
}

int getid(int i, int j) {
    return (i - 1) * m + j;
}

bool check(int t) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getid(i, j);
            vis[id] = false;
            dist[id] = 1e18;
        }
    }

    // 多源 BFS，从所有值为 1 的格子出发
    queue<node> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getid(i, j);
            if (a[id] == 1) {
                q.push({i, j});
                dist[id] = 0;
            }
        }
    }

    while (!q.empty()) {
        node f = q.front();
        q.pop();

        int id = getid(f.x, f.y);
        if (dist[id] > t) break;
        if (vis[id]) continue;
        vis[id] = true;

        int xx = f.x, yy = f.y;
        if (xx + 1 <= n) {
            q.push({xx + 1, yy});
            dist[getid(xx + 1, yy)] = min(dist[getid(xx + 1, yy)], dist[id] + 1);
        }
        if (xx - 1 > 0) {
            q.push({xx - 1, yy});
            dist[getid(xx - 1, yy)] = min(dist[getid(xx - 1, yy)], dist[id] + 1);
        }
        if (yy + 1 <= m) {
            q.push({xx, yy + 1});
            dist[getid(xx, yy + 1)] = min(dist[getid(xx, yy + 1)], dist[id] + 1);
        }
        if (yy - 1 > 0) {
            q.push({xx, yy - 1});
            dist[getid(xx, yy - 1)] = min(dist[getid(xx, yy - 1)], dist[id] + 1);
        }
    }

    // 收集所有未被覆盖的点
    vec1.clear();
    vec2.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getid(i, j);
            if (!vis[id]) {
                vec1.push_back({i, j});
                vec2.push_back({i, j});
            }
        }
    }

    if (vec1.empty()) return true;

    // 按 x+y 和 x-y 排序找极值
    sort(vec1.begin(), vec1.end(), cmp1);
    sort(vec2.begin(), vec2.end(), cmp2);

    int mi = 1e18;

    // 枚举所有格子作为激活点，计算到所有未覆盖点的最大距离
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int mx = 0;
            int res;

            // 到 x+y 最小点的距离
            res = abs(i - vec1[0].x) + abs(j - vec1[0].y);
            mx = max(mx, res);

            // 到 x+y 最大点的距离
            res = abs(i - vec1.back().x) + abs(j - vec1.back().y);
            mx = max(mx, res);

            // 到 x-y 最小点的距离
            res = abs(i - vec2[0].x) + abs(j - vec2[0].y);
            mx = max(mx, res);

            // 到 x-y 最大点的距离
            res = abs(i - vec2.back().x) + abs(j - vec2.back().y);
            mx = max(mx, res);

            mi = min(mi, mx);
        }
    }

    return mi <= t;
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getid(i, j);
            cin >> a[id];
        }
    }

    int l = 0, r = m + n - 2;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
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
