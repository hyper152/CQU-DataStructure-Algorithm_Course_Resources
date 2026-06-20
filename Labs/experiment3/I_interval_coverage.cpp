#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#define maxn 100005
using namespace std;
typedef long long ll;

int read() {
    int x = 0, f = 1, ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int n, m, k;
struct node {
    int l, r, id;
} a[maxn];

bool cmp(node a, node b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
}

priority_queue<pair<int, int> > q;

signed main() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        a[i].l = read(), a[i].r = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + m, cmp);
    a[m + 1] = {n + 1, n + 1, m + 1};
    ll ans = 0;
    int pre = 0;
    for (int i = 1; i <= m; i++) {
        q.push(make_pair(-a[i].l, -a[i].r));
        while (a[i].r == a[i + 1].r) i++, q.push(make_pair(-a[i].l, -a[i].r));
        while (q.size() > k || pre == -q.top().first) {
            pre = -q.top().first, q.pop();
            if (!q.size()) break;
        }
        int L = a[i].r - pre, R = a[i + 1].r - pre - 1;
        ans += 1ll * (L + R) * (a[i + 1].r - a[i].r) / 2;
    }
    cout << ans + 1ll * a[1].r * (a[1].r - 1) / 2 << endl;
    return 0;
}
