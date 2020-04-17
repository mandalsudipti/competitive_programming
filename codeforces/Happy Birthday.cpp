#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[10],i;
    for(int i=0;i<10;i++)
         cin>>arr[i]; 
        
    for(int i=1;i<10;i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<endl;
            return;
        }
    }
    
    string S;
    int min_freq_idx=1;
    for(int i=1;i<10;i++)
    {
        if(arr[min_freq_idx]>arr[i])
            min_freq_idx=i;
    }
    if(arr[0]<arr[min_freq_idx])
        min_freq_idx=0;
        
    if(min_freq_idx==0)
    {
        S='1';
        arr[1]--;
        if(arr[1]<arr[min_freq_idx])
            min_freq_idx=1;
    }
    for(int i=1;i<=(arr[min_freq_idx]+1);i++)
            S+=(min_freq_idx+48);
    cout<<S<<endl;
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
