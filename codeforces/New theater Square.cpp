#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col , x , y ;
        cin>>row>>col>>x>>y;
        long long int cost = 0;
        vector<string>grid(row);
        for(int i=0;i<row;i++)
        {
            cin>>grid[i];
            int j=0;
            while(j<col)
            {
                if(grid[i][j]=='.')
                {
                    if(j+1<col && grid[i][j+1]=='.' && y<=(2*x))
                    {
                        j+=2;
                        cost+=y;
                    }
                    else
                    {
                        cost+=x;
                        j++;
                    }
                }
                else
                    j++;
            }
        }
        
        cout<<cost<<endl;
    }
    return 0;
}
