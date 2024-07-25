#include <bits/stdc++.h>
using namespace std;
int f(int ind, int t, vector<int> coins, vector<vector<int>> &dp);
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // vector<vector<int>> dp(n, vector<int>(t+1, -1));
    vector<int> dp(t+1, 1e9);
    dp[0] = 0;
    for(int i=1; i<=t; i++){
            for(int j=0; j<n; j++){
                if(coins[j]<=i){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);}
            }
    }
    cout<< (dp[t]<1e9 ? dp[t] : -1)<<endl;


    // int ans = f(0, t,coins, dp);
    // if(ans == 1e9){cout<<-1<<endl; return 0;}
    // cout<<ans<<endl;
}
int f(int ind, int t, vector<int> coins, vector<vector<int>> &dp)
{
    if (ind == coins.size() - 1)
    {
        if (t % coins[ind] == 0)
        {
            return t / coins[ind];
        }
        return 1e9;
    }
    if (dp[ind][t] != -1)
    {
        return dp[ind][t];
    }
    int take = 1e9;
    if (t >= coins[ind])
    {
        take = 1 + f(ind, t - coins[ind], coins, dp);
    }
    int notTake = f(ind + 1, t, coins, dp);
    return dp[ind][t] = min(take, notTake);
}