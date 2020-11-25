#include<bits/stdc++.h>
using namespace std;

long long int square( long long int n)
{
    return n*n ;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int d , k ;
        cin>>d>>k;
        
        long long int left = 0 , right = (d/k) + (d%k!=0) ;
        
        while(right - left > 1)
        {
            long long int mid = (left + right) / 2 ;
            if(2*square(k*mid) <= (d*d))
                left = mid ;
            else
                right = mid ;
        }
        
        long long int ans = left ;
        if( square(k*ans) + square(k*(ans + 1)) <= square(d) )
            cout<<"Ashish"<<endl;
        else
            cout<<"Utkarsh"<<endl;
    }
    
    return 0;
}