#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , val;
        cin>>n;
        map<int,int>freq ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            freq[val]++;
        }
        
        for(auto itr = freq.begin() ; itr != freq.end() ; ++itr)
        {
            cout<<itr->first<<" ";
            (itr->second)--;
        }
        
        for(auto itr : freq)
        {
            while(itr.second > 0)
            {
                cout<<itr.first<<" ";
                (itr.second)--;
            }
        }
        cout<<endl;
    }
    
    return 0;
}