#include<bits/stdc++.h>
using namespace std;

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
        string ans = "";
        
        int pre = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] == '1')
            {
                if(pre != 2)
                {
                    ans+='1';
                    pre = 2 ;
                }
                else if(pre != 1)
                {
                    ans+='0';
                    pre = 1 ;
                }
            }
            else
            {
                if(pre != 1)
                {
                    ans+='1';
                    pre = 1 ;
                }
                else if( pre != 0)
                {
                    ans+='0';
                    pre = 0 ;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}