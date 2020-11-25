#include<bits/stdc++.h>
using namespace std;

void print(vector<string>&grid)
{
    for(int i=0;i<grid.size();i++)
        cout<<grid[i]<<endl;
    cout<<"---------------------\n";
}
void row_op(int i , int j , vector<vector<int>>&operation , vector<string>&grid)
{
    grid[i][j] = '0' ;
    grid[i+1][j]=='0' ? grid[i+1][j] = '1' : grid[i+1][j] = '0';
    if(j<grid[i].size()-1)
    {
        grid[i+1][j+1] == '0' ? grid[i+1][j+1] = '1' : grid[i+1][j+1] = '0' ;
        vector<int>tmp = {i+1,j+1,i+2,j+1,i+2,j+2};
        operation.push_back(tmp);
    }
    else
    {
        grid[i+1][j-1] == '0' ? grid[i+1][j-1] = '1' : grid[i+1][j-1] = '0' ;
        vector<int> tmp = {i+1,j+1,i+2,j+1,i+2,j};
        operation.push_back(tmp);
    }
    //print(grid);
}

void col_op(int i , int j ,vector<vector<int>>&operation , vector<string>&grid)
{
    grid[i][j] = '0' ;
    grid[i][j+1] == '0' ? grid[i][j+1] = '1' : grid[i][j+1] = '0' ;
    if(i+1 < grid.size())
    {
        grid[i+1][j+1] == '0' ? grid[i+1][j+1] = '1' : grid[i+1][j+1] = '0' ;
        vector<int>tmp = {i+1,j+1,i+1,j+2,i+2,j+2};
        operation.push_back(tmp);
    }
    else
    {
        grid[i-1][j+1] == '0' ? grid[i-1][j+1] = '1' : grid[i-1][j+1] = '0';
        vector<int>tmp = {i+1,j+1,i+1,j+2,i,j+2};
        operation.push_back(tmp);
    }
    //print(grid);
}

void change_to_one(vector<vector<int>>&operation , vector<pair<int,int>>&cnt , int row , int col)
{
    vector<int>tmp;
    while(cnt.size()>1)
    {
       tmp.push_back(cnt[0].first + 1);
       tmp.push_back(cnt[0].second + 1);
       cnt.erase(cnt.begin());
    }
    operation.push_back(tmp);
}

void change_to_two(vector<vector<int>>&operation , vector<pair<int,int>>&cnt , int row , int col)
{
   vector<int>tmp ;
   for(int i=row-2;i<row;i++)
   {
       for(int j=col-2;j<col;j++)
       {
           pair<int,int>p = make_pair(i,j);
           if(p!=cnt[0] && cnt.size()<3)
           {
               tmp.push_back(i+1);
               tmp.push_back(j+1);
               cnt.push_back(p);
           }
       }
   }
   tmp.push_back(cnt[0].first + 1);
   tmp.push_back(cnt[0].second + 1);
   cnt.erase(cnt.begin());
   operation.push_back(tmp);
}

void change_to_three(vector<vector<int>>&operation , vector<pair<int,int>>&cnt , int row , int col)
{
    vector<int>tmp ;
    tmp.push_back(cnt[0].first + 1);
    tmp.push_back(cnt[0].second + 1);
    
    for(int i=row - 2 ;i<row;i++)
    {
        for(int j=col - 2 ; j<col;j++)
        {
            pair<int , int> p = make_pair(i,j);
            if(p!=cnt[0] && p!=cnt[1])
            {
                tmp.push_back(i+1);
                tmp.push_back(j+1);
                cnt.push_back(p);
            }
        }
    }
    
    cnt.erase(cnt.begin());
    operation.push_back(tmp);
}

void last_cell(vector<vector<int>>&operation , vector<string>&grid)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<pair<int,int>>cnt;
    for(int i=row-2;i<row;i++)
    {
        for(int j=col-2;j<col;j++)
        {
            if(grid[i][j] == '1')
                cnt.push_back(make_pair(i,j));
        }
    }
    while(cnt.size()!=0)
    {
        if(cnt.size()==3)
        {
            vector<int>tmp;
            for(int i=0;i<3;i++)
            {
                tmp.push_back(cnt[i].first+1);
                tmp.push_back(cnt[i].second+1);
            }
            operation.push_back(tmp);
            cnt.clear();
        }
        else if(cnt.size()==4)
            change_to_one(operation,cnt,row,col);
        else if(cnt.size() == 1)
            change_to_two(operation,cnt,row,col);
        else if(cnt.size() == 2)
            change_to_three(operation,cnt,row,col);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col;
        vector<string>grid(row);
        for(int i=0;i<row;i++)
            cin>>grid[i];
            
        vector<vector<int>>operation;
        if(row>2)
        {
            for(int i=0;i<row-2;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(grid[i][j]=='1')
                    {
                        row_op(i,j,operation,grid);
                    }
                }
            }
        }
        if(col>2)
        {
            for(int j=0;j<col-2;j++)
            {
                for(int i=row-2;i<row;i++)
                {
                    if(grid[i][j]=='1')
                    {
                        col_op(i,j,operation,grid);
                    }
                }
            }
        }
        last_cell(operation,grid);
        cout<<operation.size()<<endl;
        for(int i=0;i<operation.size();i++)
        {
            for(int j=0;j<operation[i].size();j++)
                cout<<operation[i][j]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}

