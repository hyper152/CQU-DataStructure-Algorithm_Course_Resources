#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // 插入结点
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    // 找最大值结点
    TreeNode* findMax(TreeNode* node) {
        while (node->right)
            node = node->right;
        return node;
    }

    // 找最小值结点
    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    // 删除结点
    TreeNode* remove(TreeNode* node, int key) {
        if (!node) return nullptr;
        if (key < node->val)
            node->left = remove(node->left, key);
        else if (key > node->val)
            node->right = remove(node->right, key);
        else {
            // 找到目标结点
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (node->left) {
                TreeNode* maxNode = findMax(node->left);
                node->val = maxNode->val;
                node->left = remove(node->left, maxNode->val);
            }
            else if (node->right) {
                TreeNode* minNode = findMin(node->right);
                node->val = minNode->val;
                node->right = remove(node->right, minNode->val);
            }
        }
        return node;
    }

    // 递归删除整棵树（内存释放）
    void clear(TreeNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void levelOrder() {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        bool first = true;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (first) {
                cout << node->val;
                first = false;
            } else {
                cout << " " << node->val;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
};

int main() {
    int N, K, val;
    cin >> N;
    BST tree;
    for (int i = 0; i < N; i++) {
        cin >> val;
        tree.insert(val);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> val;
        tree.remove(val);
    }
    tree.levelOrder();
    return 0;
}