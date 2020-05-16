#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    vector<int>cnt(n+1,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            if(arr[i]<arr[j])
            {
                cnt[j]=max(cnt[j],cnt[i]+1);
            }
        }
    }
    int max_cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>max_cnt)
            max_cnt=cnt[i];
    }
    cout<<max_cnt<<endl;
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