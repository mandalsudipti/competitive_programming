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
        char  mat[row+1][col+1];
        for(int i=1;i<=row;i++)
        {
            if(i==1)
                mat[i][1]='B';
            else
                mat[i-1][1]=='B'?mat[i][1]='W':mat[i][1]='B';
            for(int j=2;j<=col;j++)
                mat[i][j-1]=='B'?mat[i][j]='W':mat[i][j]='B';
        }
        if((row*col)%2==0)
        {
            for(int j=col;j>=1;j--)
            {
                if(mat[row][j]=='W')
                {
                    mat[row][j]='B';
                    break;
                }
            }
        }
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
                cout<<mat[i][j];
            cout<<endl;
        }
    }
    return 0;
}