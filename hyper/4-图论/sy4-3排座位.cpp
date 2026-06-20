#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> parent;  // 全局并查集数组

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 递归路径压缩
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
        parent[rooty] = rootx;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    parent.resize(n + 1);  // 编号从1开始
    for (int i = 1; i <= n; i++) {
        parent[i] = i;  // 初始化每个节点的父节点为自身
    }
    
    vector<vector<int>> enemy(n + 1, vector<int>());
    
    for (int i = 0; i < m; i++) {
        int n1, n2, t;
        cin >> n1 >> n2 >> t;
        if (t == 1) {
            unite(n1, n2);  // 朋友关系合并
        }
        if (t == -1) {
            enemy[n1].push_back(n2);
            enemy[n2].push_back(n1);
        }
    }
    
    for (int i = 0; i < k; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        
        bool isFriend = (find(n1) == find(n2));  // 是否在同一个朋友圈
        bool isEnemy = false;
        
        // 检查是否是敌人
        auto it = find(enemy[n1].begin(), enemy[n1].end(), n2);
        if (it != enemy[n1].end()) {
            isEnemy = true;
        }
        
        if (isFriend && !isEnemy) {
            cout << "No problem" << endl;
        } else if (isFriend && isEnemy) {
            cout << "OK but..." << endl;
        } else if (!isFriend && isEnemy) {
            cout << "No way" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
    
    return 0;
}