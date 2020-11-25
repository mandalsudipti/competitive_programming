#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<vector<long long int>>arr(n+1,vector<long long int>(2,0));
        
        for(int i=1;i<=n;i++)
            cin>>arr[i][0];
            
        for(int i=1;i<=n;i++)
            cin>>arr[i][1];
            
        sort(arr.begin(),arr.end());
        
        long long int ans = arr[n][0] , x = 0 ;
        
        for(int i=n;i>0;i--)
        {
            if(x+arr[i][1]>ans)
                break;
            else
            {
                x+=arr[i][1];
                ans = max(arr[i-1][0],x);
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}