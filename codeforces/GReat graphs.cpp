#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int node ;
        cin>>node ;
        vector<long long int>distance(node);
        for(int i = 0 ; i < node ; i++)
            cin>>distance[i] ;
            
        sort(distance.begin() , distance.end());
        vector<long long int>positive_edge(node) ;
        
        positive_edge[0] = distance[0] ;
        for(int i = 1 ; i < node ; i++)
            positive_edge[i] = distance[i] - distance[i-1] ;
            
        vector<long long int>negetive_edge(node,0);
        long long int ans = distance.back() ;
        for(int i = 1 ; i < node ; i++)
        {
            negetive_edge[i] = negetive_edge[i-1] + (i * (-1) * positive_edge[i]) ;
            ans+=negetive_edge[i] ;
        }
        
        cout<<ans<<endl;
    }
    return 0 ;
}
