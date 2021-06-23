#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , query ;
    cin>>n>>query ;
    string S ;
    cin>>S ;
    
    vector<vector<int>>freq(n , vector<int>(26,0));
    for(int i = 0 ; i < n ; i++)
    {
        freq[i][S[i] - 'a']++;
        if(i > 0)
        {
            for(int j = 0 ; j < 26 ; j++)
                freq[i][j]+=freq[i-1][j] ;
        }
    }
    
    while(query--)
    {
        int left , right ;
        cin>>left>>right ;
        left-- ;
        right-- ;
        
        long long int len = 0 ;
        for(int i = 0 ; i < 26 ; i++)
        {
            int cur_freq = freq[right][i] - (left - 1 >= 0 ? freq[left-1][i] : 0);
            len+=(cur_freq * (i+1));
        }
        cout<<len<<endl;
    }
    return 0 ;
}