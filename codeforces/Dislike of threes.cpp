#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int k ;
        cin>>k;
        
        int num = 1 ;
        while(k > 1)
        {
            num++ ;
            while(num%3 == 0 || num%10 == 3)
                num++ ;
            k-- ;
        }
        cout<<num<<endl;
    }
    return 0 ;
}