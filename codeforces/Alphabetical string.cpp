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
        
        if(S.length() > 26)
        {
            cout<<"NO"<<endl;
            continue ;
        }
        
        bool flag = true ;
        int left = -1 , right = INT_MAX ;
        
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == 'a')
            {
                left = right = i ;
                break;
            }
        }
        
        if(left == -1)
            flag = false ;
        
        char ch = 'a' ;    
        while(left > 0 || right < S.length()-1)
        {
            ch++ ;
            if(left - 1 >= 0 && S[left-1] == ch)
                left--;
            else if(right + 1 < S.length() && S[right + 1] == ch)
                right++;
            else
            {
                flag = false ;
                break;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}