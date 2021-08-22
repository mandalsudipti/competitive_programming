#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    vector<long long int>square ;
    
    long long int num = 0 ;
    while(num*num < 1e10 + 7)
    {
        square.push_back(num * num) ;
        num++ ;
    }
    
    while(T--)
    {
        long long int k ;
        cin>>k ;
        
        long long int dim = lower_bound(square.begin() , square.end() , k) - square.begin() ;
    
        long long int left = square[dim-1] + 1 , right = square[dim] ;
        
        if(k <= left + (right - left)/2)
            cout<<(k - left)+1<<" "<<(dim - 1)+1<<endl;
        else
            cout<<(dim - 1)+1<<" "<<(right - k)+1<<endl;
    }
    return 0 ;
}
