/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;

void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
int f(int i, int j, int ptr, string s);
const int N = 200001;

int main()
{
    solve();
}
void solve(){
    vector<vector<int>> vis(7, vector<int>(7, 0));
    string s;
    cin>>s;
    int z = f(0, 0, 0, s, vis);
    cout<<z;
}
int f(int i, int j, int ptr, string s, vector<vector<int>> &vis){
    if(i == 6 && j==0 
){
        return 1;
    }
    vis[i][j] = 1;
    int r = 0, l=0, u=0, d=0;
    if(s[ptr] != '?'){
        if(s[ptr] == 'R' && j<6 && vis[i][j+1]==0){
            r = f(i, j+1, ptr+1, s, vis);
        }else if(s[ptr] == 'U' && i>0 && vis[i-1][j]==0){
            u = f(i-1, j, ptr+1, s, vis);
        }else if(s[ptr] == 'D' && i<6 && vis[i+1][j]==0){
            d = f(i+1, j, ptr+1, s, vis);
        }else if(s[ptr]=='L' && j>0 && vis[i][j-1]==0){
            l = f(i, j-1, ptr+1, s, vis);
        }
    }else{
        if(i>0 && vis[i-1][j]==0){u = f(i-1, j, ptr+1, s, vis);}
        if(j<6 && vis[i][j+1]==0){r = f(i, j+1, ptr+1, s, vis);}
        if(i<6 && vis[i+1][j]==0){d = f(i+1, j, ptr+1, s, vis);}
        if(j>0 && vis[i][j-1]==0){l = f(i, j-1, ptr+1, s, vis);}
    }
    vis[i][j] = 0;
    return u+d+r+l;
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