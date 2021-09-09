#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , m ;
    cin>>n>>m;
    
    vector<int>post(n+1) ; // order of post
    vector<int> post_pos(n+1) ; // position of i-th post
    vector<int> min_pos(n+1) , max_pos(n+1) ; // min and max position of i-th post
    vector<int>like(m) ; // which post is liked
    
    for(int i = 0 ; i < m ; i++)
        cin>>like[i] ;
        
    for(int i = 1 ; i <= n ; i++)
    {
        post[i] = post_pos[i] = min_pos[i] = max_pos[i] = i ;
    }
    
    for(int i = 0 ; i < m ;i++)
    {
        int liked_post_pos = post_pos[like[i]] ;
        if(liked_post_pos == 1)
            continue ;
        
        int previous_post = post[liked_post_pos - 1] ;
        swap(post_pos[like[i]] , post_pos[previous_post]) ;
        swap(post[liked_post_pos] , post[liked_post_pos - 1]);
        
        min_pos[like[i]] = min(min_pos[like[i]] , liked_post_pos - 1) ;
        max_pos[previous_post] = max(max_pos[previous_post] , liked_post_pos) ;
    }
    
    for(int i = 1 ; i <= n ; i++)
        cout<<min_pos[i]<<" "<<max_pos[i]<<endl;
        
    return 0 ;
}
