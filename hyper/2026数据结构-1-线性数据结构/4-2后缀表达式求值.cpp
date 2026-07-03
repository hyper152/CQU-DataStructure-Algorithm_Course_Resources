#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    
    vector<string> tokens;
    stringstream ss(line);
    string token;
    
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    stack<int> st;  // 改为 int 栈，因为只取整数部分
    bool ok = true;
    
    for (size_t i = 0; i < tokens.size(); i++) {
        string t = tokens[i];
        
        if (t == "#") {
            break;
        }
        
        // 如果是数字
        if (isdigit(t[0]) || (t[0] == '-' && t.length() > 1)) {
            st.push(stoi(t));  // 改为 stoi，直接转整数
        }
        // 如果是运算符
        else if (t == "+" || t == "-" || t == "*" || t == "/") {
            if (st.size() < 2) {
                ok = false;
                break;
            }
            
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result;
            
            if (t == "+") {
                result = a + b;
            }
            else if (t == "-") {
                result = a - b;
            }
            else if (t == "*") {
                result = a * b;
            }
            else if (t == "/") {
                if (b == 0) {
                    cout << "Error: " << a << "/0";
                    return 0;
                }
                // 关键：除法只取整数部分（向零取整）
                result = a / b;
            }
            
            st.push(result);
        }
    }
    
    // 检查表达式是否正确
    if (!ok || st.size() != 1) {
        if (st.empty()) {
            cout << "Expression Error";
        } else {
            cout << "Expression Error: " << st.top();
        }
    } else {
        cout << st.top();
    }
    
    return 0;
}