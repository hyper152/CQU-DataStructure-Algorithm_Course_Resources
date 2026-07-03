#include <iostream>
#include <vector>
using namespace std;

class dsu{
private:
    vector<int> parent,rank;
public:
    dsu(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int x){
        if (parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rank[rx]>rank[ry]) parent[ry]=rx;
        else if (rank[ry]>rank[rx]) parent[rx]=ry;
        else { parent[ry] = rx; rank[rx]++; }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    dsu dsu(n);
    for (int i=0;i<m;i++){
        int zi,xi,yi;
        cin>>zi>>xi>>yi;
        if (zi==1){dsu.unite(xi,yi);}
        else{
            if (dsu.find(xi)==dsu.find(yi)){cout<<"Y";}
            else {cout<<"N";}
            if (i!=m-1) cout<<endl;
        }
    }
}