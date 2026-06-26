#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct person{
    int id;
    string s;
    int score;
};

void money(int g,int n,long long& sum){
    if (n>=g) sum+=50;
    else if (n>=60) sum+=20;
}

int main(){
    int n,g,k;
    cin>>n>>g>>k;
    vector<pair<string,int>> arr;
    for (int i=0;i<n;i++){
        string s;
        int t;
        cin>>s>>t;
        arr.push_back({s,t});
    }
    sort(arr.begin(),arr.end(),[](const auto& a,const auto& b){
        if (a.second!=b.second) return a.second>b.second;
        else return a.first<b.first;
    });
    vector<person> persons;
    int pre_score=arr[0].second;
    int pre_id=1;
    long long sum=0;
    for (int i=0;i<n;i++){
        if (i>=1 and arr[i].second==pre_score){
            persons.push_back({pre_id,arr[i].first,arr[i].second});
            money(g,arr[i].second,sum);
        }
        else{
            persons.push_back({i+1,arr[i].first,arr[i].second});
            pre_id=i+1;
            pre_score=arr[i].second;
            money(g,arr[i].second,sum);
        }
    }
    cout<<sum<<endl;
    for (auto i : persons){
        if (i.id<=k) cout<<i.id<<" "<<i.s<<" "<<i.score<<endl;
    }
}