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
        
        set<pair<int,int> , greater<pair<int,int>> >num ; // value , index
        int val ;
        
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>val; 
            num.insert(make_pair(val , i)) ;
        }
        
        vector<vector<int>>ans ;
        while(num.size() > 1)
        {
            pair<int,int>P1 = (*num.begin()) ;
            num.erase(num.begin()) ;
            
            pair<int,int>P2 = (*num.begin());
            num.erase(num.begin()) ;
            
            if(P1.first == 0 || P2.first == 0)
                break;
                
            ans.push_back({P1.second , P2.second}) ;
            P1.first-- ;
            P2.first-- ;
            
            if(P1.first > 0)
                num.insert(P1) ;
            if(P2.first > 0)
                num.insert(P2) ;
        }
        
        cout<<ans.size()<<endl;
        for(int i = 0 ; i < ans.size() ; i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    
    return 0 ;
}