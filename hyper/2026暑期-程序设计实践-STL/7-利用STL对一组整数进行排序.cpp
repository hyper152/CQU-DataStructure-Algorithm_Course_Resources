#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    vector<int> numbers;
    string line;
    
    // 读取整行
    getline(cin, line);
    
    stringstream ss(line);
    string token;
    
    // 逐个读取用空格分隔的字符串
    while (ss >> token) {
        // 检查是否为数字（可能包含负号）
        bool isNumber = true;
        int start = 0;
        
        // 处理负号
        if (token[0] == '-') {
            start = 1;
            if (token.length() == 1) {
                isNumber = false;  // 单独的负号不是数字
            }
        }
        
        // 检查剩余字符是否都是数字
        for (int i = start; i < token.length(); i++) {
            if (!isdigit(token[i])) {
                isNumber = false;
                break;
            }
        }
        
        if (isNumber) {
            numbers.push_back(stoi(token));
        } else {
            break;  // 遇到非数字，停止读取
        }
    }
    
    // 排序
    sort(numbers.begin(), numbers.end());
    
    // 输出（每个数字前加空格）
    for (int i = 0; i < numbers.size(); i++) {
        cout << " " << numbers[i];
    }
    cout << endl;
    
    return 0;
}