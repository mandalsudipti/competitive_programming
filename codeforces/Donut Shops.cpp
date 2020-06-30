#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a , donut_pack , c ;
        cin>>a>>donut_pack>>c;
        a<c ? cout<<"1 " : cout<<"-1 ";
        c<(a*donut_pack) ? cout<<donut_pack<<endl : cout<<"-1"<<endl;
    }
    return 0;
}