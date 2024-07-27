#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        // linked and not linked 
        // 2 D array with 2 columns
        // 0 -> i-1 position have tile of width 1
        // 1 -> i-1 position have tile of width 2

        vector<vector<long long int>> dp(n+2, vector<long long int>(2, 0));

        // base case
        // the above tiles will be 1 for the both linked and not linked
        // either 1 tiles of width 2 or we can have 2 tiles of width 1
        dp[n+1][0] = dp[n+1][1] = 1;
int mod = 1e9+7;
        for(int i=n; i>=2; i--){
            // taking the possibilities
            // not extending any tile from above
            long long int op1 = (dp[i+1][0] + dp[i+1][1])%mod;

            // extend both
            long long int op2 = dp[i+1][0];

            // extend one of the two tiles
            long long int op3 = (2*dp[i+1][0])%mod;
            // exending both when they are linked
            long long int op4= dp[i+1][1];

            dp[i][0] = (op1 + op2 + op3)%mod;
            dp[i][1] = (op1 + op4)%mod;
        }
        cout<<(dp[2][1] + dp[2][0])%mod<<endl;

    }
    
}

