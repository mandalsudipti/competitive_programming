#include<bits/stdc++.h>
using namespace std;

bool sortfunc(const pair<long long int , long long int>&A , const pair<long long int , long long int>&B)
{
    if(A.first!=B.first)
    {
        return A.first<B.first ;
    }
    else
    {
        return A.second < B.second ;
    }
}

int main()
{
    int n , m ;
    cin>>n>>m;
    vector<long long int>food(n);
    vector<long long int>cost(n);
    vector<pair<long long int,long long int>>cost_type(n);
    
    for(int i=0;i<n;i++)
        cin>>food[i];
        
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
        cost_type[i] = make_pair(cost[i],i);
    }
    
    sort(cost_type.begin(),cost_type.end(),sortfunc);
    int idx = 0 ;
    
    
    while(m--)
    {
        long long int type , cnt , cur_cost = 0;
        cin>>type>>cnt;
        type--;
        
        long long int x = min(food[type],cnt);
        food[type]-=x;
        cur_cost+=(x*cost[type]);
        cnt-=x;
        
        while(cnt>0)
        {
            while(idx<cost_type.size() && food[cost_type[idx].second]<=0)
                idx++;
            if(idx>=cost_type.size())
                break;
            long long int y = min(cnt,food[cost_type[idx].second]);
            cur_cost+=(y*cost_type[idx].first);
            cnt-=y;
            food[cost_type[idx].second]-=y;
            //while(food[cost_type[idx].second]<=0)
                //idx++;
        }
        if(cnt==0)
            cout<<cur_cost<<endl;
        else
            cout<<"0"<<endl;
    }
    
    return 0;
        
}