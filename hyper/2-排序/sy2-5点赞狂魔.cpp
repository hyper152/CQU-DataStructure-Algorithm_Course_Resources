#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct User {
    string name;
    int totalLikes;          // 总点赞次数 K
    unordered_set<int> tags; // 不同标签
};

int main() {
    int n;
    cin >> n;
    
    vector<User> users;
    users.reserve(n);
    
    for (int i = 0; i < n; i++) {
        string name;
        int k;
        cin >> name >> k;
        
        unordered_set<int> tags;
        for (int j = 0; j < k; j++) {
            int tag;
            cin >> tag;
            tags.insert(tag);
        }
        
        users.push_back({name, k, move(tags)});  // 使用 move 避免拷贝
    }
    
    // 排序：先按不同标签数量降序，再按平均点赞次数升序
    sort(users.begin(), users.end(), [](const User& a, const User& b) {
        // 不同标签数量多的在前
        if (a.tags.size() != b.tags.size()) {
            return a.tags.size() > b.tags.size();
        }
        // 并列时，平均次数少的在前（总次数 / 不同标签数）
        double avgA = (double)a.totalLikes / a.tags.size();
        double avgB = (double)b.totalLikes / b.tags.size();
        return avgA < avgB;
    });
    
    // 输出前3名，不足用 - 补齐
    for (int i = 0; i < 3; i++) {
        if (i > 0) cout << " ";
        if (i < users.size()) {
            cout << users[i].name;
        } else {
            cout << "-";
        }
    }
    cout << endl;
    
    return 0;
}