#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        vector<int>copy_arr = arr ;
        sort(copy_arr.begin() , copy_arr.end());
        
        map<int,int>correct_pos ;
        for(int i = 0 ; i < copy_arr.size() ; i++)
            correct_pos[copy_arr[i]] = i ;
            
        
        int idx = 0 , cnt = 1 ;
        while(idx + 1< n )
        {
            if(correct_pos[arr[idx+1]] - correct_pos[arr[idx]] == 1)
                idx++ ;
            else
            {
                cnt++;
                idx++;
            }
        }
        
        if(cnt <= k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}