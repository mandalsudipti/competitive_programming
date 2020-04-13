#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        map<int,int>freq;
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            freq[val]++;
        }
        int distinct = freq.size() , max_freq=0;
        for(auto itr=freq.begin();itr!=freq.end();++itr)
        {
            if(itr->second>max_freq)
                max_freq=itr->second;
        }
        if(distinct==max_freq)
            cout<<distinct-1<<endl;
        else
            cout<<min(distinct,max_freq)<<endl;
    }
    return 0;
}