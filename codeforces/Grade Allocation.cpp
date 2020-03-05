#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ,m;
        cin>>n>>m;
        long long int x,sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }
        cout<<min(m,sum)<<endl;
    }
    return 0;
}