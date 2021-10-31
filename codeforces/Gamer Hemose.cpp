#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n  ;
        long long int H ;
        cin>>n>>H;
        
        vector<long long int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end() , greater<long long int>()) ;
        long long int val = arr[0] + arr[1] ;
        long long int step = (H / val)*2 ;
        
        if(H == 0)
            H = 1 ;
        else if((step/2) * val < H)
        {
            if(H % val <= arr[0])
                step++ ;
            else
                step+=2 ;
        }
        
        cout<<step<<endl;
    }
    return 0 ;
}