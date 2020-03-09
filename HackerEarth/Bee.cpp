#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N , K;
    cin>>N>>K;
    long long int val  , sum =0 ;
    for(int i=0;i<K;i++)
    {
        cin>>val;
        sum+=val;
    }
    if(sum>=N)
        cout<<"1";
    else
    {
        cout<<(N/sum)+(N%sum!=0);
    }
    return 0;
}