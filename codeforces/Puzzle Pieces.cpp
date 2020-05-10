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
        if(row==1 || col==1)
            cout<<"YES"<<endl;
        else if(row==2 && col==2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}