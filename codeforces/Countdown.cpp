#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , op = 0;
        cin>>n;
        string S ;
        cin>>S ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] != '0')
                op+=(1 + (S[i] - '0')) ;
        }
        
        if(S[S.length()-1] != '0')
            op-- ;
            
        cout<<op<<endl;
    }
    
    return 0 ;
}