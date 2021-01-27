#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<vector<int>>arr(n , vector<int>(2));
        vector<vector<int>> sorted_arr(n , vector<int>(2));
        vector<int>sorted_height(n) ;
        map<pair<int,int>,int>idx ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i][0]>>arr[i][1] ;
            sorted_arr[i][0] = arr[i][0] ;
            sorted_arr[i][1] = arr[i][1] ;
            
            idx[make_pair(arr[i][0] , arr[i][1])] = i ;
        }
        
        sort(sorted_arr.begin() , sorted_arr.end());
        for(int i = 0 ; i < n ; i++)
            sorted_height[i] = sorted_arr[i][0] ;
        map<pair<int,int> , int>min_weight_so_far ;
        
        
        for(int i = 0 ; i < n ; i++)
        {
            pair<int,int>p = make_pair(sorted_arr[i][0] , sorted_arr[i][1]) ;
            if(i == 0 )
                min_weight_so_far[p] = idx[p] ;
            else
            {
                int pre_idx = min_weight_so_far[make_pair(sorted_arr[i-1][0] , sorted_arr[i-1][1])] ;
                if(sorted_arr[i][1] <= arr[pre_idx][1])
                    min_weight_so_far[p] = idx[p] ;
                else
                    min_weight_so_far[p] = pre_idx ;
            }
                
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            bool flag = false ;
            int tmp = lower_bound(sorted_height.begin() , sorted_height.end() , arr[i][0]) - sorted_height.begin() ;
            tmp-- ;
            if(tmp >= 0)
            {
                int j = min_weight_so_far[make_pair(sorted_arr[tmp][0] , sorted_arr[tmp][1])] ;
                if(arr[j][1] < arr[i][1])
                {
                    flag = true ;
                    cout<<(j + 1)<<" ";
                }
            }
            if(!flag)
            {
                tmp = lower_bound(sorted_height.begin() , sorted_height.end() , arr[i][1]) - sorted_height.begin() ;
                tmp--;
                if(tmp >= 0)
                {
                    int j = min_weight_so_far[make_pair(sorted_arr[tmp][0],sorted_arr[tmp][1])] ;
                    if(arr[j][1] < arr[i][0])
                    {
                        flag = true ;
                        cout<<(j+1)<<" ";
                    }
                }
            }
            if(!flag)
                cout<<"-1"<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
