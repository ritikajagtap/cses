#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1, 1e9);
    dp[0]=0;
    for(int i=1; i<=n; i++){
        string num = to_string(i);
        for(char ch : num){
            int dig = ch-'0';
            if(dig!=0){
                dp[i] = min(dp[i], dp[i-dig]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}

