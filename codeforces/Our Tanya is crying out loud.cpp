#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N , k , A , B , cost=0 ;
    cin>>N>>k>>A>>B;
    if(k==1)
    {
        cout<<(N-1)*min(A,B);
        return 0;
    }
    while(N>=k)
    {
        cost+=(N%k)*A;
        N=N/k;
        cost+=min(B,(N*k-N)*A);
    }
    if(N>1)
        cost+=(N-1)*A;
    cout<<cost<<endl;
    return 0;
}
