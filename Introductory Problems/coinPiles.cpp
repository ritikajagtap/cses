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
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

void solve()
{
    long long int a,b;
    cin>>a>>b;
    if(a>2*b || b>2*a){
        cout<<"NO"<<endl;
        return;
    }
    if((a+b)%3){cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;

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
