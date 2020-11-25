#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x ;
        cin>>x;
        
        int digit = x%10 , len = floor(log10(x) + 1);
        int sum = (digit - 1)* 10 + (len * (len + 1))/2 ;
        cout<<sum<<endl;
    }
    
    return 0;
}