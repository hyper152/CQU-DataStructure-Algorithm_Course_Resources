#include <iostream>
#include <vector>
#include <algorithm> // 包含 sort 函数
#include <cmath>     // 包含 floor 函数

using namespace std;

// 定义选手结构体
struct Volunteer {
    int id;    // 报名号
    int score; // 成绩
};

// 自定义排序比较函数
bool compareVolunteers(const Volunteer &a, const Volunteer &b) {
    if (a.score != b.score) {
        // 成绩不同时，按成绩降序排列
        return a.score > b.score;
    } else {
        // 成绩相同时，按报名号升序排列
        return a.id < b.id;
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Volunteer> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].id >> v[i].score;
    }

    // 1. 使用标准库提供的快速排序，时间复杂度 O(n log n)
    sort(v.begin(), v.end(), compareVolunteers);

    // 2. 计算录取人数的 150%（向下取整）
    int target_num = floor(m * 1.5);
    
    // 3. 确定分数线（数组下标从0开始，所以取第 target_num - 1 名）
    int line_score = v[target_num - 1].score;

    // 4. 统计实际进入面试的人数（因为已经排好序，只需统计 >= 分数线的）
    int actual_num = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].score >= line_score) {
            actual_num++;
        } else {
            break; // 后面的人成绩更低，直接跳出
        }
    }

    // 5. 输出第一行：分数线和实际人数
    cout << line_score << " " << actual_num << endl;

    // 6. 输出所有进入面试的选手信息
    for (int i = 0; i < actual_num; i++) {
        cout << v[i].id << " " << v[i].score << endl;
    }

    return 0;
}