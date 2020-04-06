#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        long long int l , r , d ;
        cin>>l>>r>>d;
        if(l-1<d)
        {
            long long int x = (r+1)/d + ((r+1)%d!=0);
            cout<<(d*x)<<endl;
        }
        else
        {
            cout<<d<<endl;
        }
    }
    return 0;
}