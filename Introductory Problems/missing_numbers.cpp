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
    long long int sm = 0;
    for(int i=1; i<n; i++){
        long long int tmp;
        cin>>tmp;
        sm += tmp;
    }
    cout<<(n*(n+1)/2) - sm;
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