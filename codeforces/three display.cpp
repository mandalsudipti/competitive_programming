#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    long long int size[n] , cost[n] ;
    for(int i=0;i<n;i++)
        cin>>size[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
        
    long long int min_cost = 3e8+50 ;
    for(int i=1;i+1<n;i++)
    {
        long long int left_cost = 1e8+50 , right_cost = 1e8+50 ;
        for(int j=0;j<i;j++)
        {
            if(size[j]<size[i] && cost[j]<left_cost)
                left_cost=cost[j];
        }
        for(int j=i+1;j<n;j++)
        {
            if(size[j]>size[i] && cost[j]<right_cost)
                right_cost=cost[j];
        }
        if(left_cost==1e8+50 || right_cost==1e8+50)
        {
            continue;
        }
        min_cost = min(min_cost , cost[i]+left_cost+right_cost);
    }
    if(min_cost == 3e8+50)
        cout<<"-1";
    else
        cout<<min_cost;
    
    return 0;
}
