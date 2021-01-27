#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        string S ;
        cin>>S;
        if(S[S.length() - 1] == '?')
            S[S.length() - 1] = ')' ;
            
        int opening = 0 ,closing = 0 ;
        for(int i = 0 ; i <S.length() ; i++)
        {
            if(S[i] == '(')
                opening++;
            else if(S[i] == ')')
                closing++;
        }
        
        if(S.length()%2 || opening > S.length()/2 || closing > S.length()/2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        opening = S.length()/2 - opening ;
        closing = S.length()/2 - closing ;
        
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == '?')
            {
                if(opening > 0)
                {
                    S[i] = '(';
                    opening--;
                }
                else
                {
                    S[i] == ')';
                    closing--;
                }
            }
        }
        
        bool possible = true ;
        int cnt = 0 ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            S[i] == '(' ? cnt++ : cnt-- ;
            if(cnt < 0)
            {
                possible = false;
                break;
            }
        }
        
        if(!possible || cnt != 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        
    }
    
    return 0;
}