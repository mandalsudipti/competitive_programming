#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row , col , i ,j;
    cin>>row>>col;
    char arr[row+1][col+1];
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
            cin>>arr[i][j];
    }
    
    long long int horizontal[row+1][col+1]={} ,vertical[row+1][col+1]={} ;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            horizontal[i][j]=(arr[i][j-1]=='.' && arr[i][j]=='.');
            horizontal[i][j]+=horizontal[i-1][j]+horizontal[i][j-1]-horizontal[i-1][j-1];
            vertical[i][j]=(arr[i-1][j]=='.' && arr[i][j]=='.');
            vertical[i][j]+=vertical[i-1][j]+vertical[i][j-1]-vertical[i-1][j-1];
        }
    }
    int Q ;
    cin>>Q;
    while(Q--)
    {
        int r1 , c1 ,r2 , c2;
        cin>>r1>>c1>>r2>>c2;
        long long int total_cnt ;
        total_cnt=horizontal[r2][c2]-horizontal[r1-1][c2]-horizontal[r2][c1]+horizontal[r1-1][c1]; //horizontal domino
        total_cnt+=vertical[r2][c2]-vertical[r1][c2]-vertical[r2][c1-1]+vertical[r1][c1-1]; //vertical domino
        cout<<total_cnt<<endl;
    }
    return 0;
}

