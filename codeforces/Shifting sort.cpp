#include<bits/stdc++.h>
using namespace std ;

int get_right(vector<int>& arr , int idx , int num)
{
    for(int i = idx + 1 ; i < arr.size() ; i++)
    {
        if(arr[i] == num)
            return i ;
    }
    
    return -1 ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        
        vector<int>arr(n) , sorted_arr(n) ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            sorted_arr[i] = arr[i] ;
        }
        
        sort(sorted_arr.begin() , sorted_arr.end()) ;
        vector<vector<int>>op ;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] == sorted_arr[i])
                continue ;
            int left = i , right = get_right(arr , i , sorted_arr[i]), d = right - left ;
            for(int j = right - 1 ; j >= left ; j--)
            {
                arr[j+1] = arr[j] ;
            }
            arr[left] = sorted_arr[i] ;
            
            op.push_back({left+1 , right+1 , d});
        }
        
        cout<<op.size()<<endl;
        for(int i = 0 ; i < op.size() ; i++)
            cout<<op[i][0]<<" "<<op[i][1]<<" "<<op[i][2]<<endl;
    }
    
    return 0 ;
}
