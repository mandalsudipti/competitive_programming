#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,K,D,i;
        cin>>N>>K>>D;
        int A[N],freq[K+1]={0},distinct=0,min=0;
        for(i=0;i<N;i++)
            cin>>A[i];
        for(i=0;i<D;i++)
        {
            if(freq[A[i]]==0)
            {
                distinct++;
            }
            freq[A[i]]++;
        }
        min=distinct;
        for(i=D;i<N;i++)
        {
            freq[A[i-D]]=freq[A[i-D]]-1;
            if(freq[A[i-D]]==0)
                distinct=distinct-1;
            if(freq[A[i]]==0)
                distinct=distinct+1;
            freq[A[i]]=freq[A[i]]+1;
            if(distinct<min)
                min=distinct;
        }
        cout<<min<<endl;
    }
    return 0;
}
