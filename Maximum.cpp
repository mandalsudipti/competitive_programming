#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int val,ans[n],i ,maximum=0;
    memset(ans,0,sizeof(ans));
    for(i=0;i<n;i++)
    {
        cin>>val;
        ans[i]=val + maximum ;
        maximum = max(maximum,ans[i]);
    }
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}