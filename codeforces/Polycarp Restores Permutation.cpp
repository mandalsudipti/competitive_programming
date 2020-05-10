#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int ele , prefix_sum[n];
    for(int i=1;i<n;i++)
    {
        cin>>ele;
        if(i==1)
        {
            prefix_sum[i]=ele;
            continue;
        }
        prefix_sum[i]=prefix_sum[i-1]+ele;
    }
    long long int minimum = prefix_sum[1] , maximum = prefix_sum[n-1] , min_x , max_x ;
    for(int i=2;i<n;i++)
    {
        if(prefix_sum[i]<minimum)
            minimum = prefix_sum[i];
        if(prefix_sum[i]>maximum)
            maximum=prefix_sum[i];
    }
    min_x = 1 - minimum ;
    max_x = n - maximum ;
    if(min_x<1)
    {
        min_x=1;
        if(min_x>max_x)
        {
            cout<<"-1";
            return 0;
        }
    }
    vector<bool>permutation(n+1,false);
    vector<long long int>ans(n);
    ans[0]=min_x;
    if(min_x<=n && min_x>=1)
        permutation[min_x]=true;
    for(int i=1;i<n;i++)
    {
        ans[i]=prefix_sum[i]+min_x;
        if(ans[i]>n || ans[i]<1)
        {
            cout<<"-1";
            return 0;
        }
        permutation[ans[i]]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(permutation[i]==false)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}


