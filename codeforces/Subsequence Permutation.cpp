#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        string S , T ;
        cin>>S ;
        T = S ;
        sort(T.begin() , T.end()) ;
        
        int k = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] != T[i])
                k++ ;
        }
        cout<<k<<endl;
    }
    return 0 ;
}