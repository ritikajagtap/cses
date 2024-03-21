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
    string str;
    cin>> str;
    int tmp= 1;
    int best = 1;
    for(int i=1; i<str.size(); i++){
        if(str[i-1]==str[i]){
            tmp ++;
        }else{
            tmp = 1;
        }
        best = max(tmp, best);
    }
    cout<<best;
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