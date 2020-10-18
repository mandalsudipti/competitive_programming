#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n ;
    cin>>n;
    
    vector<long long int>arr(n+1,0);
    long long int sum = 0 ;
    int idx = 1 ;
    for(int i=2;i<=n;i++)
    {
        int rem1 , rem2  ;
        cout<<"? "<<idx<<" "<<i<<endl;
        fflush(stdout);
        cin>>rem1;
        fflush(stdout);
        cout<<"? "<<i<<" "<<idx<<endl;
        fflush(stdout);
        cin>>rem2;
        fflush(stdout);
        
        if(rem1==-1 || rem2==-1)
            exit(0);
            
        if(rem1>=rem2)
        {
            arr[idx] = rem1 ;
            idx = i ;
            sum+=rem1;
        }
        else
        {
            arr[i] = rem2 ;
            sum+=rem2;
        }
    }
    if(arr[idx]==0)
        arr[idx] = (n*(n+1))/2 - sum ;
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}