#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row , col ;
    cin>>row>>col;
    int max_diagonal = row+col ;
    vector<vector<int>>A_diagonal(max_diagonal+2);
    vector<vector<int>>B_diagonal(max_diagonal+2);
    int val ;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>val;
            A_diagonal[i+j].push_back(val);
        }
    }
    
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>val;
            B_diagonal[i+j].push_back(val);
        }
    }
    
    bool possible =true;
    for(int i=1;i<=max_diagonal;i++)
    {
        sort(A_diagonal[i].begin(),A_diagonal[i].end());
        sort(B_diagonal[i].begin(),B_diagonal[i].end());
        
        if(A_diagonal[i]!=B_diagonal[i])
        {
            possible=false;
            break;
        }
    }
    if(!possible)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}

