#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n ;
        string S ;
        cin>>S ;
        
        vector<long long int>ans(n,0) ;
        int cnt_d = 0  , cnt_k = 0 ;
        map<pair<int,int> , int>ratio_freq ;
        
        for(int i = 0 ; i < n ; i++)
        {
            S[i] == 'D' ? cnt_d++ : cnt_k++ ;
            
            int gcd = __gcd(cnt_d , cnt_k) ;
            pair<int,int>P = make_pair(cnt_d / gcd , cnt_k / gcd) ;
            ratio_freq[P]++ ;
            
            ans[i] = ratio_freq[P] ;
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0 ;
}
