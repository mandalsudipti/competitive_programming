#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int i , A[n+1];
    for(i=1;i<=n;i++)
        cin>>A[i]; 
    long long int diff[n];
    for(i=1;i<n;i++)
         diff[i]=abs(A[i]-A[i+1]); 
        
    long long int last_added[n],last_removed[n],maximum=diff[1];
    memset(last_added,0,sizeof(last_added));
    memset(last_removed,0,sizeof(last_removed));
    last_added[1]=diff[1];
    for(i=2;i<n;i++)
    {
        last_added[i]=max(0ll,last_removed[i-1])+diff[i];
        last_removed[i]=last_added[i-1]-diff[i];
        maximum= max(maximum,max(last_added[i],last_removed[i]));
    }
    
    cout<<maximum;
    return 0;
}



