#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string S ;
        cin>>S ;
        
        int a = 0 , b = 0 , c = 0 ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == 'A')
                a++ ;
            else 
                S[i] == 'B' ? b++ : c++ ;
        }
        if(b == a + c)
            cout<<"YES\n" ;
        else
            cout<<"NO\n" ;
    }
    
    return 0 ;
}