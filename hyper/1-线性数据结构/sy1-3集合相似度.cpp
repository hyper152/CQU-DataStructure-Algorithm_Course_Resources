#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 存储所有集合，每个集合用set存储（自动去重）
    vector<set<int>> sets(n);
    
    // 读取每个集合
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            sets[i].insert(num);  // set自动去重
        }
    }
    
    // 处理查询
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // 转换为0-based索引
        
        // 计算交集元素个数
        int nc = 0;
        // 遍历较小的集合可以提高效率
        if (sets[a].size() <= sets[b].size()) {
            for (int num : sets[a]) {
                if (sets[b].count(num)) {
                    nc++;
                }
            }
        } else {
            for (int num : sets[b]) {
                if (sets[a].count(num)) {
                    nc++;
                }
            }
        }
        
        // 计算并集元素个数
        int nt = sets[a].size() + sets[b].size() - nc;
        
        // 计算相似度
        double similarity = (double)nc / nt * 100;
        
        // 输出结果，保留2位小数
        cout << fixed << setprecision(2) << similarity << "%" << endl;
    }
    
    return 0;
}