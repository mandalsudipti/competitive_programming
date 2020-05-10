#include<bits/stdc++.h>
using namespace std;

const int nxt[]={-1,1,0};
int main()
{
    int n , k ;
    cin>>n>>k;
    vector<int>freq(n+1,0);
    vector<int>arr(k);
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    set<int>prefix;
    set<int>suffix;
    int cnt=0 , new_suffix ;
    for(int i=1;i<=n;i++)
        prefix.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0)
            suffix.insert(i);
    }
    for(auto itr=suffix.begin();itr!=suffix.end();++itr)
    {
        int val = *itr , nxt_val ;
        for(int j=0;j<3;j++)
        {
            nxt_val = val + nxt[j];
            if(prefix.find(nxt_val)!=prefix.end())
                cnt++;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(prefix.find(arr[i])!=prefix.end())
        {
            prefix.erase(prefix.find(arr[i]));
        }
        freq[arr[i]]--;
        if(freq[arr[i]]<=0)
        {
            new_suffix=arr[i];
            int nxt_val ;
            for(int j=0;j<3;j++)
            {
                nxt_val = new_suffix + nxt[j] ;
                if(prefix.find(nxt_val)!=prefix.end())
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
