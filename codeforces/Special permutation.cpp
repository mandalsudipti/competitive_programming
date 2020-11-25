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
        vector<int>arr(n+1);
        for(int i=1;i<n;i++)
            arr[i] = i+1 ;
        arr[n] = 1;
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}