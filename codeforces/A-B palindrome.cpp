#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int a , b , cnt_zero = 0 , cnt_one = 0;
        bool possible = true ;
        string S ;
        cin>>a>>b;
        cin>>S ;
        
        int left = 0 , right = S.length() - 1 ;
        while(left <= right)
        {
            if(left == right)
            {
                if(S[left] == '0')
                    cnt_zero++;
                else if(S[left] == '1')
                    cnt_one++;
                break;
            }
            if(S[left] == S[right])
            {
                if(S[left] == '0')
                    cnt_zero+=2 ;
                else if(S[left] == '1')
                    cnt_one+=2 ;
                left++;
                right--;
            }
            else
            {
                if(S[left]!='?' && S[right] != '?')
                {
                    possible = false ;
                    break;
                }
                S[left] == '?' ? S[left] = S[right] : S[right] = S[left] ;
                S[left] == '0' ? cnt_zero+=2 : cnt_one+=2 ;
                left++ ;
                right--;
            }
        }
        
        if(!possible || cnt_zero > a || cnt_one > b)
        {
            cout<<"-1"<<endl;
            continue ;
        }
        
        left = 0 , right = S.length() - 1 ;
        while(left <= right)
        {
            if(left == right && S[left] == '?')
            {
                if(cnt_zero < a)
                {
                    S[left] = '0' ;
                    cnt_zero++;
                }
                else if(cnt_one < b)
                {
                    S[left] = '1' ;
                    cnt_one++;
                }
                else
                    possible = false ;
                break;
            }
            
            if(S[left] == S[right] && S[left] == '?')
            {
                if(cnt_zero + 2 <= a)
                {
                    S[left] = S[right] = '0' ;
                    cnt_zero+=2;
                }
                else if(cnt_one + 2 <= b)
                {
                    cnt_one+=2 ;
                    S[left] = S[right] = '1';
                }
                else
                {
                    possible = false ;
                    break;
                }
            }
            
            left++;
            right--;
        }
        
        if(!possible || cnt_one != b || cnt_zero != a)
            cout<<"-1"<<endl;
        else
            cout<<S<<endl;
    }
    
    return 0 ;
}