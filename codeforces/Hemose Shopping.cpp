#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , x ;
        cin>>n>>x ;
        
        vector<int>arr(n) , sorted_arr(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            sorted_arr[i] = arr[i] ;
        }
        sort(sorted_arr.begin() , sorted_arr.end()) ;
        
        if(n >= 2*x)
            cout<<"YES\n" ;
        else
        {
            bool flag = true ;
            for(int i = 0 ; i < n ; i++)
            {
                if(i - x >= 0 || i+x < n)
                    continue ;
                if(sorted_arr[i] != arr[i])
                {
                    flag = false ;
                    break;
                }
            }
            
            if(flag)
                cout<<"YES\n" ;
            else
                cout<<"NO\n" ;
        }
    }
    return 0 ;
}