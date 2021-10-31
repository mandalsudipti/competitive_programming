#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        
        vector<int>arr(n+1) ;
        vector<vector<int>>val_at_pos(n+1 , vector<int>(n+1,-1)) ;
        
        map<int,int>cur_freq ;
        
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>arr[i] ;
            val_at_pos[0][i] = arr[i] ;
            cur_freq[arr[i]]++ ;
        }
        
        vector<vector<vector<int>>>freq(n+1 , vector<vector<int>>(n+1)) ; // step , freq , positions
        for(int i = 1 ; i <= n ; i++)
            freq[0][cur_freq[arr[i]]].push_back(i) ;
            
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(freq[i-1][j].size() == 0)
                    continue ;
                    
                int key = freq[i-1][j].size() ;
                
                for(int ele : freq[i-1][j])
                    freq[i][key].push_back(ele) ;
                //cout<<i<<" "<<j<<endl;    
                for(int k = 1 ; k <= n ; k++)
                {
                    for(int ele : freq[i-1][k])
                        val_at_pos[i][ele] = k ;
                }
            }
        }
        
        int query ;
        cin>>query ;
        
        while(query--)
        {
            int pos , k ;
            cin>>pos>>k ;
            
            if(k>n)
                k = n ;
                
            cout<<val_at_pos[k][pos]<<endl;
        }
    }
    
    return 0 ;
}

