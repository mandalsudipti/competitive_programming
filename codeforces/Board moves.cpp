#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long int sum = 0 , start=8 , p = 1 ;
        for(int i=1;i<=n/2;i++)
        {
            sum+=(start*p);
            start+=8;
            p++;
        }
        cout<<sum<<endl;
    }
    return 0;
}