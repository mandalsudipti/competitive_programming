#include<bits/stdc++.h>
using namespace std ;


void solve()
{
    string S ;
    cin>>S ;
    
    vector<vector<int>>digit(10) ;
    for(int i = 0 ; i < S.length() ; i++)
        digit[S[i] - '0'].push_back(i) ;
        
    int min_step = INT_MAX ;
    if(digit[0].size() >= 2)
        for(int i = 0 ; i < digit[0].size() - 1; i++) // 0 0 
            min_step = min(min_step , (digit[0][i+1] - digit[0][i] - 1) + (int)(S.length() - 1 - digit[0][i+1]) ) ;
        
    int idx1 = 0 , idx2 = 0 ;
    
    while(idx1 < digit[2].size() && idx2 < digit[5].size()) // 25
    {
        while(idx2 < digit[5].size() && digit[5][idx2] < digit[2][idx1])
            idx2++ ;
            
        if(idx2 < digit[5].size())
            min_step = min(min_step , (digit[5][idx2] - digit[2][idx1] - 1) + (int)(S.length() - 1 - digit[5][idx2])) ;
            
        idx1++ ;
    }
    
    idx1 = 0 , idx2 = 0 ;
    
    while(idx1 < digit[5].size() && idx2 < digit[0].size()) // 50
    {
        while(idx2 < digit[0].size() && digit[0][idx2] < digit[5][idx1])
            idx2++ ;
            
        if(idx2 < digit[0].size())
            min_step = min(min_step , (digit[0][idx2] - digit[5][idx1] - 1) + (int)(S.length() - 1 - digit[0][idx2])) ;
            
        idx1++ ;
    }
    
    idx1 = 0 , idx2 = 0 ;
    
    while(idx1 < digit[7].size() && idx2 < digit[5].size()) // 75
    {
        while(idx2 < digit[5].size() && digit[5][idx2] < digit[7][idx1])
            idx2++ ;
            
        if(idx2 < digit[5].size())
            min_step = min(min_step , (digit[5][idx2] - digit[7][idx1] - 1) + (int)(S.length() - 1 - digit[5][idx2])) ;
            
        idx1++ ;
    }
    
    cout<<min_step<<endl;
    
}


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
        solve() ;
        
    return 0 ;
}