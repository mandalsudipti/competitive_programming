#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<int>arr(m) ;
        for(int i = 0 ; i < m ; i++)
            cin>>arr[i] ;
            
        int total = 0 ;
        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[j] < arr[i])
                    total++;
            }
        }
        cout<<total<<endl;
    }
    return 0 ;
}