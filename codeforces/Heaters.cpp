#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , r ;
    cin>>n>>r;
    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int cnt = 0 , start = 1-r, cur = 0 , idx=1;
    while(idx<=n)
    {
        if(idx>start+(2*r-2)+1)
        {
            cout<<"-1";
            return 0;
        }
        if(arr[idx]==1)
            cur=idx;
        if(idx==start+(2*r-2)+1 && cur!=start && cur>=1)
        {
            cnt++;
            start = cur ;
        }
        idx++;
    }
    bool all_zero = true ;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]!=0)
        {
            all_zero = false;
            break;
        }
    }
    if(all_zero)
    {
        cout<<"-1";
        return 0;
    }
    if(n-start>r-1)
    {
        bool possible = false ;
        for(int i=n;i>=start+1;i--)
        {
            if(arr[i]==1 &&(n-i)<=r-1)
            {
                cnt++;
                possible = true;
                break;
            }
        }
        if(!possible)
        {
            cout<<"-1";
            return 0;
        }
    }
    
    cout<<cnt;
    return 0;
    
}

