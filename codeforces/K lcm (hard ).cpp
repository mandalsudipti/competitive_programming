#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , k  ;
        cin>>n>>k ;
        
        n-=(k-3) ;
        for(int i = 0 ; i < (k-3) ; i++)
            cout<<"1 ";
            
        if(n%2)
            cout<<"1"<<" "<<n/2<<" "<<n/2;
        else
        {
            if((n/2)%2)
                cout<<"2"<<" "<<(n/2)-1<<" "<<(n/2)-1 ;
            else
                cout<<n/2<<" "<<n/4<<" "<<n/4;
        }
        cout<<endl;
    }
    
    return 0;
}