#include<bits/stdc++.h>
using namespace std;

void find(long long int num , long long int *min_dig,long long int *max_dig)
{
    long long int digit;
    *min_dig=9;
    *max_dig = 0;
    while(num>0)
    {
        digit=num%10;
        num=num/10;
        if(digit<*min_dig)
            *min_dig=digit;
        if(digit>*max_dig)
            *max_dig=digit;
    }
}

void solve()
{
    long long int n , k , min_dig,max_dig;
    cin>>n>>k;
    for(int i=2;i<=k;i++)
    {
        find(n,&min_dig,&max_dig);
        if(min_dig==0||max_dig==0)
            break;
        else
            n+=(min_dig*max_dig);
    }
    cout<<n<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}