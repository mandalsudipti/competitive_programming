#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        
        vector<long long int>arr(n) ;
        vector<long long int>prefix_xor(n) ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            prefix_xor[i] = arr[i] ;
            if(i > 0)
                prefix_xor[i] = (prefix_xor[i] ^ prefix_xor[i-1]) ;
        }
        
        bool possible = false ;
        
        for(int i = 0 ; i < n-1 ; i++)
        {
            long long int left = prefix_xor[i] , right = (prefix_xor[n-1] ^ prefix_xor[i]) ;
            if(left == right)
            {
                possible = true ;
                break;
            }
            else if( right == 0)
            {
                for(int j = i+1; j < n-1 ; j++)
                {
                    long long int left_xor = (prefix_xor[j] ^ prefix_xor[i]) ;
                    long long int right_xor = (prefix_xor[n-1] ^ prefix_xor[j]) ;
                    if(left_xor == right_xor && left_xor == left)
                    {
                        possible = true ;
                        break;
                    }
                }
                if(possible)
                    break;
            }
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0 ;
}
