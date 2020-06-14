#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a , long long int b)
{
    while(a!=0 && b!=0)
    {
        a>b? (a=a%b):(b=b%a);
    }
    if(a==0)
        return b;
    else    
        return a;
}

int main()
{
    int n ;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    if(n==1)
    {
        if(arr[0]==1)
            cout<<"0";
        else
            cout<<"-1";
        return 0;
    }
    long long int min_distance = n+10;
    for(int i=0;i<n-1;i++)
    {
        long long int tmp_gcd = arr[i] , tmp_distance = 0 ;
        if(arr[i]==1)
        {
            min_distance=0;
            break;
        }
        for(int j=i+1;j<n;j++)
        {
            tmp_gcd = gcd(arr[j],tmp_gcd);
            if(arr[j]==1)
            {
                min_distance=0;
                break;
            }
            if(tmp_gcd==1)
            {
                tmp_distance = (j-i);
                min_distance = min(min_distance,tmp_distance);
                break;
            }
        }
        if(min_distance==0)
            break;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=1)
            cnt++;
    }
    if(min_distance>=n)
        cout<<"-1";
    else if(min_distance==0)
        cout<<cnt;
    else
        cout<<min_distance+n-1;
    return 0;
}


