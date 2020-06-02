#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<string>grid(n);
        for(int i=0;i<n;i++)
            cin>>grid[i];
            
        bool possible = true ;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(grid[i][j+1]=='0' && grid[i+1][j]=='0')
                    {
                        possible=false;
                        break;
                    }
                }
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}