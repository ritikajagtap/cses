/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;

void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const long long int MOD = 1e9 + 7;

int main()
{
    long long int n;
    cin>>n;
    long long int ans =1;
    for(int i=0; i<n; i++){
        ans *= 2;
        ans = ans%MOD;
    }
    cout<<ans;
    return 0;
}

void solve()
{
    
}
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
