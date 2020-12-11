#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int Alice , Bob ;
        cin>>Alice>>Bob;
        
        long long int winA = 0 , winB = 0 ;
        if(Bob >= Alice)
        {
            winA = Alice - 1 ;
            winB = Bob ;
        }
        else
        {
            winA = (Alice - Bob) + (Bob - 1);
            winB = Bob ;
        }
        
        cout<<winA<<" "<<winB<<endl;
    }
    
    return 0;
}