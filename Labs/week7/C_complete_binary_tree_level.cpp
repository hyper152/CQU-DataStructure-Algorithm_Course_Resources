#include <iostream>
using namespace std;

const int N = 2000001;
int a[N], post[N], mp[N], idx = 0, n;

void postorder(int x) {
    if (x > n) return;
    postorder(x * 2);
    postorder(x * 2 + 1);
    post[++idx] = x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    postorder(1);
    for (int i = 1; i <= n; i++) mp[post[i]] = a[i];
    for (int i = 1; i <= n; i++) {
        cout << mp[i];
        if (i == n) cout << endl;
        else cout << " ";
    }
    return 0;
}
