#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    // 处理 K 个发货序列
    while (K--)
    {
        vector<int> order(N);
        for (int i = 0; i < N; ++i) {
            cin >> order[i];
        }

        stack<int> st;
        int current = 1;    // 当前需要装填的颜色，从 1 开始
        bool ok = true;     // 标记是否能顺利完成

        for (int x : order)
        {
            // 把当前颜色放入货架
            st.push(x);

            // 货架满了，直接失败
            if (st.size() > M) {
                ok = false;
                // 这里不用 break，要把输入读完
            }

            // 循环检查栈顶是不是当前需要的
            while (!st.empty() && st.top() == current)
            {
                st.pop();
                current++;
            }
        }

        // 全部装填完成就是 YES，否则 NO
        if (ok && current == N + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}