## 二叉树三种构建方式总结（完整结构体版）

---

### 通用结构体定义

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

### 一、前序遍历 + 中序遍历

```cpp
class Solution_PreIn {
private:
    unordered_map<int, int> inorderMap;  // 优化查找
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // O(1) 时间找到根在中序中的位置
        int inRoot = inorderMap[rootVal];
        int leftSize = inRoot - inStart;
        
        // 构建左子树
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, inRoot - 1);
        // 构建右子树
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inorder, inRoot + 1, inEnd);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};
```

**参数范围说明：**
| 子树 | 前序遍历范围 | 中序遍历范围 |
|-----|------------|------------|
| 左子树 | `[preStart+1, preStart+leftSize]` | `[inStart, inRoot-1]` |
| 右子树 | `[preStart+leftSize+1, preEnd]` | `[inRoot+1, inEnd]` |

---

### 二、中序遍历 + 后序遍历

```cpp
class Solution_InPost {
private:
    unordered_map<int, int> inorderMap;  // 优化查找
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (postStart > postEnd) return nullptr;
        
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        // O(1) 时间找到根在中序中的位置
        int inRoot = inorderMap[rootVal];
        int leftSize = inRoot - inStart;
        
        // 构建左子树
        root->left = build(inorder, inStart, inRoot - 1,
                           postorder, postStart, postStart + leftSize - 1);
        // 构建右子树
        root->right = build(inorder, inRoot + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};
```

**参数范围说明：**
| 子树 | 中序遍历范围 | 后序遍历范围 |
|-----|------------|------------|
| 左子树 | `[inStart, inRoot-1]` | `[postStart, postStart+leftSize-1]` |
| 右子树 | `[inRoot+1, inEnd]` | `[postStart+leftSize, postEnd-1]` |

---

### 三、前序遍历 + 后序遍历（不唯一）

```cpp
class Solution_PrePost {
private:
    unordered_map<int, int> postorderMap;  // 优化查找
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // 只有一个节点，直接返回
        if (preStart == preEnd) return root;
        
        // 左子树的根是前序的第二个元素
        int leftRootVal = preorder[preStart + 1];
        
        // O(1) 时间找到左子树根在后序中的位置
        int leftRootPos = postorderMap[leftRootVal];
        
        // 左子树的节点数
        int leftSize = leftRootPos - postStart + 1;
        
        // 构建左子树
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           postorder, postStart, leftRootPos);
        // 构建右子树
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, leftRootPos + 1, postEnd - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postorderMap[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};
```

**参数范围说明：**
| 子树 | 前序遍历范围 | 后序遍历范围 |
|-----|------------|------------|
| 左子树 | `[preStart+1, preStart+leftSize]` | `[postStart, leftRootPos]` |
| 右子树 | `[preStart+leftSize+1, preEnd]` | `[leftRootPos+1, postEnd-1]` |

---

### 四、层序遍历辅助函数

```cpp
// 层序遍历输出（带格式）
void levelOrderPrint(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    vector<int> result;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
}

// 镜像翻转二叉树
void mirrorTree(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}
```

---

### 五、完整主函数示例

```cpp
int main() {
    int N;
    cin >> N;
    
    // 示例1：前序+中序
    vector<int> preorder(N), inorder(N);
    for (int i = 0; i < N; i++) cin >> preorder[i];
    for (int i = 0; i < N; i++) cin >> inorder[i];
    Solution_PreIn sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    // 示例2：中序+后序
    vector<int> inorder(N), postorder(N);
    for (int i = 0; i < N; i++) cin >> inorder[i];
    for (int i = 0; i < N; i++) cin >> postorder[i];
    Solution_InPost sol;
    TreeNode* root = sol.buildTree(inorder, postorder);
    
    // 示例3：前序+后序
    vector<int> preorder(N), postorder(N);
    for (int i = 0; i < N; i++) cin >> preorder[i];
    for (int i = 0; i < N; i++) cin >> postorder[i];
    Solution_PrePost sol;
    TreeNode* root = sol.buildTree(preorder, postorder);
    
    // 输出层序遍历结果
    levelOrderPrint(root);
    
    return 0;
}
```

---

### 六、快速对照表

| 构建方式 | 根节点 | 左子树大小计算 | 是否需要哈希表 |
|---------|--------|--------------|--------------|
| **前序+中序** | `preorder[preStart]` | `inRoot - inStart` | 存中序 |
| **中序+后序** | `postorder[postEnd]` | `inRoot - inStart` | 存中序 |
| **前序+后序** | `preorder[preStart]` | 通过后序查找 | 存后序 |

---

### 七、重要提醒

1. **前序+后序不唯一**：当节点只有左子树或只有右子树时，无法区分
2. **哈希表优化**：将 O(n²) 降为 O(n)
3. **递归终止条件**：`start > end` 时返回 `nullptr`
4. **内存管理**：实际使用中注意释放内存（示例中省略）