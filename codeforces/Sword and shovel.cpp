#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int stick , diamond ;
        cin>>stick>>diamond;
        int a = 0 , b = 0;
        a = max(0,(2*diamond - stick) / 3) ;
        a = min(a , min(diamond/2,stick));
        stick-=a;
        diamond-=2*a;
        b = min(stick/2,diamond);
        cout<<a+b<<endl;
    }
    return 0;
}


