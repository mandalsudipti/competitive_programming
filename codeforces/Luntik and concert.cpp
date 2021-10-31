#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int one , two , three ;
        cin>>one>>two>>three ;
        
        long long int sum = one + (2 * two) + (3 * three) ;
        cout<<sum%2<<endl;
    }
    
    return 0 ;
}
