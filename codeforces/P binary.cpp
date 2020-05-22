#include<bits/stdc++.h>
using namespace std;

int set_bit(long long int num)
{
    int cnt=0;
    while(num>0)
    {
        if(num&1)
            cnt++;
        num=num>>1;
    }
    return cnt;
}

int main()
{
    long long int sum,p;
    int cnt_one;
    cin>>sum>>p;
    if(p>=0)
    {
        sum-=p;
        cnt_one=1;
        while(sum>0 && (cnt_one<set_bit(sum) || cnt_one>sum) )
        {
            cnt_one++;
            if(cnt_one>64)
                break;
            sum-=p;
        }
    }
    else
    {
        sum-=p;
        cnt_one=1;
        while(cnt_one<set_bit(sum) || cnt_one>sum)
        {
            cnt_one++;
            if(cnt_one>64)
                break;
            sum-=p;
        }
        
    }
    if(cnt_one>=set_bit(sum) && cnt_one<=sum)
        cout<<cnt_one;
    else
        cout<<"-1";
    return 0;
}