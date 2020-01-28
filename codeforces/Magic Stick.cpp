#include<bits/stdc++.h>
using namespace std;

int main()
{
    const long long int one=1,two=2,three=3;
    long long int T;
    cin>>T;
    while(T--)
    {
        long long int x,y;
        cin>>x>>y;
        if(y<=x)
            cout<<"YES"<<endl;
        else
        {
            if(x==one||x==three)
                cout<<"NO"<<endl;
            else if(x==two && y>three)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}