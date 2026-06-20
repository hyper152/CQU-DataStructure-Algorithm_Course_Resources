#include <iostream>
#include <stack>
using namespace std;

const int N = 2000001;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> st;
    int expected = 1, count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == expected) count++, expected++;
        else st.push(a[i]);
        while (!st.empty() && st.top() == expected) st.pop(), expected++;
    }
    while (!st.empty() && st.top() == expected) st.pop(), expected++;
    if (expected == n + 1) cout << "Yes" << endl << count << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
