#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , divisor ,ele;
    map<int,int> rem_freq;
    cin>>n>>divisor;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        
        rem_freq[(ele%divisor)]++;
    }
    int cnt=0;
    for(auto itr=rem_freq.begin();itr!=rem_freq.end();++itr)
    {
        int x = divisor - itr->first ;
        if(x==itr->first)
            cnt+=(rem_freq[x]/2)*2;
        else
            cnt=cnt+ min(itr->second, rem_freq[x]);
    }
    
    if(rem_freq[0]!=0)
        cnt+= (rem_freq[0]/2)*2;
    cout<<cnt;
    return 0;
}
