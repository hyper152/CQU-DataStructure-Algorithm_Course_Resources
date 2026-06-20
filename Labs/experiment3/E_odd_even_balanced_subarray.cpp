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
#include<fstream>
#define int long long
using namespace std;
const int N = 2e6 + 101;
int a[N];
int pre[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n + 1; i++) pre[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (a[i] & 1) pre[i]++;
        else pre[i]--;
    }
    set<pair<int, int>> st;
    st.insert({0, 0});
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        auto it = st.lower_bound({pre[i], -1});
        if (it != st.end() && it->first == pre[i])
            ans = max(ans, i - it->second);
        st.insert({pre[i], i});
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}
