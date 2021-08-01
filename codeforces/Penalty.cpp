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
        
        int A_fixed = 0 , A_var = 0 , B_fixed = 0 , B_var = 0 , stop = 10;
        int A_rem = (S.length()/2) + (S.length()%2) ;
        int B_rem = S.length() - A_rem ;
        
        for(int i = 0 ; i < 9 ; i++)
        {
            if(S[i] == '?')
               i%2 == 0 ? A_var++ : B_var++ ;
            else if(S[i] == '1')
                i%2 == 0 ? A_fixed++ : B_fixed++ ;
                
            i%2 == 0 ? A_rem-- : B_rem-- ;
            
            if( (A_fixed + A_var - B_fixed > B_rem)||( B_fixed + B_var - A_fixed > A_rem) )
            {
                stop = i+1 ;
                break;
            }
        }
        
        cout<<stop<<endl;
    }
    return  0;
}