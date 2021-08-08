#include<bits/stdc++.h>
using namespace std ;

long long int get_cost(vector<long long int>& filled , vector<long long int>& empty)
{
    int n = filled.size() , extra = empty.size() - filled.size();
    vector<vector<long long int>>cost(n , vector<long long int>(empty.size())) ;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0)
        {
            cost[0][0] = abs(filled[0] - empty[0]) ;
            for(int j = 1 ; j <= extra ; j++)
                cost[i][i+j] = min( abs(filled[i] - empty[i+j]) , cost[i][i+j-1] );
        }
        else
        {
            cost[i][i] = abs(filled[i] - empty[i]) + cost[i-1][i-1] ;
            //cost[i][i+1] = abs(filled[i] - empty[i+1]) + min(cost[i-1][i] , cost[i-1][i-1]) ;
            
            for(int j = 1 ; j <= extra ; j++)
                cost[i][i+j] = min( abs(filled[i] - empty[i+j]) + cost[i-1][i+j-1] , cost[i][i+j-1]) ;
        }
    }
    
    long long int minimum = LLONG_MAX ;
    for(int i = n-1 ; i < empty.size() ; i++)
        minimum = min(minimum , cost[n-1][i]) ;
        
    return minimum ;
}

int main()
{
    int n ;
    cin>>n;
    
    vector<long long int>arr(n) , filled , empty ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i] ;
        if(arr[i] == 1)
            filled.push_back(i) ;
        else
            empty.push_back(i) ;
    }
    
    long long int total_cost = 0 ;
    if(filled.size() == empty.size())
    {
        for(int i = 0 ; i < filled.size() ; i++)
            total_cost+=abs(filled[i] - empty[i]) ;
    }
    else if(filled.size() > 0)
        total_cost = get_cost(filled , empty) ;
        
    cout<<total_cost<<endl;
    
    return 0 ;
}