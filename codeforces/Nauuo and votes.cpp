#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x , y , z ;
    cin>>x>>y>>z;
    int i = x-y ;
    if(i<0 && i+z<0)
        cout<<"-";
    else if(i>0 && i-z>0)
        cout<<"+";
    else if(i==0 && z==0)
        cout<<"0";
    else
        cout<<"?";
    return 0;
}