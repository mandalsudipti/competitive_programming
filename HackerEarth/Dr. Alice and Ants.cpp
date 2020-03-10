#include<bits/stdc++.h>
using namespace std;

const int unvisited=-1,neighbour=4;
const int neighbour_x[4]={0,0,-1,1};
const int neighbour_y[4]={-1,1,0,0};
int main()
{
    int n , m;
    cin>>n>>m;
    queue<pair<int,int>>Q ;
    int matrix[n][m] , distance[n][m];
    memset(distance,unvisited,sizeof(distance));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]==1)
            {
                distance[i][j]=0;
                Q.push(make_pair(i,j));
            }
        }
    }
    
    while(!Q.empty())
    {
        pair<int,int>P=Q.front();
        Q.pop();
        int cur_x=P.first;
        int cur_y=P.second;
        for(int i=0;i<neighbour;i++)
        {
            int nxt_x=cur_x+neighbour_x[i] , nxt_y=cur_y+neighbour_y[i];
            if(nxt_x>=0 && nxt_x<n && nxt_y>=0 && nxt_y<m && distance[nxt_x][nxt_y]==unvisited)
            {
                distance[nxt_x][nxt_y]=distance[cur_x][cur_y]+1;
                Q.push(make_pair(nxt_x,nxt_y));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<distance[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}