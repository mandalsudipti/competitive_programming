#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        int col1=x,col2=a-x-1,row1=y,row2=b-y-1;
        cout<<max(max(col1*b,col2*b),max(row1*a,row2*a))<<endl;
    }
    return 0;
}