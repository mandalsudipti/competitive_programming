#include<bits/stdc++.h>
using namespace std;

const int range = 100005 ;

int main()
{
    int n , color , loc=1 , max_freq=0;
    cin>>n;
    vector<int>freq(range,0); // how many time each color is present 
    vector<int>cnt(range,0); // each frequency is present in how many color
    for(int i=1;i<=n;i++)
    {
        cin>>color;
        cnt[freq[color]]--;
        freq[color]++;
        cnt[freq[color]]++;
        max_freq = max(max_freq,freq[color]);
        
        bool possible = false ;
        
        if(cnt[i]==1)
            possible=true;
        else if(cnt[1]==i)
            possible=true;
        else if(cnt[max_freq]==1 && cnt[max_freq - 1]*(max_freq-1)==(i-max_freq))
            possible=true;
        else if(cnt[1]==1 && cnt[max_freq]*max_freq==i-1)
            possible=true;
            
        if(possible)
            loc=i;
    }
    cout<<loc<<endl;
    
    return 0;
}