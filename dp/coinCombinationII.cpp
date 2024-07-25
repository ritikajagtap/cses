#include <bits/stdc++.h>
using namespace std;
// int f(int ind, int t, vector<int> coins, vector<vector<int>> &dp);

int main()
{
    int mod = 1e9 + 7;
    int n, t;
    cin >> n >> t;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(t + 1, 0));

    for (int i = 0; i <n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= t; j++)
        {
            int take = 0;
            if (j >= coins[i])
            {
                take = dp[i][j-coins[i]];
            }
            int notTake = dp[i+1][j];
            dp[i][j] = (take + notTake) % mod;
        }
    }
    cout<<dp[0][t]<<endl;

    // vector<vector<int>> dp(n, vector<int>(t+1, -1));
    // int ans = f(0, t, coins, dp);
    // cout<<ans<<endl;
}

// int f(int ind, int t, vector<int> coins, vector<vector<int>> &dp)
// {

//     if (ind == coins.size() - 1)
//     {
//         if (t % coins[ind] == 0)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     if (dp[ind][t] != -1)
//     {
//         return dp[ind][t];
//     }
//     int take = 0;
//     if (t >= coins[ind])
//     {
//         take = (f(ind, t - coins[ind], coins, dp) % mod);
//     }
//     int notTake = (f(ind + 1, t, coins, dp) % mod);
//     return dp[ind][t] = (take + notTake) % mod;
// }
