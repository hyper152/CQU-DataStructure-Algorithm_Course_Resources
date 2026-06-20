#include <iostream>
#include <stack>
using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> s1, s2;
    while (n--) {
        char op;
        cin >> op;
        if (op == 'I') {
            int num;
            cin >> num;
            s1.push(num);
        } else {
            if (s2.empty()) {
                if (s1.empty()) {
                    cout << "ERROR" << endl;
                } else {
                    int t = 0;
                    while (!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                        t += 2;
                    }
                    t++;
                    cout << s2.top() << " " << t << endl;
                    s2.pop();
                }
            } else {
                cout << s2.top() << " 1" << endl;
                s2.pop();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
