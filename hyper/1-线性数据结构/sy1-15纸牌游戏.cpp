#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int Ailce_sum = 0;
    int Bob_sum = 0;
    
    // 使用 vector 代替数组，保证兼容性并方便处理
    vector<string> Ailce(n);
    vector<string> Bob(n);
    // st 作为牌堆，使用 vector 以便查找内部元素
    vector<string> st;

    for (int i = 0; i < n; i++) {
        cin >> Ailce[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Bob[i];
    }

    // ==================== 按回合轮流出牌 ====================
    for (int i = 0; i < n; i++) {

        // ========== 1. Alice 出牌 ==========
        {
            string card = Ailce[i];
            int found_idx = -1;
            // 从牌堆顶部（vector末尾）向下寻找第一个点数相同的牌
            for (int j = (int)st.size() - 1; j >= 0; j--) {
                if (st[j][0] == card[0]) {
                    found_idx = j;
                    break;
                }
            }

            if (found_idx != -1) {
                // 存在相同大小的牌，开始判定得分
                unordered_map<string, bool> b = {{"C",0},{"D",0},{"H",0},{"S",0}};
                int cnt = 0;
                // 从顶部取到该牌为止
                for (int j = (int)st.size() - 1; j >= found_idx; j--) {
                    string t = st[j];
                    b[string(1, t[1])] = true;
                    cnt++;
                }
                int col = 0;
                for (auto& p : b) if (p.second) col++;
                Ailce_sum += cnt * col;
                
                // 将这些牌从牌堆移除（弃置）
                st.erase(st.begin() + found_idx, st.end());
            }
            // 判定结束后，将当前牌放至牌堆顶部
            st.push_back(card);
        }

        // ========== 2. Bob 出牌 ==========
        {
            string card = Bob[i];
            int found_idx = -1;
            for (int j = (int)st.size() - 1; j >= 0; j--) {
                if (st[j][0] == card[0]) {
                    found_idx = j;
                    break;
                }
            }

            if (found_idx != -1) {
                unordered_map<string, bool> b = {{"C",0},{"D",0},{"H",0},{"S",0}};
                int cnt = 0;
                for (int j = (int)st.size() - 1; j >= found_idx; j--) {
                    string t = st[j];
                    b[string(1, t[1])] = true;
                    cnt++;
                }
                int col = 0;
                for (auto& p : b) if (p.second) col++;
                Bob_sum += cnt * col;
                
                st.erase(st.begin() + found_idx, st.end());
            }
            st.push_back(card);
        }
    }

    cout << Ailce_sum << " " << Bob_sum << endl;
    return 0;
}