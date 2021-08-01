#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string S , T ;
        cin>>S>>T ;
        
        bool found = false ;
        for(int right_move = 0 ; right_move < T.length() ; right_move++)
        {
            int left_move = T.length() - 1 - right_move ;
            for(int i = 0 ; i < S.length() ; i++)
            {
                if( (S[i] == T[0]) && (i+right_move < S.length()) && (i+right_move - left_move >= 0) )
                {
                    
                    bool possible = true ;
                    int idx = 1 ;
                    for(int j = i+1 ; j <= i + right_move ; j++)
                    {
                        if(S[j] != T[idx])
                        {
                            possible = false ;
                            break;
                        }
                        else
                            idx++ ;
                    }
                    
                    if(!possible)
                        continue;
                    for(int j = i + right_move - 1 ; j >= i + right_move - left_move ; j--)
                    {
                        if(S[j] != T[idx])
                        {
                            possible = false ;
                            break;
                        }
                        else
                            idx++;
                    }
                    if(possible)
                    {
                        found = true ;
                        break;
                    }
                }
            }
        }
        
        if(found)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}