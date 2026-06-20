#include <iostream>
using namespace std;

int lst[1000005], cir[1000005];
bool vis[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lst[i];
    for (int i = 1; i <= n; i++) {
        if (lst[i] == i || vis[i]) continue;
        int res = 0, tmp = i;
        while (!vis[tmp]) {
            res++;
            vis[tmp] = 1;
            tmp = lst[tmp];
        }
        cir[res]++;
    }
    long long ans = 0;
    for (int i = 5; i <= n; i++) {
        ans += i * cir[i] / 3;
        if (i % 3 == 2) cir[2] += cir[i];
    }
    ans += (cir[2] + 1) / 2 + cir[3] + cir[4];
    cout << ans << endl;
    return 0;
}
