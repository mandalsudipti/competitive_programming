#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n ;
    cin>>n;
    
    vector<int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i] ;
        
    
    long long int health = 0 ;
    multiset<long long int>potion ;
    
    for(int i = 0 ; i < n ; i++)
    {
        potion.insert(arr[i]) ;
        health+=arr[i] ;
        
        while(health < 0)
        {
            health-=(*potion.begin()) ;
            potion.erase(potion.begin()) ;
        }
    }
    
    cout<<potion.size()<<endl;
    return  0;
}
