#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a , b , c ;
        cin>>a>>b>>c;
        int minimum = min(a,c) , maximum = max(a,c);
        int g1 = minimum , g2 = maximum/2 , g3 = (maximum/2)+(maximum%2) ;
        int largest = max(g1,max(g2,g3)) , x;
        
        x=min(b,largest-g1);
        g1+=x;
        b=b-x;
        
        x=min(b,largest-g2);
        g2+=x;
        b=b-x;
        
        x=min(b,largest-g3);
        g3+=x;
        b=b-x;

        int ans = max(g1,max(g2,g3)) + (b/3)+(b%3!=0) ;
        
        cout<<ans<<endl;
    }
    return 0;
}