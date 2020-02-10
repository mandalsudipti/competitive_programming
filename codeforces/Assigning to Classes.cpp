#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long int arr[2*n] , i , diff=-1 ;
        for(i=0;i<2*n;i++)
            cin>>arr[i];
        sort(arr,arr+(2*n));
        
        diff = abs(arr[n]-arr[n-1]);
        cout<<diff<<endl;
    }
    return 0;
}