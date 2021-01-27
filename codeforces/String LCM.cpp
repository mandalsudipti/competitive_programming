#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q ;
    cin>>q;
    
    while(q--)
    {
        string S , T ;
        cin>>S>>T ;
        
        int lcm = (S.length() * T.length()) / __gcd(S.length() , T.length()) ;
        string S1 = S , T1 = T ;
        
        while(lcm > S1.length())
        {
            S1 = S1 + S;
        }
            
        while(lcm > T1.length())
        {
            T1=T1 + T;
        }
            
        if(S1 == T1)
            cout<<S1<<endl;
        else
            cout<<"-1"<<endl;
    }
    
    return 0;
}