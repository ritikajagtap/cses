#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9+7;
    int n, m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
    for(int i=1; i<=n; i++){
        for(int x = 1; x<=m; x++){
                if(i==1){
                    if(arr[i]==0 || arr[i]==x){
                        dp[i][x] =1;
                    }
                    else{dp[i][x] = 0;}
                }else{
                    if(arr[i]==0 || arr[i]==x){
                        dp[i][x] = ((dp[i-1][x] + dp[i-1][x+1])%mod + dp[i-1][x-1])%mod;
                    }else{
                        dp[i][x] = 0;
                    }
                }
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        ans = (ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;
    
}

