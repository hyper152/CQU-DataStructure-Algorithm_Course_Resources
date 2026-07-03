#include <iostream>
#include <vector>
#include <string> // 用于读取字符串
#include <sstream> // 用于字符串转整数

using namespace std;

struct TreeNode {
    int val; // 节点值改为 int
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int idx = 0;

TreeNode* buildTree(vector<string>& s) { // 传入 string 向量
    if (idx >= s.size() || s[idx] == "#") {
        idx++;
        return nullptr;
    }

    // 将字符串转换为整数
    stringstream ss(s[idx]);
    int nodeVal;
    ss >> nodeVal;

    TreeNode* root = new TreeNode(nodeVal);
    idx++;
    root->left = buildTree(s);
    root->right = buildTree(s);
    return root;
}

// 每个元素换行输出
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<string> seq(n); // 读取 string
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    TreeNode* root = buildTree(seq);
    preOrder(root);

    return 0;
}