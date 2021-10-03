#include<bits/stdc++.h>
using namespace std ;

vector<int>dir_x = {0,0,1,-1} ;
vector<int>dir_y = {1,-1,0,0} ;

int main()
{
    int n ;
    cin>>n;
    
    int r1 , c1 , r2 , c2 ;
    cin>>r1>>c1>>r2>>c2 ;
    
    r1-- ; c1-- ; r2-- ; c2-- ;
    
    vector<string>grid(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>grid[i] ;
        
    vector<vector<int>>source , target ; 
    bool found_source = false , found_target = false , is_same = false;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(found_source && found_target)
            break;
        for(int j = 0 ; j < n ; j++)
        {
            if(found_source && found_target)
                break ;
            if(grid[i][j] == '0')
            {
                vector<vector<int>>cur ;
                queue<pair<int,int>>Q ;
                Q.push(make_pair(i,j)) ;
                grid[i][j] = '1' ;
                
                bool has_source = false , has_target = false ;
                while(!Q.empty())
                {
                    int x = Q.front().first , y = Q.front().second ;
                    //cout<<x<<" "<<y<<endl;
                    Q.pop() ;
                    cur.push_back({x,y}) ;
                    
                    if(x == r1 && y == c1)
                        has_source = true ;
                    if(x == r2 && y == c2)
                        has_target = true ;
                        
                    for(int dir = 0 ; dir < 4 ; dir++)
                    {
                        int new_x = dir_x[dir] + x , new_y = y + dir_y[dir] ;
                        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == '0')
                        {
                            Q.push(make_pair(new_x , new_y)) ;
                            grid[new_x][new_y] = '1' ;
                        }
                    }
                }
                
                if(has_source && has_target)
                {
                    source = target = cur ;
                    found_source = found_target = true ;
                    is_same = true ;
                }
                else if(has_source)
                {
                    found_source = true ;
                    source = cur ;
                }
                else if(has_target)
                {
                    found_target = true ;
                    target = cur ;
                }
            }
        }
    }
    
    if(is_same)
        cout<<"0"<<endl;
    else
    {
        long long int min_cost = LLONG_MAX ;
        for(int i = 0 ; i < source.size() ; i++)
        {
            for(int j = 0 ; j < target.size() ; j++)
            {
                long long int cur_cost = pow(source[i][0] - target[j][0] , 2) + pow(source[i][1] - target[j][1] , 2) ;
                min_cost = min(min_cost , cur_cost) ;
            }
        }
        
        cout<<min_cost<<endl;
    }
    
    return 0 ;
}