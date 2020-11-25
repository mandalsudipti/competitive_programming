#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x1 , y1 , x2 , y2 ;
        cin>>x1>>y1>>x2>>y2 ;
        
        long long int ans = abs(x1-x2) + abs(y1 - y2) ;
        if(x1!=x2 && y1!=y2)
            ans+=2;
        cout<<ans<<endl;
    }
    
    return 0;
}