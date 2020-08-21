#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row , col , source_x , source_y ;
    cin>>row>>col>>source_x>>source_y;
    
    cout<<source_x<<" "<<source_y<<endl;
    for(int j=1;j<=col;j++)
    {
        if(j!=source_y)
            cout<<source_x<<" "<<j<<endl;
    }
    bool right = true ;
    for(int i=source_x-1;i>=1;i--)
    {
        if(right)
        {
            right = false ;
            for(int j=col;j>=1;j--)
                cout<<i<<" "<<j<<endl;
        }
        else
        {
            right = true ;
            for(int j=1;j<=col;j++)
                cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=source_x+1;i<=row;i++)
    {
        if(right)
        {
            right = false;
            for(int j=col;j>=1;j--)
                cout<<i<<" "<<j<<endl;
        }
        else
        {
            right = true ;
            for(int j=1;j<=col;j++)
                cout<<i<<" "<<j<<endl;
        }
    }
    
    return 0;
}