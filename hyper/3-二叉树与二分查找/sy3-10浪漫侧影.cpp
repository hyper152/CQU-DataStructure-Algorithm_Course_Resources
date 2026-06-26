#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int val;
    int floor;
    node* l;
    node* r;
    node(int v){
        val=v;
        l=nullptr;
        r=nullptr;
    }
};

node* build(vector<int> post, vector<int> mid, int floor) {
    if (post.empty() || mid.empty()) return nullptr;
    
    node* root = new node(post[post.size() - 1]);
    root->floor = floor;
    
    int i = 0;
    while (mid[i] != post[post.size() - 1]) i++;
    
    // 左子树
    vector<int> post_l(post.begin(), post.begin() + i);
    vector<int> mid_l(mid.begin(), mid.begin() + i);
    
    // 右子树
    vector<int> post_r(post.begin() + i, post.end() - 1);
    vector<int> mid_r(mid.begin() + i + 1, mid.end());
    
    root->l = build(post_l, mid_l, floor + 1);   // 值传递，可以直接用 floor+1
    root->r = build(post_r, mid_r, floor + 1);
    
    return root;
}

int main(){
    int n;
    cin>>n;
    vector<int> post(n);
    vector<int> mid(n);
    for (int j=0;j<2;j++){
        for (int i=0;i<n;i++){
            if (j==0){
                int t;
                cin>>t;
                mid[i]=t;
            }
            else if (j==1){
                int t;
                cin>>t;
                post[i]=t;
            }
        }
    }
    int floor=1;
    node* root=build(post,mid,floor);

    queue<node*> q;
    q.push(root);
    vector<vector<int>> floors(n+1);
    
    while (!q.empty()){
        node* p=q.front();
        q.pop();
        
        floors[p->floor].push_back(p->val);
        
        if (p->l) q.push(p->l);
        if (p->r) q.push(p->r);
    }
    
    vector<int> left;
    vector<int> right;
    for (vector<int> i : floors){
        if (i.empty()) continue;
        left.push_back(i[0]);
        right.push_back(i[i.size()-1]);
    }
    cout<<"R: ";
    for (int i=0;i<right.size();i++){
        cout<<right[i];
        if (i!=right.size()-1) cout<<" ";
    }
    cout<<endl;
    cout<<"L: ";
    for (int i=0;i<left.size();i++){
        cout<<left[i];
        if (i!=left.size()-1) cout<<" ";
    }
    cout<<endl;
}