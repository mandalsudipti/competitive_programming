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
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end(),greater<long long int>());
        for(int i=1;i<n;i++)
        {
            if(k<=0)
                break;
            arr[0]+=arr[i];
            k--;
        }
        
        cout<<arr[0]<<endl;
    }
    
    return 0;
}
