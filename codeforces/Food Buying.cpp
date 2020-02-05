#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int coin , spend=0;
        cin>>coin;
        while(coin>=10)
        {
            spend+=(coin/10)*10;
            coin=(coin/10)+(coin%10);
        }
        spend+=coin;
        cout<<spend<<endl;
    }
    return 0;
}