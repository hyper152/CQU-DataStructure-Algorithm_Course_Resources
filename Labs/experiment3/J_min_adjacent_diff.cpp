#include<iostream>
using namespace std;
#define int long long

int n, lst[1000005], mx = 0, sum = 0;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lst[i];
        sum += lst[i];
        mx = max(mx, lst[i]);
    }
    if (sum - mx <= mx) cout << mx << endl;
    else cout << (sum + 1) / 2 << endl;
    return 0;
}
