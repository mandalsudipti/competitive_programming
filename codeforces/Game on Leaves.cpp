#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n , special_node ;
    cin>>n>>special_node;
    vector<vector<int>>edge(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x , y ;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    if(n==1 || edge[special_node].size()==1)
    {
        cout<<"Ayush"<<endl;
        return;
    }
    
    if((n-3)%2 == 0)
        cout<<"Ashish"<<endl;
    else
        cout<<"Ayush"<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}


