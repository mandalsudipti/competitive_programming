#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a , b, n ;
        cin>>a>>b>>n;
        int cnt=0;
        while(a<=n && b<=n)
        {
            cnt++;
            a<=b?a+=b:b+=a;
        }
        cout<<cnt<<endl;
    }
    return 0;
}