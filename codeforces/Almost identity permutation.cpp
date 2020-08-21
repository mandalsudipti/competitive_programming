#include<bits/stdc++.h>
using namespace std;

long long int nCr(long long int n , int r)
{
    if(r==0)
        return 1;
    else if(r==1)
        return n;
    else if(r==2)
        return (n*(n-1))/2 ;
    else if(r==3)
        return (n*(n-1)*(n-2))/6 ;
    else
        return (n*(n-1)*(n-2)*(n-3))/24 ;
}

int main()
{
    int n , k ;
    vector<long long int>combination = { 1 , 0 , 1 , 2, 9 } ;
    
    cin>>n>>k;
    
    long long int sum = 0 ;
    for(int i=0;i<=k;i++)
    {
        sum+=(combination[i]*nCr(n,i));
    }
    
    cout<<sum;
    
    return 0;
}