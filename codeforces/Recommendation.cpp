#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<pair<int,int>>arr(n,make_pair(0,0));
    
    for(int i=0;i<n;i++)
        cin>>arr[i].first;
    for(int i=0;i<n;i++)
        cin>>arr[i].second;
        
    sort(arr.begin(),arr.end());
    multiset<long long int>equal_quantity ;
    long long int ans = 0 , cur_quantity = 0 , cur_cost = 0;
    int idx = 0 ;
    
    while(idx < arr.size() || equal_quantity.size() > 0)
    {
        while(idx < arr.size() && arr[idx].first == cur_quantity)
        {
            cur_cost+=arr[idx].second ;
            equal_quantity.insert(arr[idx].second);
            idx++;
        }
        
        if(equal_quantity.size() > 0)
        {
            auto itr = equal_quantity.rbegin() ;
            long long int maximum = (*itr) ;
            equal_quantity.erase(equal_quantity.lower_bound(maximum));
            cur_cost-=maximum ;
            ans+=cur_cost;
            cur_quantity++;
        }
        else
            cur_quantity = arr[idx].first ;
    }

    cout<<ans<<endl;
    
    return 0 ;
}
