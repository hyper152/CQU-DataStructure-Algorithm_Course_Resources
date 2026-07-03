#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S_max;
    if (!(cin >> N >> M >> S_max)) return 0;

    // 使用 vector 存储 N 条轨道，每条轨道是一个字符队列
    vector<queue<char>> tracks(N + 1);
    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            tracks[i].push(c);
        }
    }

    stack<char> basket; // 筐（栈结构）
    string conveyor = ""; // 流水线结果

    int op;
    // 循环处理操作指令，直到遇到 -1
    while (cin >> op && op != -1) {
        if (op == 0) {
            // 操作 0：从筐中取一件物品放到流水线
            if (!basket.empty()) {
                conveyor += basket.top();
                basket.pop();
            }
        } else if (op >= 1 && op <= N) {
            // 操作 1-N：从对应轨道推入筐中
            if (!tracks[op].empty()) {
                // 特殊情况：如果筐满了，先强制将筐顶物品弹出到流水线
                if (basket.size() == S_max) {
                    conveyor += basket.top();
                    basket.pop();
                }
                // 将轨道前端物品移入筐顶
                basket.push(tracks[op].front());
                tracks[op].pop();
            }
        }
    }

    // 输出最终流水线上的物品
    cout << conveyor << endl;

    return 0;
}