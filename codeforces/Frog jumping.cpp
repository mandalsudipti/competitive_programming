#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int left , right , k;
        cin>>right>>left>>k;
        long long int ans = (right-left)*(k/2) + right*(k%2) ;
        cout<<ans<<endl;
    }
    return 0;
}