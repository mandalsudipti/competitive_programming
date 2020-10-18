#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        if(n<=2)
        {
            cout<<"1"<<endl;
            continue;
        }
        n-=2;
        int ans = (n/x) + (n%x!=0) ;
        cout<<ans+1<<endl;
    }
    
    return 0;
}
