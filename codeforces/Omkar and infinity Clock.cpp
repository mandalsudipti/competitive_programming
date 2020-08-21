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
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int maximum = arr[0] ;
        for(int i=1;i<n;i++)
            maximum = max(maximum,arr[i]);
        if(k%2)
        {
            for(int i=0;i<n;i++)
                cout<<maximum-arr[i]<<" ";
            cout<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
                arr[i] = maximum - arr[i];
                
            maximum = arr[0];
            for(int i=0;i<n;i++)
                maximum = max(maximum,arr[i]);
                
            for(int i=0;i<n;i++)
                cout<<maximum - arr[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}