#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // For find

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据先序和中序序列构建二叉树
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    // 如果先序序列为空，或者中序序列为空，则返回空
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    // 先序序列的第一个元素是根节点
    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);

    // 在中序序列中找到根节点的位置
    auto it = find(inorder.begin(), inorder.end(), rootVal);
    int rootIndexInInorder = distance(inorder.begin(), it);

    // 分割中序序列为左子树和右子树的中序序列
    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndexInInorder);
    vector<int> rightInorder(inorder.begin() + rootIndexInInorder + 1, inorder.end());

    // 分割先序序列为左子树和右子树的先序序列
    // 左子树先序序列的长度与左子树中序序列的长度相同
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
    vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

    // 递归构建左子树和右子树
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

// 后序遍历并输出
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

// 辅助函数：将字符串按空格分割为整数向量
vector<int> parseInput(const string& line) {
    vector<int> result;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

int main() {
    int n;
    cin >> n; // 读取元素个数

    // 消耗掉换行符
    cin.ignore();

    string preorderLine, inorderLine;
    
    // 读取先序序列
    getline(cin, preorderLine);
    vector<int> preorder = parseInput(preorderLine);

    // 读取中序序列
    getline(cin, inorderLine);
    vector<int> inorder = parseInput(inorderLine);

    // 构建二叉树
    TreeNode* root = buildTree(preorder, inorder);

    // 输出后序序列
    postorderTraversal(root);
    cout << endl; // 确保最后有一个换行符

    return 0;
}