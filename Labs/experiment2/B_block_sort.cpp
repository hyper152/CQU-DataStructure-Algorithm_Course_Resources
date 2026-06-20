#include <iostream>
using namespace std;

int lst[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lst[i];
    int mx = -1, ans = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, lst[i]);
        if (mx == i) ans++;
    }
    cout << ans << endl;
    return 0;
}
