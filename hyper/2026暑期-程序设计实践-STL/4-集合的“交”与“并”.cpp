#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    set<int> set1, set2;
    
    // 读取第一个集合
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        set1.insert(num);
    }
    
    // 读取第二个集合
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        set2.insert(num);
    }
    
    // 计算交集
    set<int> intersection;
    for (int num : set1) {
        if (set2.find(num) != set2.end()) {
            intersection.insert(num);
        }
    }
    
    // 计算并集
    set<int> union_set = set1;
    for (int num : set2) {
        union_set.insert(num);
    }
    
    // 输出交集
    if (intersection.empty()) {
        cout << 0 << endl;
    } else {
        cout << intersection.size();
        for (int num : intersection) {
            cout << " " << num;
        }
        cout << endl;
    }
    
    // 输出并集
    if (union_set.empty()) {
        cout << 0 << endl;
    } else {
        cout << union_set.size();
        for (int num : union_set) {
            cout << " " << num;
        }
        cout << endl;
    }
    
    return 0;
}