#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
     long long int n ,d , x;
     bool possible=false;
     cin>>n>>d;
     for(x=0;x<=sqrt(d);x++)
     {
        if(x+( d/(x+1)) + (d%(x+1)!=0)<= n )
        {
            cout<<"YES"<<endl;
            possible=true;
            break;
        }
     }
     if(!possible)
        cout<<"NO"<<endl;
    }
    return 0;
}


