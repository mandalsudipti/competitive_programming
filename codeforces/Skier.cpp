#include<bits/stdc++.h>
using namespace std ;

void get_next(int x , int y , int* x1 , int* y1 , char ch)
{
    (*x1) = x ;
    (*y1) = y ;
    
    switch(ch)
    {
        case 'N' :
            (*y1)++ ;
            break;
        case 'S' :
            (*y1)-- ;
            break;
        case 'E' :
            (*x1)++ ;
            break;
        case 'W' :
            (*x1)-- ;
            break;
    }
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string path ;
        cin>>path;
        
        int cur_x = 0 , cur_y = 0 ;
        set<vector<int>>visited ;
        
        long long int cost = 0 ;
        for(int i = 0 ; i < path.length() ; i++)
        {
            int next_x , next_y ;
            get_next(cur_x , cur_y , &next_x , &next_y , path[i]) ;
            
            if(visited.find({cur_x , cur_y , next_x , next_y}) != visited.end() || visited.find({next_x , next_y , cur_x , cur_y}) != visited.end())
                cost++ ;
            else
            {
                cost+=5 ;
                visited.insert({cur_x , cur_y , next_x , next_y}) ;
                visited.insert({next_x , next_y , cur_x , cur_y}) ;
            }
            
            cur_x = next_x ;
            cur_y = next_y ;
        }
        
        cout<<cost<<endl;
    }
    
    return 0 ;
}

