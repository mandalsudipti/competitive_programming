#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T ;
    
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        
        vector<int>arr(n);
        for(int i = 0 ; i < n ;i++)
        {
            cin>>arr[i] ;
        }
        sort(arr.begin() , arr.end());
        
        int prefix_sum = 0 ;
        bool flag = true ;
        for(int i = 0 ; i < n ; i++)
        {
            prefix_sum+=arr[i] ;
            if(prefix_sum == x)
            {
                for(int j = i ; j >= 0 ; j--)
                {
                    if(arr[j] != arr[n-1])
                    {
                        swap(arr[j],arr[n-1]);
                        prefix_sum = prefix_sum - arr[j] + arr[n-1] ;
                        break;
                    }
                }
                if(prefix_sum == x || arr[0] == x || i == n-1)
                    flag = false ;
                break;
            }
        }
        
        if(!flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i = 0 ; i < n ; i++)
                cout<<arr[i]<<" ";
                
            cout<<endl;
        }
    }
    return 0 ;
}

