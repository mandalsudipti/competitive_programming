#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n ;
        cin>>n;
        
        long long int ans = (floor(log10(n)+1) - 1)* 9 ;
        string S = to_string(n) , T ;
        for(int i = 0 ; i < S.length() ; i++)
            T+='1' ;
            
        while(T <= S)
        {
            ans++;
            if(T[0] == '9')
                break;
            for(int i = 0 ; i < T.length() ; i++)
            {
                if(T[i] < '9')
                    T[i]++ ;
            }
        }
        cout<<ans<<endl;
    }
    return 0 ; 
}
