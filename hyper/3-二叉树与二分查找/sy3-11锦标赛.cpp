#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int round, int idx, int expW,const vector<vector<int>>& arr){
    int l=arr[round][idx];
    if (expW < l) return {};
    if (round==1) return {expW,l};

    auto left=solve(round-1,2*idx-1,expW,arr);
    auto right=solve(round-1,2*idx,l,arr);

    if (!left.empty() and !right.empty()) {
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }

    left=solve(round-1,2*idx-1,l,arr);
    right=solve(round-1,2*idx,expW,arr);

    if (!left.empty() and !right.empty()) {
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
    
    return {};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    vector<vector<int>> arr(k+1);
    for (int i = 1; i <= k; i++){
        arr[i].resize(1 << (k-i)+1);
        for (int j = 1; j <= 1<<(k-i); j++){
            int t;
            cin>>t;
            arr[i][j]=t;
        }
    }
    int w;
    cin>>w;

    vector<int> results;
    results=solve(k,1,w,arr);

    if (results.empty()){
        cout<<"No Solution";
    }
    else{
        for (int i=0;i<results.size();i++){
            cout<<results[i];
            if (i!=results.size()-1) cout<<" ";
        }
        cout<<endl;
    }
}