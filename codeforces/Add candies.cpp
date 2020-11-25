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
        cout<<(n-1)<<endl;
        for(int i=2;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
    }
    
    return 0;
}