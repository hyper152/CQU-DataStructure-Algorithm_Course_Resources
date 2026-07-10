#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断在给定最大时间限制下，能否用不超过m个GPU完成训练
bool canFinish(const vector<long long>& a, int m, long long maxTime) {
    int gpuCount = 1;  // 当前使用的GPU数量
    long long currentSum = 0;  // 当前GPU的训练总时间
    
    for (int i = 0; i < a.size(); i++) {
        // 如果单个模型时间就超过了限制，无法完成
        if (a[i] > maxTime) return false;
        
        // 如果当前GPU加上这个模型后超过限制，需要新GPU
        if (currentSum + a[i] > maxTime) {
            gpuCount++;
            currentSum = a[i];
        } else {
            currentSum += a[i];
        }
    }
    
    return gpuCount <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    long long maxVal = 0;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
        sum += a[i];
    }
    
    // 二分查找最小的最大完成时间
    long long left = maxVal;
    long long right = sum;
    long long result = sum;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canFinish(a, m, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}