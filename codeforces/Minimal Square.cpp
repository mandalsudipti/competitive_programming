#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a , b ;
        cin>>a>>b;
        int side =  max( min(a,b)*2 , max(a,b) );
        cout<<(side*side)<<endl;
    }
    return 0;
}