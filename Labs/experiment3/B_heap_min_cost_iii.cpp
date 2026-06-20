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
const int N = 1e7 + 101;
int a[N], b[N];
int n, m;

bool check(int mid) {
    __int128 res = 0;
    int j = 1;
    bool flag = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (flag) {
            res += (__int128)a[j] * b[i];
            j++;
        } else if (mid > a[j]) {
            res += (__int128)mid * b[i];
            flag = 1;
        } else {
            res += (__int128)a[j] * b[i];
            j++;
        }
        if (res >= m) return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= n + 2; i++) a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) cin >> b[i];
    sort(a + 1, a + n + 1, greater<int>());
    sort(b + 1, b + n + 2, greater<int>());
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}
