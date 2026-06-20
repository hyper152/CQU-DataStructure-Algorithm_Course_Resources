#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == 2) {
                if (n / i == 2) continue;
                p = min(p, n / i);
            } else {
                p = min(p, i);
                break;
            }
        }
    }
    cout << n / p << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
