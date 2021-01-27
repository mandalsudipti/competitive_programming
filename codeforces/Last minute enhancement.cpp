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
        map<int,int>freq ;
        int val ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            freq[val]++;
        }
        
        auto itr = freq.begin() ;
        while(itr != freq.end())
        {
            if(itr->second >= 2)
                freq[itr->first + 1]++;
            ++(itr);
        }
        
        cout<<freq.size()<<endl;
    }
    
    return 0;
}