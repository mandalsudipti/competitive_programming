#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        vector<int>arr(4);
        for(int i = 0 ; i < 4 ; i++)
            cin>>arr[i] ;
        
        int max1 = 0 , max2 ;
        for(int i = 1 ; i  < 4 ; i++)
        {
            if(arr[i] > arr[max1])
                max1 = i ;
        }
        max2 = (max1 + 1)%4 ;
        for(int i = 0 ; i < 4 ; i++)
        {
            if(arr[i] > arr[max2] && arr[i] != arr[max1])
                max2 = i ;
        }
        
        if( ( (max1 == 0 || max1 == 1) && (max2 == 2 || max2 == 3) ) || ( (max1 == 2 || max1 == 3) && (max2 == 0 || max2 == 1) ))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
