#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n , k;
    cin>>n>>k;
    if(k>n)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(n%2==1 && k%2==0)
    {
        cout<<"NO"<<endl;
    }
    else if(n%2==0 && k%2==0)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;i++)
            cout<<"1"<<" ";
        cout<<(n-(k-1))<<endl;
    }
    else if (n%2==0 && k%2==1)
    {
        if(n<(k*2))
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k-1;i++)
                cout<<"2"<<" ";
            cout<<n-(2*(k-1))<<endl;
        }
    }
    else if(n%2==1 && k%2==1)
    {
        if(n<k)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k-1;i++)
                cout<<"1"<<" ";
            cout<<(n-(k-1))<<endl;
        }
    }
    
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}