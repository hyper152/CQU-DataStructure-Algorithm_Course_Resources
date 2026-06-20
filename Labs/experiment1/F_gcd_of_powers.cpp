#include <iostream>
using namespace std;

const long long mod = 998244353;

long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

long long ksm(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long calc(long long a, long long b, long long c, long long d) {
    if (d < b) {
        swap(b, d);
        swap(a, c);
    }
    long long g = gcd(a, c);
    if (g == 1) return 1;
    return ksm(g, b) * calc(a / g, b, c, d - b) % mod;
}

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << calc(a, b, c, d) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
