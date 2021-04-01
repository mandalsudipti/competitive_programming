#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<int>house(n) , color(n) , painter(m) ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>house[i];
        for(int i = 0 ; i < n ; i++)
            cin>>color[i];
        for(int i = 0 ; i < m ; i++)
            cin>>painter[i] ;
            
        bool found = false ;
        vector<int>pos(m,-1);
        for(int i = 0 ; i < n ; i++)
        {
            if(color[i] == painter[m-1])
            {
                found = true ;
                pos[m-1] = i ;
                if(house[i] != color[i])
                    break;
            }
        }
        
        if(!found)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
            house[pos[m-1]] = -1 ;
            
        map<int,unordered_set<int>> painter_for_color ;
        for(int i = 0 ; i < m-1 ; i++)
            painter_for_color[painter[i]].insert(i);
            
        bool possible = true;    
        for(int i = 0 ; i < n ; i++)
        {
            if(house[i] != -1 && house[i] != color[i])
            {
                if(painter_for_color[color[i]].size() == 0)
                {
                    possible = false ;
                    break;
                }
                else
                {
                    int tmp = (*painter_for_color[color[i]].begin()) ;
                    painter_for_color[color[i]].erase(painter_for_color[color[i]].begin());
                    pos[tmp] = i ;
                }
            }
        }
        
        if(!possible)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i = 0 ; i < m ; i++)
            {
                if(pos[i] == -1)
                    cout<<pos[m-1]+1<<" ";
                else
                    cout<<pos[i]+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
