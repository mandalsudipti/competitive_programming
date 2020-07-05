#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col , a , b ;
        cin>>row>>col>>a>>b;
        if(row*a!=col*b)
        {
            cout<<"NO"<<endl;
            continue;
        }
        vector<vector<int>>grid(row,vector<int>(col,0));
        cout<<"YES"<<endl;
        int start = 0 ;
        for(int i=0;i<row;i++)
        {
            int cnt = 0 ;
            while(cnt<a)
            {
                start = start%col ;
                grid[i][start]=1;
                start++;
                cnt++;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cout<<grid[i][j];
            cout<<endl;
        }
    }
    return 0;
}
