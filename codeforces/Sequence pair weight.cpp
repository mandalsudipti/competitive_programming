#include<bits/stdc++.h>
using namespace std ;

long long int get_weight(vector<int>& arr , int n)
{
    long long int right = n - arr.back() , weight = 0;
    
    for(int i = arr.size()-2 ; i >= 0 ; i--)
    {
        long long int left = arr[i]+1 ;
        weight+=(left * right) ;
        
        right+=(n - arr[i]) ;
    }
    return weight ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , val; 
        cin>>n;
        
        map<int , vector<int>>occur ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val ;
            occur[val].push_back(i) ;
        }
        
        long long int weight = 0 ;
        for(pair<int,vector<int>>P : occur)
        {
            if(P.second.size() < 2)
                continue ;
                
            weight+=get_weight(P.second , n) ;
        }
        cout<<weight<<endl;
    }
    return 0 ;
}