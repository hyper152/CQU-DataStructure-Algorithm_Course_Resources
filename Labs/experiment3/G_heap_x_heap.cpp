#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, d, K, cnt[200005];

int ksm(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans *= a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

struct node {
    int a = 0, k = 0, idx = 0;
    bool operator < (const node& nd) const {
        if (k >= nd.k) {
            if (a * ksm(d, k - nd.k) == nd.a) return idx > nd.idx;
            return a * ksm(d, k - nd.k) > nd.a;
        } else {
            if (a == nd.a * ksm(d, nd.k - k)) return idx > nd.idx;
            return a > nd.a * ksm(d, nd.k - k);
        }
    }
};

priority_queue<node> q;
node mx;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d >> K;
    int x; node nd;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        nd.a = x, nd.k = 0, nd.idx = i;
        q.push(nd);
        mx = min(mx, nd);
    }
    while (K--) {
        nd = q.top(); q.pop();
        nd.k++, cnt[nd.idx]++, q.push(nd);
        if (nd < mx) break;
    }
    int lft = K % n;
    while (lft--) {
        nd = q.top(); q.pop();
        cnt[nd.idx] += K / n + 1;
    }
    while (!q.empty()) {
        nd = q.top(); q.pop();
        cnt[nd.idx] += K / n;
    }
    for (int i = 1; i < n; i++) cout << cnt[i] << " ";
    cout << cnt[n] << endl;
    return 0;
}
