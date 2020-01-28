#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    long long int arr[n];
    int len[n], removed_len[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    removed_len[0]=len[0]=1;
    if(n>1)
    {
        for(i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                len[i]=len[i-1]+1;
                removed_len[i]=removed_len[i-1]+1;
            }
            else
            {
                len[i]=removed_len[i]=1;
            }
            if(i-2>=0 && arr[i-2]<arr[i])
                removed_len[i]=max(removed_len[i],len[i-2]+1);
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
        ans= max(ans, max(len[i],removed_len[i]));
    cout<<ans;
    return 0;
}
