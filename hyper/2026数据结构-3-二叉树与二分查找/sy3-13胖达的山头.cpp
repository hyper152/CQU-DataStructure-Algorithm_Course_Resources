#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// —— 工具函数：将 "hh:mm:ss" 格式的时间字符串转换为总秒数 ——
// 例如 "00:01:30" → 90
int to_seconds(const string& t) {
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // —— 输入 ——
    int n;
    cin >> n;

    vector<int> starts(n), ends(n);
    string s1, s2;

    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;                // 读入起始时间和结束时间
        starts[i] = to_seconds(s1);
        ends[i] = to_seconds(s2);
    }

    // —— 扫描线算法（Sweep Line）求最大重叠区间数 ——
    // 分别排序：我们只关心时间轴上的先后顺序，不关心哪个开始对应哪个结束
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    // i: 指针扫描 starts[]，指向下一个"开始事件"
    // j: 指针扫描 ends[]，   指向下一个"结束事件"
    // cur: 当前扫描线上有多少个区间同时覆盖
    // max_overlap: 历史峰值
    int i = 0, j = 0;
    int cur = 0;
    int max_overlap = 0;

    // 当还有开始事件未处理时继续扫描
    while (i < n) {
        // 条件1：所有结束事件已处理完 (j == n)，剩下的全是开始事件
        // 条件2：下一个开始 ≤ 下一个结束 → 先处理开始事件（区间左闭右闭语义）
        if (j == n || starts[i] <= ends[j]) {
            ++cur;                       // 新山头出现，活跃数 +1
            if (cur > max_overlap) max_overlap = cur;  // 更新峰值
            ++i;                         // 移动开始指针
        } else {
            // 下一个结束事件更早 → 先处理结束事件
            --cur;                       // 有山头结束，活跃数 -1
            ++j;                         // 移动结束指针
        }
        // 注意：每轮循环只处理一个事件（开始或结束），保证算法 O(n)
    }

    // —— 输出 ——
    int xpmclzjkln = max_overlap;   // 按题目要求存储中间值
    cout << xpmclzjkln << '\n';

    return 0;
}