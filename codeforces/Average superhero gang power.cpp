#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k , m ;
    cin>>n>>k>>m;
    
    long double arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<long double>());
    
    int ele = n ;
    for(int i=n-1;i>0;i--)
    {
        if(m>0 && arr[i]<arr[0])
        {
            ele--;
            m--;
        }
        else if(m>1 && arr[i]<=arr[0])
        {
            ele--;
            m--;
        }
        else
            break;
    }
    //cout<<ele<<endl;
    long double avg = 0 ;
    for(int i=0;i<ele;i++)
    {
        arr[i]+=min(k,m);
        m-=min(k,m);
        avg+=arr[i];
    }
    int x = ele ;
    for(int i=x;i<n;i++)
    {
        m++;
        if(arr[i]+min(k,m)>=arr[0])
        {
            arr[i]+=min(k,m);
            m-=min(k,m);
            avg+=arr[i];
            ele++;
        }
        else
            break;
    }
    cout<<fixed<<setprecision(18)<<avg/ele;
    
    return 0;
}


