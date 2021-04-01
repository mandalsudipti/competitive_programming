#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int val ;
        map<int,int>freq;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            freq[val]++;
        }
        
        int max_freq = 1 ;
        for(auto itr = freq.begin() ; itr != freq.end() ; ++itr)
            max_freq = max( max_freq , itr->second);
            
        cout<<max_freq<<endl;
    }
    
    return 0;
}