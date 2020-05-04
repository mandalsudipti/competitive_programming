#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double arr[n] , ten=10;
    long long int ans[n] , sum = 0 ;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans[i]=arr[i];
        sum+=ans[i];
    }
    if(sum>0)
    {
        for(int i=0;i<n;i++)
        {
            if(sum>0)
            {
                if(arr[i]<0 && arr[i]!=(double)(ans[i]))
                {
                    ans[i]--;
                    sum--;
                }
                
            }
        }
    }
    else if(sum<0)
    {
        for(int i=0;i<n;i++)
        {
            if(sum<0)
            {
                if(arr[i]>0 && arr[i]!=(double)(ans[i]))
                {
                    ans[i]++;
                    sum++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
        
    return 0;
}
