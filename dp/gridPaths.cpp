#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<char>> grid, vector<vector<int>> &dp);
int main()
{
    int mod = 1e9+7;
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int right =0, down=0;
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }else if(i==n-1 && j==n-1){dp[i][j] = 1;}
            else{
                if(j<n-1){right = dp[i][j+1];}
                if(i<n-1){down = dp[i+1][j];}
                dp[i][j] = (right+down)%mod;
            }
        }
    }
    int ans = dp[0][0];
    cout<<ans<<endl;
    // int ans = func(0, 0, grid, dp);
    // cout<<ans<<endl;
}

int func(int i, int j, vector<vector<char>> grid, vector<vector<int>> &dp)
{
    int mod = 1e9 + 7;
    // base
    if (i < grid.size() && j < grid.size() && grid[i][j] == '*')
    {
        return 0;
    }
    if (i >= grid.size() || j >= grid.size())
    {
        return 0;
    }
    if (i == grid.size() - 1 && j == grid[i].size() - 1)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // going right
    int r = func(i, j + 1, grid, dp) % mod;
    // going down
    int d = func(i + 1, j, grid, dp) % mod;
    return dp[i][j] = (r + d) % mod;
}