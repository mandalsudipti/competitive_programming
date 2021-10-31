#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int a , b ;
        cin>>a>>b ;
        
        int op = INT_MAX ;
        
        for(int i = 0 ; i <= 100 ; i++)
        {
            int c = b + i , d = a , cur_op = i;
            if(c == 1)
            {
                c++ ;
                cur_op++ ;
            }
            
            while(d > 0)
            {
                d = d / c ;
                cur_op++ ;
            }
            op = min(op , cur_op) ;
        }
        cout<<op<<endl;
    }
    return 0 ;
}