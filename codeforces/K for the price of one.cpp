#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,p,k;
    cin>>n>>p>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int maximum = 0,pre=0;
    for(int i=0;i<=k;i++)
    {
        int sum=pre,cnt=i;
        if(sum>p)
            break;
        for(int j=i+k-1;j<n;j+=k)
        {
            sum+=arr[j];
            if(sum<=p)
                cnt+=k;
            else
                break;
        }
        pre+=arr[i];
        maximum = max(maximum,cnt);
    }
    cout<<maximum<<endl;
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




