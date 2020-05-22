#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        long long int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long int minimum_diff = 2000000000 , x ;
        for(int i=0;i+k<n;i++)
        {
            long long int mid = (arr[i]+arr[i+k])/2;
            long long int diff = max(mid-arr[i],arr[i+k]-mid);
            if(diff<minimum_diff)
            {
                minimum_diff=diff;
                x=mid;
            }
        }
        cout<<x<<endl;
    }
    return 0;
}

