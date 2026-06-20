#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    string op;
    int x;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            q.push(x);
        } else if (op == "query") {
            cout << q.front() << endl;
        } else if (op == "empty") {
            cout << (q.empty() ? "YES" : "NO") << endl;
        } else if (op == "pop") {
            q.pop();
        }
    }
    return 0;
}
