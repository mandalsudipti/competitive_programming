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
        string S="";
        for(int i=1;i<=n/2;i++)
        {
            S+='1';
        }
        if(n%2==1)
            S[0]='7';
        cout<<S<<endl;
    }
    return 0;
}