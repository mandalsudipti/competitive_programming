#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , x ;
        cin>>n>>x;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end(),greater<long long int>());
        
        int start = 0 , cnt = 0 ;
        for(int i=0;i<n;i++)
        {
            if(arr[i]*(i-start+1)>=x)
            {
                cnt++;
                start = i+1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}