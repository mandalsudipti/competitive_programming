#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<pair<int,int>>edge(n-1);
    int count_edge[n+1] , maximum=n-2,minimum=0;
    memset(count_edge,0,sizeof(count_edge));
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        edge[i]=make_pair(x,y);
        count_edge[x]++;
        count_edge[y]++;
    }
    vector<int>ans(n-1,-1) ;
    for(int i=0;i<n-1;i++)
    {
        if(count_edge[edge[i].first]==1 || count_edge[edge[i].second]==1)
            ans[i]=minimum++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(ans[i]==-1)
            ans[i]=maximum--;
    }
    for(int i=0;i<n-1;i++)
        cout<<ans[i]<<endl;
    return 0;
}

