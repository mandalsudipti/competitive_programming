#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,x,a,b,ldif,rdif,diff;
        cin>>N>>x>>a>>b;
        if(a<b)
        {
            ldif=a-1;
            rdif=N-b;
            diff=b-a;
        }
        else
        {
            ldif=b-1;
            rdif=N-a;
            diff=a-b;
        }
        //cout<<diff<<endl;
        if(ldif<x)
        {
            diff+=ldif;
            x=x-ldif;
            if(rdif<=x)
                diff+=rdif;
            else
                diff+=x;
        }
        else
            diff+=x;
        cout<<diff<<endl;
    }
    return 0;
}