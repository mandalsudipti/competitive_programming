#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        if(k<=n)
        {
            if(k%2==n%2)
                cout<<"0"<<endl;
            else
                cout<<"1"<<endl;
        }
        else
            cout<<(k-n)<<endl;
    }
    return 0;
}