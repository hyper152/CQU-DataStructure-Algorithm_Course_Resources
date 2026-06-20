#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Mooncake {
    double stock;   // 库存量（万吨）
    double total;   // 总售价（亿元）
    double price;   // 单价（亿元/万吨）
};

// 比较函数，用于按单价降序排序
bool compare(const Mooncake &a, const Mooncake &b) {
    return a.price > b.price;
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<Mooncake> mooncakes(N);

    // 读取库存量
    for (int i = 0; i < N; i++) {
        cin >> mooncakes[i].stock;
    }
    // 读取总售价并计算单价
    for (int i = 0; i < N; i++) {
        cin >> mooncakes[i].total;
        if (mooncakes[i].stock > 0) {
            mooncakes[i].price = mooncakes[i].total / mooncakes[i].stock;
        } else {
            mooncakes[i].price = 0; // 库存为0时单价为0
        }
    }

    // 按单价从高到低排序
    sort(mooncakes.begin(), mooncakes.end(), compare);

    double maxProfit = 0.0;
    int remainingDemand = D;

    // 贪心算法：优先卖单价高的月饼
    for (int i = 0; i < N && remainingDemand > 0; i++) {
        if (mooncakes[i].stock <= remainingDemand) {
            // 如果当前月饼库存小于等于需求量，全部卖出
            maxProfit += mooncakes[i].total;
            remainingDemand -= mooncakes[i].stock;
        } else {
            // 如果库存大于需求量，只卖出需求量的部分
            maxProfit += mooncakes[i].price * remainingDemand;
            remainingDemand = 0; // 需求满足，结束循环
        }
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2) << maxProfit << endl;

    return 0;
}