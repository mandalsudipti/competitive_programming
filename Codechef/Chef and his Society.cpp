#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , th ;
        cin>>n>>th;
        long long int arr[n] , diff[n] , x=0 ;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long int tmp=0;
        for(int i=1;i<n;i++)
            tmp+= arr[i]-arr[0] ;
        diff[0]=tmp;
        for(int i=1;i<n;i++)
            diff[i] = diff[i-1]-(arr[i]-arr[i-1])*(n-i) ;
        long long int idx=-1 ;
        for(int i=0;i<n;i++)
        {
            if(th>=diff[i])
            {
                idx = i;
                break;
            }
        }
        //cout<<arr[idx]<<endl;
        long long int inc = ((th-diff[idx])/(n-idx)) + ((th-diff[idx])%(n-idx)!=0) ;
        long long int  M = arr[idx]-inc;
        long long int S = diff[idx]+ (n-idx)*inc ;
        cout<<M<<" "<<S<<endl;
    }
    return 0;
}