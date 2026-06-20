#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in, out, ans = "";
    cin >> in >> out;
    int sz = in.size();
    stack<char> stk;
    bool flag = true;
    int i = 0, j = 0;
    while (true) {
        if (i == sz && j == sz) break;
        if (stk.empty()) {
            stk.push(in[i]);
            ans += 'P';
            i++;
        } else if (stk.top() == out[j]) {
            stk.pop();
            ans += 'O';
            j++;
        } else {
            if (i == sz) {
                flag = false;
                break;
            }
            stk.push(in[i]);
            ans += 'P';
            i++;
        }
    }
    if (flag) {
        cout << "right" << endl;
        cout << ans << endl;
    } else {
        cout << "wrong" << endl;
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        cout << res << endl;
    }
    return 0;
}
