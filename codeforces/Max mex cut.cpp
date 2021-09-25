#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    int zero_zero = 0 , zero_one = 1 , one_one = 2 ;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<string>grid(2) ;
        
        for(int i = 0 ; i < 2 ; i++)
            cin>>grid[i] ;
            
        vector<int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
        {
            if(grid[0][i] == grid[1][i])
            {
                if(grid[0][i] == '0')
                    arr[i] = zero_zero ;
                else
                    arr[i] = one_one ;
            }
            else
                arr[i] = zero_one ;
        }
        
        int total = 0 , idx = 0 ;
        while(idx < n)
        {
            if(arr[idx] == zero_one)
            {
                idx++ ;
                total+=2 ;
            }
            else if(arr[idx] == one_one)
            {
                if(idx + 1 < n && arr[idx+1] == zero_zero)
                {
                    total+=2;
                    idx+=2;
                }
                else
                    idx++;
            }
            else
            {
                if(idx + 1 < n && arr[idx+1] == one_one)
                {
                    total+=2;
                    idx+=2;
                }
                else
                {
                    total++;
                    idx++;
                }
            }
        }
        
        cout<<total<<endl;
    }
    return 0 ;
}