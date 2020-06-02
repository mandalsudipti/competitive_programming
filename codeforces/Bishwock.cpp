#include<bits/stdc++.h>
using namespace std;

bool combined(vector<string>&grid,int col)
{
    for(int i=col;i<col+3;i++)
    {
        if(grid[0][i]=='X' || grid[1][i]=='X')
            return false;
    }
    return true;
}

bool single(vector<string>&grid , int col)
{
    if(grid[0][col]=='0' && grid[0][col+1]=='0')
    {
        if(grid[1][col]=='0' || grid[1][col+1]=='0')
            return true;
        else
            return false;
    }
    else if(grid[1][col]=='0' && grid[1][col+1]=='0')
    {
        if(grid[0][col]=='0' || grid[0][col+1]=='0')
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    vector<string>grid(2);
    for(int i=0;i<2;i++)
    {
        cin>>grid[i];
    }
    int i=0 , cnt = 0 ;
    while(i<grid[0].length())
    {
        if(i+2<grid[0].length() && combined(grid,i))
        {
            i+=3;
            cnt+=2;
        }
        else if (i+1<grid[0].length() && single(grid,i))
        {
            i+=2;
            cnt++;
        }
        else
            i++;
    }
    cout<<cnt<<endl;
    
    return 0;
}