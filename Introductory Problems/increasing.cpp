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
    long long int moves = 0;
    long long int n;
    cin>>n;
    long long int prev;
    cin>>prev;
    for(int i=1; i<n; i++){
        long long int tmp;
        cin>>tmp;
      //  cout<<"tmp: "<<tmp<<endl;
        if(prev>tmp){
            moves += (prev-tmp);
           // cout<<"moves: "<<moves<<endl;
            continue;
        }
        prev = tmp;
        
    }
    cout<<moves;
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