#include<bits/stdc++.h>
using namespace std ;


bool is_equal(vector<vector<int>>& ip_freq , vector<vector<int>>& op_freq , string& S)
{
    bool possible = true ;
    for(int i = 0 ; i <S.length() ; i++)
    {
        for(int j = 0 ; j < 26 ; j++)
        {
            int cur_freq = ip_freq[i][j] - (S[i] == ('a' + j) ? 1 : 0) ;
            if(op_freq[i][j] != cur_freq)
                return false ;
        }
    }
    
    return true ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<string>ip_str(n) ;
        vector<vector<int>>ip_freq(m , vector<int>(26,0)) ; 
        vector<vector<int>>op_freq(m , vector<int>(26,0)) ;
        string S ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>S ;
            ip_str[i] = S ;
            for(int j = 0 ; j < m ; j++)
                ip_freq[j][S[j] - 'a']++;
        }
        
        for(int i = 0 ; i < (n-1) ; i++)
        {
            cin>>S;
            for(int j = 0 ; j < m ; j++)
                op_freq[j][S[j] - 'a']++ ;
        }
        
        string ans ;
        
        for(int i = 0 ; i < n ; i++)
        {
            ans = ip_str[i] ;
            if(is_equal(ip_freq , op_freq , ans))
                break;
        }
        cout<<ans<<endl;
        fflush(stdout);
    }
    return 0 ;
}