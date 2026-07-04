#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<int, int> count;  // 使用map自动按键排序
    int num;
    
    // 读取所有数字
    while (cin >> num) {
        count[num]++;
    }
    
    int maxCount = 0;
    int result = 0;
    
    // 遍历map（按键升序），找出出现次数最多的数
    for (const auto& pair : count) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            result = pair.first;
        }
    }
    
    cout << result << endl;
    
    return 0;
}