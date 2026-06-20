#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int n, idx = 0;
vector<string> seq;

TreeNode* build() {
    if (idx >= n || seq[idx] == "#") {
        idx++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(seq[idx]));
    idx++;
    node->left = build();
    node->right = build();
    return node;
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cin >> n;
    seq.resize(n);
    for (int i = 0; i < n; i++) cin >> seq[i];
    TreeNode* root = build();
    preorder(root);
    return 0;
}
