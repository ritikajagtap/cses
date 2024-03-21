/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;

void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const int N = 200001;

int main()
{
    solve();
}
void solve(){
    long long int n;
    cin>>n;
    if(n==1){cout<<"1 ";}
    if(n==3 || n==2){cout<<"NO SOLUTION"; return;}
    for(int i = 2; i<=n; i+=2){
        cout<<i<<" ";
    }
    for(int i=1; i<=n; i+=2){
        cout<<i<<" ";
    }
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