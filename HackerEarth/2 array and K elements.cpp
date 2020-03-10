#include<bits/stdc++.h>
using namespace std;

long long int get_sum(int A[],int N , int len)
{
    int prefix , suffix ;
    long long int maximum=-1000000001,sum=0;
    for(prefix=0;prefix<=len;prefix++)
    {
        suffix = len-prefix;
        /*if(prefix==0)
        {
            for(int i=N-1;i>=N-suffix;i--)
                sum+=A[i];
        }
        else
        {
            sum+=A[prefix-1];
            if(N-suffix<N)
                sum-=A[N-suffix];
        }*/
        for(int i=0;i<prefix;i++)
            sum+=A[i];
        if(N-suffix<=N-1)
            for(int i=N-1;i>=N-suffix;i--)
                sum+=A[i];
        maximum = max (maximum,sum);
        sum=0;
    }
    return maximum ;
}

int main()
{
    int N , K;
    cin>>N>>K;
    int A[N],B[N],i;
    long long int maximum=-1000000001 ;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        cin>>B[i];
    for(i=0;i<=min(N,K);i++)
    {
        if(K-i<=N)
            maximum=max(maximum , (get_sum(A,N,i)+get_sum(B,N,K-i)) );
    }
    cout<<maximum;
    return 0;
}