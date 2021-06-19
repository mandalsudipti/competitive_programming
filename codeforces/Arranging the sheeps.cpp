#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        string S ;
        cin>>n>>S;
        
        vector<int>star ;
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] == '*')
                star.push_back(i) ;
        }
        
        long long int left_cost = 0 , right_cost = 0 , left_cnt = 0 , right_cnt = star.size() ;
        for(int i = 0 ; i < star.size(); i++)
            right_cost+=(star[i] - i);
            
        long long int min_cost = right_cost ;
        for(int partition = 1 ; partition < n ; partition++)
        {
            if(S[partition-1] == '*')
            {
                left_cnt++ ;
                right_cnt--;
                continue ;
            }
            left_cost+=left_cnt ;
            right_cost-=right_cnt ;
            
            min_cost = min(min_cost , left_cost + right_cost) ;
        }
        cout<<min_cost<<endl;
    }
    
    return 0 ;
}