#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int i , A[n] , B[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<n;i++)
        cin>>B[i];
    int diff[n];
    for(i=0;i<n;i++)
        diff[i]=A[i]-B[i];
    sort(diff,diff+n);
    long long int ans=0;
    for(i=0;i<n-1;i++)
        ans+= n-( upper_bound(diff+i+1,diff+n,0-diff[i]) - diff );
    cout<<ans;
    return 0;
}