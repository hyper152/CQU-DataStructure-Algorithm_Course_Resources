#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10000; // 站点编号最大可能 9999

struct Edge {
    int to;
    int company; // 这条边属于哪家公司
};

struct PreNode {
    int from;
    int company;
    int transfers; // 到当前节点的换乘次数
};

int main() {
    int N;
    cin >> N;
    
    vector<vector<Edge>> graph(MAXN);
    
    // 读入每家公司线路，并建图
    for (int c = 1; c <= N; c++) {
        int M;
        cin >> M;
        vector<int> stations(M);
        for (int i = 0; i < M; i++) {
            cin >> stations[i];
        }
        // 相邻站点之间建双向边，记录公司编号
        for (int i = 0; i < M - 1; i++) {
            int u = stations[i], v = stations[i + 1];
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }
    }
    
    int K;
    cin >> K;
    
    while (K--) {
        int start, target;
        cin >> start >> target;
        
        if (start == target) {
            cout << 0 << endl;
            // 起点终点相同，无需换乘
            continue;
        }
        
        // BFS：dist记录经停站数量，transfers记录换乘次数
        vector<int> dist(MAXN, -1);
        vector<int> transfers(MAXN, 1e9);
        vector<PreNode> pre(MAXN, {-1, -1, 0});
        
        queue<int> q;
        dist[start] = 0;
        transfers[start] = 0;
        q.push(start);
        
        bool found = false;
        
        while (!q.empty() && !found) {
            int u = q.front();
            q.pop();
            
            for (const Edge& e : graph[u]) {
                int v = e.to;
                int comp = e.company;
                
                // 计算新的换乘次数：如果u不是起点且公司不同，则换乘+1
                int newTransfers = transfers[u];
                if (u != start) {
                    int prevComp = pre[u].company;
                    if (prevComp != comp) {
                        newTransfers++;
                    }
                }
                
                // 如果v未访问，或者经停站更少，或者经停站相同但换乘更少
                if (dist[v] == -1 || 
                    dist[u] + 1 < dist[v] || 
                    (dist[u] + 1 == dist[v] && newTransfers < transfers[v])) {
                    
                    dist[v] = dist[u] + 1;
                    transfers[v] = newTransfers;
                    pre[v] = {u, comp, transfers[v]};
                    q.push(v);
                    
                    if (v == target) {
                        found = true;
                        // 不能直接break，因为可能还有更优路径，但BFS保证第一次遇到就是最优（经停最少）
                        // 但换乘最少需要相同层比较，所以这里不break，继续处理完当前层？
                        // 标准BFS：第一次访问到target时，dist一定最小，但换乘不一定最小，所以必须继续
                        // 但为了效率，可以标记，但继续处理。
                    }
                }
            }
        }
        
        if (dist[target] == -1) {
            cout << "Sorry, no line is available." << endl;
        } else {
            // 输出经停站数量
            cout << dist[target] << endl;
            
            // 回溯路径，得到换乘点
            vector<int> path; // 存储路径上的站点（包括起点和终点）
            int cur = target;
            while (cur != -1) {
                path.push_back(cur);
                cur = pre[cur].from;
            }
            reverse(path.begin(), path.end());
            
            // 输出格式：从path[0]到path[last]，分段输出
            int curCompany = pre[path[1]].company; // 第一段的公司
            int segStart = path[0];
            
            for (int i = 1; i < path.size(); i++) {
                int node = path[i];
                int comp = (i < path.size() - 1) ? pre[path[i + 1]].company : -1;
                
                // 如果是最后一个节点，或者公司发生变化，则输出一段
                if (i == path.size() - 1 || comp != curCompany) {
                    cout << "Go by the line of company #" << curCompany 
                         << " from " << segStart << " to " << node << "." << endl;
                    if (i < path.size() - 1) {
                        segStart = node;
                        curCompany = comp;
                    }
                }
            }
        }
    }
    
    return 0;
}