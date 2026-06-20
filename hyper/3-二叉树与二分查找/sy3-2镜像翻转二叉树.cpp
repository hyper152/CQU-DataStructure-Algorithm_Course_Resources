// sy3-2.cpp
// 构建二叉树、镜像翻转并进行层次遍历的程序
// 输入：节点数 N，中序遍历序列，前序遍历序列
// 输出：镜像翻转后的二叉树的层次遍历序列

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd) return nullptr;
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    int leftSize = rootIndex - inStart;
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
    return root;
}

void mirror(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        res.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> inorder(N), preorder(N);
    for (int i = 0; i < N; ++i) cin >> inorder[i];
    for (int i = 0; i < N; ++i) cin >> preorder[i];
    TreeNode* root = buildTree(preorder, inorder, 0, N - 1, 0, N - 1);
    mirror(root);
    vector<int> res = levelOrder(root);
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}