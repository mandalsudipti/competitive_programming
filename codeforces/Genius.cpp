#include<bits/stdc++.h>
using namespace std ;

long long int get_point(vector<int>& tag , vector<long long int>& score)
{
    int n = tag.size() - 1 ;
    vector<long long int>points(n+1,0);
    
    for(int left = 2 ; left <= n ;left++)
    {
        for(int right = left - 1 ; right >= 1 ; right--)
        {
            if(tag[left] == tag[right])
                continue ;
                
            long long int l = points[left] , r = points[right] ;
            points[left] = max(l , r + abs(score[left] - score[right])) ;
            points[right] = max(r , l + abs(score[left] - score[right])) ;
        }
    }
    
    long long int total_point = 0 ;
    for(int i = 1 ; i <= n ; i++)
        total_point = max(total_point , points[i]) ;
        
    return total_point ;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>tag(n+1);
        vector<long long int>score(n+1) ;
        
        for(int i = 1 ; i <= n ; i++)
            cin>>tag[i] ;
            
        for(int i = 1 ; i <= n ; i++)
            cin>>score[i] ;
            
        long long int total_point = get_point(tag , score) ;
        cout<<total_point<<endl;
    }
    
    return 0 ;
}