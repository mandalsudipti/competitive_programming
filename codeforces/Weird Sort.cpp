#include<bits/stdc++.h>
using namespace std;

void non_decreasing(int arr[],int n)
{
    /*for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i]>=0)
            continue;
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

void solve()
{
    int n , m ;
    cin>>n>>m;
    int arr[n],swap[m],i,j;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<m;i++)
        {
            cin>>swap[i];
            swap[i]--;
        }
    sort(swap,swap+m);
    int start , end;
    if(m==1)
    {
        start=swap[0];
        end=min(start+1,n-1);
        sort(arr+start,arr+end+1);
        non_decreasing(arr,n);
        return;
    }
    start=swap[0]; end=start+1; i=1;
    while(i<m)
    {
        while(i<m && swap[i]-swap[i-1]==1)
        {
             end=min(end+1,n-1);
             i++;
        }
        if(i>=m || swap[i]-swap[i-1]!=1)
        {
            sort(arr+start,arr+end+1);
            if(i<m)
            {
                start=swap[i];
                end=min(start+1,n-1);
                i++;
            }
        }
    }
    sort(arr+start,arr+end+1);
    non_decreasing(arr,n);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}

