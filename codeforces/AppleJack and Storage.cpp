#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,multiset<int,greater<int>>&freq)
{
    char ch ;
    cin>>ch;
    int num ;
    cin>>num;
    
    int pre = arr[num] , cur = arr[num] ;
    ch=='+' ? cur++ : cur--;
    ch=='+' ? arr[num]++ : arr[num]-- ;
    freq.erase(freq.lower_bound(pre));
    freq.insert(cur);
        
    auto itr = freq.begin();
    //cout<<(*itr)<<endl;
    if(itr==freq.end()||(*itr)<4)
        cout<<"NO"<<endl;
    else if((*itr)>=8)
        cout<<"YES"<<endl;
    else if((*itr)>=6)
    {
        ++itr;
        if(itr==freq.end()||(*itr)<2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    else
    {
        ++itr;
        if(itr==freq.end()||(*itr)<2)
            cout<<"NO"<<endl;
        else if((*itr)>=4)
            cout<<"YES"<<endl;
        else
        {
            ++itr;
            if(itr==freq.end()||(*itr)<2)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
}
int main()
{
    int n , val;
    cin>>n;
    vector<int>arr(100005,0);
    multiset<int,greater<int>>freq;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        arr[val]++;
    }
    for(int i=0;i<arr.size();i++)
        freq.insert(arr[i]);
        
    int query;
    cin>>query;
    while(query--)
    {
        solve(arr,freq);
    }
    return 0;
}
