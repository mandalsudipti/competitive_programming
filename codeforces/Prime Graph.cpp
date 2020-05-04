#include<bits/stdc++.h>
using namespace std;

const int range = 2000;
vector<bool>is_prime(range,true);
vector<int>prime;

void sieve()
{
    for(int i=2;i*i<range;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<range;j+=i)
                is_prime[j]=false;
        }
    }
    for(int i=2;i<range;i++)
    {
        if(is_prime[i])
            prime.push_back(i);
    }
}

int main()
{
    sieve();
    int n ;
    cin>>n;
    int x = upper_bound(prime.begin(),prime.end(),n-1) - prime.begin();
    int edge = prime[x];
    cout<<edge<<endl;
    for(int i=1;i<n;i++)
        cout<<i<<" "<<i+1<<endl;
    cout<<n<<" "<<"1"<<endl;
    edge = edge - n ;
    vector<bool>node(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(edge==0)
            break;
        else if(node[i]==false)
        {
            cout<<i<<" "<<i+2<<endl;
            node[i]=true;
            node[i+2]=true;
            edge--;
        }
    }
    return 0;
}

