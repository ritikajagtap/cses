#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;
    set<int> st;
    while(n--){
        int x;
        cin>>x;
        if(st.empty()){
            st.insert(x);
            continue;
        }
        vector<int> tt;
        for(auto it: st){
            tt.push_back(it+x);
        }
        st.insert(x);
        for(auto it: tt){
            st.insert(it);
        }
    }
    cout<<st.size()<<endl;
    for(auto it: st){
        cout<<it<<" ";
    }
    
}

