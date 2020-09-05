#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int l , r , m ;
        cin>>l>>r>>m;
        
        long long int a , b, c ;
        for(int i=l;i<=r;i++)
        {
            long long int rem1 = m%i , rem2 = i - (m%i) ;
            if(i<=m && r-rem1>=l)
            {
                a = i ;
                b = r ;
                c = r - rem1 ;
                break;
            }
            else if(r-rem2>=l)
            {
                a = i ;
                b = r-rem2;
                c = r;
                break;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}
