#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int cnt(int sm, int target, vector<int> &dp);
int main(){
    int target;
    cin>>target;
    vector<int> dp(target+2, -1);
    int ans = cnt(0, target, dp);
    cout<<ans<<endl;
}
int cnt(int sm, int target, vector<int> &dp){
    if(sm>target){return 0;}
    if(sm==target){return 1;}
    if(dp[sm]!=-1){return dp[sm];}
    int take =0;
    for(int i=1; i<=6; i++){
        if(sm+i<=target){
            take = (take + cnt(sm+i, target, dp))%mod;
        }
        if(sm+i>target){break;}
    }
    return dp[sm]=take%mod;
}