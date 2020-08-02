#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        if(n-30<=0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            int a =  6 , b = 10 , c = 14 ;
            if(n-(a+b+c)==6 ||(n-(a+b+c))==14 ||(n-(a+b+c))==10)
                c =15;
            cout<<a<<" "<<b<<" "<<c<<" "<<(n-(a+b+c))<<endl;
        }
    }
    return 0;
}

