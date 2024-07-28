#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxi = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (a[prev] < a[i] && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;
            }
            if (maxi < dp[i])
            {
                maxi = dp[i];
            }
        }
    }
    cout << maxi << endl;
}
