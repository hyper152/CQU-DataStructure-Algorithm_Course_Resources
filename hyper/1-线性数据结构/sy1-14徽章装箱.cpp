#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

const int MAXN = 100010;
int box[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    // 读入盒子编号
    for (int i = 0; i < N; ++i)
    {
        cin >> box[i];
    }

    unordered_map<int, int> mp;
    stack<int> st;
    int pos = 0;
    int batch = N / S;

    // 分批入栈、装箱
    for (int i = 0; i < batch; ++i)
    {
        // 入栈 S 个徽章
        for (int j = 0; j < S; ++j)
        {
            int x;
            cin >> x;
            st.push(x);
        }

        // 出栈装箱
        while (!st.empty())
        {
            mp[box[pos++]] = st.top();
            st.pop();
        }
    }

    // 查询
    int Q;
    cin >> Q;
    while (Q--)
    {
        int x;
        cin >> x;
        if (mp.find(x) != mp.end())
            cout << mp[x] << '\n';
        else
            cout << "Wrong Number\n";
    }

    return 0;
}
