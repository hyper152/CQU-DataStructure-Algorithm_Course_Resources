#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> ss;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ss.insert({a, b});
    }
    for (int i = 2; i <= n; i++) {
        if (!ss.count({i - 1, i})) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
