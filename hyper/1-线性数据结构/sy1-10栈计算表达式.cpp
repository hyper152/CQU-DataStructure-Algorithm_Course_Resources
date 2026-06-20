#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;         // 数字个数

    stack<int> S1;    // 数字栈
    stack<char> S2;   // 运算符栈

    // 1. 把所有数字压入 S1
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        S1.push(num);
    }

    // 2. 把所有运算符压入 S2
    for (int i = 0; i < N - 1; i++) {
        char op;
        cin >> op;
        S2.push(op);
    }

    // 3. 开始按规则计算
    while (!S2.empty()) {
        // 弹出两个数字：顺序 n1, n2
        int n1 = S1.top(); S1.pop();
        int n2 = S1.top(); S1.pop();

        // 弹出一个运算符
        char op = S2.top(); S2.pop();

        int res;
        // 除法特判：分母是 n1！！！
        if (op == '/') {
            if (n1 == 0) {
                cout << "ERROR: " << n2 << "/0" << endl;
                return 0; // 直接结束程序
            }
            res = n2 / n1; // 整数除法
        }
        else if (op == '+') res = n2 + n1;
        else if (op == '-') res = n2 - n1;
        else if (op == '*') res = n2 * n1;

        // 结果压回栈
        S1.push(res);
    }

    // 输出最后结果
    cout << S1.top() << endl;
    return 0;
}