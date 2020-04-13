#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int arr[n+1],i;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    vector<vector<bool>>dp(n+1,vector<bool>(6,false));
    for(int i=1;i<=n;i++)
    {
        for(int finger=1;finger<=5;finger++)
        {
            if(i==1)
            {
                dp[i][finger]=true;
            }
            if(arr[i]>=arr[i-1])
            {
                for(int j=1;j<finger;j++)
                {
                    if(dp[i-1][j]==true)
                        dp[i][finger]=true;
                }
            }
            if(arr[i]<=arr[i-1])
            {
                for(int j=5;j>finger;j--)
                {
                    if(dp[i-1][j]==true)
                        dp[i][finger]=true;
                }
            }
        }
    }
    vector<int>ans(n+1,0);
    for(int i=n;i>=1;i--)
    {
        if(i==n)
        {
            for(int j=1;j<=5;j++)
            {
                if(dp[i][j]==true)
                {
                    ans[i]=j;
                    break;
                }
            }
            continue;
        }
        if(arr[i]<arr[i+1])
        {
            for(int j=ans[i+1]-1;j>=1;j--)
            {
                if(dp[i][j]==true)
                {
                    ans[i]=j;
                    break;
                }
            }
        }
        else if(arr[i]>arr[i+1])
        {
            for(int j=ans[i+1]+1;j<=5;j++)
            {
                if(dp[i][j]==true)
                {
                    ans[i]=j;
                    break;
                }
            }
        }
        else if (arr[i]==arr[i+1])
        {
            for(int j=1;j<=5;j++)
            {
                if(dp[i][j]==true && ans[i+1]!=j)
                {
                    ans[i]=j;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}


