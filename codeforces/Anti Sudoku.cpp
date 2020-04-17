#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<string>grid(9);
        for(int i=0;i<9;i++)
            cin>>grid[i];
            
        int pre = grid[0][0]-48;
        int cur = (pre+1==10)?1:pre+1;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(grid[i][j]==pre+48)
                    grid[i][j]=cur+48;
            }
        }
        for(int i=0;i<9;i++)
        {
            cout<<grid[i]<<endl;
        }
    }
    return 0;
}

