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
    string s;
    cin>>s;
    map<char, int> mp;
    for(auto it: s){
        mp[it]++;
    }
    bool flag = 0;
    pair<char, int> mid;
    for(auto it: mp){
        if(it.second%2==1 && !flag){mid = it; flag=1; continue;}
        if(it.second % 2 == 1 && flag){cout<<"NO SOLUTION"<<endl; return 0;}
    }
    string stnew = "";
    for(auto it: mp){
        if(it.second%2 == 0){
            for(int i=0; i<it.second/2; i++){
                stnew += it.first;
                cout<<it.first;
            }
        }
    }
    reverse(stnew.begin(), stnew.end());
    for(int i=0; i<mid.second; i++){
        cout<<mid.first;
    }
    cout<<stnew;

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
