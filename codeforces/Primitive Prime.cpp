#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m ,p;
    cin>>n>>m>>p;
    int i, A[n] , B[m] ;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<m;i++)
        cin>>B[i];
        
    int first_A=0 , first_B=0 ;
    while(A[first_A]%p==0)
        first_A++;
    while(B[first_B]%p==0)
        first_B++;
    cout<<first_A+first_B;
    return 0;
}