#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int long long

int n, x, wpl = 0, tmp1, tmp2;
struct cmp {
    bool operator()(const int &x1, const int &x2) {
        return x1 > x2;
    }
};

priority_queue<int, vector<int>, cmp> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x, q.push(x);
    while (q.size() > 1) {
        tmp1 = q.top(), q.pop();
        tmp2 = q.top(), q.pop();
        wpl += (tmp1 + tmp2);
        q.push(tmp1 + tmp2);
    }
    cout << wpl << endl;
    return 0;
}
