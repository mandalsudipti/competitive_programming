#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x , y  ;
        cin>>x>>y;
        int step;
        
        if(x<y)
        {
            step = 2*x ;
            y-=x;
            if(y>0)
                step+=(y+(y-1));
        }
        else
        {
            step = 2*y ;
            x-=y;
            if(x>0)
                step+=(x+(x-1));
        }
        cout<<step<<endl;
    }
    
    return 0;
}