#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k;
        cin>>n>>k;
        if(n%2!=k%2)
            cout<<"NO\n";
        else
        {
            if(k*k>n)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}