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
        
        int count = 0 ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == '0' && (i == 0 || S[i-1] != '0'))
                count++ ;
        }
        
        if(count == 0)
            cout<<"0\n";
        else if(count == 1)
            cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0 ;
}