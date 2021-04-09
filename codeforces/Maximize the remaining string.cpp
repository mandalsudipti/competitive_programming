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
        int n = S.length() ;
        vector<vector<int>>suffix_cnt(n,vector<int>(26,0));
        vector<bool>visited(26,false);
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            suffix_cnt[i][S[i] - 'a']++;
            if(i < n-1)
            {
                for(int j = 0 ; j < 26 ; j++)
                    suffix_cnt[i][j]+=suffix_cnt[i+1][j] ;
            }
        }
        
        string ans ;
        for(int i = 0 ; i < n ; i++)
        {
            while(ans.length() > 0 &&!visited[S[i] - 'a'] && suffix_cnt[i][ans.back() - 'a'] >= 1 && S[i] > ans.back())
            {
                visited[ans.back() - 'a'] = false ;
                ans.pop_back();
            }
            if(!visited[S[i] - 'a'])
            {
                visited[S[i] - 'a'] = true ;
                ans+=S[i];
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
