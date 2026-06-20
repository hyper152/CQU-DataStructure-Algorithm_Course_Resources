#include <iostream>
using namespace std;

// 递归函数计算阶乘
int factorial(int n) {
    // 递归基：0! = 1
    if (n == 0) {
        return 1;
    }
    // 递归调用：n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    // 计算并输出阶乘
    cout << factorial(n) << endl;
    
    return 0;
}