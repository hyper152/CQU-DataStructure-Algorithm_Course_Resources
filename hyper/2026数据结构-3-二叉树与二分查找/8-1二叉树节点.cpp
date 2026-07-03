#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 二叉树节点结构体
// val: 节点存储的字符
// left: 指向左子树的指针
// right: 指向右子树的指针
struct TreeNode {
    char val;
    TreeNode *left, *right;
    // 构造函数：初始化节点值，并将左右指针置为空
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};

/**
 * 根据先序遍历字符串递归建树
 * 遇到 '#' 表示空节点，否则创建一个新节点，并递归构造左右子树
 * 
 * @param s   先序遍历字符串（包含 '#' 表示空节点）
 * @param idx 当前处理的字符下标（引用类型，保证递归过程中全局递增）
 * @return    构建好的二叉树根节点指针
 */
TreeNode* buildTree(string &s, int &idx) {
    // 如果下标越界，或当前字符为 '#'，代表空节点
    if (idx >= s.size() || s[idx] == '#') {
        idx++;      // 跳过当前字符（'#' 或末尾）
        return nullptr;
    }
    // 创建当前根节点，赋值后 idx 自增（指向下一个待处理的字符）
    TreeNode* root = new TreeNode(s[idx++]);
    // 递归构建左子树和右子树
    root->left = buildTree(s, idx);
    root->right = buildTree(s, idx);
    return root;
}

/**
 * 在二叉树中查找值为 target 的节点，并记录从根到该节点的路径
 * 采用深度优先搜索（DFS）配合回溯的思想
 * 
 * @param root   当前搜索的子树根节点
 * @param target 目标节点值
 * @param path   记录路径的容器，会将遍历过程中经过的节点值依次压入
 * @return       是否找到目标节点，找到返回 true，否则返回 false
 */
bool findPath(TreeNode* root, char target, vector<char>& path) {
    // 空节点：直接返回未找到
    if (!root) return false;
    
    // 将当前节点值加入路径
    path.push_back(root->val);
    
    // 如果当前节点就是目标节点，说明路径已找到，返回 true
    if (root->val == target) return true;
    
    // 在左子树中查找，若找到则直接返回 true（路径已在递归中构建好）
    if (findPath(root->left, target, path)) return true;
    // 在右子树中查找，若找到则直接返回 true
    if (findPath(root->right, target, path)) return true;
    
    // 左右子树都没有找到目标节点：
    // 说明当前节点不在目标节点的路径上，进行回溯（将当前节点从路径中移除）
    path.pop_back();
    return false;
}

int main() {
    string pre;   // 先序遍历字符串，如 "ABD##E##C#F##"
    char a, b;    // 待查找最近公共祖先的两个节点字符
    cin >> pre;   // 输入先序序列
    cin >> a >> b;// 输入两个字符节点，例如 A F

    // 建树：idx 记录当前处理到的字符位置，初始为0
    int idx = 0;
    TreeNode* root = buildTree(pre, idx);

    // pathA 保存根到节点 a 的路径上的节点值
    // pathB 保存根到节点 b 的路径上的节点值
    vector<char> pathA, pathB;
    bool hasA = findPath(root, a, pathA);
    bool hasB = findPath(root, b, pathB);

    // 如果任意一个节点不存在于树中，输出提示并结束程序
    if (!hasA || !hasB) {
        cout << "结点未找到" << endl;
        return 0;
    }

    /**
     * 寻找最近公共祖先（LCA）：
     * 两个路径都是从根开始记录，根节点在数组最前面，目标节点在最后。
     * 要找到深度最大的公共节点，即从路径尾部向前遍历，
     * 第一个同时出现在两个路径中的节点即为最近公共祖先。
     * 
     * 这里采用简单的双重循环从后往前查找：
     * 外层遍历 pathA 的节点（从目标节点 a 向根方向），
     * 内层遍历 pathB 的节点（从目标节点 b 向根方向），
     * 一旦发现两节点值相同，就说明找到了最近的公共祖先，
     * 直接输出并结束程序。
     */
    char ans;
    for (int i = pathA.size() - 1; i >= 0; i--) {
        for (int j = pathB.size() - 1; j >= 0; j--) {
            if (pathA[i] == pathB[j]) {
                ans = pathA[i];
                cout << ans << endl;
                return 0;
            }
        }
    }

    // 理论上程序不会执行到这里，添加返回以防万一
    return 0;
}