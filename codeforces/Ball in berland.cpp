#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int a , b , couple ;
        cin>>a>>b>>couple ;
        
        map<int,set<int>>boy ;
        map<int,set<int>>girl ;
        
        vector<int>B(couple);
        vector<int>G(couple);
        
        for(int i = 0 ; i < couple ; i++)
            cin>>B[i];
        for(int i = 0 ; i < couple ; i++)
            cin>>G[i];
            
        for(int i = 0 ; i < couple ; i++)
        {
            boy[B[i]].insert(G[i]);
            girl[G[i]].insert(B[i]);
        }
        
        long long int count = 0 ;
        for(auto itr = boy.begin() ; itr != boy.end() ; ++itr)
        {
            int b = itr->first ;
            for(auto i = boy[b].begin() ; i != boy[b].end() ; ++i)
            {
                int g = (*i);
                count+=(couple - boy[b].size() - girl[g].size() + 1);
            }
        }
        cout<<count/2<<endl;
    }
    
    return 0;
}