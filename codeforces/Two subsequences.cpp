#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string S ;
        cin>>S;
        
        string S1 = "" , S2 = "" ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(i == 0)
                S1+=S[0] ;
            else if(S1[0] > S[i])
                S1[0] = S[i] ;
        }
        
        bool removed = false ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] != S1[0] || removed)
                S2+=S[i] ;
            else
                removed = true ;
        }
        
        cout<<S1<<" "<<S2<<endl;
    }
    return 0 ;
}