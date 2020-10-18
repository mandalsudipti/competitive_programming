#include<bits/stdc++.h>
using namespace std;

int left_most(int num)
{
    int bit = 0 ;
    while(num>0)
    {
        bit++;
        num = num/2;
    }
    return bit-1 ;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<long long int>left_most_bit(40,0);
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            int x = left_most(val);
            left_most_bit[x]++;
        }
        
        long long int cnt = 0 ;
        for(int i=0;i<left_most_bit.size();i++)
        {
            cnt+=(left_most_bit[i]*(left_most_bit[i]-1))/2 ;
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}