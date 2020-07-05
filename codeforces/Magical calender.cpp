#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , r ;
        cin>>n>>r;
        long long int cnt = 0 ;
        if(n<=r)
            cnt++;
        long long int x = min(r,n-1);
        cnt+=(x*(x+1))/2 ;
        cout<<cnt<<endl;
    }
    return 0;
}