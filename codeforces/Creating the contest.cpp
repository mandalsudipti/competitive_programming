#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>arr(n);
    vector<int>ans;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int cnt = 1 ;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=arr[i-1]*2)
            cnt++;
        if(i==n-1 || arr[i]>arr[i-1]*2)
        {
            ans.push_back(cnt);
            cnt = 1 ;
        }
    }
    int maximum = 1 ;
    for(int i=0;i<ans.size();i++)
        maximum = max(ans[i],maximum);
        
    cout<<maximum<<endl;
    
    return 0;
}