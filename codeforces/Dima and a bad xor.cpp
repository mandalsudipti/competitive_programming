#include<bits/stdc++.h>
using namespace std;

int check(vector<int>&grid , int bit , vector<vector<pair<int,int>>>&arr, int row)
{
    int  set = -1 , unset= -1;
    for(int i=0;i<grid.size();i++)
    {
        if(grid[i] & (1<<bit))
            set=i;
        else
            unset=i;
    }
    if(unset>-1 && set>-1)
    {
        arr[row][bit] = make_pair(unset,set);
        return 2;
    }
    else if(unset>-1)
    {
        arr[row][bit]=make_pair(-2,0); // all zero
        return 0;
    }
    else
    {
        arr[row][bit]=make_pair(-1,0); // all one
        return 1;
    }
}

int main()
{
    int row , col ;
    cin>>row>>col;
    vector<int>all_set_bit(10,0);  // how many rows have all xth bit set
    vector<int>all_unset_bit(10,0); // how many rows have all xth bit not_set
    vector<vector<pair<int,int>>>arr(row,vector<pair<int,int>>(10));
    
    for(int i=0;i<row;i++)
    {
        vector<int>grid(col);
        for(int j=0;j<col;j++)
            cin>>grid[j];
        for(int bit=0;bit<10;bit++)
        {
            int x = check(grid,bit,arr,i);
            if(x==0)
                all_unset_bit[bit]++;
            else if(x==1)
                all_set_bit[bit]++;
        }
    }
    vector<int>ans;
    for(int bit=0;bit<10;bit++)
    {
        if(ans.size()==row)
            break;
        int cnt;
        if(all_set_bit[bit]%2==1)
            cnt=0;
        else if(row - (all_set_bit[bit]+all_unset_bit[bit])>=1)
            cnt=1;
        else
            continue;
        for(int i=0;i<row;i++)
        {
            //cout<<arr[i][bit].first<<" "<<arr[i][bit].second<<endl;
            if(arr[i][bit].first==-2 || arr[i][bit].first==-1) // all set or all unset
                ans.push_back(arr[i][bit].second);
            else
            {
                if(cnt)
                {
                    ans.push_back(arr[i][bit].second);
                    cnt--;
                }
                else
                    ans.push_back(arr[i][bit].first);
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"NIE";
        return 0;
    }
    cout<<"TAK"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
        
    return 0;
}





