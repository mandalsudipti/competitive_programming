#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<pair<long long , long long>> arr(n);
    long long x , y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arr[i]=make_pair(x,y);
    }
    vector<long long>ans;
    long long cur =0 ;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            cur = (arr[i].first>arr[n-1].second?arr[i].first-arr[n-1].second:0);
        else
            cur = (arr[i].first>arr[i-1].second?arr[i].first-arr[i-1].second:0);
        ans.push_back(cur);
    }
    int min_idx=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].first-ans[i]< arr[min_idx].first-ans[min_idx])
          min_idx=i;  
    }
    ans[min_idx]=arr[min_idx].first;
    long long total_bullet =0 ;
    for(int i=0;i<n;i++)
        total_bullet+=ans[i];
        
    cout<<total_bullet<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
