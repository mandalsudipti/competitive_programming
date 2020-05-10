#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a , long long int b)
{
    while(a!=0 && b!=0)
    {
        if(a>=b)
            a=a%b;
        else
            b=b%a;
    }
    if(a==0)
        return b;
    else
        return a;
}

long long int get_cnt(long long int num , vector<long long int>&good_num,long long int lcm)
{
    long long int full_cycle = num/lcm;
    return full_cycle*good_num[lcm]+good_num[num%lcm];
}

void solve()
{
    long long int a , b, query;
    cin>>a>>b>>query;
    long long int lcm = (a*b)/gcd(a,b);
    vector<long long int>good_num(lcm+1,0);
    for(int i=1;i<=lcm;i++)
        good_num[i]=good_num[i-1] + ((i%a)%b!=(i%b)%a) ;
        
    while(query--)
    {
        long long int left , right ;
        cin>>left>>right;
        long long int cnt = get_cnt(right,good_num,lcm) - get_cnt(left-1,good_num,lcm);
        cout<<cnt<<" ";
    }
    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
