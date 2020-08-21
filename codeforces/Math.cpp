#include<bits/stdc++.h>
using namespace std;

bool flag = false;
int nearest_power_of_two(int num)
{
    int cnt = 0 , tmp = num;
    while(num>1)
    {
        //cout<<num<<endl;
        cnt++;
        num = num/2;
    }
    while(pow(2,cnt)<tmp)
    {
        cnt++;
        flag = true ;
    }
    return pow(2,cnt);
}

int main()
{
    int n ;
    cin>>n;
    
    map<int,int>prime_factor;
    while(n%2==0)
    {
        prime_factor[2]++;
        n = n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            prime_factor[i]++;
            n = n/i;
        }
    }
    if(n>=2)
        prime_factor[n]++;
        
    for(auto itr=prime_factor.begin();itr!=prime_factor.end();++itr)
    {
        itr->second = nearest_power_of_two(itr->second);
    }
    
    int max_freq = 0 , min_freq = n+100;
    long long int num = 1;
    for(auto itr=prime_factor.begin();itr!=prime_factor.end();++itr)
    {
       num = num*(itr->first);
       int freq = itr->second ;
       max_freq = max(max_freq,freq);
       min_freq = min(min_freq,freq);
    }
    
    int tmp = max_freq , step=0;
    while(tmp>1)
    {
        step++;
        tmp = tmp/2;
    }
    
    if((min_freq!=max_freq && max_freq>0)||flag)
        step++;
        
    cout<<num<<" "<<step<<endl;
    
    return 0;
}



