#include <iostream>
#include <stack>
using namespace std;

const int N = 2000001;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) b[i] = max(a[i], b[i + 1]);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(a[i]);
        while (!st.empty() && st.top() > b[i + 1]) {
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}
