#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<long long int,long long int>>arr(n);
    long long int a , b ;
    long long int sum=0 ;
    vector<long long int>diff(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        diff[i] = (a-b);
        sum+= b*(n-1) ;
    }
    sort(diff.begin(),diff.end(),greater<long long int>());
    for(int i=0;i<n;i++)
        sum+=(diff[i]*i);
    cout<<sum<<endl;
    
    return 0;
}