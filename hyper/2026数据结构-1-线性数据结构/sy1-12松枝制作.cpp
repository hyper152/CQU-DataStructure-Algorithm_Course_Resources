#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int main() {
    int N, M, K;
    // 使用 cin 读取 N, M, K
    if (!(cin >> N >> M >> K)) return 0;

    // 用 deque 模拟推送器，支持 push_front 操作
    deque<int> pusher;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        pusher.push_back(temp);
    }

    stack<int> box; // 模拟小盒子

    // 当推送器里还有东西，或者盒子里还有东西时，继续制作松枝
    while (!pusher.empty() || !box.empty()) {
        vector<int> branch;
        
        while ((int)branch.size() < K) {
            // 1. 如果是第一片松针（枝干为空）
            if (branch.empty()) {
                if (!box.empty()) {
                    branch.push_back(box.top());
                    box.pop();
                } else if (!pusher.empty()) {
                    branch.push_back(pusher.front());
                    pusher.pop_front(); // 修正：deque 使用 pop_front
                } else {
                    break; // 全空了，结束
                }
            } 
            // 2. 如果枝干上已经有松针了
            else {
                int last = branch.back();
                
                // 优先检查盒子顶部
                if (!box.empty() && box.top() <= last) {
                    branch.push_back(box.top());
                    box.pop();
                } 
                // 盒子顶部的不能用，看推送器
                else if (!pusher.empty()) {
                    int p = pusher.front();
                    pusher.pop_front(); // 修正：deque 使用 pop_front
                    
                    if (p <= last) {
                        branch.push_back(p);
                    } else {
                        // 推送器拿到的不符合要求，尝试放进盒子
                        if ((int)box.size() < M) {
                            box.push(p);
                            // 注意：放进盒子后，当前位置没填，继续找适合这一位的松针
                            continue; 
                        } else {
                            // 盒子满了，压回推送器头部，结束这根松枝
                            pusher.push_front(p);
                            break;
                        }
                    }
                } 
                // 盒子顶部的没用，且推送器也空了
                else {
                    break;
                }
            }
        }

        // 输出当前做好的松枝信息
        if (!branch.empty()) {
            for (int i = 0; i < (int)branch.size(); ++i) {
                cout << branch[i] << (i == (int)branch.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}