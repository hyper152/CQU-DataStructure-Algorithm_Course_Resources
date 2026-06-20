#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 2000001;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> f, b;
    for (int i = 1; i <= n; i++) {
        f.push_back(1LL * a[i] * a[i] + 1LL * i * i);
        b.push_back(1LL * a[i] * a[i] - 1LL * i * i);
    }
    sort(f.begin(), f.end());
    sort(b.begin(), b.end());
    cout << max(llabs(f[0] - f[n - 1]), llabs(b[0] - b[n - 1])) << endl;
    return 0;
}
