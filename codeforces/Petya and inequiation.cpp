#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , x , y ;
    cin>>n>>x>>y;
    if(y<n)
    {
        cout<<"-1";
        return 0;
    }
    long long int sum=n-1ll+(y-n+1ll)*(y-n+1ll);
    if(sum<x)
        cout<<"-1";
    else
    {
        cout<<(y-n+1ll)<<endl;
        for(int i=0;i<n-1;i++)
            cout<<"1"<<endl;
    }
    return 0;
}