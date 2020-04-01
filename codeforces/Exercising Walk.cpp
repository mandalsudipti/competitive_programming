#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int l , r , d , u ;
        cin>>l>>r>>d>>u;
        long long int x,y ,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        long long int last_x = x+r-l , last_y=y+u-d ;
        if((x==x1 && x==x2 && (l!=0 || r!=0))|| (y==y1 && y==y2 &&(u!=0 || d!=0) ))
            cout<<"NO"<<endl;
        else if(last_x<=x2 && last_x>=x1 && last_y<=y2 && last_y>=y1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
    }
    return 0;
}