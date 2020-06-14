#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int side = (n/2) + 1 ;
    cout<<side<<endl;
    for(int i=1;i<=n/2;i++)
        cout<<"1"<<" "<<i<<endl;
    for(int i=1;i<=n/2+(n%2);i++)
        cout<<side<<" "<<i<<endl;
    return 0;
}

