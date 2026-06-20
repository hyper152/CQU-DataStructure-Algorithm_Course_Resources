#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 998244353;
const int N = 2e6 + 101;
int a[N];
pair<bool, int> q[N];
int ans[N];

void solve() {
    int n, m, Q; cin >> n >> m >> Q;
    for (int i = 0; i <= n + 1; i++) q[i].first = 0, q[i].second = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int r, w; cin >> r >> w;
        q[r].first = 1, q[r].second += w;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        if (q[i].first) {
            int t = pq.top(); pq.pop();
            pq.push(t - q[i].second);
        }
    }
    int sum = 0, idx = 1;
    while (!pq.empty()) {
        int t = pq.top(); pq.pop();
        sum += t;
        ans[idx] = sum;
        idx++;
    }
    while (Q--) {
        int k; cin >> k;
        cout << -ans[k] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
