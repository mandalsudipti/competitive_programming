#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        vector<string>grid(n);
        for(int i=0;i<n;i++)
            cin>>grid[i];
            
        vector<vector<pair<long long int,long long int>> >row_extreme(n,vector<pair<long long int,long long int>>(10,make_pair(-1,-1)));
        vector<vector<pair<long long int,long long int>> > col_extreme(n , vector<pair<long long int,long long int>>(10,make_pair(-1,-1)));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x = grid[i][j] - '0' ;
                if(row_extreme[i][x].first == -1)
                    row_extreme[i][x].first = row_extreme[i][x].second = j ;
                else
                    row_extreme[i][x].second = j ;
                    
                if(col_extreme[j][x].first == -1)
                    col_extreme[j][x].first = col_extreme[j][x].second = i ;
                else
                    col_extreme[j][x].second = i ;
            }
        }
        
        vector<long long int>min_left(10,-1);
        vector<long long int>max_right(10,-1);
        vector<long long int>top(10,-1);
        vector<long long int>bottom(10,-1);
        
        for(int j=0;j<10;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(min_left[j] == -1 || ( row_extreme[i][j].first < min_left[j] && row_extreme[i][j].first!=-1))
                    min_left[j] = row_extreme[i][j].first;
                if(max_right[j] == -1 || row_extreme[i][j].second > max_right[j])
                    max_right[j] = row_extreme[i][j].second;
                    
                if(top[j] == -1 || ( top[j] > col_extreme[i][j].first && col_extreme[i][j].first!=-1) )
                    top[j] = col_extreme[i][j].first;
                if(bottom[j] == -1 || bottom[j] < col_extreme[i][j].second)
                    bottom[j] = col_extreme[i][j].second;
            }
        }
        
        vector<long long int>max_area(10,0);
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<10;j++)
            {
                long long int area1 = (row_extreme[i][j].second - row_extreme[i][j].first) * max(i ,n - 1 - i);
                long long int area2 = (col_extreme[i][j].second - col_extreme[i][j].first) * max(i , n - i - 1);
                long long int area3 = max(row_extreme[i][j].second , n - 1 - row_extreme[i][j].first) * max(abs(i - top[j]) ,abs(i - bottom[j]));
                long long int area4 = max(col_extreme[i][j].second , n - 1 - col_extreme[i][j].first) * max(abs(i - min_left[j]) , abs(i - max_right[j]));
                max_area[j] = max( max_area[j] , max(area1 , area2) );
                
                if(row_extreme[i][j].first!=-1 && col_extreme[i][j].first!=-1)
                    max_area[j] = max( max_area[j] , max(area4 , area3) );
                    
                else if(row_extreme[i][j].first!=-1)
                    max_area[j] = max( max_area[j] , area3);
                    
                else if(col_extreme[i][j].first!=-1)
                    max_area[j] = max( max_area[j] , area4);
            }
        }
        for(int i=0;i<10;i++)
            cout<<max_area[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}