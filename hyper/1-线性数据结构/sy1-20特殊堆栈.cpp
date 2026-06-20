#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void f(stack<int>& st,string s,vector<int>& vec_st){
    if (s=="Push"){
        // cout<<"Push"<<endl;
        int t;
        cin>>t;
        st.push(t);
        auto it = lower_bound(vec_st.begin(), vec_st.end(), t);
        vec_st.insert(it,t);
    }
    else if (st.empty()){
        cout<<"Invalid"<<endl;
    }
    else if (s=="Pop"){
        // cout<<"Pop"<<endl;
        if (!st.empty()){
            auto it = find(vec_st.begin(), vec_st.end(), st.top());
            vec_st.erase(it);
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    else if (s=="PeekMedian"){
        // cout<<"PeekMedian"<<endl;
        int n=vec_st.size();
        cout<<vec_st[(n-1)/2]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    stack<int> st;
    vector<int> vec_st;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        f(st,s,vec_st);
    }
}