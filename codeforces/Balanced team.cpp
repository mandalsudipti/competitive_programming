#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,  cnt=0 , i , j ;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(i=1;i<n;i++)
        arr[i]=arr[i]-arr[0];
    arr[0]=0;
    
    for(i=0;i<n;i++)
    {
        if(i+cnt<n)
        {
            for(j=i+cnt;j<n;j++)
            {
                if(arr[j]-arr[i]>5)
                    break;
                else 
                {
                    cnt = max (cnt , j-i+1);
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}

