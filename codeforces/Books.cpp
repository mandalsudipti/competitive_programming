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
        
        vector<vector<int>>adj_list(n+1) ;
        vector<int>indegree(n+1 , 0) ;
        for(int i = 1 ; i <= n ; i++)
        {
            int k , parent;
            cin>>k;
            indegree[i] = k ;
            for(int j = 0 ; j < k ; j++)
            {
                cin>>parent ;
                adj_list[parent].push_back(i) ;
            }
        }
        
        set<int>S1 , S2 ;
        for(int i = 1 ; i <= n ; i++)
        {
            if(indegree[i] == 0)
                S1.insert(i) ;
        }
        
        int step = 0 ;
        while(S1.size() > 0 || S2.size() > 0)
        {
            step++ ;
            if(step%2)
            {
                while(S1.size() > 0)
                {
                    int cur_node = (*S1.begin()) ;
                    S1.erase(S1.begin()) ;
                    for(int child : adj_list[cur_node])
                    {
                        indegree[child]-- ;
                        if(indegree[child] == 0)
                        {
                            if(child > cur_node)
                                S1.insert(child) ;
                            else
                                S2.insert(child) ;
                        }
                    }
                }
            }
            else
            {
                while(S2.size() > 0)
                {
                    int cur_node = (*S2.begin()) ;
                    S2.erase(S2.begin()) ;
                    for(int child : adj_list[cur_node])
                    {
                        indegree[child]-- ;
                        if(indegree[child] == 0)
                        {
                            if(child > cur_node)
                                S2.insert(child) ;
                            else
                                S1.insert(child) ;
                        }
                    }
                }
            }
        }
        
        bool all_visited = true ;
        for(int i = 1 ; i <= n ; i++)
        {
            if(indegree[i] > 0)
            {
                all_visited = false ;
                break;
            }
        }
        
        if(!all_visited)
            cout<<"-1"<<endl;
        else
            cout<<step<<endl;
    }
    
    return 0 ;
}