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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int min_diff = 2000 ;
        for(int i=1;i<n;i++)
        {
            min_diff = min(min_diff , arr[i]-arr[i-1]) ;
        }
        cout<<min_diff<<endl;
    }
    return 0;
}