#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string& S)
{
    int left = 0 , right = S.length()-1 ;
    while(left <= right)
    {
        if(S[left] != S[right])
            return false ;
        left++ ;
        right--;
    }
    return true ;
}

void solve(string& S)
{
    int count_zero = 0 ;
    for(int i = 0 ; i <S.length() ; i++)
    {
        if(S[i] == '0')
            count_zero++;
    }
    
    if(count_zero == 0)
        cout<<"DRAW\n";
    else if(count_zero%2 == 0 || count_zero == 1)
        cout<<"BOB\n";
    else
        cout<<"ALICE\n";
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        string S ;
        cin>>S;
        
        
        if(S.length() == 1)
        {
            if(S[0] == '0')
                cout<<"BOB\n";
            else
                cout<<"DRAW\n";
        }
        else if(is_palindrome(S))
            solve(S) ;
        else
        {
            int cnt_zero = 0 ;
            for(int i = 0 ; i < S.length() ; i++)
            {
                if(S[i] == '0')
                    cnt_zero++;
            }
            if(cnt_zero == 2 && S.length()%2 == 1 && S[S.length()/2] == '0')
                cout<<"DRAW\n";
            else
                cout<<"ALICE\n";
        }
    }
    return 0 ;
}
