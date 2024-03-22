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
    long long int t;
    cin>>t;
    while(t--){

    solve();
    }
}
void solve(){
    long long int x, y;
    cin>>x>>y;
    long long int mx = max(x, y);
    long long int sqr = (mx-1)*(mx-1);
    if(mx%2==0){
        if(x>=y){
            cout<< mx*mx-y+1;
        }else{
            cout<< (mx-1)*(mx-1) + x;
        }
    }else{
        if(x>=y){
            cout<<sqr+y;
        }else{
            cout<<mx*mx-x+1;
        }
    }
    cout<<endl;
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