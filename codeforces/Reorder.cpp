#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , m;
        cin>>n>>m;
        long long int sum = 0 , val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            sum+=val;
        }
        if(sum==m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}