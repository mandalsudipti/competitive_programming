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
        
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        sort(arr.begin(),arr.end());
        if(arr[n-1]>k)
        {
            cout<<"0";
            continue;
        }
        
        long long int cnt = 0 ;
        for(int i=1;i<n;i++)
            cnt+=(k-arr[i])/arr[0];
            
        cout<<cnt<<endl;
    }
    
    return 0;
}