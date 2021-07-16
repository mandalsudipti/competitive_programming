#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n , a, b ;
        cin>>n>>a>>b;
        string S ;
        cin>>S;
        
        long long int point = n*a ;
        
        if(b >= 0)
            point+=(n*b) ;
        else
        {
            long long int segment = 1 ;
            int start = 0 ;
            for(int i = 1 ; i < n ; i++)
            {
                if(S[i] != S[start])
                {
                    segment++;
                    start = i ;
                }
            }
            
            point+=(( (segment/2) + 1)*b) ;
        }
        
        cout<<point<<endl;
    }
    return 0 ;
}