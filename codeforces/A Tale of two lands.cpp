#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long int>arr(n);
    vector<long long int>diff(n);
    long long int val ;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        arr[i]=abs(val);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        diff[i]=arr[i]-arr[0];
        
    long long int pre_diff=0 , cnt=0;
    for(int i=0;i<n-1;i++)
    {
        pre_diff = arr[i]-arr[0] ;
        int idx = lower_bound(diff.begin(),diff.end(),arr[i]+pre_diff) - diff.begin();
        
        if(idx==n)
            idx--;
        if(diff[idx]>(arr[i]+pre_diff))
            idx--;
        if(idx+1<n && diff[idx+1]==(arr[i]+pre_diff))
            idx++;
            
        cnt+=(idx-i);
    }
    cout<<cnt;
    return 0;
}