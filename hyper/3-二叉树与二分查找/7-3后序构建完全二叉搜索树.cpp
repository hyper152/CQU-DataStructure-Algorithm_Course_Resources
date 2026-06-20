#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> post, tree;

void build(int idx) {
    if (idx > n) return;
    build(idx * 2);        // 左子树
    build(idx * 2 + 1);    // 右子树
    static int pos = 0;
    tree[idx] = post[pos++]; // 根节点
}

int main() {
    cin >> n;
    post.resize(n);
    tree.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    
    build(1);
    
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << tree[i];
    }
    return 0;
}