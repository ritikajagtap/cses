#include <bits/stdc++.h>
using namespace std;
int f(int n, int t){
    if(n==0 && t==0){return 1;}
    if(n==0 && t!=0){return 0;}
    int pick = 0;
    if(t>=n){
        pick = f(n-1, t-n);
    }
    int notPick = f(n-1, t);
    return pick+notPick;
}
int main()
{
    int mod = 1e9+7;
    int n;
    cin>>n;
    if((n*(n+1))%4 != 0){cout<<0<<endl; return 0;}
    int t = (n*(n+1))/4;
    vector<vector<long long int>> dp(n+1, vector<long long int>(t+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j = 0; j<=t; j++){
            int pick= 0;
            if(j>=i){
                pick = (dp[i-1][j-i])%mod;
            }
            int notPick = (dp[i-1][j])%mod;
            dp[i][j] = (pick+notPick)%mod;
        }
    }
    // inverse of 2
    long long int ans = (dp[n][t]*500000004)%mod;
    cout<<ans<<endl;
    // int ans = f(n, t);
    // cout<<ans/2<<endl;
}

