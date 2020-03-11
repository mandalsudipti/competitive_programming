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
        int i , arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}