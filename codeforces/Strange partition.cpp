#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T ;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        
        long long int total = 0 , minimum = 0 , maximum = 0 ,val ;
        for(int i = 0 ; i < n ;i++)
        {
            cin>>val;
            maximum+=((val/x) + (val%x != 0));
            total+=val;
        }
        
        minimum = (total / x) + (total % x != 0);
        cout<<minimum<<" "<<maximum<<endl;
    }
    
    return 0;
}
