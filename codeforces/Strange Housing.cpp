#include<bits/stdc++.h>
using namespace std;

const int white = 0 , red = 1 , blue = 2 ;
int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int node , edge ;
        cin>>node>>edge ;
        
        vector<vector<int>>adj_list(node + 1);
        int u , v ;
        for(int i = 0 ; i < edge ; i++)
        {
            cin>>u>>v ;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        vector<int>color(node + 1 , white);
        int red_node = 1 ;
        queue<int>Q_blue ;
        
        color[1] = red ;
        
        while(red_node != -1 || Q_blue.size() >= 1)
        {
            if(red_node != -1)
            {
                for(int i = 0 ; i < adj_list[red_node].size() ; i++)
                {
                    int child = adj_list[red_node][i] ;
                    if(color[child] == white)
                    {
                        color[child] = blue ;
                        Q_blue.push(child) ;
                    }
                }
                
                red_node = -1 ;
            }
            
            if(!Q_blue.empty())
            {
                int root = Q_blue.front() ;
                int cnt = 0 ;
                for(int i = 0 ; i <adj_list[root].size() ; i++)
                {
                    int child = adj_list[root][i] ;
                    if(color[child] == white)
                    {
                        cnt++;
                        color[child] = red ;
                        red_node = child ;
                        break;
                    }
                }
                if(cnt == 0)
                    Q_blue.pop();
                
            }
        }
        
        bool possible = true ;
        int cnt_red = 0 ;
        for(int i = 1 ; i<= node ; i++)
        {
            if(color[i] == white)
            {
                possible = false ;
                break;
            }
            else if(color[i] == red)
                cnt_red++;
        }
        
        if(!possible)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<cnt_red<<endl;
            for(int i = 1 ; i <= node ; i++)
            {
                if(color[i] == red)
                    cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}

