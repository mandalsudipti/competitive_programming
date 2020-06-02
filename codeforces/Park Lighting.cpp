#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int row , col ;
        cin>>row>>col ;
        long long int x  = (row/2)*col;
        if(row%2==1)
            x+=(col/2) + (col%2) ;
        cout<<x<<endl;
    }
    return 0;
}
