#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , I , unit_size;
    cin>>n>>I;
    unit_size = (I*8)/n;
    map<long long int,int>freq;
    long long int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        freq[val]++;
    }
    if(unit_size>30)
    {
        cout<<"0";
        return 0;
    }
    long long int distinct_val = min((long long int)freq.size(),(1ll<<unit_size) ) ;
    
    //long long int reduce = freq.size() - distinct_val ;
    vector<int>get_freq;
    get_freq.push_back(0);
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        get_freq.push_back(itr->second);
    }
    /*sort(get_freq.begin(),get_freq.end());
    long long int ans=0;
    for(int i=0;i<reduce;i++)
        ans+=get_freq[i];
    cout<<ans;*/
    for(int i=1;i<get_freq.size();i++)
        get_freq[i]+=get_freq[i-1];
    int x=0;
    for(int i=distinct_val;i<get_freq.size();i++)
        x= max(x,get_freq[i]-get_freq[i- distinct_val]);
    cout<<n-x;
    return 0;
}



