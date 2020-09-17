#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a , b ;
        cin>>a>>b;
        
        long long int x  =abs(a-b);
        cout<<(x/10)+(x%10!=0)<<endl;
    }
    
    return 0;
}