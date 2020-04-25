#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        long long int arr[n+1];
        vector<long long int> prefix(n+1,0);
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                prefix[i]=0;
                continue;
            }
            if(i==n)
            {
                prefix[i]=prefix[i-1];
                continue;
            }
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                prefix[i]=prefix[i-1]+1;
            else
                prefix[i]=prefix[i-1];
        }
        
        long long int left_border=1 , peak =0 , max_peak =0 ;
        for(int i=1;i+k-1<=n;i++)
        {
            peak = prefix[i+k-2]-prefix[i] ;
            //cout<<i<<" "<<i+k-1<<" "<<peak<<endl;
            if(peak>max_peak)
            {
                max_peak=peak;
                left_border = i;
            }
        }
        cout<<max_peak+1<<" "<<left_border<<endl;
    }
    return 0;
}

