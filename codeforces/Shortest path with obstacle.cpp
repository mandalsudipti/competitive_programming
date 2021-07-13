#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        vector<vector<int>>point(3 , vector<int>(2,0)) ;
        
        for(int i = 0 ; i < 3 ; i++)
            cin>>point[i][0]>>point[i][1] ;
            
        
        long long int distance = abs(point[0][0] - point[1][0]) + abs(point[0][1] - point[1][1]) ;
        
        int min_x = min(point[0][0] , point[1][0]) , max_x = max(point[0][0] , point[1][0]) ;
        int min_y = min(point[0][1] , point[1][1]) , max_y = max(point[0][1] , point[1][1]) ;
        
        if(point[0][0] == point[1][0] && point[1][0] == point[2][0] && point[2][1] >= min_y && point[2][1] <= max_y)
            distance+=2 ;
        else if(point[0][1] == point[1][1] && point[1][1] == point[2][1] && point[2][0] >= min_x && point[2][0] <= max_x)
            distance+=2;
            
        cout<<distance<<endl;
    }
    return 0 ;
}