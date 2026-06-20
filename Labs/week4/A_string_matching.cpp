#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    map<char, int> pro = {{'<', 0}, {'(', 1}, {'[', 2}, {'{', 3}};
    map<char, char> zu = {{'>', '<'}, {')', '('}, {']', '['}, {'}', '{'}};

    for (int i = 0; i < n; i++) {
        stack<char> s;
        string f;
        getline(cin, f);
        bool ok = true;
        for (char ch : f) {
            if (pro.count(ch)) {
                if (!s.empty() && pro[ch] > pro[s.top()]) {
                    ok = false;
                    break;
                }
                s.push(ch);
            } else if (zu.count(ch)) {
                if (s.empty() || zu[ch] != s.top()) {
                    ok = false;
                    break;
                }
                s.pop();
            }
        }
        cout << (ok && s.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}
