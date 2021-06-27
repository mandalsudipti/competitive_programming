#include<bits/stdc++.h>
using namespace std ;


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
        
        int cnt = 0 ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == '0')
                cnt++ ;
        }
        
        if(cnt == 0)
            cout<<"DRAW\n";
        else if(cnt == 1)
            cout<<"BOB\n";
        else if(cnt%2 == 1)
            cout<<"ALICE\n";
        else
            cout<<"BOB\n";
    }
    return  0 ;
}
