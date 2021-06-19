#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int A , B , x , y , z ;
        cin>>A>>B;
        
        if(B == 1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            x = B*A ;
            y = A ;
            z = (B+1)*A ;
            
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
    }
    return 0 ;
}