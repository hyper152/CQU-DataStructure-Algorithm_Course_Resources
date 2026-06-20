#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2000001;
struct Node {
    long long w, v, c;
} a[N];

bool cmp(Node n1, Node n2) {
    return n2.c * n1.w < n1.c * n2.w;
}

long long suf[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v >> a[i].c;
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i].w;
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i].v - a[i].c * suf[i + 1];
    cout << ans << endl;
    return 0;
}
