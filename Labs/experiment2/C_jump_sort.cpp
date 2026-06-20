#include <iostream>
#include <cstdlib>
using namespace std;

int lst[100005];

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

int main() {
    int n, k, g = 0;
    bool flag = false;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> lst[i];
        if (lst[i] - i == 0) continue;
        if (!flag) g = abs(lst[i] - i), flag = true;
        else g = gcd(g, abs(lst[i] - i));
    }
    while (k--) {
        int tmp;
        cin >> tmp;
        if (g % tmp == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
