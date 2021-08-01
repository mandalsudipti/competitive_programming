#include<bits/stdc++.h>
using namespace std ;

bool get_subsequence(string& S , string& T , int start)
{
    int parity = (start%2 == 0 ? 1 : 0) , idx = 0;
    for(int i = start ; i < S.length() ; i++)
    {
        if(idx >= T.length())
        {
            if((S.length() - i)%2 == 0)
                return true ;
            else
                return false;
        }
        if(i%2 != parity && S[i] == T[idx])
        {
            idx++ ;
            parity = i%2 ;
        }
    }
    
    if(idx >= T.length())
        return true ;
    else
        return false ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string S , T ;
        cin>>S>>T ;
        
        bool possible = false ;
        for(int i = 0 ; i < S.length() ; i+=2)
        {
            if(S[i] == T[0])
            {
                possible = get_subsequence(S , T , i) ;
                break;
            }
        }
        
        if(!possible)
        {
            for(int i = 1 ; i < S.length() ; i+=2)
            {
                if(S[i] == T[0])
                {
                    possible = get_subsequence(S , T , i);
                    break;
                }
            }
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}
