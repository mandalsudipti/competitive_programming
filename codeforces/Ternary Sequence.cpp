#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int A_zero , A_one , A_two , B_zero , B_one , B_two ;
        cin>>A_zero>>A_one>>A_two>>B_zero>>B_one>>B_two;
        
        long long int x = min(B_two,A_zero);
        B_two-=x;
        A_zero-=x;
        
        long long int y = min(B_two ,A_two);
        B_two-=y;
        A_two-=y;
        
        if(B_two>0)
        {
            cout<<(-2)*(B_two)<<endl;
        }
        else
        {
            long long int sum = 0 ;
            x = min(A_two,B_one);
            A_two-=x;
            B_one-=x;
            sum  = x*2 ;
            cout<<sum<<endl;
        }
    }
    
    return 0;
}
