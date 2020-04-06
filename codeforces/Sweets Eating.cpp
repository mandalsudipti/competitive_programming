#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    cin>>n>>k;
    long long int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    vector<long long int>ans;
    vector<long long int>add_each_step(k) ;
    
    ans.push_back(arr[0]);
    for(i=0;i<k;i++)
        add_each_step[i]=arr[i];
        
    for(i=1;i<n;i++)
    {
        long long int sum = ans.back()+arr[i];
        long long int ele = (i/k);
        long long int idx = i%k ;
        /*while(ele>0 && idx<n)
        {
            sum+=arr[idx];
            idx+=k;
            ele--;
        }*/
        if(ele==1)
            sum=sum+add_each_step[idx];
        else if(ele>1)
        {
            add_each_step[idx]+=arr[idx+k*(ele-1)];
            sum=sum+add_each_step[idx];
        }
        ans.push_back(sum);
    }
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
