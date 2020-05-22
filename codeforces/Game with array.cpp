#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , s ;
    cin>>n>>s;
    if(s<=(2*n-1))
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n-1;i++)
            cout<<"1"<<" ";
        cout<<s-(n-1)<<endl;
        cout<<n;
    }
    return 0;
}