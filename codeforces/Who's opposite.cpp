#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int a , b , c ;
        cin>>a>>b>>c ;
        
        if(a > b)
            swap(a,b) ;
            
        if(b - a <= 1 || b - a - 1 < (a-1)) // check whether valid circle
            cout<<"-1\n" ;
        else
        {
            long long int n = b + ( b - a - 1 - (a - 1)) ;
            
            if(c > n)
                cout<<"-1\n" ;
            else if(c < a)
                cout<<(b - (a - c))<<endl;
            else if(c > b)
                cout<<(a + (c-b))<<endl;
            else if(c > a)
                cout<<( (b + (c-a))<=n ? b + (c-a) : (b + (c-a)) - n)<<endl;
            else
                cout<<"-1\n" ;
        }
    }
    return 0 ;
}
