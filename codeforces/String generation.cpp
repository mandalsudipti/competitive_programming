#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        char ch = 'a' ;
        string S = "";
        while(S.length() < n)
        {
            for(int i = 0 ; i < k ;i++)
            {
                if(S.length() >= n)
                    break;
                S+=ch;
            }
            if(ch == 'a')
                ch = 'b' ;
            else if(ch == 'b')
                ch = 'c';
            else
                ch = 'a';
        }
        
        cout<<S<<endl;
    }
    
    return 0;
}