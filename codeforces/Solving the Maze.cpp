#include<bits/stdc++.h>
using namespace std;

const int dir_x[]={-1,0,0,1};
const int dir_y[]={0,-1,1,0};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        int good_person =  0;
        cin>>row>>col;
        vector<string>grid(row);
        for(int i=0;i<row;i++)
        {
            cin>>grid[i];
            for(int j=0;j<col;j++)
                if(grid[i][j]=='G')
                    good_person++;
        }
            
        bool possible = true;
        for(int i=0;i<row;i++)
        {
            if(!possible)
                break;
            for(int j=0;j<col;j++)
            {
                if(!possible)
                    break;
                if(grid[i][j]=='B')
                {
                    for(int k=0;k<4;k++)
                    {
                            int x = i+dir_x[k] , y = j+dir_y[k] ;
                            if(x>=0 && x<row && y>=0 && y<col)
                            {
                                if(grid[x][y]=='G')
                                {
                                    possible = false;
                                    //cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                                    break;
                                }
                                if(grid[x][y]=='.')
                                    grid[x][y]='#';
                            }
                        
                    }
                }
            }
        }
        
        if(!possible || grid[row-1][col-1]=='B')
        {
            cout<<"NO"<<endl;
            continue;
        }
        int cnt = 0 ;
        queue<pair<int,int>>Q;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='G')
                {
                    Q.push(make_pair(i,j));
                    visited[i][j]=true;
                    cnt++;
                    i=row+10;
                    break;
                }
            }
        }
        
        while(!Q.empty())
        {
            pair<int,int> node = Q.front() ;
            Q.pop();
            for(int i=0;i<4;i++)
            {
                
                    int x = node.first + dir_x[i] , y = node.second + dir_y[i] ;
                    if(x>=0 && x<row && y>=0 && y<col && (grid[x][y]=='G'||grid[x][y]=='.') && !visited[x][y] )
                    {
                        visited[x][y] = true ;
                        if(grid[x][y]=='G')
                        {
                            cnt++;
                        }
                        Q.push(make_pair(x,y));
                    }
            }
        }
        //cout<<good_person<<" "<<cnt<<endl;
        if(good_person!=cnt)
            cout<<"NO"<<endl;
        else if(good_person>0 && !visited[row-1][col-1])
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}





