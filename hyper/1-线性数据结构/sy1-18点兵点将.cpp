#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // 前缀最大子段和
    vector<long long> pre_max(n);
    long long cur = arr[0];
    pre_max[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        cur = max(arr[i], cur + arr[i]);
        pre_max[i] = max(pre_max[i-1], cur);
    }

    // 后缀最大子段和
    vector<long long> suf_max(n);
    cur = arr[n-1];
    suf_max[n-1] = arr[n-1];
    for (int i = n - 2; i >= 0; --i) {
        cur = max(arr[i], arr[i] + cur);   // 以 i 开头的最大子段和
        suf_max[i] = max(suf_max[i+1], cur);
    }

    // 枚举分界点（i 为左段最后一个元素下标）
    long long ans = LLONG_MIN;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, pre_max[i] + suf_max[i+1]);
    }

    cout << ans << endl;
    return 0;
}   