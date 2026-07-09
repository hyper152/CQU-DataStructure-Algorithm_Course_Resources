#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct matrix{
    int row,col;
    string name;
    matrix(int r = 0, int c = 0, string n = "") 
        : row(r), col(c), name(n) {}
};

string buildExpression(vector<matrix> mats,vector<vector<int>>& dp,vector<vector<int>>& s,int i,int j,int t){
    if (i==j){
        return "(" +mats[i].name+ ")";
    }
    int k = s[i][j];
    string left = buildExpression(mats,dp,s,i, k,t+1);
    string right = buildExpression(mats,dp,s,k + 1, j,t+1);
    if (t==0) return left + "x" + right;
    else return "(" + left + "x" + right + ")";
}

int main(){
    int n;
    cin>>n;
    vector<matrix> mats(n);
    vector<int> arr(n+1);
    int t;
    cin>>t;
    arr[0]=t;
    
    for (int i=1;i<=n;i++){
        cin>>t;
        arr[i]=t;
        mats[i-1] = matrix(arr[i-1], arr[i], "M" + to_string(i));
    }
    
    if (n == 1) {
        cout << mats[0].name << endl;
        cout << 0;
        return 0;
    }
    
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> s(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
            s[i][j] = 0;
        }
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] 
                         + mats[i].row * mats[k].col * mats[j].col;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << buildExpression(mats,dp,s,0, n-1,0) << endl;
    cout << dp[0][n-1];
    
    return 0;
}