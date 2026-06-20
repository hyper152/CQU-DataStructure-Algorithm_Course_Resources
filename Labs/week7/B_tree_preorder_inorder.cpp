#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
    if (preL > preR) return nullptr;
    int rootVal = preorder[preL];
    TreeNode* root = new TreeNode(rootVal);
    int k = inL;
    while (k <= inR && inorder[k] != rootVal) k++;
    int leftSize = k - inL;
    root->left = build(preorder, inorder, preL + 1, preL + leftSize, inL, k - 1);
    root->right = build(preorder, inorder, preL + leftSize + 1, preR, k + 1, inR);
    return root;
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode* root = build(preorder, inorder, 0, n - 1, 0, n - 1);
    postorder(root);
    cout << endl;
    return 0;
}
