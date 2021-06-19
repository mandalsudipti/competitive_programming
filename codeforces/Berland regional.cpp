#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<vector<long long int> >mp(n+1) ; // university - skill
        vector<int>university(n) , skill(n) ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>university[i] ;
        for(int i = 0 ; i < n ; i++)
            cin>>skill[i] ;
            
        for(int i = 0 ; i < n ; i++)
            mp[university[i]].push_back(skill[i]);
            
        for(int i =  1 ; i <= n ; i++)
        {
            sort(mp[i].begin() , mp[i].end() , greater<long long int>());
            for(int j = 1 ; j < mp[i].size() ; j++)
                mp[i][j]+=mp[i][j-1] ;
        }
        
        vector<long long int>total(n+1 , 0);
        
        for(int idx = 1 ; idx <= n ; idx++)
        {
            vector<long long int>tmp = mp[idx] ;
            
            for(int i = 1 ; i <= min( n , (int)(tmp.size()) ) ; i++)
            {
                int rem = tmp.size() % i ;
                total[i]+=tmp[tmp.size() - 1 - rem] ;
            }
        }
        
        for(int i = 1 ; i < total.size() ; i++)
           cout<<total[i]<<" "; 
        cout<<endl;
    }
    return 0 ;
}


