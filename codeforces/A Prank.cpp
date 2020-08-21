#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    
    int cnt = 0 , max_cnt = 0 ;
    for(int i=0;i<n;i++)
    {
        if((i==0 && arr[i+1]==2) || (i==n-1 && arr[i-1]==999))
            cnt++;
        else if((n>=3) && (arr[i+1]-arr[i]==1 && arr[i]-arr[i-1]==1))
            cnt++;
            
        if(i==0)
            continue;
        if(i==n-1 || (arr[i+1]-arr[i]!=1 || arr[i]-arr[i-1]!=1))
        {
            max_cnt = max(max_cnt , cnt);
            cnt = 0 ;
        }
    }
    
    cout<<max_cnt;
    return 0;
}


