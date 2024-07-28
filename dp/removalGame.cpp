#include <bits/stdc++.h>
using namespace std;
int func(bool a, int i, int j, int n, vector<int> arr);
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = func(1, 0, n-1, n, arr);
    cout<<ans<<endl;
}

int func(bool a, int i, int j, int n, vector<int> arr)
{
    if (i > j || j < i)
    {
        return 0;
    }
    int pickFirst;
    int pickLast;
    if (a == 1)
    {
        pickFirst = arr[i] + func(0, i + 1, j, n, arr);
        pickLast = arr[j] + func(0, i, j - 1, n, arr);
    }
    else
    {
        pickFirst = func(1, i + 1, j, n, arr);
        pickLast = func(1, i, j - 1, n, arr);
    }
    return max(pickFirst, pickLast);
}