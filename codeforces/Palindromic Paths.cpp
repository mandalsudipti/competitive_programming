#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col;
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cin>>grid[i][j];
        }
        vector<pair<int,int>>diagonal;
        for(int i=0;i<row;i++)
        {
            int cnt_zero = 0 , cnt_one = 0 ,tmp = i , j = 0 ;
            while(tmp>=0 && j<col)
            {
                if(grid[tmp][j]==0)
                    cnt_zero++;
                else
                    cnt_one++;
                tmp--;
                j++;
            }
            diagonal.push_back(make_pair(cnt_zero,cnt_one));
        }
        for(int j=1;j<col;j++)
        {
            int cnt_one = 0 , cnt_zero = 0 , tmp = j , i=row-1 ;
            while(tmp<col && i>=0)
            {
                if(grid[i][tmp]==1)
                    cnt_one++;
                else
                    cnt_zero++;
                i--;
                tmp++;
            }
            diagonal.push_back(make_pair(cnt_zero,cnt_one));
        }
        //for(int i=0;i<diagonal.size();i++)
            //cout<<diagonal[i].first<<" "<<diagonal[i].second<<endl;
        int change = 0 , left = 0 , right = diagonal.size() - 1;
        while(left<right)
        {
            change+=min(diagonal[left].first+diagonal[right].first , diagonal[left].second+diagonal[right].second);
            left++;
            right--;
        }
        cout<<change<<endl;
    }
    return 0;
}
