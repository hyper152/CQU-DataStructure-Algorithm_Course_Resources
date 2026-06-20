#include <iostream>
using namespace std;

int lst[1000005];
bool vis[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lst[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (lst[i] == i || vis[i]) continue;
        int res = 0, tmp = i;
        if (i == 1) res--;
        else res++;
        while (!vis[tmp]) {
            res++;
            vis[tmp] = 1;
            tmp = lst[tmp];
        }
        ans += res;
    }
    cout << ans << endl;
    return 0;
}
