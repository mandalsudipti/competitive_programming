#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row , col ;
    cin>>row>>col;
    
    int A[row][col],B[row][col];
    vector<int>A_row_parity(row);
    vector<int>B_row_parity(row);
    
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            cin>>A[i][j];
            sum+=A[i][j];
        }
        sum%2==1?A_row_parity[i]=1:A_row_parity[i]=0;
    }
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            cin>>B[i][j];
            sum+=B[i][j];
        }
        sum%2==1?B_row_parity[i]=1:B_row_parity[i]=0;
    }
    for(int i=0;i<row;i++)
    {
        if(A_row_parity[i]!=B_row_parity[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    for(int j=0;j<col;j++)
    {
        int sum_A = 0 , sum_B=0;
        for(int i=0;i<row;i++)
        {
            sum_B+=B[i][j];
            sum_A+=A[i][j];
        }
        if(sum_A%2!=sum_B%2)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}