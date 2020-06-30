#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1e9+7 , size = 2000005 ;

int main()
{
    int T;
    cin>>T;
    vector<long long int>level(size) ;
    level[0]=0;
    level[1]=0;
    level[2]=0;
    for(int i=3;i<level.size();i++)
        level[i] = (level[i-1] + (2*level[i-2])%mod + (i%3==0 ? 4 : 0))%mod;
    while(T--)
    {
        int n ;
        cin>>n;
        cout<<level[n]<<endl;
    }
    return 0;
}