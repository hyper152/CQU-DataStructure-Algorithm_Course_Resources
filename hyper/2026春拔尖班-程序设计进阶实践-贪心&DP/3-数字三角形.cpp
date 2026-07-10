#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n+1,vector<int>(n+1));
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            int t;
            cin>>t;
            arr[i][j]=t;
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<vector<int>> s(n+1,vector<int>(n+1,0));
    dp[1][1]=arr[1][1];
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i;j++){
            if (j>1 and j<i){
                if (dp[i-1][j-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][j-1]+arr[i][j];
                    s[i][j]=s[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=dp[i-1][j]+arr[i][j];
                    s[i][j]=s[i-1][j]-1;
                }
            }
            else if (j==1){
                dp[i][j]=dp[i-1][j]+arr[i][j];
                s[i][j]=s[i-1][1]-1;
            }
            else {
                dp[i][j]=dp[i-1][j-1]+arr[i][j]; 
                s[i][j]=s[i-1][j-1]+1;
            }
        }
    }
    int max=0;
    for (int i=1;i<=n;i++){
        if (dp[n][i]>max and (s[n][i]>=-1 and s[n][i]<=1)){
            max=dp[n][i];
        }
    }

    cout<<max<<endl;
    // cout<<27<<endl;
}