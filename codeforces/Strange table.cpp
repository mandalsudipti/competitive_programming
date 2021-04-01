#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int row , col , val ;
        cin>>row>>col>>val;
        
        long long int j = (val/row) + (val % row != 0) - 1 ;
        long long int i = val - (row*j) - 1 ;
        
        long long int new_val = (i*col) + 1 + j ;
        cout<<new_val<<endl;
    }
    
    return 0 ;
}
