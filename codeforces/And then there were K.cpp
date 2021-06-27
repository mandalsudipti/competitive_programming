#include<bits/stdc++.h>
using namespace std ;

int msb(int num)
{
    int idx = -1 ;
    while(num > 0)
    {
        idx++ ;
        num = num / 2 ;
    }
    
    return idx ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        int left_most_bit = msb(n) ;
        int num = (1<<left_most_bit) ;
        
        cout<<(num - 1)<<endl;
    }
    return 0 ;
}