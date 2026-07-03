#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    vector<int> degree(n + 1, 0);
    int root = -1;
    int max_degree = 0;

    for (int i = 1; i <= n; ++i) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            root = i;
        } else {
            children[parent].push_back(i);
            degree[parent]++;
            if (degree[parent] > max_degree) {
                max_degree = degree[parent];
            }
        }
    }

    // 判断是否为 max_degree 阶满树
    bool is_full = true;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 0 && degree[i] != max_degree) {
            is_full = false;
            break;
        }
    }

    // 输出树的度与判断结果
    cout << max_degree << " " << (is_full ? "yes" : "no") << "\n";

    // 前序遍历（兄弟按编号升序），非递归实现
    for (int i = 1; i <= n; ++i) {
        sort(children[i].begin(), children[i].end());
    }

    vector<int> preorder;
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        preorder.push_back(u);
        // 逆序压栈，保证小的先访问
        for (auto it = children[u].rbegin(); it != children[u].rend(); ++it) {
            st.push(*it);
        }
    }

    for (size_t i = 0; i < preorder.size(); ++i) {
        if (i > 0) cout << " ";
        cout << preorder[i];
    }
    cout << "\n";

    return 0;
}