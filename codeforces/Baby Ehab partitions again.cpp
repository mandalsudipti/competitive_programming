#include<bits/stdc++.h>
using namespace std ;


bool partition(vector<int>& arr , long long int sum)
{
    sum = sum / 2 ;

    vector<vector<bool>>is_sum(arr.size() , vector<bool>(sum+1,false));
    
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(i == 0 && arr[i] <= sum)
            is_sum[0][arr[i]] = true ;
        else if(i > 0)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(j == arr[i] || is_sum[i-1][j] == true)
                    is_sum[i][j] = true ;
                else if( j - arr[i] > 0 && is_sum[i-1][j - arr[i]] == true)
                    is_sum[i][j] = true ;
            }
        }
    }
    
    
    int n = arr.size() - 1 ;
    return is_sum[n][sum] ;
}

int main()
{
        int n ;  
        cin>>n;
        
        vector<int>arr(n) ;
        long long int sum = 0 ; 
        int is_odd = -1 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            sum+=arr[i] ;
            if(arr[i]%2 == 1)
                is_odd = i ;
        }
        
        if(sum % 2 == 1 || (sum%2 == 0 && !partition(arr , sum)) )
        {
            cout<<"0"<<endl;
        }
        else if( is_odd != -1)
        {
            cout<<"1"<<endl;
            cout<<is_odd+1<<endl;
        }
        else
        {
            int minimum = 100 ;
            
            for(int i = 0 ; i < n ; i++)
            {
                int cur = arr[i] , cur_power = 0;
                while(cur % 2 == 0)
                {
                    cur_power++ ;
                    cur = cur / 2 ;
                }
                minimum = min(minimum , cur_power) ;
            }
            
            long long int divide = 1 ;
            while(minimum > 0)
            {
                divide = divide * 2 ;
                minimum-- ;
            }
            
            for(int i = 0 ; i < n ; i++)
                arr[i] = arr[i] / divide ;
                
            int idx = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if(arr[i] % 2 == 1)
                {
                    idx = i ;
                    break;
                }
            }
            
            cout<<"1"<<endl;
            cout<<idx+1<<endl;
        }
    
    return 0 ;
}