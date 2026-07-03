#include <bits/stdc++.h>
using namespace std;

// 定义二叉树节点结构体
struct TreeNode {
    int val;              // 节点的值
    TreeNode* left;       // 左子节点指针
    TreeNode* right;      // 右子节点指针
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  // 构造函数，初始化节点值，左右子节点为空
};

// 根据后序遍历和中序遍历重建二叉树
// 参数：
//   postorder: 后序遍历序列
//   postStart, postEnd: 后序遍历的起始和结束索引
//   inorder: 中序遍历序列
//   inStart, inEnd: 中序遍历的起始和结束索引
// 返回值：重建的二叉树的根节点
TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd) {
    // 如果后序遍历的起始索引大于结束索引，说明没有节点，返回空
    if (postStart > postEnd) return NULL;

    // 后序遍历的最后一个元素是根节点的值
    int rootVal = postorder[postEnd];
    // 创建根节点
    TreeNode* root = new TreeNode(rootVal);

    // 在中序遍历中找到根节点的位置
    int inRoot = inStart;
    while (inorder[inRoot] != rootVal) inRoot++;

    // 计算左子树的节点数量
    int leftSize = inRoot - inStart;

    // 递归构建左子树
    // 左子树的后序遍历范围：postStart 到 postStart + leftSize - 1
    // 左子树的中序遍历范围：inStart 到 inRoot - 1
    root->left = buildTree(postorder, postStart, postStart + leftSize - 1, inorder, inStart, inRoot - 1);

    // 递归构建右子树
    // 右子树的后序遍历范围：postStart + leftSize 到 postEnd - 1
    // 右子树的中序遍历范围：inRoot + 1 到 inEnd
    root->right = buildTree(postorder, postStart + leftSize, postEnd - 1, inorder, inRoot + 1, inEnd);

    // 返回根节点
    return root;
}

// 进行层序遍历（广度优先搜索）
// 参数：root - 二叉树的根节点
// 输出：层序遍历的序列，每个节点值之间用空格分隔
void levelOrder(TreeNode* root) {
    // 如果根节点为空，直接返回
    if (!root) return;

    // 使用队列进行BFS
    queue<TreeNode*> q;
    // 将根节点入队
    q.push(root);

    // 当队列不为空时，继续遍历
    while (!q.empty()) {
        // 取出队首节点
        TreeNode* node = q.front(); q.pop();

        // 输出当前节点的值
        cout << node->val;

        // 如果队列不为空，或者当前节点有子节点，则输出空格
        // 这是为了确保最后一个节点后没有多余空格
        if (!q.empty() || node->left || node->right) cout << " ";

        // 如果左子节点存在，将其入队
        if (node->left) q.push(node->left);
        // 如果右子节点存在，将其入队
        if (node->right) q.push(node->right);
    }
}

int main() {
    // 读取节点数量N
    int N;
    cin >> N;

    // 读取后序遍历序列
    vector<int> postorder(N);
    for(int i = 0; i < N; i++) cin >> postorder[i];

    // 读取中序遍历序列
    vector<int> inorder(N);
    for(int i = 0; i < N; i++) cin >> inorder[i];

    // 根据后序和中序遍历重建二叉树
    TreeNode* root = buildTree(postorder, 0, N-1, inorder, 0, N-1);

    // 进行层序遍历并输出结果
    levelOrder(root);

    // 输出换行符
    cout << endl;

    // 程序结束
    return 0;
}