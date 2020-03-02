#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    long long int i , j, x , arr[100005];
    memset(arr,0,sizeof(arr));
    for(i=1;i<=n;i++)
    {
        cin>>x;
        arr[x]+=x;
    }
    
    long long int first_max = 1 , sec_max = 1 ;
    for(i=2;i<100005;i++)
    {
        if(first_max < i-1)
            arr[i]+=arr[first_max];
        else if(sec_max<i-1)
            arr[i]+=arr[sec_max];
            
        if(arr[i]>arr[first_max])
        {
            sec_max = first_max ;
            first_max = i;
        }
        else if (arr[i]> arr[sec_max])
        {
            sec_max = i;
        }
        //cout<<i<<" "<<first_max<<" "<<sec_max<<endl;
    }
    sort(arr,arr+100005,greater<long long int>());
    cout<<arr[0];
    return 0;
}


