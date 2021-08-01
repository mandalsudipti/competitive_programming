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
        vector<int>freq(26,0) ;
        
        for(int i = 0 ; i < S.length() ; i++)
            freq[S[i] - 'a']++ ;
            
        int freq1 = 0 , freq_other = 0 ;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i] == 1)
                freq1++ ;
            else if(freq[i] > 1)
                freq_other++ ;
        }
        
        int red = freq_other + (freq1 / 2) ;
        cout<<red<<endl;
    }
    return 0 ;
}