#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 并查集类：用于管理连通分量（家族）
class UnionFind {
private:    
    vector<int> parent; // 父节点数组
    vector<int> rank;   // 树的秩（高度优化）
    
public:
    // 构造函数：初始化 n 个独立元素
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // 每个节点自成一族，父节点为自己
        }
    }
    
    // 查找根节点（路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 递归路径压缩
        }
        return parent[x];
    }
    
    // 合并两个元素所在的集合
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // 按秩合并：将矮树合并到高树下
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++; // 树高增加
            }
        }
    }
    
    // 判断两个元素是否属于同一集合
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m; // n: 家庭数量, m: 关系数量
    cin >> n >> m;
    
    // 存储每个家庭的财富值
    vector<int> wealth(n);
    for (int i = 0; i < n; i++) {
        cin >> wealth[i];
    }
    
    // 初始化并查集
    UnionFind uf(n);
    
    // 读入连通关系并合并
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v); // 合并两个家庭所在的家族
    }
    
    // 使用map存储每个家族（根节点）下包含的所有家庭编号
    map<int, vector<int>> families;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);     // 找到家庭 i 的家族根节点
        families[root].push_back(i); // 将 i 加入该家族列表
    }
    
    // 存储每个家族的结果：最大财富值 和 对应的家庭编号
    vector<pair<int, int>> results;
    
    // 遍历每个家族
    for (auto& entry : families) {
        int maxWealth = -1; // 当前家族的最大财富
        int maxId = -1;     // 当前家族中财富最大的家庭编号（财富相同时取编号最小）
        
        // 找出该家族中财富最大的家庭
        for (int id : entry.second) {
            if (wealth[id] > maxWealth) {
                maxWealth = wealth[id];
                maxId = id;
            } else if (wealth[id] == maxWealth) {
                // 财富相同，选择编号更小的家庭
                if (id < maxId) {
                    maxId = id;
                }
            }
        }
        
        // 存储当前家族的结果
        results.push_back({maxWealth, maxId});
    }
    
    // 按家族中最大财富的家庭编号从小到大排序（题目要求输出顺序）
    sort(results.begin(), results.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // 按家庭编号升序
    });
    
    // 输出每个家族的结果
    for (auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}