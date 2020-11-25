#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int left , right ;
        cin>>left>>right;
        long long int ans = left*2;
        if(right>=ans)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    return 0;
}