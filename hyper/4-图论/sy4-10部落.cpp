#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int maxn = 10001;

int parent[maxn];
int rnk[maxn];

void init(){
    for (int i=1;i<maxn;i++){
        parent[i]=i;
        rnk[i]=1;
    }
}

int find(int x){
    if (x!=parent[x]){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unite(int x,int y){
    if (find(x)==find(y)) return;

    int rx=find(x);
    int ry=find(y);
    // cout<<"unite "<<x<<" "<<y<<endl;
    if (rnk[rx]>rnk[ry]){
        parent[ry]=rx;
        // cout<<"r"<<parent[rx]<<endl;
    }
    else if (rnk[rx]<rnk[ry]){
        parent[rx]=ry;
        // cout<<"r"<<parent[rx]<<endl;
    }
    else{
        parent[ry]=rx;
        rnk[rx]++;
        // cout<<"r"<<parent[rx]<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    
    vector<int> persons(10001,0);
    for (int i=1;i<=n;i++){
        int k,r;
        cin>>k>>r;
        persons[r]=1;
        for (int j=2;j<=k;j++){
            int t;
            cin>>t;
            persons[t]=1;
            unite(r,t);
            parent[r]=find(parent[r]);
            parent[t]=find(parent[t]);
        }
    }
    int q;
    cin>>q;
    vector<bool> if_root(10001,false);
    int sum=0;
    for (int i=1;i<=10000;i++){
        if (persons[i]==1 and if_root[find(i)]==false){
            if_root[find(i)]=true;
            sum+=1;
        }
    }
    
    cout<<accumulate(persons.begin(),persons.end(),0)<<" "<<sum<<endl;
    
    for (int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if (find(a)==find(b)) cout<<"Y";
        else cout<<"N";
        if (i!=q) cout<<endl;
    }
}