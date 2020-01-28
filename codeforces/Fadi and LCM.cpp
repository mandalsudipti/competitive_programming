#include<bits/stdc++.h>
using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( ( n&(1LL << bit) ) != 0);
}

int main()
{
    long long int n , num;
    cin>>n;
    num=n;
    vector<long long int> prime_factor;
    long long int val=1;
    while(n%2==0)
    {
        val*=2;
        n=n/2;
    }
    prime_factor.push_back(val);
    for(int i=3;i<=sqrt(n);i+=2)
    {
        val=1;
        while(n%i==0)
        {
            val*=i;
            n=n/i;
        }
        if(val!=1)
            prime_factor.push_back(val);
    }
    if(n>2)
        prime_factor.push_back(n);
    
    long long int x , y , ans_x=1 , ans_y=num , unique_factor=prime_factor.size();
    
    for(long long mask = 0; mask < (1LL <<unique_factor); mask++) //total number of combination
    {
        x = 1, y = 1;
        for(int bit = 0; bit <unique_factor; bit++)
        {
            if(is_bit_set(mask, bit))
            {
               x *= prime_factor[bit];
            }
            else
            {
                y *= prime_factor[bit];
            }
        }
        //cout<<max(x,y)<<" "<<max(ans_x,ans_y)<<endl;
        if(max(x, y) < max(ans_x, ans_y))
        {
            ans_x = x;
            ans_y = y;
            //cout<<ans_x<<" "<<ans_y<<endl;
        }
    }
    cout<<ans_x<<" "<<ans_y;
    return 0;
}
