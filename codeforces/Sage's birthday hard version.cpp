#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>cost(n);
    
    for(int i=0;i<n;i++)
        cin>>cost[i];
    sort(cost.begin(),cost.end());
    vector<long long int>ans(n);
    
    int idx = 0 ;
    for(int i=1;i<n;i+=2)
    {
        ans[i] = cost[idx];
        idx++;
    }
    for(int i=0;i<n;i+=2)
    {
        ans[i]=cost[idx];
        idx++;
    }
    
    int cnt = 0 ;
    for(int i=1;i<n;i+=2)
    {
        if(i+1<n)
        {
            if(ans[i]<ans[i-1] && ans[i]<ans[i+1])
                cnt++;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
        
    return 0;
}
