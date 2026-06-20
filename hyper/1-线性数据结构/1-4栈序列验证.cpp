#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string pushSeq, popSeq;
    cin >> pushSeq >> popSeq;
    
    stack<char> st;
    string operations; // 记录操作序列
    
    int pushIndex = 0;
    int popIndex = 0;
    int n = pushSeq.length();
    
    // 模拟入栈出栈过程
    while (pushIndex < n) {
        // 入栈操作
        st.push(pushSeq[pushIndex]);
        operations += 'P';
        pushIndex++;
        
        // 检查是否可以出栈
        while (!st.empty() && popIndex < n && st.top() == popSeq[popIndex]) {
            st.pop();
            operations += 'O';
            popIndex++;
        }
    }
    
    // 判断是否完全匹配
    if (popIndex == n) {
        // 合法序列
        cout << "right" << endl;
        cout << operations << endl;
    } else {
        // 不合法序列，输出栈中剩余元素（从底到顶）
        cout << "wrong" << endl;
        
        // 需要将栈中元素从底到顶输出
        // 方法：将栈中元素转移到另一个栈，实现从底到顶的顺序
        stack<char> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        string remaining;
        while (!temp.empty()) {
            remaining += temp.top();
            temp.pop();
        }
        
        cout << remaining << endl;
    }
    
    return 0;
}