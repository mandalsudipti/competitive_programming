#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n;
        cin>>n;
        long long int num=4;
        while(num-1<=n)
        {
            if(n%(num-1)==0)
            {
                cout<<n/(num-1)<<endl;
                break;
            }
            num=num*2;
        }
    }
    return 0;
}