#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , q ;
    cin>>n>>q;
    
    vector<vector<int>>fence(n+1);
    vector<vector<int>>range(q,vector<int>(2,0));
    for(int i=0;i<q;i++)
    {
        cin>>range[i][0]>>range[i][1];
        for(int j=range[i][0];j<=range[i][1];j++)
            fence[j].push_back(i);
    }
    
    vector<int>unique_paint(q,0);
    int total_unique_paint = 0 ;
    vector<vector<int>>double_paint(q,vector<int>(q,0));
    
    for(int i=1;i<=n;i++)
    {
        if(fence[i].size()==1)
        {
            unique_paint[fence[i][0]]++;
        }
        else if(fence[i].size()==2)
        {
            int x = fence[i][0] , y = fence[i][1] ;
            double_paint[x][y]++;
            double_paint[y][x]++;
        }
    }
    
    for(int i=0;i<q;i++)
        total_unique_paint+=unique_paint[i];
        
    int ans = INT_MAX ;
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<q;j++)
        {
            if(j==i)
                continue;
            ans = min(ans ,  unique_paint[i] + unique_paint[j] + double_paint[i][j]);
        }
    }
    
    int cnt = 0 ;
    for(int i=1;i<fence.size();i++)
    {
        if(fence[i].size()==0)
            cnt++;
    }
    cout<<n - cnt - ans<<endl;
    
    return 0;
}





