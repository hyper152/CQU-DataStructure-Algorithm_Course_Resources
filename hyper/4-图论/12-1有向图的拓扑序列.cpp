#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> indeg(N + 1, 0);
    
    // 构建邻接表（头插法）
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(adj[u].begin(), v); // 插入到头部
        indeg[v]++;
    }
    
    stack<int> st;
    // 初始入度为0的节点入栈（题目保证只有一个）
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            st.push(i);
        }
    }
    
    int count = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        count++;
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                st.push(v);
            }
        }
    }
    
    // 输出结果
    if (count == N) {
        cout << endl;
    } else {
        cout << endl << "0" << endl;
    }
    
    return 0;
}