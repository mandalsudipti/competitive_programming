#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n ;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    vector<long long int>dp_negetive(n,0);
    int start=-1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(arr[i]<0)
            {
                dp_negetive[i]=1;
                start=0;
            }
            continue;
        }
        if(arr[i]>0)
            dp_negetive[i]=dp_negetive[i-1];
        else
        {
            dp_negetive[i]+=(i-start);
            if(start>0)
                dp_negetive[i]+=dp_negetive[start-1];
            start=i;
        }
    }
    long long int total_positive = 0 , total_negetive = 0;
    for(int i=0;i<n;i++)
    {
        total_negetive+=dp_negetive[i];
        //cout<<dp_negetive[i]<<" ";
    }
        
    total_positive = (n*(n+1ll))/2ll - total_negetive ;
    
    cout<<total_negetive<<" "<<total_positive;
    return 0;
}
