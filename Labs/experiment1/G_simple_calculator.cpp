#include <iostream>
#include <stack>
#include <map>
using namespace std;

stack<char> opstk;
stack<long long> numstk;
map<char, int> pri;
int ans1 = -1, ans2 = -1, opsz = 0, numsz = 0;
bool last = 1, flag = 1;
string ans = "";

long long getnum(const string& s) {
    long long a = 0;
    for (char ch : s) a = a * 10 + ch - '0';
    return a;
}

void cal(char op) {
    long long num2 = numstk.top(); numstk.pop();
    long long num1 = numstk.top(); numstk.pop();
    if (op == '+') numstk.push(num1 + num2);
    else if (op == '-') numstk.push(num1 - num2);
    else if (op == '*') numstk.push(num1 * num2);
    else if (op == '/') {
        if (num2 == 0) {
            cout << "error:" << num1 << "/" << num2 << endl;
            flag = 0;
            return;
        }
        numstk.push(num1 / num2);
    }
    numsz--;
}

void solve() {
    char c;
    while (cin >> c) {
        if (c >= '0' && c <= '9') {
            ans += c;
            last = 0;
        } else {
            last = 1;
            if (ans != "") {
                numstk.push(getnum(ans));
                numsz++;
                ans2 = max(ans2, numsz);
                ans = "";
            }
            if (c == '(') {
                opstk.push(c);
                opsz++;
                ans1 = max(ans1, opsz);
            } else if (c == ')') {
                while (opstk.top() != '(') {
                    char op = opstk.top(); opstk.pop(); opsz--;
                    cal(op);
                    if (!flag) return;
                }
                opstk.pop(); opsz--;
            } else {
                while (!opstk.empty() && opstk.top() != '(' && pri[opstk.top()] >= pri[c]) {
                    char op = opstk.top(); opstk.pop(); opsz--;
                    cal(op);
                    if (!flag) return;
                }
                opstk.push(c);
                opsz++;
                ans1 = max(ans1, opsz);
            }
        }
    }
    if (ans != "") {
        numstk.push(getnum(ans));
        numsz++;
        ans2 = max(ans2, numsz);
    }
    while (!opstk.empty()) {
        char op = opstk.top(); opstk.pop(); opsz--;
        cal(op);
        if (!flag) return;
    }
}

int main() {
    pri['+'] = 1; pri['-'] = 1;
    pri['*'] = 2; pri['/'] = 2;
    solve();
    if (flag) {
        cout << numstk.top() << endl;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
