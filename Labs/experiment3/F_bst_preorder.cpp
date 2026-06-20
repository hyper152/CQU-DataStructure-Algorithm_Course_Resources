#include<iostream>
using namespace std;
#define int long long

int n, x;
struct node {
    int val;
    node* lchild = NULL;
    node* rchild = NULL;
};

void ist(node* root, int v) {
    node* tmp = root;
    node* add = new node;
    add->val = v;
    while (tmp != NULL) {
        if (v == tmp->val) return;
        else if (v > tmp->val) {
            if (tmp->rchild == NULL) tmp->rchild = add;
            else tmp = tmp->rchild;
        } else {
            if (tmp->lchild == NULL) tmp->lchild = add;
            else tmp = tmp->lchild;
        }
    }
}

void preorder(node* nd) {
    if (nd == NULL) {
        cout << 0 << " ";
        return;
    }
    cout << nd->val << " ";
    preorder(nd->lchild);
    preorder(nd->rchild);
}

signed main() {
    cin >> n >> x;
    node* root = new node;
    root->val = x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        ist(root, x);
    }
    preorder(root);
    return 0;
}
