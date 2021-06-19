#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1e9 + 7 ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr1(n) , arr2(n) ;
        vector<bool>visited(n , false);
        vector<vector<int>>idx(n+1 , vector<int>(2));
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr1[i] ;
            idx[arr1[i]][0] = i ;
        }
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr2[i] ;
            idx[arr2[i]][1] = i ;
        }
        
        int count = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(visited[i])
                continue ;
            queue<pair<int,int>>Q ;
            count++;
            visited[i] = true ;
            Q.push(make_pair(arr1[i] , arr2[i]));
            
            while(!Q.empty())
            {
                int x = Q.front().first , y = Q.front().second ;
                Q.pop() ;
                
                if(!visited[idx[x][1]])
                {
                    int tmp = idx[x][1] ;
                    visited[tmp] = true ;
                    Q.push(make_pair(arr1[tmp] , arr2[tmp]));
                }
                if(!visited[idx[y][0]])
                {
                    int tmp = idx[y][0] ;
                    visited[tmp] = true ;
                    Q.push(make_pair(arr1[tmp] , arr2[tmp]));
                }
            }
            
        }
        
        long long int ans = 1 ;
        while(count > 0)
        {
            ans = (ans * 2ll)%mod ;
            count--;
        }
        cout<<ans<<endl;
    }
    return 0 ;
}