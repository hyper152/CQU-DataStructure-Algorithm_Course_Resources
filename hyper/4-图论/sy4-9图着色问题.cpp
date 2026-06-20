#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point{
    int id;
    vector<int> to;
    int color;
};

int main(){
    int v,e,k;
    cin>>v>>e>>k;
    vector<point> points;
    points.push_back({0,{},-1});
    for (int i=1;i<=v;i++){
        points.push_back({i,{},-1});
    }
    
    for (int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        points[v1].to.push_back(v2);
        points[v2].to.push_back(v1);
    }
    
    int n;
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=1;j<=v;j++){
            int col;
            cin>>col;
            points[j].color=col;
        }
        
        vector<bool> vis(v+1,false);
        queue<int> q;
        bool found = false;
        
        for (int j=1;j<=v;j++){
            if (found == true) break;
            if (vis[j]==false){
                q.push(j);
                vis[j]=true;
                
                while(!q.empty()){
                    int p=q.front();
                    q.pop();
                    int pre_col=points[p].color;
                    
                    for (int a : points[p].to){
                        if (vis[a]==false) {
                            vis[a]=true;
                            q.push(a);
                        }
                        int col=points[a].color;
                        if (col==pre_col){
                            cout<<"No"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if (found == true) break;
                }
            }
        }
        if (found == false) cout<<"Yes"<<endl;
    }
}