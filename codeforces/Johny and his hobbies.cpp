#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    set<long long int>S;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        S.insert(arr[i]);
    }
    long long int ans = INT_MAX;
    bool possible = false;
    for(int i=1;i<n;i++)
    {
        long long int x  = arr[0]^arr[i] ;
        set<long long int>tmp;
        tmp.insert(arr[0]);
        tmp.insert(arr[i]);
        for(int j=1;j<n;j++)
        {
            if(j!=i)
            {
                long long int y = arr[j]^x;
                tmp.insert(y);
            }
        }
        if(S==tmp)
        {
            possible =true;
            ans = min(ans,x);
        }
    }
    if(!possible)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}