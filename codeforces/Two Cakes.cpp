#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , val ;
    cin>>n;
    vector<vector<int>>loc(2,vector<int>(n+1,-1));
    for(int i=1;i<=2*n;i++)
    {
        cin>>val;
        loc[0][val]==-1?loc[0][val]=i:loc[1][val]=i;
    }
    long long int distance = loc[0][1]+loc[1][1]-2;
    
    for(int i=2;i<=n;i++)
    {
       int x = abs(loc[0][i-1]-loc[0][i])+abs(loc[1][i-1]-loc[1][i]);
       int y = abs(loc[0][i-1]-loc[1][i])+abs(loc[1][i-1]-loc[0][i]);
       distance+=min(x,y);
       
    }
    cout<<distance<<endl;
    return 0;
}