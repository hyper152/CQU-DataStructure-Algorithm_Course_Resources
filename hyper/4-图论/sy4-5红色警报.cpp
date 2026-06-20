#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

const int INF = INT_MAX / 2;

// 统计连通分量数（忽略已删除的节点）
int count(int n, vector<vector<int>>& edges, vector<bool>& destroyed) {
    vector<bool> vis(n, false);
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        if (!destroyed[i] && !vis[i]) {
            components++;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            
            while (!q.empty()) {
                int p = q.front();
                q.pop();
                
                for (int t : edges[p]) {
                    if (!destroyed[t] && !vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(n);
    vector<bool> destroyed(n, false);  // 标记城市是否已被攻占
    
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    
    // 计算初始连通分量数
    int prev_components = count(n, edges, destroyed);
    
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        
        // 标记城市为已删除
        destroyed[v] = true;
        
        // 计算删除后的连通分量数（忽略已删除节点）
        int curr_components = count(n, edges, destroyed);
        
        // 判断连通性是否改变
        // 注意：如果删除后城市总数为0，说明没有剩余城市了
        int remaining = n - (i + 1);
        
        if (remaining == 0) {
            // 所有城市都被攻占了，先输出最后一个城市的信息，最后输出Game Over
            if (curr_components > prev_components) {
                cout << "Red Alert: City " << v << " is lost!" << endl;
            } else {
                cout << "City " << v << " is lost." << endl;
            }
            cout << "Game Over." << endl;
            break;
        }
        
        if (curr_components > prev_components) {
            // 连通分量增加，说明改变了其他城市的连通性
            cout << "Red Alert: City " << v << " is lost!" << endl;
        } else {
            // 连通分量未增加或减少（孤立城市被删除可能减少）
            cout << "City " << v << " is lost." << endl;
        }
        
        prev_components = curr_components;
    }
    
    return 0;
}