#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    
    vector<vector<int>>arr(n+1,vector<int>(2));
    for(int i=1;i<=n;i++)
        cin>>arr[i][0]>>arr[i][1];
        
    vector<int>ans(n+1,0);
    
    ans[1]=1;
    int s1 = arr[1][0] , s2 = arr[1][1] ;
    if(arr[s1][0]==s2 || arr[s1][1]==s2)
    {
        ans[2] = s1;
        ans[3] = s2;
    }
    else
    {
        ans[2] = s2 ;
        ans[3] = s1 ;
    }
    
    for(int i=1;i<=n;i++)
    {
        int val = ans[i] ;
        arr[val][0]==ans[i+1] ? ans[i+2] = arr[val][1] : ans[i+2] = arr[val][0] ;
    }
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
        
    return 0;
}