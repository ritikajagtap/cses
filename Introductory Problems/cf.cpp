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

    // solve();
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}

void solve()
{
    string st;
    cin>>st;
    int n = st.size();
    for(int i=0; i<n/2; i++){
        if(st[i] != st[n-i-1]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
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
