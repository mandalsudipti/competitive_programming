#include<bits/stdc++.h>
using namespace std ;

int solve(vector<string>& arr , vector<vector<int>>& freq , int idx)
{
    vector<int>diff ;
    for(int i = 0 ; i < arr.size() ; i++)
        diff.push_back(freq[i][idx] - (arr[i].size() - freq[i][idx]) ) ;
        
    sort(diff.begin() , diff.end() , greater<int>());
    long long int sum = diff[0] ;
    if(sum <= 0)
        return 0 ;
        
    for(int i = 1 ; i < diff.size() ; i++)
    {
        if(sum + diff[i] <= 0)
            return i ;
            
        sum+=diff[i] ;
    }
    
    return (int)diff.size() ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        vector<string>arr(n);
        vector<vector<int>>freq( n , vector<int>(5,0));
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            for(int j = 0 ; j < arr[i].length() ; j++)
                freq[i][arr[i][j] - 'a']++ ;
        }
        
        int maximum = 0 ;
        for(int i = 0 ; i < 5 ; i++)
            maximum = max(maximum , solve(arr , freq , i));
            
        cout<<maximum<<endl;
    }
    
    return 0 ;
}