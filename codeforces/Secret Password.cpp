#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>adj_list , vector<int>&visited , int node)
{
    int nxt_node ;
    if(adj_list[node].size()>0 && adj_list[node][0]==-1)
        return;
    visited[node]=1;
    for(int i=0;i<adj_list[node].size();i++)
    {
        nxt_node = adj_list[node][i];
        if(!visited[nxt_node])
            DFS(adj_list,visited,nxt_node);
    }
}

int main()
{
    int n ;
    cin>>n;
    vector<string>S(n);
    for(int i=0;i<n;i++)
        cin>>S[i];
    vector<vector<int>>letter(26);
    for(int i=0;i<S.size();i++)
    {
        for(int j=0;j<S[i].length();j++)
        {
            char ch = S[i][j];
            if(letter[ch-'a'].size()==0)
                letter[ch-'a'].push_back(i);
            else if(letter[ch-'a'].back()!=i)
                letter[ch-'a'].push_back(i);
        }
    }

    vector<vector<int>>adj_list(26);
    vector<int>visited(26,0);
    for(int i=0;i<26;i++)
    {
        if(letter[i].size()==0)
        {
            adj_list[i].push_back(-1);
            continue;
        }
        vector<int>loc(n,0);
        for(int j=0;j<letter[i].size();j++)
            loc[letter[i][j]]=1;
        for(int j=i+1;j<26;j++)
        {
            for(int k=0;k<letter[j].size();k++)
            {
                if(loc[letter[j][k]]==1)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                    break;
                }
            }
        }
    }
    
    int component=0;
    for(int i=0;i<26;i++)
    {
        if(visited[i]==0 && (adj_list[i].size()==0 || (adj_list[i].size()>0 && adj_list[i][0]!=-1)) )
        {
            component++;
            DFS(adj_list,visited,i);
        }
    }
    cout<<component<<endl;
    return 0;
}

