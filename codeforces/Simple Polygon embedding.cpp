#include<bits/stdc++.h>
using namespace std;
const long double PI =  3.14159265;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long double n ;
        cin>>n;
        cout<<fixed<<setprecision(9)<<1/tan(PI/(2*n))<<endl;
    }
    return 0;
}