#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool flag=true;
    long long int N;
    cin>>N;
    long long int arr[N],sorted_arr[N],i,max_idx,left,right;
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        sorted_arr[i]=arr[i];
    }
    sort(sorted_arr,sorted_arr+N);
    for(i=0;i<N;i++)
    {
        if(arr[i]==sorted_arr[N-1])
        {
            max_idx=i;
            break;
        }
    }
    left=max_idx-1;
    right=max_idx+1;
    for(i=N-2;i>=0;i--)
    {
        if(left>=0 && arr[left]==sorted_arr[i])
            left=left-1;
        else if(right<N && arr[right]==sorted_arr[i])
            right=right+1;
        else
        {
            cout<<"NO";
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"YES";
    return 0;
}
