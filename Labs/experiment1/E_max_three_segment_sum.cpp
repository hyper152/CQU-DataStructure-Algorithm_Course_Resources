#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10000001;
int a[N], presum[N], mipresum[N], resl[N];
int sufsum[N], misufsum[N], resr[N];

void solve() {
    int n;
    cin >> n;
    fill(a, a + n + 2, 0);
    fill(presum, presum + n + 2, 0);
    fill(mipresum, mipresum + n + 2, 0);
    fill(resl, resl + n + 2, 0);
    fill(sufsum, sufsum + n + 2, 0);
    fill(misufsum, misufsum + n + 2, 0);
    fill(resr, resr + n + 2, 0);
    resl[0] = -1e18;
    resr[n + 1] = -1e18;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) presum[i] = presum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) mipresum[i] = min(mipresum[i - 1], presum[i]);
    for (int i = 1; i <= n; i++) resl[i] = max(resl[i - 1], presum[i] - mipresum[i - 1]);

    for (int i = n; i >= 1; i--) sufsum[i] = sufsum[i + 1] + a[i];
    for (int i = n; i >= 1; i--) misufsum[i] = min(misufsum[i + 1], sufsum[i]);
    for (int i = n; i >= 1; i--) resr[i] = max(resr[i + 1], sufsum[i] - misufsum[i + 1]);

    long long ans = -1e18;
    for (int i = 1; i <= n; i++) {
        if (i - 2 < 1 || i + 2 > n) continue;
        ans = max(ans, a[i] + resl[i - 2] + resr[i + 2]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
