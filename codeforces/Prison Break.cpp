#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col , i , j ;
        cin>>row>>col>>i>>j;
        
        cout<<max(row - i , i - 1) + max( col - j , j - 1)<<endl;
    }
    
    return 0;
}