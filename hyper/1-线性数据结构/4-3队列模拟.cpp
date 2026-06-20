#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int M;
    cin >> M;
    
    queue<int> q;
    string op;
    
    while (M--) {
        cin >> op;
        
        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == "pop") {
            q.pop();
        }
        else if (op == "empty") {
            if (q.empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else if (op == "query") {
            cout << q.front() << endl;
        }
    }
    
    return 0;
}