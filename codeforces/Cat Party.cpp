#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&freq)
{
    map<int,int>color_cnt;
    for(int i=1;i<=10;i++)
    {
        if(freq[i]!=0)
        {
            color_cnt[freq[i]]++;
        }
    }
    
    if(color_cnt.size()>=3)
        return false;
    else if(color_cnt.size()==2)
    {
        auto itr=color_cnt.begin();
        if(itr->first==1)
        {
            if(itr->second==1)
                return true;
        }
        
            int x = itr->first;
            ++itr;
            if((itr->first)-x==1 && itr->second==1)
                return true;
            else
                return false;
    }
    else if(color_cnt.size()==1 && (color_cnt.begin()->first==1||color_cnt.begin()->second==1))
        return true;
    else
        return false;
}

int main()
{
    int n ;
    cin>>n;
    int val ,loc = -1;
    vector<int>freq(11,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>val;
        freq[val]++;
        if(check(freq))
            loc=i;
    }
    cout<<loc+1;
    return 0;
}
