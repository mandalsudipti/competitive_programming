#include<bits/stdc++.h>
using namespace std;
const long long int mod = 998244353 ;
int main()
{
    int n;
    cin>>n;
    vector<long long int>A(n+1,0);
    vector<long long int>B(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
        cin>>B[i];
    sort(B.begin()+1,B.end(),greater<long long int>());
    vector<long long int>product(n+1,0);
    
    long long int pre_col=0 , add=n ;
    for(int i=1;i<=((n/2)+(n%2));i++)
    {
        long long int x = pre_col+add ;
        pre_col=x;
        add-=2;
        
        long long int y ;
        //y= ( (x%mod)*(A[i]%mod))%mod;
        y=x*A[i];
        product[i]=y;
        
        //y= ( (x%mod)*(A[n+1-i]%mod))%mod;
        y=x*A[n+1-i];
        product[n+1-i]=y;
    }
    sort(product.begin(),product.end());
    for(int i=1;i<=n;i++)
        product[i]=((product[i]%mod)*B[i])%mod;
        
    long long int sum=0;
    for(int i=1;i<=n;i++)
        sum=(sum+product[i])%mod;
        
    cout<<sum%mod;
    return 0;
}
