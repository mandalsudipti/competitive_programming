#include<bits/stdc++.h>
using namespace std ;

void solve()
{
    int n ;
    cin>>n;
    
    vector<pair<int,int>>location(n+1,make_pair<int,int>(1,1));
    for(int i = 1 ; i <= n ; i++)
        cin>>location[i].first ;
    for(int i = 1 ; i <= n ; i++)
        cin>>location[i].second ;
        
    sort(location.begin() , location.end());
    
    long long int cost = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
        long long int diff_source = location[i-1].first - location[i-1].second ;
        long long int diff_target = location[i].first - location[i].second ;
        
        long long int diff = diff_target - diff_source ;
       
        if(diff == 0)
            cost+=( (location[i-1].first + location[i-1].second)%2 == 0 ? location[i].first - location[i-1].first : 0) ;
        else
        {
            if((location[i-1].first + location[i-1].second)%2 == 0)
                cost+=(diff / 2) ;
            else
                cost+=((diff / 2) + (diff % 2)) ;
        }
    }
    
    cout<<cost<<endl;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
        solve() ;
        
    return 0 ;
}