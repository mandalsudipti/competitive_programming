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
        int ans= (n-1)- (n/2);
        if(ans>=1)
            cout<<ans<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}