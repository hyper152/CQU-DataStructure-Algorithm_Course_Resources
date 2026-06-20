#include<iostream>
using namespace std;
#define int long long

int n, post[15], in[15];

struct node {
    int val;
    node* lchild = NULL;
    node* rchild = NULL;
};

node* make(int lin, int rin, int lpost, int rpost) {
    node* nd = new node;
    nd->val = post[rpost];
    int k = 0;
    while (in[lin + k] != post[rpost]) k++;
    if (k > 0) nd->lchild = make(lin, lin + k - 1, lpost, lpost + k - 1);
    if (lin + k < rin) nd->rchild = make(lin + k + 1, rin, lpost + k, rpost - 1);
    return nd;
}

void preorder(node* nd) {
    if (nd == NULL) return;
    cout << nd->val << " ";
    preorder(nd->lchild);
    preorder(nd->rchild);
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> post[i];
    for (int i = 1; i <= n; i++) cin >> in[i];
    node* root = make(1, n, 1, n);
    preorder(root);
    return 0;
}
