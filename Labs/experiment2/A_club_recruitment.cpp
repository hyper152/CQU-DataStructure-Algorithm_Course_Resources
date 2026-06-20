#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long x, y;
};

bool cmp(Node n1, Node n2) {
    return n1.x - n1.y > n2.x - n2.y;
}

Node lst[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lst[i].x >> lst[i].y;
    sort(lst + 1, lst + n + 1, cmp);
    long long ans = 0;
    for (int i = 1; i <= n / 2; i++) ans += lst[i].x;
    for (int i = n / 2 + 1; i <= n; i++) ans += lst[i].y;
    cout << ans << endl;
    return 0;
}
