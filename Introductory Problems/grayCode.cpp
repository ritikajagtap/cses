/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;

void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const long long int MOD = 1e9 + 7;

const int maxN = 16;

int N;
bool b[maxN+1];

void print(){
    for(int i = N; i > 0; i--)
        printf("%d", b[i]);
    printf("\n");
}
int main()
{
    scanf("%d", &N);
    print();
    for(int i = 1; i < (1<<N); i++){
        int LSB = __builtin_ffs(i);
      //  cout<<LSB<<endl;
        b[LSB] ^= 1;
        print();
    }

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
