#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        if((n/2)%2 == 0 && n%2 == 0)
            cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        else if((n/2)%2 == 1 && n%2 == 0)
            cout<<(n/2)-1<<" "<<(n/2)-1<<" "<<"2"<<endl;
        else if((n/2)%2 == 0 && n%2 == 1)
            cout<<n/2<<" "<<n/2<<" "<<"1"<<endl;
        else
            cout<<n/2<<" "<<n/2<<" "<<"1"<<endl;
            
    }
    
    return 0;
}
