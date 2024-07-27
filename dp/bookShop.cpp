#include <bits/stdc++.h>
using namespace std;
int func(int ind, int mxPr, int n, vector<int> books, vector<int> pages, vector<vector<int>> &dp);
int main()
{
    int n, maxPr;
    cin >> n >> maxPr;
    vector<int> books(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    // vector<vector<int>> dp(n, vector<int>(maxPr+1, -1));
    vector<vector<int>> dp(n+1, vector<int>(maxPr + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int mxPr = 0; mxPr <= maxPr; mxPr++)
        {
            
            int take = 0;
            if (mxPr >= books[ind])
            {
                take = pages[ind] + dp[ind+1][mxPr-books[ind]];
            }
            int notTake = dp[ind+1][mxPr];
            dp[ind][mxPr] = max(take, notTake);
        }
    }
    int ans = dp[0][maxPr];
    cout<<ans<<endl;
    // int ans = func(0, maxPr, n, books, pages, dp);
    // cout<<ans<<endl;
} 
int func(int ind, int mxPr, int n, vector<int> books, vector<int> pages, vector<vector<int>> &dp)
{
    if (ind >= n)
    {
        return 0;
    }
    if (dp[ind][mxPr] != -1)
    {
        return dp[ind][mxPr];
    }
    int take = 0;
    if (mxPr >= books[ind])
    {
        take = pages[ind] + func(ind + 1, mxPr - books[ind], n, books, pages, dp);
    }
    int notTake = func(ind + 1, mxPr, n, books, pages, dp);
    return dp[ind][mxPr] = max(take, notTake);
}
