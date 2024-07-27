#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, string s, string t, vector<vector<int>> &dp);
int main()
{

    string s;
    string t;
    cin >> s >> t;
    // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    // int ans = func(s.size()-1, t.size()-1, s, t, dp);

    // cout<<ans<<endl;

    for (int i = 0; i < s.size() + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i < t.size() + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i][j-1], dp[i-1][j]});
        }
    }
    cout<<dp[s.size()][t.size()]<<endl;
}

int func(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == t[j])
    {
        return dp[i][j] = func(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = 1 + min({func(i - 1, j - 1, s, t, dp), func(i, j - 1, s, t, dp), func(i - 1, j, s, t, dp)});
}
