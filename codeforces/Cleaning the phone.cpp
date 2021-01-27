#include<bits/stdc++.h>
using namespace std;

long long int get_cost(vector<long long int>&arr , int each_cost , long long int m)
{
    long long int sum = 0 , total_cost = 0;
    int idx = 0 ;
    while(idx < arr.size() && sum < m)
    {
        sum+=arr[idx++];
        total_cost+=each_cost;
    }
    
    if(sum < m)
        return -1 ;
    else
        return total_cost ;
}

long long int solve(vector<long long int>&cost1 , vector<long long int>&cost2 , long long int m)
{
    long long int total_memory = 0 , total_cost = 0 ;
    int idx1 = 0 , idx2 = 0 ;
    while(idx1 < cost1.size() && total_memory < m)
    {
        total_memory+=cost1[idx1++];
        total_cost++;
    }
    
    while(idx2 < cost2.size() && total_memory < m)
    {
        total_memory+=cost2[idx2++];
        total_cost+=2;
    }
    
    if(total_memory < m)
        return -1 ;
        
    long long int min_cost = total_cost ;
    for(int i = idx1 - 1 ; i >= 0 ; i--)
    {
        total_memory-=cost1[i];
        total_cost--;
        while(total_memory < m && idx2 < cost2.size())
        {
            total_memory+=cost2[idx2++];
            total_cost+=2;
        }
        
        if(total_memory >= m)
            min_cost = min( min_cost , total_cost);
    }
    
    return min_cost ;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n , m  ;
        cin>>n>>m;
        vector<long long int>memory(n);
        for(int i = 0 ; i < n ;i++)
            cin>>memory[i];
         
        vector<long long int>cost1 ;
        vector<long long int>cost2 ;
        for(int i = 0 ; i < n ; i++)
        {
            int val;
            cin>>val;
            if(val == 1)
                cost1.push_back(memory[i]);
            else
                cost2.push_back(memory[i]);
        }
        sort(cost1.begin(),cost1.end(),greater<long long int>());
        sort(cost2.begin(),cost2.end(),greater<long long int>());
        
        long long int total_cost = 0 ;
        if(cost1.size() == 0)
            total_cost = get_cost(cost2 , 2 , m);
        else if(cost2.size() == 0)
            total_cost = get_cost(cost1 , 1 , m);
        else
            total_cost = solve(cost1 , cost2 , m) ;
            
        cout<<total_cost<<endl;
    }
}