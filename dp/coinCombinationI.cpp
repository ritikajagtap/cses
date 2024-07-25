#include <bits/stdc++.h>
using namespace std;
// int f(int t, vector<int> coins, vector<int> &dp);

int main()
{
    long long int n, t;
    cin >> n >> t;
    vector<long long int> coins(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int mod = 1e9 + 7;
    // vector<int> dp(t+1, -1);
    // int ans = f(t, coins, dp);
    // cout << ans << endl;
    vector<long long int> dp(t + 1, 0);
    dp[0] = 1;
    for (long long int ind = 1; ind <= t; ind++)
    {
        for (long long int i = 0; i < coins.size(); i++)
        {
            if (ind >= coins[i])
            {
                dp[ind] += dp[ind-coins[i]];
                dp[ind]%=mod;
            }
        }
    }
    cout<<dp[t]<<endl;
}
// int f(int t, vector<int> coins, vector<int> &dp)
// {
//     if (t == 0)
//     {
//         return 1;
//     }
//     if (t < 0)
//     {
//         return 0;
//     }
//     if (dp[t] != -1)
//     {
//         return dp[t];
//     }
//     int take = 0;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         if (t >= coins[i])
//         {
//             take = (take + f(t - coins[i], coins, dp)) % mod;
//         }
//     }
//     return dp[t] = (take) % mod;
// }