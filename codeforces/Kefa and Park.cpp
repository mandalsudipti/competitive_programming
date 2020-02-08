#include<bits/stdc++.h>
using namespace std;

int path_cnt,node,max_cat;
const int MAX_NODE =2e5+1;
int has_cat[MAX_NODE]={false};
int visited[MAX_NODE]={false};
int consecutive_cat[MAX_NODE]={0};
vector<vector<int>>path(MAX_NODE);

void DFS(int loc)
{
    if(path[loc].size()==1 && visited[path[loc][0]])
        path_cnt++;
    for(int i=0;i<path[loc].size();i++)
    {
        int nxt_loc=path[loc][i];
        if(!visited[nxt_loc])
        {
            visited[nxt_loc]=true;
            consecutive_cat[nxt_loc] = has_cat[nxt_loc]? consecutive_cat[loc]+1:0;
            if(consecutive_cat[nxt_loc]<=max_cat)
                DFS(nxt_loc);
        }
    }
}

int main()
{
    cin>>node>>max_cat;
    //vector<int>has_cat(node+1);
    //vector<vector<int>>path(node+1);
    //vector<bool>visited(node+1,false);
    //vector<int>consecutive_cat(node+1);
    int i , x, y;
    for(i=1;i<=node;i++)
    {
        cin>>has_cat[i];
    }
    for(i=0;i<node-1;i++)
    {
        cin>>x>>y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    visited[1]=true;
    consecutive_cat[1]=has_cat[1];
    path_cnt=0;
    DFS(1);
    cout<<path_cnt;
    return 0;
}
