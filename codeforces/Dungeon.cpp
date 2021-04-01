#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int a , b , c ;
        cin>>a>>b>>c;
        
        if((a+b+c)%9 != 0)
            cout<<"NO\n";
        else
        {
            int x = (a+b+c)/9 ;
            if(a < x || b < x || c < x)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    
    return 0;
}