#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));

    for(int ht = 1; ht<=a; ht++){
        for(int wt=1; wt<=b; wt++){
            
            if(ht == wt){
                dp[ht][wt] = 0;
            }else{
                int ans = 1e9;
                for(int i=1; i<ht;i++){
                    ans = min(ans, 1+dp[ht-i][wt] + dp[i][wt]);
                }
                for(int i=1; i<wt;i++){
                    ans = min(ans, 1+dp[ht][wt-i] + dp[ht][i]);
                }
                dp[ht][wt] =ans;
            }
        }
    }
    cout<< dp[a][b]<<endl;
}

