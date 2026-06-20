#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

// 定义括号的优先级
map<char, int> priority = {
    {'<', 1}, {'>', 1},
    {'(', 2}, {')', 2},
    {'[', 3}, {']', 3},
    {'{', 4}, {'}', 4}
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        bool ok = true;

        for (char ch : s) {
            // 左括号入栈
            if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
                // 检查嵌套顺序：如果栈非空，新左括号的优先级必须 >= 栈顶左括号的优先级
                if (!st.empty() && priority[ch] > priority[st.top()]) {
                    ok = false;
                    break;
                }
                st.push(ch);
            }
            // 右括号匹配
            else {
                if (st.empty()) {
                    ok = false;
                    break;
                }
                char top = st.top();
                // 检查是否匹配
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{') ||
                    (ch == '>' && top != '<')) {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (ok && st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}