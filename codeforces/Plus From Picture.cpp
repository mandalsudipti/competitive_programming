#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row , col ;
    cin>>row>>col;
    char mat[row][col];
    int i,j,total_star=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='*')
                total_star++;
        }
    }
    vector<pair<int,int>>horizontal;
    vector<pair<int,int>>vertical;
    
    for(i=0;i<row;i++)
    {
        int start=-1 , end=-1;
        for(j=0;j<col;j++)
        {
            if(mat[i][j]=='*'&&(j==0||mat[i][j-1]!='*'))
            {
                start=j;
                end=j;
            }
            else if(mat[i][j]=='*'&& mat[i][j-1]=='*')
                end=j;
            if((j==col-1 ||mat[i][j]=='.') && end-start>=2)
            {
                horizontal.push_back(make_pair(i,start));
                horizontal.push_back(make_pair(i,end));
                i=row+1;
                break;
            }
        }
    }
    for(j=0;j<col;j++)
    {
        int start=-1 , end=-1;
        for(i=0;i<row;i++)
        {
            if(mat[i][j]=='*' && (i==0||mat[i-1][j]!='*'))
            {
                start=i;
                end=i;
            }
            else if(mat[i][j]=='*' && mat[i-1][j]=='*')
                end=i;
            if(end-start>=2 && (mat[i][j]=='.'||i==row-1))
            {
                vertical.push_back(make_pair(start,j));
                vertical.push_back(make_pair(end,j));
            }
        }
    }
    if(horizontal.size()==0||vertical.size()==0)
    {
      cout<<"NO";
      return 0;
    }
    if(horizontal[0].first>vertical[0].first && horizontal[0].first<vertical[1].first && vertical[0].second>horizontal[0].second && vertical[0].second<horizontal[1].second)
    {}
    else
    {
        cout<<"NO";
        return 0;
    }
    int ele = (horizontal[1].second-horizontal[0].second)+(vertical[1].first-vertical[0].first)+1;
    if(ele!=total_star)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}




