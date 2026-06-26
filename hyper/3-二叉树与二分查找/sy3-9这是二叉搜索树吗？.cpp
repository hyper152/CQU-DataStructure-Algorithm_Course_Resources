#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v){
        val=v;
        left=nullptr;
        right=nullptr;
    }
};

bool isBST(vector<int>& arr,int start,int end,bool ismirror){
    if (start >= end) return true;
    int root = arr[start];
    int i = start + 1;
    
    if (!ismirror){
        // 正常BST：左子树 < root，右子树 >= root
        while (i <= end && arr[i] < root) i++;
        int mid = i;
        while (i <= end && arr[i] >= root) i++;
        if (i <= end) return false;
        // 递归检查左右子树，保持相同的 ismirror 值
        return isBST(arr, start+1, mid-1, ismirror) && 
               isBST(arr, mid, end, ismirror);
    }
    else{
        // 镜像BST：左子树 >= root，右子树 < root
        while (i <= end && arr[i] >= root) i++;
        int mid = i;
        while (i <= end && arr[i] < root) i++;
        if (i <= end) return false;
        return isBST(arr, start+1, mid-1, ismirror) && 
               isBST(arr, mid, end, ismirror);
    }
}

TreeNode* buildBST(vector<int>& arr,int start,int end,bool ismirror){
    if (start > end) return nullptr;  // 添加边界条件
    
    TreeNode* node = new TreeNode(arr[start]);
    int root = arr[start];
    int i = start + 1;
    
    if (!ismirror){
        while (i <= end && arr[i] < root) i++;
        int mid = i;
        node->left = buildBST(arr, start+1, mid-1, ismirror);
        node->right = buildBST(arr, mid, end, ismirror);
    }
    else{
        while (i <= end && arr[i] >= root) i++;
        int mid = i;
        node->left = buildBST(arr, start+1, mid-1, ismirror);
        node->right = buildBST(arr, mid, end, ismirror);
    }
    return node;
}

void postprint(TreeNode* root, vector<int>& result){
    if (!root) return;
    postprint(root->left, result);
    postprint(root->right, result);
    result.push_back(root->val);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if (isBST(arr, 0, n-1, false)){
        TreeNode* node = buildBST(arr, 0, n-1, false);
        cout << "YES" << endl;
        vector<int> results;
        postprint(node, results);
        for (int i = 0; i < results.size(); i++){
            if (i > 0) cout << " ";
            cout << results[i];
        }
        cout << endl;
    }
    else if (isBST(arr, 0, n-1, true)){
        TreeNode* node = buildBST(arr, 0, n-1, true);
        cout << "YES" << endl;
        vector<int> results;
        postprint(node, results);
        for (int i = 0; i < results.size(); i++){
            if (i > 0) cout << " ";
            cout << results[i];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}