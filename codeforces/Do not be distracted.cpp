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
        cin>>S ;
        
        vector<bool>visited(26,false) ;
        bool flag = true ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i > 0 && S[i] == S[i-1])
                continue ;
            else
            {
                if(!visited[S[i] - 'A'])
                    visited[S[i] - 'A'] = true ;
                else
                {
                    flag = false ;
                    break;
                }
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}