#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k , val;
        cin>>n>>k;
        map<int,int>freq;
        long long int maximum = 0 ;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val%k==0)
                continue;
            val = val%k;
            val = k-val ;
           freq[val]++;
        }
        for(auto itr=freq.begin();itr!=freq.end();++itr)
        {
            long long int x = (itr->first)+((itr->second)-1)*k;
            maximum = max(maximum,x+1);
        }
        cout<<maximum<<endl;
    }
    return 0;
}
