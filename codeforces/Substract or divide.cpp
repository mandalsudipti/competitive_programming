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
        int cnt = 0 ;
        if((n%2 == 0 && n>2) || n==3)
            cnt = 2;
        else if(n ==2)
            cnt = 1;
        else if( n > 3 && n%2 == 1)
            cnt = 3 ;
        cout<<cnt<<endl;
    }
    
    return 0;
}
