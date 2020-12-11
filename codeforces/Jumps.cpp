#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        long long int sum = 0 , step = 0 ;
        while(sum < n)
        {
            step++;
            sum+=step;
        }
        
        if(sum - n == 1)
            step++;
            
        cout<<step<<endl;
    }
    
    return 0;
}
