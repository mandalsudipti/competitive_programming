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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(arr[0]<arr[n-1])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}