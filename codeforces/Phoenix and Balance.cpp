#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        long long int grp1 = (1ll<<n) ,grp2 = 0 , start=1 ,i;
        for(i=1;i<(n/2);i++)
            grp1 = (grp1+(1ll<<i));
        for(i=n/2;i<n;i++)
            grp2 = (grp2+(1ll<<i));
        //cout<<grp1<<" "<<grp2<<endl;
        cout<<abs(grp1- grp2)<<endl;
    }
    return 0;
}
