#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 加速输入输出
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> tails;  // tails[i] 表示长度为 i+1 的递增子序列的最小末尾
    
    for (int i = 0; i < n; i++) {
        // 二分查找第一个大于 arr[i] 的位置
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        
        if (it == tails.end()) {
            tails.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    
    cout << tails.size() << endl;
    
    return 0;
}