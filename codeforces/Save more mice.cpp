#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int hole , k , cat = 0;
        cin>>hole>>k ;
        
        vector<long long int>mice(k) ;
        for(int i = 0 ; i < k ; i++)
            cin>>mice[i] ;
            
        sort(mice.begin() , mice.end()) ;
        
        int saved = 0 ;
        for(int i = k-1 ; i >= 0 ; i--)
        {
            if(cat >= mice[i])
                break;
            
            saved++ ;
            cat+=(hole - mice[i]) ;
        }
        cout<<saved<<endl;
    }
    return 0 ;
}
