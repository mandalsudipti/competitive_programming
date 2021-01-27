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
        
        vector<bool>change(S.length() , false);
        
        for(int i = 1 ; i < S.length() ; i++)
        {
            if(S[i] == S[i-1] && !change[i-1])
                change[i] = true ;
                
            if(i-2 >= 0 && S[i-2] == S[i] && !change[i-2] && !change[i])
                change[i] = true ;
        }
        
        int cnt  = 0 ;
        for(int i = 0 ; i < change.size() ; i++)
        {
            if(change[i])
                cnt++;
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}