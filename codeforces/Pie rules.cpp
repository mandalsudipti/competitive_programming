#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long int>arr(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    if(N==1)
    {
        cout<<"0"<<" "<<arr[0];
        return 0;
    }
    vector<int>idx(N,0);
    idx[N-2] = 1 ;
    vector<long long int>sum(3,0);
    sum[1] = max(arr[N-2],arr[N-1]);
    sum[2] = min(arr[N-2],arr[N-1]);
    
    if(N-3>=0)
    {
        for(int i=N-3;i>=0;i--)
     {
        sum[3 - idx[i+1]]+=arr[i];
        if(sum[3-idx[i+1]]>=sum[idx[i+1]])
            idx[i] = 3 - idx[i+1] ;
        else
            idx[i] = idx[i+1] ;
     }
    }
    
    cout<<sum[3 - idx[0]]<<" "<<sum[idx[0]];
    
    return 0;
}

