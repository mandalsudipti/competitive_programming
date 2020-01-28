#include<bits/stdc++.h>
using namespace std;
long long int get_pow(long long int a,long long int b)
{
    if(b==0)
    {
        a=1;
        return a;
    }
    for(int i=1;i<b;i++)
    {
        a=a<<1;
    }
    return a;
}
int main()
{
    long long int n,l,r, x=2,y=1;
    cin>>n>>l>>r;
    long long int min,max;
    if(l==1)
    {
        min=n;
        cout<<min;
    }
    else
    {
        min=n-l+y+(x*(get_pow(x,l-y)-y));
        cout<<min;
    }
    max=get_pow(x,r)-1;
    if(n>r)
        max+=(n-r)*get_pow(x,r-1);
    cout<<" "<<max;
    return 0;
}

