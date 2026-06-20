#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int ch, math, id;
    bool operator < (const Node &n1) const {
        if (n1.ch == ch && n1.math == math) return id < n1.id;
        else if (n1.ch == ch) return n1.math < math;
        return n1.ch < ch;
    }
};

const int N = 2000001;
Node a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].id >> a[i].ch >> a[i].math;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) cout << a[i].id << endl;
    return 0;
}
