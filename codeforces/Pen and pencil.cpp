#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int lecture , practical , one_pen , one_pencil , k ;
        cin>>lecture>>practical>>one_pen>>one_pencil>>k;
        int x = (lecture/one_pen) + (lecture%one_pen!=0) ;
        int y = (practical/one_pencil) + (practical%one_pencil!=0) ;
        if((x+y)>k)
            cout<<"-1"<<endl;
        else
            cout<<x<<" "<<y<<endl;
    }
    return 0;
}
