#include<bits/stdc++.h>
using namespace std;
const long long int limit = 1e18;
vector<long long int>power_three;

void precompute()
{
    power_three.push_back(1ll);
    while(power_three.back()<limit)
    {
        power_three.push_back(power_three.back()*3);
    }
}

int main()
{
    precompute();
    int Q;
    cin>>Q;
    while(Q--)
    {
        long long int N,K,tmp;
        cin>>N>>K;
        tmp=N;
        int cnt_bit=0;
        for(int i=power_three.size()-1;i>=0;i--)
        {
            while(N>=power_three[i])
            {
                cnt_bit++;
                N-=power_three[i];
            }
        }
        if(K<cnt_bit||K>tmp)
            cout<<"NO\n";
        else if(K%2==cnt_bit%2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}