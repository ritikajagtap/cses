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
    long long int n;
    cin>>n;
    long long int sm = (n*(n+1))/2;
    if(sm%2){cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    vector<int> s1;
    vector<int> s2;
    long long int ans = sm/2;
    for(int i=n; i>=1; i--){
        if(i<=ans){
            s1.push_back(i);
            ans -=i;
        }else{
            s2.push_back(i);

        }
    }
    cout<<s1.size()<<endl;
    sort(s1.begin(), s1.end());
    for(auto i: s1){cout<<i<<" ";}
    cout<<endl;
    sort(s2.begin(), s2.end());
    cout<<s2.size()<<endl;
    for(auto i: s2){cout<<i<<" ";}
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
