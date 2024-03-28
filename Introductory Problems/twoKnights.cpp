/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;

void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const long long int e = 1e9 + 7;

int main()
{
    auto ans = [](long long int k){
        long long int totalWays = (k*k*(k*k - 1))/2;
        long long int attacks = 4*(k-1)*(k-2);
        return totalWays-attacks;
    };
    long long int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cout<<ans(i)<<endl;
    }
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
