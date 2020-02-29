#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n , dist , step=0;
    cin>>n>>dist;
    int i , arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==dist)
            step=1;
    }
    if(step==1)
    {
        cout<<step<<endl;
        return;
    }
    sort(arr,arr+n);
    if(2*arr[n-1]>=dist)
    {
        cout<<"2\n";
        return;
    }
    step = (dist/arr[n-1])+(dist%arr[n-1]!=0);
    
    cout<<step<<endl;
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